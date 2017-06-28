/******************************************************************************

  Copyright (C), 2011-2012, CDT Co., Ltd.

 ******************************************************************************
  File Name     : Multimeter.h
  Version       : Initial Draft
  Author        : ZhengJH
  Created       : 2015/12/21
  Last Modified :
  Description   : Multimeter.cpp header file
  Function List :
  History       :
  1.Date        : 2015/12/21
    Author      : ZhengJH
    Modification: Created file

******************************************************************************/

/*----------------------------------------------*
 * external variables                           *
 *----------------------------------------------*/

/*----------------------------------------------*
 * external routine prototypes                  *
 *----------------------------------------------*/

/*----------------------------------------------*
 * internal routine prototypes                  *
 *----------------------------------------------*/

/*----------------------------------------------*
 * project-wide global variables                *
 *----------------------------------------------*/

/*----------------------------------------------*
 * module-wide global variables                 *
 *----------------------------------------------*/

/*----------------------------------------------*
 * constants                                    *
 *----------------------------------------------*/

/*----------------------------------------------*
 * macros                                       *
 *----------------------------------------------*/

/*----------------------------------------------*
 * routines' implementations                    *
 *----------------------------------------------*/

#ifndef __MULTIMETER_H__
#define __MULTIMETER_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */

//#define VICTOR
#define CHIPMAST

#if defined (VICTOR)
#define VICTOR86C_NUM_VALID     0
#define VICTOR86C_NUM0_INVALID  1
#define VICTOR86C_NUM1_INVALID  2
#define VICTOR86C_NUM2_INVALID  3
#define VICTOR86C_NUM3_INVALID  4
#define VICTOR86C_NUM_BEYOND    5

#define VICTOR86C_DECIMAL_VALID     0
#define VICTOR86C_DECIMAL_INVALID   1

#define VICTOR86C_VALUE_VALID   0

#define VICTOR86C_SIGN_VALID    0
#define VICTOR86C_SIGN_INVALID  1

#define VICTOR86C_BASE_VALID    0
#define VICTOR86C_BASE_INVALID  1

#define VICTOR86C_UNIT_VALID    0
#define VICTOR86C_UNIT_INVALID  1

#define VICTOR86C_TYPE_VALID    0
#define VICTOR86C_TYPE_INVALID  1

#define VICTOR86C_STUFF_VALID   0
#define VICTOR86C_STUFF_INVALID 1

#define VICTOR86C_DIGIT0_0	0x81
#define VICTOR86C_DIGIT0_1  0x01
#define VICTOR86C_DIGIT0_2	0xC1
#define VICTOR86C_DIGIT0_3	0x41
#define VICTOR86C_DIGIT0_4	0xA1
#define VICTOR86C_DIGIT0_5	0x21
#define VICTOR86C_DIGIT0_6	0xE1
#define VICTOR86C_DIGIT0_7	0x61
#define VICTOR86C_DIGIT0_8	0x91
#define VICTOR86C_DIGIT0_9	0x11
#define VICTOR86C_DIGIT0_BEYOND 0x71

#define VICTOR86C_DIGIT1_0	0x6F
#define VICTOR86C_DIGIT1_1	0xEF
#define VICTOR86C_DIGIT1_2	0xAF
#define VICTOR86C_DIGIT1_3	0x2F
#define VICTOR86C_DIGIT1_4	0x8F
#define VICTOR86C_DIGIT1_5	0x0F
#define VICTOR86C_DIGIT1_6	0xCF
#define VICTOR86C_DIGIT1_7	0x4F
#define VICTOR86C_DIGIT1_8	0x7F
#define VICTOR86C_DIGIT1_9	0xFF
#define VICTOR86C_DIGIT1_BEYOND 0xBF

#define VICTOR86C_DIGIT2_0	0x71
#define VICTOR86C_DIGIT2_1	0xF1
#define VICTOR86C_DIGIT2_2	0xB1
#define VICTOR86C_DIGIT2_3	0x31
#define VICTOR86C_DIGIT2_4	0x91
#define VICTOR86C_DIGIT2_5	0x11
#define VICTOR86C_DIGIT2_6	0xD1
#define VICTOR86C_DIGIT2_7	0x51
#define VICTOR86C_DIGIT2_8	0x81
#define VICTOR86C_DIGIT2_9	0x01

#define VICTOR86C_DIGIT3_0	0x77
#define VICTOR86C_DIGIT3_1	0xF7
#define VICTOR86C_DIGIT3_2	0xB7
#define VICTOR86C_DIGIT3_3	0x37
#define VICTOR86C_DIGIT3_4	0x32
#define VICTOR86C_DIGIT3_5	0x17
#define VICTOR86C_DIGIT3_6	0xD7
#define VICTOR86C_DIGIT3_7	0x57
#define VICTOR86C_DIGIT3_8	0x87
#define VICTOR86C_DIGIT3_9	0x07

