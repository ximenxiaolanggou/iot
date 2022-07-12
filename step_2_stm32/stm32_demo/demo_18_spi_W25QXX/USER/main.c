#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "lcd.h"
#include "spi1.h"
#include "w25q64.h"

//要写入到W25Q64的字符串数组
const u8 TEXT_Buffer[]={"MiniSTM32 SPI TEST"};
#define SIZE sizeof(TEXT_Buffer)	 

 int main(void)
 { 
	 u8 key;
	 u16 i=0;
	 u8 datatemp[SIZE];
	 u32 FLASH_SIZE;
    u16 id = 0;
		SPI_Flash_Init();  		//SPI FLASH 初始化 
	delay_init();	    	 //延时函数初始化	  
	uart_init(9600);	 	//串口初始化为9600
 	LCD_Init();	
	 
   id = SPI_Flash_ReadID();
	if (id != W25Q64 || id != NM25Q64){
		LCD_ShowString(30,150,200,16,16,"W25Q64 Check Failed!");
		delay_ms(500);
		LCD_ShowString(30,150,200,16,16,"Please Check!        ");
		delay_ms(500);
	}
	
		

		LCD_ShowString(60,150,200,16,16,"25Q64 Ready!");
		
		SPI_Flash_Write((u8*)TEXT_Buffer,FLASH_SIZE-100,SIZE);		//从倒数第100个地址处开始,写入SIZE长度的数据
		SPI_Flash_Read(datatemp,FLASH_SIZE-100,SIZE);				//从倒数第100个地址处开始,读出SIZE个字节
		LCD_ShowString(60,170,200,16,16,"The Data Readed Is:  ");	//提示传送完成
		LCD_ShowString(60,190,200,16,16,datatemp);					//显示读到的字符串
		
		while(1);
}
	
