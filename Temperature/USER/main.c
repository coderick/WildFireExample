/******************** (C) COPYRIGHT 2011 Ұ��Ƕ��ʽ���������� ********************
 * �ļ���  ��main.c
 * ����    ��STM32�ڲ��¶Ȳ��ԣ�������Ϣͨ��USART1��ӡ�ڵ��Եĳ����նˡ�
 *          
 * ʵ��ƽ̨��Ұ��STM32������
 * ��汾  ��ST3.5.0
 *
 * ����    ��wildfire team 
 * ��̳    ��http://www.amobbs.com/forum-1008-1.html
 * �Ա�    ��http://firestm32.taobao.com
**********************************************************************************/	
#include "stm32f10x.h"
#include "usart1.h"
#include "tempad.h"

/* ADC1ת���ĵ�ѹֵͨ��MDA��ʽ����sram*/
extern __IO u16 ADC_ConvertedValue;


/*�������¶�ֵ*/
 u16 Current_Temp;	 

 
/* �����ʱ	*/
void Delay(__IO u32 nCount)
{
  for(; nCount != 0; nCount--);
} 

/*
 * ��������main
 * ����  ��������
 * ����  : ��
 * ���  ����
 */
int main(void)
{  
		 
 /* USART1 config 115200 8-N-1 */
  	USART1_Config();

	Temp_ADC1_Init();

	printf("\r\n ����һ���ڲ��¶ȴ�����ʵ�� \r\n");
	printf( "\r\n Print current Temperature  \r\n");	

  while (1)
  { 

	Delay(0xffffee);      // ��ʱ 
	
	//���㷽��1            	                 									  
 	 //Current_Temp= (1.43- ADC_ConvertedValue*3.3/4096)*1000 / 4.3+ 25 ;
	
	//���㷽��2
	Current_Temp=(V25-ADC_ConvertedValue)/AVG_SLOPE+25;	

	//10������ʾ
	printf("\r\n The current temperature= %3d ��\r\n", Current_Temp);	      
 	 
	//16������ʾ 						 
 	// printf("\r\n The current temperature= %04x \r\n", Current_Temp);		 
  }
}
/******************* (C) COPYRIGHT 2011 Ұ��Ƕ��ʽ���������� *****END OF FILE****/ 
