#ifndef __USART1_H
#define	__USART1_H

#include "stm32f10x.h"
#include <stdio.h>

void USART1_Config(void);				//���ڴ���USART1������
int fputc(int ch, FILE *f);			//��Ҫʹ��printf()��������printf()���¶��򵽴�����
void USART1_printf(USART_TypeDef *USARTx, uint8_t *Data,...);  //��ʽ�������������C���е�printf��������û���õ�C��
			  //�����к���itoa����	 ����ġ�...���ǲ�ȷ����������ݵĸ���������д���
#endif /* __USART1_H */	