#define VICTOR86C_DIGIT3_BEYOND 0x67

#define VICTOR86C_DECIMAL_1     0x84
#define VICTOR86C_DECIMAL_D1    0xA4
#define VICTOR86C_DECIMAL_D01   0xC4
#define VICTOR86C_DECIMAL_D001  0x04

/*#define VICTOR86C_BASE_NANO     0x69*/ //I don't know where is nano field. When measuring capacitance value, base_one equal the base_nano
#define VICTOR86C_BASE_MILLI    0x6B
#define VICTOR86C_BASE_ONE      0x69
#define VICTOR86C_BASE_MICRO    0x6A
#define VICTOR86C_BASE_KILO     0x6D
#define VICTOR86C_BASE_MEGA     0x71
#define VICTOR86C_BASE_BEYOND   0x89

#define VICTOR86C_UNIT_VOLT     0x6A
#define VICTOR86C_UNIT_HERTZ    0x79
#define VICTOR86C_UNIT_PERCENT  0x69
#define VICTOR86C_UNIT_CELCIUS  0xA9
#define VICTOR86C_UNIT_FARENHEIT    0xE9
#define VICTOR86C_UNIT_AMPERE   0x6B
#define VICTOR86C_UNIT_OHM      0x6D
#define VICTOR86C_UNIT_FARAD    0x89

#define VICTOR86C_TYPE_DC       0xF6
#define VICTOR86C_TYPE_AC       0xFE
#define VICTOR86C_TYPE_DCPEAK    0x72 //into dc max/min mode
#define VICTOR86C_TYPE_ACPEAK    0x7A //into ac max/min mode
#define VICTOR86C_TYPE_RESISTANCE 0xEE
#define VICTOR86C_TYPE_DIODE    0x6A
#define VICTOR86C_TYPE_DIODE_TEST 0xEA
#define VICTOR86C_TYPE_DC_RANGE    0xF2 //for dc Manual range
#define VICTOR86C_TYPE_AC_RANGE    0xFA //for ac Manual range
#define VICTOR86C_TYPE_CAP          0x6E

#define VICTOR86C_MODE_MAX      0x68
#define VICTOR86C_MODE_MIN      0x6C
#define VICTOR86C_MODE_AUTO     0x64
#define VICTOR86C_MODE_DIODE    0xA4
#define VICTOR86C_MODE_OTHER    0x84

#define VICTOR86C_SIGN_NEGATIVE 0x23
#define VICTOR86C_SIGN_POSITIVE 0x43

#define VICTOR86C_VENDOR_ID		0x1244//0x2571 //0x1244
#define VICTOR86C_PRODUCT_ID	0xd237//0x4100 //0xd237

#elif defined (CHIPMAST)

#define VICTOR86C_NUM_VALID     0
#define VICTOR86C_NUM0_INVALID  1
#define VICTOR86C_NUM1_INVALID  2
#define VICTOR86C_NUM2_INVALID  3
#define VICTOR86C_NUM3_INVALID  4
#define VICTOR86C_NUM_BEYOND    5

#define VICTOR86C_DECIMAL_VALID     0
#define VICTOR86C_DECIMAL_INVALID   1

#define VICTOR86C_VALUE_VALID   0

#define VICTOR86C_SIGN_VALID    0
#define VICTOR86C_SIGN_INVALID  1

#define VICTOR86C_BASE_VALID    0
#define VICTOR86C_BASE_INVALID  1

#define VICTOR86C_UNIT_VALID    0
#define VICTOR86C_UNIT_INVALID  1

#define VICTOR86C_TYPE_VALID    0
#define VICTOR86C_TYPE_INVALID  1

#define VICTOR86C_STUFF_VALID   0
#define VICTOR86C_STUFF_INVALID 1

#define VICTOR86C_DIGIT0_0	0x00
#define VICTOR86C_DIGIT0_1	0x01
#define VICTOR86C_DIGIT0_2	0x02
#define VICTOR86C_DIGIT0_3	0x03
#define VICTOR86C_DIGIT0_4	0x04
#define VICTOR86C_DIGIT0_5	0x05
#define VICTOR86C_DIGIT0_6	0x06
#define VICTOR86C_DIGIT0_7	0x07
#define VICTOR86C_DIGIT0_8	0x08
#define VICTOR86C_DIGIT0_9	0x09
#define VICTOR86C_DIGIT0_BEYOND 0x0C

#define VICTOR86C_DIGIT1_0	0x00
#define VICTOR86C_DIGIT1_1	0x01
#define VICTOR86C_DIGIT1_2	0x02
#define VICTOR86C_DIGIT1_3	0x03
#define VICTOR86C_DIGIT1_4	0x04
#define VICTOR86C_DIGIT1_5	0x05
#define VICTOR86C_DIGIT1_6	0x06
#define VICTOR86C_DIGIT1_7	0x07
#define VICTOR86C_DIGIT1_8	0x08
#define VICTOR86C_DIGIT1_9	0x09

