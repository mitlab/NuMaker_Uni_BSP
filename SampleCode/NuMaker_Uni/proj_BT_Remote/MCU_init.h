
//Define Clock source
#define MCU_CLOCK_SOURCE      
#define MCU_CLOCK_SOURCE_HIRC // HXT, LXT, HIRC, LIRC
#define MCU_CLOCK_SOURCE_LXT
#define MCU_CLOCK_FREQUENCY   42000000  //Hz

//Define MCU Interfaces
#define MCU_INTERFACE_UART0
#define UART_CLOCK_SOURCE_HIRC // HXT, LXT, PLL, HIRC
#define UART_CLOCK_DIVIDER    3
#define PIN_UART0_RX_PB0
#define PIN_UART0_TX_PB1

#define MCU_INTERFACE_PWM0
#define PWM0_CH01_CLOCK_SOURCE_HIRC // HXT, LXT, HCLK, HIRC
#define PIN_PWM0_CH0_PA12
#define PIN_PWM0_CH1_PA13


