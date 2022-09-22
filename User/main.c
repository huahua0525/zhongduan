#include "stm32f10x.h"                  // Device header
#include "OLED_I2C.h"
uint32_t witchr=0;
void count_init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);

	GPIO_InitTypeDef	GPIOB_init;
	GPIOB_init.GPIO_Mode = GPIO_Mode_IPU;
	GPIOB_init.GPIO_Speed = GPIO_Speed_50MHz;
	GPIOB_init.GPIO_Pin = GPIO_Pin_14;
	GPIO_Init(GPIOB,&GPIOB_init);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);

	EXTI_InitTypeDef EXTI_Initstructure;
	EXTI_Initstructure.EXTI_Line = EXTI_Line14;
	EXTI_Initstructure.EXTI_LineCmd = ENABLE;
	EXTI_Initstructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_Initstructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_Initstructure);

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
}

void EXTI15_10_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line14) == SET)
			{
				EXTI_ClearITPendingBit(EXTI_Line14);
				witchr++;
				
			}
}

int main(void)
{
	I2C_Configuration();
	OLED_Init();
	OLED_CLS();
	count_init();
	while(1)
	{
		OLED_ShowNum(1,1,witchr,4,1);
	}
}
