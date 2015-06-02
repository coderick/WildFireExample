/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * 文件名  ：main.c
 * 描述    ：串口USART2向电脑的超级终端发送信息。       
 * 实验平台：野火STM32开发板
 * 库版本  ：ST3.5.0
 *
 * 作者    ：wildfire team 
 * 论坛    ：http://www.amobbs.com/forum-1008-1.html
 * 淘宝    ：http://firestm32.taobao.com
**********************************************************************************/
#include "stm32f10x.h"
#include "usart2.h"

/*
 * 函数名：main
 * 描述  ：主函数
 * 输入  ：无
 * 输出  ：无
 */
int main(void)
{	
	uint8_t i;
	
	/* USART2 config */
	USART2_Config();

	USART2_printf(USART2, "\r\n This is a USART2_printf demo \r\n");
	USART2_printf(USART2, "\r\n 欢迎使用野火M3实验板 \r\n");
	for ( i=0; i<8; i++ )
		USART2_printf( USART2, "\r\n %d \r\n", i );
}


/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
