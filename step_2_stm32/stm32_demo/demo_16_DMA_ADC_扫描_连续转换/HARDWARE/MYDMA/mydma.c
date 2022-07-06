#include "mydma.h"
#include "delay.h"

uint16_t MYDMA_SIZE;
// ��ʼ��
void MYDMA_Init(uint32_t AddrA, uint32_t AddrB, uint16_t Size) {
	
	
	DMA_InitTypeDef DMA_InitStrture;
	
	MYDMA_SIZE = Size;

	// ����ʱ��
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	
	// ��ʼ��DMA   ����վ��3���������洢��վ��3������
	DMA_InitStrture.DMA_PeripheralBaseAddr = AddrA; // ���������ַ
	DMA_InitStrture.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte; // �������ݿ��
	DMA_InitStrture.DMA_PeripheralInc = DMA_PeripheralInc_Enable; // ��ַ�Ƿ�����
	DMA_InitStrture.DMA_MemoryBaseAddr = AddrB; //�洢��������ַ
	DMA_InitStrture.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte; // �洢�����ݿ��
	DMA_InitStrture.DMA_MemoryInc = DMA_MemoryInc_Enable; // ��ַ�Ƿ�����
	DMA_InitStrture.DMA_DIR = DMA_DIR_PeripheralSRC; // ָ������վ����Դ�˻���Ŀ�ĵ�
	DMA_InitStrture.DMA_BufferSize = Size; // �������
	DMA_InitStrture.DMA_Mode = DMA_Mode_Normal; // ����ģʽ
	DMA_InitStrture.DMA_M2M = DMA_M2M_Enable; // �Ƿ�Ϊ�洢�����洢��ת�ˣ������������Ӳ��������
	DMA_InitStrture.DMA_Priority = DMA_Priority_Medium; // ���ȼ�
	DMA_Init(DMA1_Channel1, &DMA_InitStrture);
	
		
	// ʹ��DMA
	// DMA_Cmd(DMA1_Channel1,ENABLE);

}

/*
�ֶ�ת��
1. ��ʧ��
2. ����ת�˴���
3. ʹ��

*/

void MYDMA_Transfer() {
	//ʧ��
	 DMA_Cmd(DMA1_Channel1,DISABLE);
	//����ת�˴���
	 DMA_SetCurrDataCounter(DMA1_Channel1,MYDMA_SIZE);
	//ʹ��
	 DMA_Cmd(DMA1_Channel1,ENABLE);
	
	// �ȴ�ת�����
	while(DMA_GetFlagStatus(DMA1_FLAG_TC1) == RESET);
	
	// �����־λ
	DMA_ClearFlag(DMA1_FLAG_TC1);
	
	
}
