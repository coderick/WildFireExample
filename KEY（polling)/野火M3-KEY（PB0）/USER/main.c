/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * 文件名  ：main.c
 * 描述    ：PB0连接到key1，PB0配置为线中断模式，key1按下时，进入线中断处理函数，
 *           LED1状态取反。         
 * 实验平台：野火STM32开发板
 * 库版本  ：ST3.5.0
 *
 * 作者    ：wildfire team 
 * 论坛    ：http://www.amobbs.com/forum-1008-1.html
 * 淘宝    ：http://firestm32.taobao.com
**********************************************************************************/

#include "stm32f10x.h"
#include "led.h"
#include "key.h"  

/**
  * @brief  Main program.
  * @param  None
  * @retval : None
  */
int main(void)
{ 
	/* config the sysclock to 72m */      
  SystemInit();

	/* config the led */
  LED_GPIO_Config();
	LED1( ON );
	/*config key*/
	Key_GPIO_Config();


  while(1)                            
  {	   
 	if( Key_Scan(GPIOB,GPIO_Pin_0) == KEY_ON  )
	{
			/*LED1反转*/
		   	GPIO_WriteBit(GPIOC, GPIO_Pin_3, 
		             (BitAction)((1-GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_3))));
	}   
  }
}

/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE****/
