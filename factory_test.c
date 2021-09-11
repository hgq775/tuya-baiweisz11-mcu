#include "factory_test.h"
#include "protocol.h"
#include "system.h"


static void fac_test_enter(uint8_t *para,uint16_t len)
{
	uint8_t buf[30]={0};
	const uint8_t true_ret_str[] = "{\"ret\":true}";
	const uint8_t false_ret_str[] = "{\"ret\":false}";

	memcpy(buf,true_ret_str,sizeof(true_ret_str));
	bt_uart_write_factory_test_frame(FAC_TEST_ENTER,buf,strlen(buf));

}


static void fac_test_read_pid(uint8_t *para,uint16_t len)
{
    uint8_t alloc_buf[200]={0};
    uint8_t i = 0;
	if(len == 0)
	{
		alloc_buf[i++] = '{';
	    alloc_buf[i++] = '\"';
	    memcpy(&alloc_buf[i],"ret",3);
	    i += 3;
	    alloc_buf[i++] = '\"';

	    alloc_buf[i++] = ':';
	    memcpy(&alloc_buf[i],"true",4);
	    i += 4;

	    alloc_buf[i++] = ',';
	    alloc_buf[i++] = '\"';
	    memcpy(&alloc_buf[i],"pid",3);
	    i += 3;
	    
	    alloc_buf[i++] = '\"';
	    alloc_buf[i++] = ':';
	    alloc_buf[i++] = '\"';
	    memcpy(&alloc_buf[i],PRODUCT_KEY,8);
	    i += 8;
	    alloc_buf[i++] = '\"';
	    alloc_buf[i++] = '}';
	    bt_uart_write_factory_test_frame(FAC_TEST_PID_READ,alloc_buf,strlen(alloc_buf));
	}
	else
	{
		memcpy(alloc_buf,"{\"ret\":false}",13);
		bt_uart_write_factory_test_frame(FAC_TEST_PID_READ,alloc_buf,strlen(alloc_buf));
	}
}

void factory_test_handler(uint8_t cmd,uint8_t *para,uint16_t len)
{
	uint8_t protocol_type = para[0];
	uint16_t subCmd = ((uint16_t)para[1]<<8)+para[2];
	uint8_t* subPara = &para[3];
	uint16_t sub_len = len - 3;
	if(cmd!=0xf0)
	{
		return;
	}
	
	switch(subCmd)
	{
		case FAC_TEST_ENTER:                 fac_test_enter(subPara,sub_len);            break;
		case FAC_TEST_PID_READ:              fac_test_read_pid(subPara,sub_len);         break;
		default:
			break;
	}
}