#define VICTOR86C_DIGIT2_0	0x00
#define VICTOR86C_DIGIT2_1	0x01
#define VICTOR86C_DIGIT2_2	0x02
#define VICTOR86C_DIGIT2_3	0x03
#define VICTOR86C_DIGIT2_4	0x04
#define VICTOR86C_DIGIT2_5	0x05
#define VICTOR86C_DIGIT2_6	0x06
#define VICTOR86C_DIGIT2_7	0x07
#define VICTOR86C_DIGIT2_8	0x08
#define VICTOR86C_DIGIT2_9	0x09
#define VICTOR86C_DIGIT2_BEYOND 0x0F

#define VICTOR86C_DIGIT3_0	0x00
#define VICTOR86C_DIGIT3_1	0x01
#define VICTOR86C_DIGIT3_2	0x02
#define VICTOR86C_DIGIT3_3	0x03
#define VICTOR86C_DIGIT3_4	0x04
#define VICTOR86C_DIGIT3_5	0x05
#define VICTOR86C_DIGIT3_6	0x06
#define VICTOR86C_DIGIT3_7	0x07
#define VICTOR86C_DIGIT3_8	0x08
#define VICTOR86C_DIGIT3_9	0x09


#define VICTOR86C_DECIMAL_1     0x00
#define VICTOR86C_DECIMAL_D1    0x04
#define VICTOR86C_DECIMAL_D01   0x02
#define VICTOR86C_DECIMAL_D001  0x01

#define VICTOR86C_BASE_NANO     0x0200
#define VICTOR86C_BASE_MILLI    0x0040
#define VICTOR86C_BASE_ONE      0x0000
#define VICTOR86C_BASE_MICRO    0x0080
#define VICTOR86C_BASE_KILO     0x0020
#define VICTOR86C_BASE_MEGA     0x0010
#define VICTOR86C_BASE_BEYOND   0x0004 // or 0x0008 [0x0004 lower 0x0008 upper]

#define VICTOR86C_UNIT_VOLT     0x80
#define VICTOR86C_UNIT_HERTZ    0x08
#define VICTOR86C_UNIT_PERCENT  0x00
#define VICTOR86C_UNIT_CELCIUS  0x02
#define VICTOR86C_UNIT_FARENHEIT    0x01
#define VICTOR86C_UNIT_AMPERE   0x40
#define VICTOR86C_UNIT_OHM      0x20
#define VICTOR86C_UNIT_FARAD    0x04

/*
BYTE[3] 
b7  b6  b5  b4  b3  b2  b1  b0
--  --  --  --  --  --  --  --
        AUT DC  AC  REL HOL BAR
*/
#define VICTOR86C_TYPE_DC       0x31
#define VICTOR86C_TYPE_AC       0x29
#define VICTOR86C_TYPE_DCPEAK    0x10 //into dc max/min mode
#define VICTOR86C_TYPE_ACPEAK    0x08 //into ac max/min mode
#define VICTOR86C_TYPE_RESISTANCE 0x21
#define VICTOR86C_TYPE_DIODE    0x00
#define VICTOR86C_TYPE_DIODE_TEST 0x01
#define VICTOR86C_TYPE_DC_RANGE    0x11 //for dc Manual range
#define VICTOR86C_TYPE_AC_RANGE    0x09 //for ac Manual range
#define VICTOR86C_TYPE_CAP      0x20

#define VICTOR86C_MODE_MAX      0x02
#define VICTOR86C_MODE_MIN      0x01
#define VICTOR86C_MODE_AUTO     0x00
#define VICTOR86C_MODE_DIODE    0xFE //fake In order to compile
#define VICTOR86C_MODE_OTHER    0xFF

#define VICTOR86C_SIGN_NEGATIVE 0x0D
#define VICTOR86C_SIGN_POSITIVE 0x0B

#define VICTOR86C_VENDOR_ID		0x2571 //0x1244
#define VICTOR86C_PRODUCT_ID	    0x4100 //0xd237
#endif

extern unsigned int victor86c_get_base(unsigned char *buf, unsigned int * base);
extern unsigned int victor86c_get_decimal(unsigned char *buf, double * decimal);
extern unsigned int victor86c_get_num(unsigned char *buf, unsigned int * num);
extern unsigned int victor86c_get_sign(unsigned char *buf, int *sign);
extern unsigned int victor86c_get_stuff(unsigned char *buf, unsigned int *stuff);
extern unsigned int victor86c_get_type(unsigned char *buf, unsigned int *type);
extern unsigned int victor86c_get_unit(unsigned char *buf, unsigned int * unit);
extern unsigned int victor86c_get_value(unsigned char *buf, double * value);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __MULTIMETER_H__ */

