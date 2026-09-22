#include "EventLoggerLED.h"

#include <QDebug>
#include <QSettings>

#include <linux/i2c-dev.h>

#include <sys/ioctl.h>

#include <fcntl.h>
#include <unistd.h>

#include <errno.h>
#include <cstring>


// ============================================================
// CONSTRUCTOR
// ============================================================

EventLoggerLED::EventLoggerLED(const QString &configPath,
                               QObject *parent)
    : QObject(parent),
      m_configPath(configPath),
      m_i2cAddress(0),
      m_gpioLine(-1),
      m_minVoltage(0.0),
      m_maxVoltage(0.0),
      m_i2cFd(-1),
      m_gpioChipHandle(nullptr),
      m_gpioLineHandle(nullptr),
      m_timer(nullptr),
      m_ledState(false)
{
    qInfo() << "========================================";
    qInfo() << "EventLoggerLED Initialization";
    qInfo() << "========================================";

    // --------------------------------------------------------
    // Read ALL hardware configuration from Config.cfg
    // --------------------------------------------------------

    if (!readConfiguration())
    {
        qWarning()
            << "[EventLoggerLED] Configuration read FAILED";

        return;
    }

    // --------------------------------------------------------
    // Initialize I2C
    // --------------------------------------------------------

    if (!initializeI2C())
    {
        qWarning()
            << "[EventLoggerLED] INA228 initialization FAILED";

        return;
    }

    // --------------------------------------------------------
    // Initialize GPIO
    // --------------------------------------------------------

    if (!initializeGPIO())
    {
        qWarning()
            << "[EventLoggerLED] Power LED GPIO initialization FAILED";

        return;
    }

    // --------------------------------------------------------
    // Start with LED OFF
    // --------------------------------------------------------

    setLed(false);

    // --------------------------------------------------------
    // Create monitoring timer
    // --------------------------------------------------------

    m_timer = new QTimer(this);

    connect(
        m_timer,
        &QTimer::timeout,
        this,
        &EventLoggerLED::check24VHealth);

    // Check every 1 second
    m_timer->start(1000);

    // Check immediately
    check24VHealth();

    qInfo()
        << "[EventLoggerLED] Monitoring started";
}


// ============================================================
// DESTRUCTOR
// ============================================================

EventLoggerLED::~EventLoggerLED()
{
    cleanup();
}


// ============================================================
// READ CONFIGURATION
// ============================================================

