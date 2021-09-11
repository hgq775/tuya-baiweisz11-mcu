
This MCU_SDK is the MCU code automatically generated according to the product functions defined on the Tuya 
development platform. Modifications and supplements on this basis can quickly complete the MCU program.


Development steps:

1: Need to configure according to the actual situation of the product (reset the bluetooth button and bluetooth 
status indicator processing method, whether to support MCU upgrade, etc.), please modify this configuration in protocol.h;

2: To transplant this MCU_SDK, please check the transplantation steps in the protocol.c file, and complete the transplantation correctly. 
After transplantation, please complete the code of the data delivery processing and data reporting part to complete all bluetooth functions.


File overview:
This MCU_SDK includes nine files:
(1) protocol.h and protocol.c need to be modified by you.The protocol.h and protocol.c files contain detailed 
instructions for modification. Please read them carefully. 
(2) bluetooth.h file is the total header file, if you need to call bluetooth internal functions, please #include "bluetooth.h". 
(3) system.c and system.h are bluetooth function implementation codes without user modification. 
(4) All the functions that users need to call are implemented in mcu_api.c and mcu_api.h, and users do not need to 
modify them.	
(5) mcu_ota_handler.h and mcu_ota_handler.c is an OTA-related implementation example.You need to modify. Ota is closely related to the
chip and requires users to debug and modify according to their own chip platform. These two documents are for reference only.


此MCU_SDK是根据Tuya上定义的产品功能自动生成的MCU代码

开发平台。在此基础上进行修改和补充，可以快速完成单片机程序。

发展步骤：

1：需要根据产品的实际情况进行配置（重置蓝牙按钮和蓝牙

状态指示器处理方法、是否支持MCU升级等），请在协议h中修改此配置；

2：要移植此MCU_SDK，请检查protocol.c文件中的移植步骤，并正确完成移植。

移植后，请完成数据传递处理和数据报告部分的代码，以完成所有蓝牙功能。

文件概述：

此MCU_SDK包含九个文件：

（1） protocol.h和protocol.c需要您修改。protocol.h和protocol.c文件包含详细的

修改说明。请仔细阅读。

（2） bluetooth.h文件是总头文件，如果您需要调用bluetooth内部功能，请包含“bluetooth.h”。

（3） system.c和system.h是无需用户修改的蓝牙功能实现代码。

（4） 用户需要调用的所有函数都在mcu_api.c和mcu_api.h中实现，用户无需

修改它们。

（5） mcu_ota_handler.h和mcu_ota_handler.c是一个与ota相关的实现示例。您需要修改。Ota与网络有着密切的关系

并要求用户根据自己的芯片平台进行调试和修改。这两份文件仅供参考。