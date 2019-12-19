#include "filter.h"
#include "delay.h"
#include "uartlib.h"
#include "ADC.h"
#include "stdio.h"
#define BUFFER_SIZE 64
#define FILTER_ARITY 32

unsigned int digit_display0 = 0;
struct Buffer buf;

int main()
{
	GPIOA_Init_0_7_i();
	led_init_out_c13();
	ADC_init();
	UART_open(USART1, 9600, USART_Mode_Rx | USART_Mode_Tx);
	delay_ms(1000);
	GPIO_SetBits(GPIOA, GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5);
	led_toggle();
	delay_ms(1500);
	GPIO_ResetBits(GPIOA, GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5);
	buf = cbuf_new(BUFFER_SIZE);
	
	/*seed n initial values into buffer*/
	
	for(int i = 0; i < FILTER_ARITY; i++){
		cbuf_write(&buf, ADC_read());
		cbuf_read(&buf);
		delay_ms(5);
	}
	
	int filter_val = 0;
	while (1)
	{
		led_toggle();
		cbuf_write(&buf, ADC_read());
		filter_val = n_term_recursive_filter(&buf, FILTER_ARITY, filter_val);
		UART_putc(USART1, filter_val);
		cbuf_read(&buf);
		delay_ms(100);
	}
}