bool EventLoggerLED::readConfiguration()
{
    QSettings settings(
        m_configPath,
        QSettings::IniFormat);

    settings.beginGroup("POWER");

    // --------------------------------------------------------
    // INA228 I2C Device
    // --------------------------------------------------------

    m_i2cDevice =
        settings.value(
            "INA228_24V_I2C")
        .toString()
        .trimmed();

    if (m_i2cDevice.isEmpty())
    {
        qWarning()
            << "[EventLoggerLED] Missing:"
            << "INA228_24V_I2C";

        settings.endGroup();
        return false;
    }

    // --------------------------------------------------------
    // INA228 Address
    //
    // Example:
    // INA228_24V_Addr=0x41
    // --------------------------------------------------------

    const QString addressString =
        settings.value(
            "INA228_24V_Addr")
        .toString()
        .trimmed();

    bool addressOk = false;

    m_i2cAddress =
        addressString.toInt(
            &addressOk,
            0);

    if (!addressOk)
    {
        qWarning()
            << "[EventLoggerLED] Invalid INA228 address:"
            << addressString;

        settings.endGroup();
        return false;
    }

    // --------------------------------------------------------
    // Power LED GPIO Chip
    // --------------------------------------------------------

    m_gpioChip =
        settings.value(
            "PowerLedGpioChip")
        .toString()
        .trimmed();

    if (m_gpioChip.isEmpty())
    {
        qWarning()
            << "[EventLoggerLED] Missing:"
            << "PowerLedGpioChip";

        settings.endGroup();
        return false;
    }

    // --------------------------------------------------------
    // Power LED GPIO Line
    // --------------------------------------------------------

    bool gpioLineOk = false;

    m_gpioLine =
        settings.value(
            "PowerLedGpioLine")
        .toString()
        .trimmed()
        .toInt(&gpioLineOk);

    if (!gpioLineOk || m_gpioLine < 0)
    {
        qWarning()
            << "[EventLoggerLED] Invalid GPIO line";

        settings.endGroup();
        return false;
    }

    // --------------------------------------------------------
    // 24V minimum voltage
    // --------------------------------------------------------

    bool minVoltageOk = false;

    m_minVoltage =
        settings.value(
            "Power24VMin")
        .toString()
        .trimmed()
        .toDouble(&minVoltageOk);

    if (!minVoltageOk)
    {
        qWarning()
            << "[EventLoggerLED] Invalid Power24VMin";

        settings.endGroup();
        return false;
    }

    // --------------------------------------------------------
    // 24V maximum voltage
    // --------------------------------------------------------

    bool maxVoltageOk = false;

    m_maxVoltage =
        settings.value(
            "Power24VMax")
        .toString()
        .trimmed()
        .toDouble(&maxVoltageOk);

    if (!maxVoltageOk)
    {
        qWarning()
            << "[EventLoggerLED] Invalid Power24VMax";

        settings.endGroup();
        return false;
    }

    settings.endGroup();

    // --------------------------------------------------------
    // Print configuration
    // --------------------------------------------------------

    qInfo()
        << "[EventLoggerLED] Configuration";

    qInfo()
        << "  I2C Device  :"
        << m_i2cDevice;

    qInfo()
        << "  INA228 Addr  :"
        << QString("0x%1")
               .arg(
                   m_i2cAddress,
                   2,
                   16,
                   QChar('0'));

    qInfo()
        << "  GPIO Chip    :"
        << m_gpioChip;

    qInfo()
        << "  GPIO Line    :"
        << m_gpioLine;

    qInfo()
        << "  Min Voltage  :"
        << m_minVoltage
        << "V";

    qInfo()
        << "  Max Voltage  :"
        << m_maxVoltage
        << "V";

    return true;
}


// ============================================================
// INITIALIZE INA228
// ============================================================

bool EventLoggerLED::initializeI2C()
{
    m_i2cFd =
        ::open(
            m_i2cDevice.toLocal8Bit().constData(),
            O_RDWR);

    if (m_i2cFd < 0)
    {
        qWarning()
            << "[EventLoggerLED] Cannot open I2C:"
            << m_i2cDevice
            << strerror(errno);

        return false;
    }

    if (ioctl(
            m_i2cFd,
            I2C_SLAVE,
            m_i2cAddress) < 0)
    {
        qWarning()
            << "[EventLoggerLED] Cannot set INA228 address:"
            << QString("0x%1")
                   .arg(
                       m_i2cAddress,
                       2,
                       16,
                       QChar('0'))
            << strerror(errno);

        ::close(m_i2cFd);

        m_i2cFd = -1;

        return false;
    }

    qInfo()
        << "[EventLoggerLED] INA228 I2C initialized";

    return true;
}


// ============================================================
// INITIALIZE POWER LED GPIO
// ============================================================

bool EventLoggerLED::initializeGPIO()
{
    QString chipPath =
        m_gpioChip;

    if (!chipPath.startsWith("/dev/"))
        chipPath =
            "/dev/" + chipPath;

    m_gpioChipHandle =
        gpiod_chip_open(
            chipPath.toLocal8Bit().constData());

    if (!m_gpioChipHandle)
    {
        qWarning()
            << "[EventLoggerLED] Cannot open GPIO chip:"
            << chipPath
            << strerror(errno);

        return false;
    }

    m_gpioLineHandle =
        gpiod_chip_get_line(
            m_gpioChipHandle,
            static_cast<unsigned int>(
                m_gpioLine));

    if (!m_gpioLineHandle)
    {
        qWarning()
            << "[EventLoggerLED] Cannot get GPIO line:"
            << m_gpioLine
            << strerror(errno);

        return false;
    }

    // GPIO output, initial LOW
    if (gpiod_line_request_output(
            m_gpioLineHandle,
            "EventLoggerLED",
            0) < 0)
    {
        qWarning()
            << "[EventLoggerLED] Cannot request GPIO output:"
            << strerror(errno);

        return false;
    }

    qInfo()
        << "[EventLoggerLED] Power LED GPIO initialized";

    return true;
}


