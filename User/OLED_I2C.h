#ifndef __OLED_I2C_H
#define	__OLED_I2C_H

#include "stm32f10x.h"

#define OLED_ADDRESS	0x78 //通过调整0R电阻,屏可以0x78和0x7A两个地址 -- 默认0x78

void I2C_Configuration(void);					//端口初始化
void OLED_Init(void);							//OLED初始化
void I2C_WriteByte(uint8_t addr,uint8_t data);	//写一字节
void WriteCmd(unsigned char I2C_Command);		//写指令
void WriteDat(unsigned char I2C_Data);			//写数据
void OLED_SetPos(unsigned char x, unsigned char y);  	//设置起始坐标
void OLED_Fill(unsigned char fill_Data);				//OLED_Fill(0xFF); 全屏点亮   OLED_Fill(0x00);全屏灭
void OLED_CLS(void);		//清屏
void OLED_ON(void);			//OLED休眠后唤醒
void OLED_OFF(void);		//OLED休眠
void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N);		//显示汉字
void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]); 		//显示图片
void OLED_ShowChar6X8(unsigned char x, unsigned char y, unsigned char chr);				//显示一个6X8字符
void OLED_ShowChar8X16(unsigned char x, unsigned char y, unsigned char chr);			//显示一个8X16字符
void OLED_ShowStr(unsigned char x, unsigned char y, unsigned char *chr, unsigned char TextSize);			//显示字符串  TextSize 1: 6x8   2: 8X16
void OLED_ShowNum(unsigned char x, unsigned char y, int Number, unsigned char Length, unsigned char TextSize);//显示有符号数字

#endif

