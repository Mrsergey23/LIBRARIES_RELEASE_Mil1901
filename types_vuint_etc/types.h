/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TYPES_H
#define __TYPES_H

#include <stdint.h>

typedef unsigned char const     ucint8_t;
typedef volatile unsigned char  vuint8_t;
typedef unsigned short const    ucint16_t;
typedef volatile unsigned short vuint16_t;
typedef volatile unsigned long  vuint32_t;

typedef enum {FALSE = 0, TRUE = !FALSE} bool;

#endif /* __TYPES_H */
