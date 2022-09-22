#ifndef __OLED_I2C_H
#define	__OLED_I2C_H

#include "stm32f10x.h"

#define OLED_ADDRESS	0x78 //ͨ������0R����,������0x78��0x7A������ַ -- Ĭ��0x78

void I2C_Configuration(void);					//�˿ڳ�ʼ��
void OLED_Init(void);							//OLED��ʼ��
void I2C_WriteByte(uint8_t addr,uint8_t data);	//дһ�ֽ�
void WriteCmd(unsigned char I2C_Command);		//дָ��
void WriteDat(unsigned char I2C_Data);			//д����
void OLED_SetPos(unsigned char x, unsigned char y);  	//������ʼ����
void OLED_Fill(unsigned char fill_Data);				//OLED_Fill(0xFF); ȫ������   OLED_Fill(0x00);ȫ����
void OLED_CLS(void);		//����
void OLED_ON(void);			//OLED���ߺ���
void OLED_OFF(void);		//OLED����
void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N);		//��ʾ����
void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]); 		//��ʾͼƬ
void OLED_ShowChar6X8(unsigned char x, unsigned char y, unsigned char chr);				//��ʾһ��6X8�ַ�
void OLED_ShowChar8X16(unsigned char x, unsigned char y, unsigned char chr);			//��ʾһ��8X16�ַ�
void OLED_ShowStr(unsigned char x, unsigned char y, unsigned char *chr, unsigned char TextSize);			//��ʾ�ַ���  TextSize 1: 6x8   2: 8X16
void OLED_ShowNum(unsigned char x, unsigned char y, int Number, unsigned char Length, unsigned char TextSize);//��ʾ�з�������

#endif

