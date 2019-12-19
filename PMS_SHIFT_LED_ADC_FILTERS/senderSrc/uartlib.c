#include "uartlib.h"
#include "delay.h"

int UART_putc(USART_TypeDef* USARTx, char c)
{
	while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);
	USART_SendData(USARTx, c);
	
	return 0;
}


int UART_open(USART_TypeDef* USARTx, uint32_t baud, uint32_t flags)
{
	// This function assumes GPIOA is used for USART

	GPIO_InitTypeDef             GPIO_InitStructure;
	USART_InitTypeDef            USART_InitStructure;
	GPIO_StructInit(&GPIO_InitStructure);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	if(USARTx == USART1)
	{
		
		 /* Enalbe clock for USART1, AFIO and GPIOA */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_AFIO | 
                           RCC_APB2Periph_GPIOA, ENABLE);
					
		/* GPIOA PIN9 alternative function Tx */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    /* GPIOA PIN9 alternative function Rx */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
	}
	;
	// Initialise USART structure
	USART_StructInit(&USART_InitStructure);
	// Modify USART_InitStructure for non-default values, e.G.
	USART_InitStructure.USART_BaudRate = baud;
	USART_InitStructure.USART_Mode = flags;
	USART_Init(USARTx, &USART_InitStructure);
	USART_Cmd(USARTx, ENABLE);
	
	return 0;
}

//--------------

uint32_t GPIOC14_gnd_connect(void){
    if (!GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_15))// Catch from GND 
		{//slow, press and connect GPIOC 13 to GND 
		 delay_ms(10);
         return 1;
		}
		
		else 
        {//fast no press !!!
        delay_ms(10);
        return 0;    
        }
		
	}

//----------------------
	uint32_t GPIOA0_gnd_connect(void){
    if (!GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0))// Catch from GND 
		{//slow, press and connect GPIOC 13 to GND 
		 delay_ms(10);
         return 1;
		}
		
		else 
        {//fast no press !!!
        delay_ms(10);
        return 0;    
        }
		
	}
		
uint32_t GPIOA1_gnd_connect(void){
    if (!GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_1))// Catch from GND 
		{//slow, press and connect GPIOC 13 to GND 
		 delay_ms(10);
         return 1;
		}
		
		else 
        {//fast no press !!!
        delay_ms(10);
        return 0;    
        }
		
	}
	
uint32_t GPIOA2_gnd_connect(void){
    if (!GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2))// Catch from GND 
		{//slow, press and connect GPIOC 13 to GND 
		 delay_ms(10);
         return 1;
		}
		
		else 
        {//fast no press !!!
        delay_ms(10);
        return 0;    
        }
		
	}
	
uint32_t GPIOA3_gnd_connect(void){
    if (!GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3))// Catch from GND 
		{//slow, press and connect GPIOC 13 to GND 
		 delay_ms(10);
         return 1;
		}
		
		else 
        {//fast no press !!!
        delay_ms(10);
        return 0;    
        }
		
	}
	

	
	
	
	
	
	
	
	
	
	
void led_toggle(void)
{
    /* Read LED output (GPIOA PIN8) status */
    uint8_t led_bit = GPIO_ReadOutputDataBit(GPIOC, GPIO_Pin_13);
     
    /* If LED output set, clear it */
    if(led_bit == (uint8_t)Bit_SET)
    {
        GPIO_ResetBits(GPIOC, GPIO_Pin_13);
    }
    /* If LED output clear, set it */
    else
    {
        GPIO_SetBits(GPIOC, GPIO_Pin_13);
    }
}



void led_init_out_c13 (void){
	//to output for display
   GPIO_InitTypeDef GPIO_InitStructure;
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC , ENABLE); // (1)
   GPIO_StructInit (& GPIO_InitStructure);
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
   GPIO_Init(GPIOC , &GPIO_InitStructure); 
}


void btn_init_in_c15 (void){
    //To input for button 
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC , ENABLE); // (1)
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;    
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}

//-----------







void GPIOA_Init_0_7_i(void)
{
   	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		GPIO_InitTypeDef  GPIO_A_init;
		GPIO_A_init.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
		GPIO_A_init.GPIO_Mode = GPIO_Mode_IPU;
		GPIO_A_init.GPIO_Speed = GPIO_Speed_2MHz;
		GPIO_Init(GPIOA, &GPIO_A_init);
}