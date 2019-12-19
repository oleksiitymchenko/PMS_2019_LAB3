#include "display.h"
#include "uartlib.h"
#include "delay.h"

volatile char info_usart=0;

int main() {
	USART1A910_Init();
	GPIOA_Init_0_7_o();
	GPIOC_Init_13_o();
	SetupDisplay();
	while(1){
		ClearDisplay();
		WriteDigit(2000);
	}
}

void USART1_IRQHandler()
{
 
  if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
  {
		led_toggle();
		info_usart=USART_ReceiveData(USART1);
  }
}