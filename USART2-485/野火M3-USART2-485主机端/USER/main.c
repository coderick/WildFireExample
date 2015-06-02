/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * 文件名  ：main.c
 * 描述    ：串口USART2向电脑的超级终端发送信息。       
 * 实验平台：野火STM32开发板
 * 库版本  ：ST3.5.0
 *
 * 作者    ：wildfire team 
 * 论坛    ：www.ourdev.cn/bbs/bbs_list.jsp?bbs_id=1008
 * 淘宝    ：http://firestm32.taobao.com
**********************************************************************************/
#include "stm32f10x.h"
#include "usart2.h"
#include "usart1.h"

/*
 * 函数名：main
 * 描述  ：主函数
 * 输入  ：无
 * 输出  ：无
 本工程为主机，实验时先给从机上电
 */
int main(void)
{	

	uint8_t temp = 0;

	/* USART2 config */
	USART2_Config();  //串口2用于收发485的数据
	USART1_Config();  //串口1用于输出调试信息


  while(1){

			 GPIO_SetBits(GPIOA,GPIO_Pin_0); //进入发送模式
			 USART_SendData(USART2, temp);	 //发送数据
  			while (USART_GetFlagStatus(USART2,USART_FLAG_TC) !=SET);//轮询直到发送数据完毕	
			printf("发送数据成功！\r\n"); //使用串口1打印调试信息到终端

			GPIO_ResetBits(GPIOA,GPIO_Pin_0);	//进入接收模式
  			while(	USART_GetFlagStatus(USART2,USART_FLAG_RXNE)!= SET); //轮询直到485接收到数据
			
			  temp = USART_ReceiveData(USART2);
			   	printf("接收到的数据为%d \r\n",temp);
			 
			
   }

}


/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
