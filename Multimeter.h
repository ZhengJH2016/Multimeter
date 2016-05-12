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

extern int _tmain(int argc, _TCHAR* argv[]);
extern void victor86c_decode(unsigned char *buf, char *str);
extern unsigned int victor86c_get_base(unsigned char *buf, unsigned char * base);
extern unsigned int victor86c_get_decimal(unsigned char *buf, double * decimal);
extern unsigned int victor86c_get_num(unsigned char *buf, unsigned int * num);
extern unsigned int victor86c_get_sign(unsigned char *buf, int *sign);
extern unsigned int victor86c_get_stuff(unsigned char *buf, unsigned int *stuff);
extern unsigned int victor86c_get_type(unsigned char *buf, unsigned int *type);
extern unsigned int victor86c_get_unit(unsigned char *buf, unsigned int * unit);
extern unsigned int victor86c_get_unit_sign(unsigned int val, unsigned char ** sign);
extern unsigned int victor86c_get_value(unsigned char *buf, double * value);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __MULTIMETER_H__ */
