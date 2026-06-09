#ifndef _TCAS_CRC_32_H_
#define _TCAS_CRC_32_H_

#include <stdint.h>

#ifdef __cplusplus
  extern "C"
  {
#endif /* __cplusplus */

uint32_t CalculateCRC32 (const uint32_t cnt,
                          const uint8_t *buf);

uint32_t CalculateCRC32_KMS (const uint32_t cnt,
                          const uint8_t *buf);



#ifdef __cplusplus
  }
#endif /* __cplusplus */

#endif  // _TCAS_CRC_32_H_
