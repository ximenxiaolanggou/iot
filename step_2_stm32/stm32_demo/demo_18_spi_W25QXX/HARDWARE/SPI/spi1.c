#include "spi1.h"
#include "delay.h"
#include "sys.h"

SPI_InitTypeDef SPI_InitStruce;

// ��ʼ��
void SPI1_Init(){
	
	GPIO_InitTypeDef GPIO_InitStruce;

	
	// ʹ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_SPI1, ENABLE);
	
	GPIO_InitStruce.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
  GPIO_InitStruce.GPIO_Mode = GPIO_Mode_AF_PP; 		 // �����������
  GPIO_InitStruce.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	GPIO_Init(GPIOA, &GPIO_InitStruce);
	
	GPIO_InitStruce.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
  GPIO_InitStruce.GPIO_Mode = GPIO_Mode_IPU; 		   // ��������
  GPIO_InitStruce.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	GPIO_Init(GPIOA, &GPIO_InitStruce);
	
	GPIO_SetBits(GPIOA,GPIO_Pin_4);// Ƭѡ ���� ����״̬
	
	SPI_InitStruce.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256; //Ԥ��Ƶ 256
	SPI_InitStruce.SPI_CPHA = SPI_CPHA_2Edge; //���ݲ����ڵڶ���ʱ����
	SPI_InitStruce.SPI_CPOL = SPI_CPOL_High; //ѡ���˴���ʱ�ӵ���̬:ʱ�����ո�
	SPI_InitStruce.SPI_CRCPolynomial = 7; //CRCֵ����Ķ���ʽ
	SPI_InitStruce.SPI_DataSize = SPI_DataSize_8b; // 8 λ֡�ṹ
	SPI_InitStruce.SPI_Direction = SPI_Direction_2Lines_FullDuplex; //���� SPI ȫ˫��
	SPI_InitStruce.SPI_FirstBit = SPI_FirstBit_MSB; // ָ�����ݴ����MSB����LSBλ��ʼ
	SPI_InitStruce.SPI_Mode = SPI_Mode_Master; // ���� SPI ����ģʽ:����Ϊ�� SPI
	SPI_InitStruce.SPI_NSS = SPI_NSS_Soft; // NSS�ź���Ӳ��(NSS�ܽ�)�������(ʹ��SSIλ)����
	SPI_Init(SPI1, &SPI_InitStruce);
	
	SPI_Cmd(SPI1, ENABLE); // ʹ�� SPI ����
	

}

//SPI �ٶ����ú���
//SpeedSet:
//SPI_BaudRatePrescaler_2 2 ��Ƶ (SPI 36M@sys 72M)
//SPI_BaudRatePrescaler_8 8 ��Ƶ (SPI 9M@sys 72M)
//SPI_BaudRatePrescaler_16 16 ��Ƶ (SPI 4.5M@sys 72M)
//SPI_BaudRatePrescaler_256 256 ��Ƶ (SPI 281.25K@sys 72M)
void SPI1_SetSpeed(u8 SpeedSet)
{
		SPI_InitStruce.SPI_BaudRatePrescaler = SpeedSet ;
		SPI_Init(SPI1, &SPI_InitStruce);
		SPI_Cmd(SPI1,ENABLE);
}

//SPIx ��дһ���ֽ�
//TxData:Ҫд����ֽ�
//����ֵ:��ȡ�����ֽ�
u8 SPI1_ReadWriteByte(u8 TxData)
{
	u8 retry=0;
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET) //���ָ���� SPI��־λ�������:���ͻ���ձ�־λ
	{
		retry++;
		if(retry>200)return 0;
	}
	SPI_I2S_SendData(SPI1, TxData); //ͨ������ SPIx ����һ������
	retry=0;
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET)//���ָ����SPI ��־λ�������:���ܻ���ǿձ�־λ
	{
		retry++;
		if(retry>200)return 0;
	}
	return SPI_I2S_ReceiveData(SPI1); //����ͨ�� SPIx ������յ�����
}
 
