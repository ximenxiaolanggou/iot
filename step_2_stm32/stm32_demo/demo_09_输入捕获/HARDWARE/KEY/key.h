#ifndef __KEY_H
#define __KEY_H

// KEY��ʼ��
void KEY_Init(void);

// ��ȡ���µİ���
// 0 ����KEY0���£� 1 ����KEY1 ���£� 3 ����WK_UP���� - 1����δ����
// mode 0 ��֧�������� 1 ֧��������
char KEY_Scan(char mode);

#endif
