/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * �ļ���  ��main.c
 * ����    ������USART2����Եĳ����ն˷�����Ϣ��       
 * ʵ��ƽ̨��Ұ��STM32������
 * ��汾  ��ST3.5.0
 *
 * ����    ��wildfire team 
 * ��̳    ��http://www.amobbs.com/forum-1008-1.html
 * �Ա�    ��http://firestm32.taobao.com
**********************************************************************************/
#include "stm32f10x.h"
#include "usart2.h"

/*
 * ��������main
 * ����  ��������
 * ����  ����
 * ���  ����
 */
int main(void)
{	
	uint8_t i;
	
	/* USART2 config */
	USART2_Config();

	USART2_printf(USART2, "\r\n This is a USART2_printf demo \r\n");
	USART2_printf(USART2, "\r\n ��ӭʹ��Ұ��M3ʵ��� \r\n");
	for ( i=0; i<8; i++ )
		USART2_printf( USART2, "\r\n %d \r\n", i );
}


/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
