
/******************************************************************************
 *                                                                            *
 * Application Name : RFPSDB                                                  *
 *                                                                            *
 * File name        : RFPSDB.cpp                                              *
 *                                                                            *
 * Class name       : RFPSDB                                                  *
 *                                                                            *
 * Author           : DLRL RFPS                                               *
 *                                                                            *
 * Description      : This class is part of the RFPSDB library, which is used *
 *                    to establish the connection with the PostgreSQL         *
 *                    database. Periodically checks the connectivity with     *
 *                    the database.                                           *
 *                                                                            *
 * Date             : 10 sep, 2014                                            *
 *                                                                            *
 * Version          : 0.0.1                                                   *
 *                                                                            *
 * Reference       : < SRS Ref >                                              *
 *                                                                            *
 * Remarks          : None                                                    *
 *                                                                            *
 ******************************************************************************/

#include "nmsDB.h"

/******************************************************************************
 *                                                                            *
 * Function        : RFPSDB                                                   *
 *                                                                            *
 * Description     : parameterized constructor of the class used to initialize*
 *                   all the member variables                                 *
 *                                                                            *
 * Arguments       : QString  : strDB - database name                         *
 *                   QString  : strHost - host address where the database is  *
 *                                        running.                            *
 *                   QString  : strUser - username using which we are         *
 *                                        connecting to the database.         *
 *                   QString  : strPwd  - password used to connect to database*
 *                   QString  : strPortNum - port number                      *
 *                                                                            *
 * Returns         : None                                                     *
 *                                                                            *
 * Reference       : < SRS Ref >                                              *
 *                                                                            *
 * Remarks         : None                                                     *
 *                                                                            *
 ******************************************************************************/

NMSDB::NMSDB (const QString strHost,  /* database name */
                const uint16_t  usPortNum,
                const QString strDB,
                const QString strUser,
                const QString strPwd,
                QObject *parent)
              : QThread(parent),
                m_strHost (strHost),
                m_usPortNum (usPortNum),
                m_strUser (strUser),
                m_strPwd (strPwd),                
                m_strDB (strDB),
                m_bDBOpen(false)
{

  m_ocDB = QSqlDatabase::addDatabase ("QPSQL");
  m_ocDB.setDatabaseName (m_strDB);

  m_ocDB.setHostName (m_strHost);
  m_ocDB.setPort (m_usPortNum);
}


/******************************************************************************
 *                                                                            *
 * Function        : ~RFPSDB                                                  *
 *                                                                            *
 * Description     : virtual destructor of the class, disconnects from the    *
 *                   database just before this class goes out of scope        *
 *                                                                            *
 * Arguments       : None                                                     *
 *                                                                            *
 * Returns         : None                                                     *
 *                                                                            *
 * Reference       : None                                                     *
 *                                                                            *
 * Remarks         : None                                                     *
 *                                                                            *
 ******************************************************************************/

NMSDB::~NMSDB ()
{

  m_ocDB.removeDatabase (m_strDB);

  Disconnect ();
}


/******************************************************************************
 *                                                                            *
 * Function        : ~RFPSDB                                                  *
 *                                                                            *
 * Description     : thread function keep running continuously in the backend.*
 *                   Validates the database connection and emits the          *
 *                   connection status for every 15 seconds.                  *
 *                                                                            *
 * Arguments       : None                                                     *
 *                                                                            *
 * Returns         : None                                                     *
 *                                                                            *
 * Reference       : None                                                     *
 *                                                                            *
 * Remarks         : None                                                     *
 *                                                                            *
 ******************************************************************************/

void NMSDB::run ()
{

  while (true)
  {
     /* database connection status */
   uint8_t ucDBStatus = IsConnected() ? 1 : 0;

   //emit sigDbStatus(ucDBStatus);

   sleep(10);

   Q_UNUSED(ucDBStatus);
  }
}


/******************************************************************************
 *                                                                            *
 * Function        : Connect                                                  *
 *                                                                            *
 * Description     : function connects to the database using the existing     *
 *                   credentials.                                             *
 *                                                                            *
 * Arguments       : None                                                     *
 *                                                                            *
 * Returns         : RFPS_BOOL                                                *
 *                                                                            *
 * Reference       : None                                                     *
 *                                                                            *
 * Remarks         : None                                                     *
 *                                                                            *
 ******************************************************************************/

bool NMSDB::Connect ()
{

  m_bDBOpen = m_ocDB.open (m_strUser, m_strPwd);

  return m_bDBOpen;
}

/******************************************************************************
 *                                                                            *
 * Function        : Disconnect                                               *
 *                                                                            *
 * Description     : function to disconnect from the database                 *
 *                                                                            *
 * Arguments       : None                                                     *
 *                                                                            *
 * Returns         : RFPS_BOOL : RFPS_TRUE on success. Otherwise RFPS_FALSE   *
                                 will be returned.                            *
 *                                                                            *
 * Reference       : None                                                     *
 *                                                                            *
 * Remarks         : None                                                     *
 *                                                                            *
 ******************************************************************************/

void NMSDB::Disconnect ()
{

  if (m_ocDB.isOpen() == true)
  {
    m_ocDB.close();
  }
}

/******************************************************************************
 *                                                                            *
 * Function        : Get                                                      *
 *                                                                            *
 * Description     : functon returns the database connection. Which is used in*
 *                   other classes to perform database operations             *
 *                                                                            *
 * Arguments       : None                                                     *
 *                                                                            *
 * Returns         : QSqlDatabase                                             *
 *                                                                            *
 * Reference       : None                                                     *
 *                                                                            *
 * Remarks         : None                                                     *
 *                                                                            *
 ******************************************************************************/

QSqlDatabase NMSDB::Get () const
{
  return m_ocDB;
}

QString NMSDB::GetDBPassword()
{
    return m_strPwd;
}


/******************************************************************************
 *                                                                            *
 * Function        : IsDBOpen                                                 *
 *                                                                            *
 * Description     : functon returns the status of the database connection.   *
 *                                                                            *
 * Arguments       : None                                                     *
 *                                                                            *
 * Returns         : RFPS_BOOL : m_bDBOpen, which is updated in the thread.   *
 *                                                                            *
 * Reference       : None                                                     *
 *                                                                            *
 * Remarks         : None                                                     *
 *                                                                            *
 ******************************************************************************/

bool NMSDB::IsDBOpen ()
{
  return m_bDBOpen;
}


/******************************************************************************
 *                                                                            *
 * Function        : IsConnected                                              *
 *                                                                            *
 * Description     : function returns RFPS_TRUE if connected to the database  *
 *                   and is valid. Otherwise false will be returned. Updates  *
 *                   the member variable m_bDBOpen variable internally.       *
 *                                                                            *
 * Arguments       : None                                                     *
 *                                                                            *
 * Returns         : RFPS_BOOL : m_bDBOpen.                                   *
 *                                                                            *
 * Reference       : None                                                     *
 *                                                                            *
 * Remarks         : None                                                     *
 *                                                                            *
 ******************************************************************************/

bool NMSDB::IsConnected()
{
  m_bDBOpen = ((m_ocDB.isOpen() == true) && (m_ocDB.isValid() == true)?1:0);

  if(m_ocDB.isOpen() == false || m_ocDB.isValid() == false)
  {
    m_bDBOpen = m_ocDB.open (m_strUser, m_strPwd);
  }
  return m_bDBOpen;
}
