#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include <string.h>
#include "stm32f10x_usart.h"

int UART_open(USART_TypeDef* USARTx, uint32_t baud, uint32_t flags);
int UART_putc(USART_TypeDef* USARTx, char c);

uint32_t GPIOC14_gnd_connect(void);
void GPIOA_Init_0_7_i(void);

uint32_t GPIOA0_gnd_connect(void);
uint32_t GPIOA1_gnd_connect(void);
uint32_t GPIOA2_gnd_connect(void);
uint32_t GPIOA3_gnd_connect(void);



void led_toggle(void);
void led_init_out_c13 (void);
void btn_init_in_c15 (void);
void USART1A910_Init(void);
void GPIOA_Init_0_7_o(void);
void GPIOA_test_0_7_o(void);
void GPIOC_Init_13_o(void);

