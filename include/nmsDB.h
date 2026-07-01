
#ifndef NMS_DB_H
#define NMS_DB_H

#include "nmsQtInc.h"


class NMSDB : public QThread
{

    Q_OBJECT

  public:
             /** @brief parameterized constructor of the class used to initialize
                all the member variables */
             NMSDB  (const QString strHost,  /* database name */
                     const uint16_t  usPortNum,
                     const QString strDB,
                     const QString strUser,
                     const QString strPwd,
                     QObject *parent);

      /** @brief virtual destructor of the class, disconnects from the database
                 just before this class goes out of scope */
    virtual ~NMSDB ();

      /** @brief thread function keeps running continuously in the backend */
    void run();

      /** @brief function connects to the database using the existing credentials */
    bool Connect();

      /** @brief function to disconnect from the database */
    void Disconnect ();

      /** @brief functon returns the status of the database connection */
    bool IsDBOpen();

      /** @brief function returns true if connected to the database. Otherwise
         false will be returned. */
    bool IsConnected();

    /** @brief functon returns the database connection. Which is used in other
       classes to perform database operations */
    QSqlDatabase Get () const;

    QString GetDBPassword();

  private:

      /** @brief host address where the database is installed. */
    QString           m_strHost;

      /** @brief database port number */
    uint16_t            m_usPortNum;

      /** @brief database username */
    QString           m_strUser;

      /** @brief database password */
    QString           m_strPwd;

      /** @brief database name */
    QString           m_strDB;

      /** @brief boolean flag indicating the database connection status */
    bool         m_bDBOpen;

      /** @brief instance of the database connection. */
    QSqlDatabase      m_ocDB;
};

#endif /* NMS_DB_H */
