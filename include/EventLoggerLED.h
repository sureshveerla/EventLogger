#ifndef EVENTLOGGERLED_H
#define EVENTLOGGERLED_H

#include <QObject>
#include <QTimer>
#include <QString>

#include <gpiod.h>

class EventLoggerLED : public QObject
{
    Q_OBJECT

public:
    explicit EventLoggerLED(const QString &configPath,
                            QObject *parent = nullptr);

    ~EventLoggerLED();

private slots:
    void check24VHealth();

private:
    bool readConfiguration();
    bool initializeI2C();
    bool initializeGPIO();

    bool read24VVoltage(double &voltage);
    bool setLed(bool on);

    void cleanup();

private:
    QString m_configPath;

    // Configuration
    QString m_i2cDevice;
    int m_i2cAddress;

    QString m_gpioChip;
    int m_gpioLine;

    double m_minVoltage;
    double m_maxVoltage;

    // I2C
    int m_i2cFd;

    // GPIO
    gpiod_chip *m_gpioChipHandle;
    gpiod_line *m_gpioLineHandle;

    // Timer
    QTimer *m_timer;

    bool m_ledState;

    static constexpr unsigned char INA228_BUS_VOLTAGE_REG = 0x05;
    static constexpr double INA228_BUS_VOLTAGE_LSB =
        0.0001953125;
};

#endif // EVENTLOGGERLED_H
