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
	
	printf("\r\n this is a printf demo \r\n");

	printf("\r\n ��ӭʹ��Ұ��M3ʵ���:) \r\n");
		
	USART1_printf(USART1, "\r\n This is a USART1_printf demo \r\n");
	
	USART1_printf(USART1, "\r\n ("__DATE__ " - " __TIME__ ") \r\n");

	for(;;)
	{
		
	}
}
/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
