#include "nmsDB.h"

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

NMSDB::~NMSDB ()
{

  m_ocDB.removeDatabase (m_strDB);

  Disconnect ();
}

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

bool NMSDB::Connect ()
{

  m_bDBOpen = m_ocDB.open (m_strUser, m_strPwd);

  return m_bDBOpen;
}

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

bool NMSDB::IsDBOpen ()
{
  return m_bDBOpen;
}

bool NMSDB::IsConnected()
{
  m_bDBOpen = ((m_ocDB.isOpen() == true) && (m_ocDB.isValid() == true)?1:0);

  if(m_ocDB.isOpen() == false || m_ocDB.isValid() == false)
  {
    m_bDBOpen = m_ocDB.open (m_strUser, m_strPwd);
  }
  return m_bDBOpen;
}
