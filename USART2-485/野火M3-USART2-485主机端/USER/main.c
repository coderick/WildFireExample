/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * �ļ���  ��main.c
 * ����    ������USART2����Եĳ����ն˷�����Ϣ��       
 * ʵ��ƽ̨��Ұ��STM32������
 * ��汾  ��ST3.5.0
 *
 * ����    ��wildfire team 
 * ��̳    ��www.ourdev.cn/bbs/bbs_list.jsp?bbs_id=1008
 * �Ա�    ��http://firestm32.taobao.com
**********************************************************************************/
#include "stm32f10x.h"
#include "usart2.h"
#include "usart1.h"

/*
 * ��������main
 * ����  ��������
 * ����  ����
 * ���  ����
 ������Ϊ������ʵ��ʱ�ȸ��ӻ��ϵ�
 */
int main(void)
{	

	uint8_t temp = 0;

	/* USART2 config */
	USART2_Config();  //����2�����շ�485������
	USART1_Config();  //����1�������������Ϣ


  while(1){

			 GPIO_SetBits(GPIOA,GPIO_Pin_0); //���뷢��ģʽ
			 USART_SendData(USART2, temp);	 //��������
  			while (USART_GetFlagStatus(USART2,USART_FLAG_TC) !=SET);//��ѯֱ�������������	
			printf("�������ݳɹ���\r\n"); //ʹ�ô���1��ӡ������Ϣ���ն�

			GPIO_ResetBits(GPIOA,GPIO_Pin_0);	//�������ģʽ
  			while(	USART_GetFlagStatus(USART2,USART_FLAG_RXNE)!= SET); //��ѯֱ��485���յ�����
			
			  temp = USART_ReceiveData(USART2);
			   	printf("���յ�������Ϊ%d \r\n",temp);
			 
			
   }

}


/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
