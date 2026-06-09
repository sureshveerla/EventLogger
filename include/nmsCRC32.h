
/******************************************************************************
 *                                                                            *
 * Application Name : RFPScommon                                              *
 *                                                                            *
 * File name        : RFPSCRC32.h                                             *
 *                                                                            *
 * Class name       : RFPSCRC32                                               *
 *                                                                            *
 * Author           : Sana Software                                           *
 *                                                                            *
 * Description      : The class computes the CRC32 of the given data.         *
 *                                                                            *
 * Date             : 14 Aug, 2023                                            *
 *                                                                            *
 * Version          : 0.0.1                                                   *
 *                                                                            *
 * Reference        : None                                                    *
 *                                                                            *
 * Remarks          : None                                                    *
 *                                                                            *
 ******************************************************************************/

#ifndef NMS_CRC32_H
#define NMS_CRC32_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

//#include <RFPSDTypes.h>

class nmsCRC32
{

public:

    /* default constructor of the class. */
   nmsCRC32 ();

    /* virtual destructor of the class. */
   ~nmsCRC32 ();

    /* function return's the CRC32 of the given buffer of the
       specified length */
  uint32_t get (const void* buf, size_t len);

    /* function verifies the CRC32 of buffer against the given CRC value.
       Returns RFPS_TRUE if CRC is matched. Otherwise RFPS_FALSE will be
       returned. */
  bool verify(const void* buf, size_t len, uint32_t uiCRC);
};

#endif /* NMS_CRC32_H */
