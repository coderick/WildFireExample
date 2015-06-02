/******************** (C) COPYRIGHT 2012 WildFire Team **************************
 * 文件名  ：main.c
 * 描述    ：LCD显示实验，可中英混合显示，可显示BMP格式的图片，可截图，
 *           截图保存在MicroSD卡中，文件名存为myScreen.bmp，
 *           需显示的BMP图片和字库存放在MicroSD卡中。         
 * 实验平台：野火STM32开发板
 * 库版本  ：ST3.5.0
 *
 * 作者    ：wildfire team 
 * 论坛    ：http://www.amobbs.com/forum-1008-1.html
 * 淘宝    ：http://firestm32.taobao.com
**********************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "SysTick.h"
#include "usart1.h"	
#include "lcd.h"
#include "sd_fs_app.h"
#include "Sd_bmp.h"


int main(void)
{
   /* USART1 config */
	USART1_Config();
	SysTick_Init();
	LCD_Init();										/* LCD 初始化*/		
    sd_fs_init();
    
	/*显示图像*/
    Lcd_show_bmp(0, 0,"/pic3.bmp");   
    Lcd_show_bmp( 40,200,"/pic2.bmp");
    Lcd_show_bmp( 100,100,"/pic1.bmp");	
 
    /*横屏显示*/
    LCD_Str_O(20, 10, "lCD_DEMO",0); 	  
    LCD_Str_CH(20,30,"阿莫论坛野火专区",0,0xffff);	  
    LCD_Str_CH_O(20,50,"阿莫论坛野火专区",0);
    LCD_Num_6x12_O(20, 70, 65535, BLACK);
    LCD_Str_6x12_O(20, 90,"LOVE STM32", BLACK);	   

    /*竖屏显示*/     
    LCD_Str_O_P(300, 10, "Runing", 0);	
    LCD_Str_CH_P(280,10,"阿莫论坛野火专区欢迎你",0xff,0xffff);		   
    LCD_Str_CH_O_P(260,10,"阿莫论坛野火专区",0);
    LCD_Str_6x12_O_P(240, 10,"LOVE STM32", 0);    
    LCD_Str_ENCH_O_P(220,10,"欢迎使用野火stm32开发板",0);
    
	/*截图*/
    LCD_Str_CH(20,150,"正在截图",0,0xffff);
 	Screen_shot(0, 0, 240,320 , "/myScreen");
    LCD_Str_CH(20,150,"截图完成",0,0xffff);
    
 	 
  while (1)
  {}
}

	  
/******************* (C) COPYRIGHT 2012 WildFire Team *****END OF FILE************/