// ============================================================
// READ INA228 24V BUS VOLTAGE
// ============================================================

bool EventLoggerLED::read24VVoltage(
    double &voltage)
{
    voltage = 0.0;

    if (m_i2cFd < 0)
        return false;

    // --------------------------------------------------------
    // Select VBUS register
    // --------------------------------------------------------

    unsigned char reg =
        INA228_BUS_VOLTAGE_REG;

    if (::write(
            m_i2cFd,
            &reg,
            1) != 1)
    {
        return false;
    }

    // --------------------------------------------------------
    // Read 24-bit VBUS register
    // --------------------------------------------------------

    unsigned char data[3] =
    {
        0,
        0,
        0
    };

    const ssize_t bytesRead =
        ::read(
            m_i2cFd,
            data,
            3);

    if (bytesRead != 3)
    {
        return false;
    }

    // --------------------------------------------------------
    // Combine bytes
    // --------------------------------------------------------

    const quint32 raw =
        (static_cast<quint32>(data[0]) << 16) |
        (static_cast<quint32>(data[1]) << 8) |
        static_cast<quint32>(data[2]);

    // --------------------------------------------------------
    // Convert to volts
    // --------------------------------------------------------

    voltage =
        static_cast<double>(raw) *
        INA228_BUS_VOLTAGE_LSB;

    return true;
}


// ============================================================
// CHECK 24V POWER HEALTH
// ============================================================

void EventLoggerLED::check24VHealth()
{
    double voltage = 0.0;

    // --------------------------------------------------------
    // INA228 communication failure
    // --------------------------------------------------------

    if (!read24VVoltage(voltage))
    {
        qWarning()
            << "[EventLoggerLED]"
            << "24V Monitor Communication FAILURE";

        // Communication failure -> LED OFF
        setLed(false);

        return;
    }

    qInfo()
        << "[EventLoggerLED]"
        << "24V Rail:"
        << QString::number(
               voltage,
               'f',
               3)
        << "V";

    // --------------------------------------------------------
    // POWER HEALTHY
    //
    // 16.8 V <= V <= 30.0 V
    //
    // AND
    //
    // INA228 communication successful
    // --------------------------------------------------------

    if (voltage >= m_minVoltage &&
        voltage <= m_maxVoltage)
    {
        qInfo()
            << "[EventLoggerLED]"
            << "24V POWER HEALTHY";

        setLed(true);
    }
    else
    {
        // ----------------------------------------------------
        // POWER FAULT
        //
        // V < 16.8 V
        // OR
        // V > 30.0 V
        // ----------------------------------------------------

        qWarning()
            << "[EventLoggerLED]"
            << "24V POWER FAULT";

        setLed(false);
    }
}


// ============================================================
// SET LED
// ============================================================

bool EventLoggerLED::setLed(bool on)
{
    if (!m_gpioLineHandle)
        return false;

    const int value =
        on ? 1 : 0;

    if (gpiod_line_set_value(
            m_gpioLineHandle,
            value) < 0)
    {
        qWarning()
            << "[EventLoggerLED] GPIO LED write failed:"
            << strerror(errno);

        return false;
    }

    m_ledState = on;

    qInfo()
        << "[EventLoggerLED] LED:"
        << (on ? "ON" : "OFF");

    return true;
}


// ============================================================
// CLEANUP
// ============================================================

void EventLoggerLED::cleanup()
{
    // --------------------------------------------------------
    // LED OFF
    // --------------------------------------------------------

    if (m_gpioLineHandle)
    {
        gpiod_line_set_value(
            m_gpioLineHandle,
            0);

        gpiod_line_release(
            m_gpioLineHandle);

        m_gpioLineHandle = nullptr;
    }

    // --------------------------------------------------------
    // GPIO chip
    // --------------------------------------------------------

    if (m_gpioChipHandle)
    {
        gpiod_chip_close(
            m_gpioChipHandle);

        m_gpioChipHandle = nullptr;
    }

    // --------------------------------------------------------
    // I2C
    // --------------------------------------------------------

    if (m_i2cFd >= 0)
    {
        ::close(m_i2cFd);
        m_i2cFd = -1;
    }
}
