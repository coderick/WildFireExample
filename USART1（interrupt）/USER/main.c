/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * 文件名  ：main.c
 * 描述    ：通过电脑的超级终端向单片机发送数据，单片机将接收到的数据发回电脑，
 *         ：并显示在超级终端上。用的是串口1的中断方式。         
 * 实验平台：野火STM32开发板
 * 库版本  ：ST3.5.0
 *
 * 作者    ：wildfire team 
 * 论坛    ：http://www.amobbs.com/forum-1008-1.html
 * 淘宝    ：http://firestm32.taobao.com
*********************************************************************************/
#include "stm32f10x.h"
#include "usart1.h"

/*
 * 函数名：main
 * 描述  ：主函数
 * 输入  ：无
 * 输出  ：无
 */
int main(void)
{	
	/* USART1 config 115200 8-N-1 */
	USART1_Config();
	NVIC_Configuration();

	printf("\r\n this is a USART Interrupt demo \r\n");

	printf("\r\n***************串口实验--接受中断实验****************\r\n");
	printf("\r\n描述:使用超级终端来测试比较好,在超级终端敲入一系列字符，\r\n 单片机接收到自己之后直接将接收到的字符按原样打印出来\r\n");
	printf("\r\n请开始输入字符串:\r\n");

	for(;;)
	{
		
	}
}
/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
