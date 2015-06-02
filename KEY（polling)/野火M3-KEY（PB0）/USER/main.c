/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * �ļ���  ��main.c
 * ����    ��PB0���ӵ�key1��PB0����Ϊ���ж�ģʽ��key1����ʱ���������жϴ�������
 *           LED1״̬ȡ����         
 * ʵ��ƽ̨��Ұ��STM32������
 * ��汾  ��ST3.5.0
 *
 * ����    ��wildfire team 
 * ��̳    ��http://www.amobbs.com/forum-1008-1.html
 * �Ա�    ��http://firestm32.taobao.com
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
			/*LED1��ת*/
		   	GPIO_WriteBit(GPIOC, GPIO_Pin_3, 
		             (BitAction)((1-GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_3))));
	}   
  }
}

/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE****/
