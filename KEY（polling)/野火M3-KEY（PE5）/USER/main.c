/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * 文件名  ：main.c
 * 描述    ：按键测试函数，按键为扫描模式        
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

/*
 * 函数名：main
 * 描述  ：主函数
 * 输入  ：无
 * 输出  ：无
 */
int main(void)
{	
	/* config the led */
	LED_GPIO_Config();
	LED1( ON );

	/*config key*/
	Key_GPIO_Config();	
	
	while(1)                            
	{	   
		if( Key_Scan(GPIOE,GPIO_Pin_5) == KEY_ON  )
		{
			/*LED1反转*/
			GPIO_WriteBit(GPIOC, GPIO_Pin_3, 
				(BitAction)(1-(GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_3))));
		}   
	}
}


/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
