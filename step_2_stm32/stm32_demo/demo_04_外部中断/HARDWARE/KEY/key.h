#ifndef __KEY_H
#define __KEY_H

// KEY初始化
void KEY_Init(void);

// 获取按下的按键
// 0 代表KEY0按下， 1 代表KEY1 按下， 3 代表WK_UP按下 - 1代表未按下
// mode 0 不支持连续按 1 支持连续按
char KEY_Scan(char mode);

#endif
