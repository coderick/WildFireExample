/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * �ļ���  ��main.c
 * ����    ����c���е�printf()����ʵ�ֵ�����1(USART1)���������ǾͿ�����printf()��
 *           ������Ϣͨ�����ڴ�ӡ�������ϡ�         
 * ʵ��ƽ̨��Ұ��STM32������
 * ��汾  ��ST3.5.0
 *
 * ����    ��wildfire team 
 * ��̳    ��http://www.amobbs.com/forum-1008-1.html
 * �Ա�    ��http://firestm32.taobao.com
**********************************************************************************/
#include "stm32f10x.h"
#include "usart1.h"
#include "led.h"

 extern uint8_t SendBuff[SENDBUFF_SIZE];
 uint16_t i;


/*
 * ��������main
 * ����  ��������
 * ����  ����
 * ���  ����
 */
int main(void)
{	
	/* USART1 config 115200 8-N-1 */
	USART1_Config();
	DMA_Config();
	LED_GPIO_Config();
	

  /*��佫Ҫ���͵�����*/
 for(i=0;i<SENDBUFF_SIZE;i++)
   	{
		SendBuff[i]	 = 0xff;
   }

 /*������ DMA�������� */
 USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);	

  /*��DMA��δ�������ʱ��cpu����ִ��main�����еĴ���*/
  /*������LED��*/
/*��ͬʱDMA���򴮿��������ݣ���DMA�������ʱ�����жϺ����ر�LED�� */


	LED1(ON);


	while(1);
}
/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
