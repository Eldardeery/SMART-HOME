<<<<<<< HEAD
/*
 * common.h
 *
 *  Created on: Jul 14, 2018
 *      Author: dardeery
 */

#ifndef COMMON_H_
#define COMMON_H_

#define Access_reg(Reg)   (*(volatile uint8*)Reg)

#define Toggle_bit(reg,pin)       (Access_reg(reg) ^=(1<<pin))

#define Clear_bit(reg,pin)        (Access_reg(reg) &=~(1<<pin))

#define Set_bit(reg,pin)          (Access_reg(reg) |=(1<<pin)

#define Bit_is_clear(reg,pin)     (!(Access_reg(reg) & (1<<pin)))

#define Bit_is_set(reg,pin)       (Access_reg(reg) & (1<<pin))

#define NULL (void *) 0



typedef unsigned char                       uint8;
typedef signed char                         sint8;
typedef unsigned short                     uint16;
typedef signed short                       sint16;
typedef unsigned int                       uint32;
typedef signed int                         sint32;
typedef unsigned long                      uint64;
typedef signed long                        sint64;



typedef  enum
{
	E_FALSE =0,
	E_TRUE ,
}bool_t;

typedef enum
{
	IN=0,
	OUT,
}DIRECTION;

#endif /* COMMON_H_ */
=======
/*
 * common.h
 *
 *  Created on: Jul 14, 2018
 *      Author: dardeery
 */

#ifndef COMMON_H_
#define COMMON_H_

#define Access_reg(Reg)   (*(volatile uint8*)Reg)

#define Toggle_bit(reg,pin)       (Access_reg(reg) ^=(1<<pin))

#define Clear_bit(reg,pin)        (Access_reg(reg) &=~(1<<pin))

#define Set_bit(reg,pin)          (Access_reg(reg) |=(1<<pin)

#define Bit_is_clear(reg,pin)     (!(Access_reg(reg) & (1<<pin)))

#define Bit_is_set(reg,pin)       (Access_reg(reg) & (1<<pin))

#define NULL (void *) 0



typedef unsigned char                       uint8;
typedef signed char                         sint8;
typedef unsigned short                     uint16;
typedef signed short                       sint16;
typedef unsigned int                       uint32;
typedef signed int                         sint32;
typedef unsigned long                      uint64;
typedef signed long                        sint64;



typedef  enum
{
	E_FALSE =0,
	E_TRUE ,
}bool_t;

typedef enum
{
	IN=0,
	OUT,
}DIRECTION;

#endif /* COMMON_H_ */
>>>>>>> 50770696eabc6891b153c0666b8d9d5b1191c063
