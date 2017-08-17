
//Define Clock source
#define MCU_CLOCK_SOURCE      
#define MCU_CLOCK_SOURCE_HIRC // HXT, LXT, HIRC, LIRC
#define MCU_CLOCK_SOURCE_LXT
#define MCU_CLOCK_FREQUENCY   42000000  //Hz

//Define MCU Interfaces
#define MCU_INTERFACE_TMR1
#define TMR1_CLOCK_SOURCE_LXT // HXT, LXT, LIRC, EXT, HIRC, HCLK
#define TMR1_CLOCK_DIVIDER    1
#define TMR1_OPERATING_MODE   TIMER_PERIODIC_MODE // ONESHOT, PERIODIC, TOGGLE, CONTINUOUS
#define TMR1_OPERATING_FREQ   1 //Hz
  
#define MCU_INTERFACE_I2C0
#define I2C0_CLOCK_FREQUENCY  400000 //Hz
#define PIN_I2C0_SCL_PA9
#define PIN_I2C0_SDA_PA8
