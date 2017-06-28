/******************************************************************************

  Copyright (C), 2011-2012, CDT Co., Ltd.

 ******************************************************************************
  File Name     : victor86c.cpp
  Version       : Initial Draft
  Author        : ZhengJH
  Created       : 2015/12/21
  Last Modified :
  Description   : vc86c decoder
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
 
#include "stdafx.h"
#include "Victor86c.h" 

unsigned int victor86c_get_num(unsigned char *buf, unsigned int * num)
{
	int digit[4] = { 0, 0, 0, 0 };
#if defined(VICTOR)	
	switch (buf[6]) {
#elif defined(CHIPMAST)
	switch (buf[2]&0x0F) {
#endif
	case VICTOR86C_DIGIT0_0:
		digit[0] = 0;
		break;
	case VICTOR86C_DIGIT0_1:
		digit[0] = 1;
		break;
	case VICTOR86C_DIGIT0_2:
		digit[0] = 2;
		break;
	case VICTOR86C_DIGIT0_3:
		digit[0] = 3;
		break;
	case VICTOR86C_DIGIT0_4:
		digit[0] = 4;
		break;
	case VICTOR86C_DIGIT0_5:
		digit[0] = 5;
		break;
	case VICTOR86C_DIGIT0_6:
		digit[0] = 6;
		break;
	case VICTOR86C_DIGIT0_7:
		digit[0] = 7;
		break;
	case VICTOR86C_DIGIT0_8:
		digit[0] = 8;
		break;
	case VICTOR86C_DIGIT0_9:
		digit[0] = 9;
		break;
#if defined(VICTOR)    
    case VICTOR86C_DIGIT0_BEYOND:
        digit[0] = VICTOR86C_DIGIT0_BEYOND;
        break;
#elif defined(CHIPMAST)
    case VICTOR86C_DIGIT0_BEYOND:
        digit[0] = VICTOR86C_DIGIT0_BEYOND;
        break;
#endif
	default:
		return VICTOR86C_NUM0_INVALID;
	}
#if defined(VICTOR)	
	switch (buf[9]) {
#elif defined(CHIPMAST)
	switch ((buf[2] >> 4) &0x0F) {
#endif
	case VICTOR86C_DIGIT1_0:
		digit[1] = 0;
		break;
	case VICTOR86C_DIGIT1_1:
		digit[1] = 1;
		break;
	case VICTOR86C_DIGIT1_2:
		digit[1] = 2;
		break;
	case VICTOR86C_DIGIT1_3:
		digit[1] = 3;
		break;
	case VICTOR86C_DIGIT1_4:
		digit[1] = 4;
		break;
	case VICTOR86C_DIGIT1_5:
		digit[1] = 5;
		break;
	case VICTOR86C_DIGIT1_6:
		digit[1] = 6;
		break;
	case VICTOR86C_DIGIT1_7:
		digit[1] = 7;
		break;
	case VICTOR86C_DIGIT1_8:
		digit[1] = 8;
		break;
	case VICTOR86C_DIGIT1_9:
		digit[1] = 9;
		break;
    #if defined(VICTOR)
    case VICTOR86C_DIGIT1_BEYOND:
        return VICTOR86C_NUM_BEYOND;
    #endif
	default:
		return VICTOR86C_NUM1_INVALID;
	}
#if defined(VICTOR)
	switch (buf[3]) {
#elif defined(CHIPMAST)
	switch (buf[1] & 0x0F) {
#endif        
	case VICTOR86C_DIGIT2_0:
		digit[2] = 0;
		break;
	case VICTOR86C_DIGIT2_1:
		digit[2] = 1;
		break;
	case VICTOR86C_DIGIT2_2:
		digit[2] = 2;
		break;
	case VICTOR86C_DIGIT2_3:
		digit[2] = 3;
		break;
	case VICTOR86C_DIGIT2_4:
		digit[2] = 4;
		break;
	case VICTOR86C_DIGIT2_5:
		digit[2] = 5;
		break;
	case VICTOR86C_DIGIT2_6:
		digit[2] = 6;
		break;
	case VICTOR86C_DIGIT2_7:
		digit[2] = 7;
		break;
	case VICTOR86C_DIGIT2_8:
		digit[2] = 8;
		break;
	case VICTOR86C_DIGIT2_9:
		digit[2] = 9;
		break;
#if defined(CHIPMAST)
    case VICTOR86C_DIGIT2_BEYOND:
        digit[2] = VICTOR86C_DIGIT2_BEYOND;
        break;
#endif        
	default:
		return VICTOR86C_NUM2_INVALID;
	}
#if defined(VICTOR)
	switch (buf[10]) {
#elif defined(CHIPMAST)
	switch ((buf[1] >> 4) &0x0F) {
#endif        
	case VICTOR86C_DIGIT3_0:
		digit[3] = 0;
		break;
	case VICTOR86C_DIGIT3_1:
		digit[3] = 1;
		break;
	case VICTOR86C_DIGIT3_2:
		digit[3] = 2;
		break;
	case VICTOR86C_DIGIT3_3:
        digit[3] = 3;
        break;
	case VICTOR86C_DIGIT3_4:
        digit[3] = 4;
        break;
	case VICTOR86C_DIGIT3_5:
        digit[3] = 5;
        break;
	case VICTOR86C_DIGIT3_6:
        digit[3] = 6;
        break;
	case VICTOR86C_DIGIT3_7:
        digit[3] = 7;
        break;
	case VICTOR86C_DIGIT3_8:
        digit[3] = 8;
        break;
	case VICTOR86C_DIGIT3_9:
        digit[3] = 9;
        break;  
        #if defined(VICTOR)
    case VICTOR86C_DIGIT3_BEYOND:
        digit[2] = VICTOR86C_DIGIT3_BEYOND;
        break;        
        #endif
	default:
		return VICTOR86C_NUM3_INVALID;
	}
#if defined(CHIPMAST)
    if((VICTOR86C_DIGIT0_BEYOND == digit[0])||(VICTOR86C_DIGIT2_BEYOND == digit[2]))
        return VICTOR86C_NUM_BEYOND;
#endif
    *num = digit[3]*1000 + digit[2]*100 + digit[1]*10 + digit[0];
	return VICTOR86C_NUM_VALID;
}

unsigned int victor86c_get_decimal(unsigned char *buf, double * decimal)
{
#if defined(VICTOR)
    switch ( buf[5] )
#elif defined(CHIPMAST)
    switch ( buf[0] & 0x0F )
#endif
    {
        case VICTOR86C_DECIMAL_1 :
            *decimal = 1;
            break;
        case VICTOR86C_DECIMAL_D1:
            *decimal = 0.1;
            break;
        case VICTOR86C_DECIMAL_D01 :
            *decimal = 0.01;
            break;
        case VICTOR86C_DECIMAL_D001:
            *decimal = 0.001;
            break;
        default:
            return VICTOR86C_DECIMAL_INVALID;
    }
    
    return VICTOR86C_DECIMAL_VALID;
}

unsigned int victor86c_get_sign(unsigned char *buf, int *sign)
{
#if defined(VICTOR)    
    switch ( buf[1] )
#elif defined(CHIPMAST)
    switch ((buf[0] >> 4) & 0x0F)
#endif
    {
        case VICTOR86C_SIGN_NEGATIVE:
            *sign = -1;
            break;
        case VICTOR86C_SIGN_POSITIVE:
            *sign = 1;
            break;
        default:
            return VICTOR86C_SIGN_INVALID;
    }
    return VICTOR86C_SIGN_VALID;
}

unsigned int victor86c_get_value(unsigned char *buf, double * value)
{
    unsigned int num;
    double decimal;
    int sign;
    unsigned int err;
    if(err = victor86c_get_num(buf, &num))
    {
        if(VICTOR86C_NUM_BEYOND == err)
            printf("NUM BEYOND!\n");
        else
            printf("Invalid digit = 0x%x\n", err);
        return err;
    }

    if(err = victor86c_get_decimal(buf, &decimal))
    {
        printf("Invalid decimal\n");
        return err;
    }

    if(err = victor86c_get_sign(buf, &sign))
    {
        printf("Invalid sign\n");
        return err;
    }
    *value = sign * num * decimal;
    return VICTOR86C_VALUE_VALID;
}

unsigned int victor86c_get_base(unsigned char *buf, unsigned int * base)
{
#if defined(VICTOR)
    *base = buf[12];
#elif defined(CHIPMAST)  
    *base = buf[4];
    *base = (*base << 8) & 0xFF00;
    *base = *base | buf[5];
#endif
    switch ( *base )
    {
        case VICTOR86C_BASE_MILLI:
        case VICTOR86C_BASE_ONE:
        case VICTOR86C_BASE_MICRO:
        case VICTOR86C_BASE_KILO:
        case VICTOR86C_BASE_MEGA:
        case VICTOR86C_BASE_BEYOND:  
        #if defined(CHIPMAST)    
        case VICTOR86C_BASE_NANO:
        #endif    
            return VICTOR86C_BASE_VALID;
        default:
            return VICTOR86C_BASE_INVALID;
    }
}

unsigned int victor86c_get_unit(unsigned char *buf, unsigned int * unit)
{
#if defined(VICTOR)    
    *unit = buf[8];
#elif defined(CHIPMAST)   
    *unit = buf[6];
#endif
    switch ( *unit )
    {
        case VICTOR86C_UNIT_VOLT:
        case VICTOR86C_UNIT_HERTZ:
        case VICTOR86C_UNIT_PERCENT:
        case VICTOR86C_UNIT_CELCIUS:
        case VICTOR86C_UNIT_FARENHEIT:
        case VICTOR86C_UNIT_AMPERE:
        case VICTOR86C_UNIT_OHM:
        case VICTOR86C_UNIT_FARAD:
            return VICTOR86C_UNIT_VALID;
        default:
            return VICTOR86C_UNIT_INVALID;
    }     
}

unsigned int victor86c_get_type(unsigned char *buf, unsigned int *type)
{
#if defined(VICTOR)    
    *type = buf[0];
#elif defined(CHIPMAST)
    *type = buf[3];
#endif
    switch ( *type )
    {
        case VICTOR86C_TYPE_DC:
        case VICTOR86C_TYPE_AC :
        case VICTOR86C_TYPE_DCPEAK:
        case VICTOR86C_TYPE_ACPEAK:
        case VICTOR86C_TYPE_RESISTANCE:
        case VICTOR86C_TYPE_DIODE:
        case VICTOR86C_TYPE_DIODE_TEST:    
        case VICTOR86C_TYPE_DC_RANGE: 
        case VICTOR86C_TYPE_AC_RANGE: 
        case VICTOR86C_TYPE_CAP:
            return VICTOR86C_TYPE_VALID;
        default:
            return VICTOR86C_TYPE_INVALID;
    }
}

unsigned int victor86c_get_stuff(unsigned char *buf, unsigned int *stuff)
{
#if defined(VICTOR)
    *stuff = buf[2];
#elif defined(CHIPMAST)
    *stuff = (buf[4] >> 4) & 0x0F;
#endif
    switch ( *stuff )
    {
        case VICTOR86C_MODE_MAX:
        case VICTOR86C_MODE_MIN :
        case VICTOR86C_MODE_AUTO:
        case VICTOR86C_MODE_DIODE: 
        case VICTOR86C_MODE_OTHER:            
            return VICTOR86C_STUFF_VALID;
        default:
            return VICTOR86C_STUFF_INVALID;
    }
}
