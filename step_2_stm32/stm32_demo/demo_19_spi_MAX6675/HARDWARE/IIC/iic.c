#include "iic.h"
#include "delay.h"
#include "usart.h"

// io Ϊ0ʱ��ʾ���� 1ʱ��ʾ���
void IIC_SDA_IO(u8 io){
	 GPIO_InitTypeDef  GPIO_InitStructure;
	if(io == 0) { // ����
		 GPIO_InitStructure.GPIO_Pin = SDA;				
		 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 			 
		 GPIO_Init(IIC_Port, &GPIO_InitStructure);										 

	}else{ // ���
		 GPIO_InitStructure.GPIO_Pin = SDA;				
		 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		
		 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
		 GPIO_Init(IIC_Port, &GPIO_InitStructure);		
	}
}

// ��ʼ��
void IIC_Init(){
	
	 GPIO_InitTypeDef  GPIO_InitStructure;
 	
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);	
		
	 GPIO_InitStructure.GPIO_Pin = SDA | SCL;				 
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		
	 GPIO_Init(IIC_Port, &GPIO_InitStructure);	
	 GPIO_SetBits(IIC_Port,SDA | SCL);
		
	 SCL_HIGH;
	 SDA_HIGH;
}

// ��ʼ
void IIC_Start(){
	IIC_SDA_IO(1); // SDA���
	SCL_HIGH;
	SDA_HIGH;
	delay_us(4);
	
	SDA_LOW;
	delay_us(4); 
	SCL_LOW; // ǯסIIC���ߣ�׼����������
	
}

// ��ֹ
void IIC_Stop(void){
	IIC_SDA_IO(1); // SDA���
	SCL_LOW;
	SDA_LOW;
	delay_us(4);
	
	SCL_HIGH;
	SDA_HIGH;
	delay_us(4);
}

// ��������
void IIC_SendByte(u8 Data){
	u8 i;
	IIC_SDA_IO(1); // SDA���
	SCL_LOW; // ����ʱ�ӿ�ʼ���ݴ���
	for(i = 0 ; i < 8 ; i++) {
		if((Data & 0x80) >> 7) {
			SDA_HIGH;
		}else {
			SDA_LOW;
		}
		Data <<= 1; // ����һλ
		delay_us(2);
		SCL_HIGH;
		delay_us(2);
		SCL_LOW;
		delay_us(2);
	}

}

// ��������
u8 IIC_Read_Byte(){
	u8 i;
	u8 Data = 0x00;
	IIC_SDA_IO(0); // SDA����
	for(i = 0 ; i < 8 ; i++) {
		SCL_LOW;
		delay_us(2);
		SCL_HIGH;
		Data <<= 1;
		if(SDA_READ) { // ����Ϊ1
			Data++;	
		}
	}
	return Data;
}

// �ȴ�Ӧ�� 1 ��Ӧ�� 0 Ӧ��
u8 IIC_Wait_Ack() {
	u8 Timer_Ack;
	IIC_SDA_IO(0); // SDA����
	SDA_HIGH; delay_us(1);
	SCL_HIGH;delay_us(1);
	while(SDA_READ) {
		Timer_Ack++;
		if( Timer_Ack > 250) {
			return 1;
		}
	}
	SCL_LOW;
	return 0; 
}

// ����ACK
void IIC_Ack(void) {
	IIC_SDA_IO(1); // SDA���
	SCL_LOW;
	SDA_LOW;
	delay_us(2);
	SCL_HIGH;
	delay_us(2);
	SCL_LOW;
}

// ������ACK
void IIC_NAck(){
	IIC_SDA_IO(1); // SDA���
	SCL_LOW;
	SDA_HIGH;
	delay_us(2);
	SCL_HIGH;
	delay_us(2);
	SCL_LOW;
}


 
