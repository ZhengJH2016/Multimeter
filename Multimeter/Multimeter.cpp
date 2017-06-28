/******************************************************************************

  Copyright (C), 2015-2016, CDT Co., Ltd.

 ******************************************************************************
  File Name     : Multimeter.cpp
  Version       : Initial Draft
  Author        : ZhengJH
  Created       : 2015/12/18
  Last Modified :
  Description   : Get Multimeter's Hid Data
  Function List :
              _tmain
  History       :
  1.Date        : 2015/12/18
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

// Multimeter.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "hidapi.h"
#include <string.h>
#include "Victor86c.h" 

#define IN
#define OUT

unsigned int victor86c_get_base_sign(unsigned int val, char ** sign)
{
    static char base[2] ={0};
    switch ( val )
    {
        case  VICTOR86C_BASE_MILLI:
            base[0] = 'm';
            break;
        case VICTOR86C_BASE_ONE:
            base[0] = ' ';
            break;
        case VICTOR86C_BASE_MICRO:
            base[0] = 'u';
            break;
        case VICTOR86C_BASE_KILO:
            base[0] = 'K';
            break;
        case VICTOR86C_BASE_MEGA:
            base[0] = 'M';
            break;
        case VICTOR86C_BASE_BEYOND:
            base[0] = 'L';
            break;
        #if defined(CHIPMAST)    
        case VICTOR86C_BASE_NANO:
            base[0] = 'n';
            break;
        #endif    
        default:
            return VICTOR86C_BASE_INVALID;
    }
    *sign = base;
    return VICTOR86C_BASE_VALID;
}

unsigned int victor86c_get_unit_sign(unsigned int val, char ** sign)
{
    static char unit[3] = {0};
    switch ( val )
    {
        case  VICTOR86C_UNIT_VOLT:
            unit[0] = 'V';
            unit[1] = '\0';
            break;
        case VICTOR86C_UNIT_HERTZ:
            unit[0] = 'H';
            unit[1] = 'z';
            break;
        case VICTOR86C_UNIT_PERCENT:
            unit[0] = '%';
            unit[1] = '\0';
            break;
        case VICTOR86C_UNIT_CELCIUS:
            unit[0] = 167;
            unit[1] = 'C';
            break;
        case VICTOR86C_UNIT_FARENHEIT:
            unit[0] = 167;
            unit[1] = 'F';
            break;
        case VICTOR86C_UNIT_AMPERE:
            unit[0] = 'A';
            unit[1] = '\0';
            break;
        case VICTOR86C_UNIT_OHM:
            unit[0] = 234;
            unit[1] = '\0';
            break;
        case VICTOR86C_UNIT_FARAD:
            unit[0] = 'F';
            unit[1] = '\0';
            break;
        default:
            return VICTOR86C_UNIT_INVALID;
    }
    *sign = unit;
    return VICTOR86C_UNIT_VALID;
}

unsigned int victor86c_get_type_sign(unsigned int val, char ** sign)
{
    static char type[3] = {0};
    switch ( val )
    {
        case VICTOR86C_TYPE_DC:
        case VICTOR86C_TYPE_DC_RANGE:    
            type[0] = 'D';
            type[1] = 'C';
            break;
        case VICTOR86C_TYPE_AC :
        case VICTOR86C_TYPE_AC_RANGE:  
            type[0] = 'A';
            type[1] = 'C';
            break;            
        case VICTOR86C_TYPE_DCPEAK:
            type[0] = 'D';
            type[1] = 'P';
            break;            
        case VICTOR86C_TYPE_ACPEAK:
            type[0] = 'A';
            type[1] = 'P';
            break;            
        case VICTOR86C_TYPE_RESISTANCE:
            type[0] = 'R';
            type[1] = 'T';
            break;            
        case VICTOR86C_TYPE_DIODE:
        case VICTOR86C_TYPE_DIODE_TEST:
            type[0] = 'D';
            type[1] = 'I';
            break;  
        case VICTOR86C_TYPE_CAP:
            type[0] = 'C';
            type[1] = 'A';
			break;
        default:
            return VICTOR86C_TYPE_INVALID;
    }    
    *sign = type;
    return VICTOR86C_TYPE_VALID;
}

unsigned int victor86c_get_stuff_sign(unsigned int val, char ** sign)
{
    static char stuff[5] = {0};
    switch ( val )
    {
        case VICTOR86C_MODE_MAX:
            stuff[0] = 'M';
            stuff[1] = 'A';
            stuff[2] = 'X';
            stuff[3] = '\0';
            break;
        case VICTOR86C_MODE_MIN :
            stuff[0] = 'M';
            stuff[1] = 'I';
            stuff[2] = 'N';
            stuff[3] = '\0';
            break;            
        case VICTOR86C_MODE_AUTO:
        case VICTOR86C_MODE_DIODE:
        case VICTOR86C_MODE_OTHER:
            stuff[0] = 'A';
            stuff[1] = 'U';
            stuff[2] = 'T';
            stuff[3] = 'O';            
            break;
        default:
            return VICTOR86C_STUFF_INVALID;
    }
    *sign = stuff;
    return VICTOR86C_STUFF_VALID;
}

#define VICTOR86C_ACQ_DEV_NO_ERR 0x00
#define VICTOR86C_ACQ_DEV_PARAM_ERR 0x01
#define VICTOR86C_ACQ_DEV_N0DEV_ERR 0x02
unsigned int victor86c_acquire_dev(IN unsigned int sequence, OUT struct hid_device_info **devs, OUT struct hid_device_info **dev)
{
    struct hid_device_info *cur_devs, *cur_dev;
	cur_devs = hid_enumerate(0x0, 0x0);
    if(NULL == cur_devs)
    {
        return VICTOR86C_ACQ_DEV_N0DEV_ERR;
    }
    cur_dev = cur_devs;	
    for(unsigned int i = 0; i <= sequence; i++)
	{
        if(NULL == cur_dev)
        {
            return VICTOR86C_ACQ_DEV_PARAM_ERR; //sequence is too much
        }
        if(i < sequence)
		    cur_dev = cur_dev->next;
	}
    
    *devs = cur_devs;
    *dev = cur_dev;
    return VICTOR86C_ACQ_DEV_NO_ERR;
}

void victor86c_release_dev(struct hid_device_info *devs)
{
    hid_free_enumeration(devs);
}
    
#define MAX_STR 255
int _tmain(int argc, _TCHAR* argv[])
{
	int res;
	unsigned char buf[256] = {0};
	hid_device *handle1;
    hid_device *handle2;
	//int option_index = 0;
	//wchar_t wstr[MAX_STR];
    double val;
    unsigned int unit;
    unsigned int base;
    unsigned int type;
    unsigned int stuff;
    unsigned int err;
    char * temp;
    char str[256] = {0};
    char num[5] = {0};
    //test
    //system("chcp 437");

	// Enumerate and print the HID devices on the system
	struct hid_device_info *devs, *cur_dev;
	
	devs = hid_enumerate(0x0, 0x0);
	cur_dev = devs;	
	while (cur_dev) {
		printf("Device Found\n  type: %04hx %04hx\n  path: [%s]\n  serial_number: %ls",
			cur_dev->vendor_id, cur_dev->product_id, cur_dev->path, cur_dev->serial_number);
		printf("\n");
		printf("  Manufacturer: %ls\n", cur_dev->manufacturer_string);
		printf("  Product:      %ls\n", cur_dev->product_string);
		printf("\n");
		cur_dev = cur_dev->next;
	}
	hid_free_enumeration(devs);
    
	//handle1 = hid_open(VICTOR86C_VENDOR_ID, VICTOR86C_PRODUCT_ID, 0);
	#if 1
    err = victor86c_acquire_dev(0, &devs, &cur_dev);
    if(err)
    {
        if(VICTOR86C_ACQ_DEV_PARAM_ERR == err)
            printf("victor86c_acquire_dev err = Not so many devs\n");
        else if(VICTOR86C_ACQ_DEV_N0DEV_ERR == err)
            printf("victor86c_acquire_dev err = Don't have any dev\n");
        return 1;
    }
	handle1 = hid_open_path(cur_dev->path);
	if (handle1) {
    /**********Just for test!!***************
    	// Read the Manufacturer String
    	wstr[0] = 0x0000;
    	res = hid_get_manufacturer_string(handle1, wstr, MAX_STR);
    	if (res < 0)
    		printf("Unable to read manufacturer string\n");
    	printf("Manufacturer String: %ls\n", wstr);
        //Sleep(4000);
    ***************************************/
        for(int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 256; j++)
                str[j] = '\0';
            res = hid_read(handle1, buf, sizeof(buf));
            if (res <= 0 || buf[0] == 0)
    			continue;
    		printf("%d \tres = %d : \n", i, res);
        	for (int j = 0; j < res; j++)
        		printf("%02hhx ", buf[j]);
        	printf("\n");
            if(err = victor86c_get_value(buf, &val)) //数值
            {
                printf("Invalid value\n");
                continue;
            }
            if(err = victor86c_get_base(buf, &base)) //单位
            {
                printf("Invalid base\n");
                continue;
            }
            if(err = victor86c_get_unit(buf, &unit)) //测试类型
            {
                printf("Invalid unit\n");
                continue;
            }  
            if(err = victor86c_get_type(buf, &type)) //交直流
            {
                printf("Invalid type\n");
                continue;
            }   
            if(err = victor86c_get_stuff(buf, &stuff)) //测试限制
            {
                printf("Invalid stuff");
                continue;
            }
            victor86c_get_type_sign(type, &temp);
            strcat(str, temp);
            sprintf(num," %f", val);
            strcat(str, num);
            victor86c_get_base_sign(base, &temp);
            strcat(str, temp);
            victor86c_get_unit_sign(unit, &temp);
            strcat(str, temp);
            strcat(str, "\t");
            victor86c_get_stuff_sign(stuff, &temp);
            strcat(str, temp);
            printf("%s \n", str);
        }
    	hid_close(handle1);
	}
    else {
		printf("unable to open device\n");
	}
    victor86c_release_dev(devs);    
    #endif


    err = victor86c_acquire_dev(1, &devs, &cur_dev);
    if(err)
    {
        if(1 == err)
            printf("victor86c_acquire_dev err = Not so many devs\n");
        else if(2 == err)
            printf("victor86c_acquire_dev err = Don't have dev\n");
        return 1;
    }
	handle2 = hid_open_path(cur_dev->path);
	if (!handle2) {
		printf("unable to open device\n");
 		return 1;
	}
    victor86c_release_dev(devs);
    for(int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 256; j++)
            str[j] = '\0';
        res = hid_read(handle2, buf, sizeof(buf));
        if (res <= 0 || buf[0] == 0) //The data is invalid when buf[0] equal 0.
			continue;
		printf("%d \tres = %d : \n", i, res);
    	for (int j = 0; j < res; j++)
    		printf("%02hhx ", buf[j]);
    	printf("\n");
        if(err = victor86c_get_value(buf, &val)) //数值
        {
            printf("Invalid value");
            continue;
        }
        if(err = victor86c_get_base(buf, &base)) //单位
        {
            printf("Invalid base");
            continue;
        }
        if(err = victor86c_get_unit(buf, &unit)) //测试类型
        {
            printf("Invalid unit");
            continue;
        }  
        if(err = victor86c_get_type(buf, &type)) //交直流
        {
            printf("Invalid type");
            continue;
        }   
        if(err = victor86c_get_stuff(buf, &stuff)) //测试限制
        {
            printf("Invalid stuff");
            continue;
        }
        victor86c_get_type_sign(type, &temp);
        strcat(str, temp);
        sprintf(num," %f", val);
        strcat(str, num);
        victor86c_get_base_sign(base, &temp);
        strcat(str, temp);
        victor86c_get_unit_sign(unit, &temp);
        strcat(str, temp);
        strcat(str, "\t");
        victor86c_get_stuff_sign(stuff, &temp);
        strcat(str, temp);
        printf("%s \n", str);
    }
	hid_close(handle2);
    
	hid_exit();
    //system("chcp 936");
	return 0;
}

