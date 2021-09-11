#ifndef __FACTORY_TEST_H_
#define __FACTORY_TEST_H_

#include "stdint.h"






#define      FAC_TEST_ENTER              	  0xFF02
#define      FAC_TEST_EXIT		          	  0xFF03
#define      FAC_TEST_PID_READ               0x0015//pid检测







void factory_test_handler(uint8_t cmd,uint8_t *para,uint16_t len);











#endif

