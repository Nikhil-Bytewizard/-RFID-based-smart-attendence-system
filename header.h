extern void delay_ms(unsigned int ms);
extern void delay_sec(unsigned int sec);
extern void lcd_data(unsigned char data);
extern void lcd_cmd(unsigned char cmd);
extern void lcd_init(void);
extern void lcd_integer(int num);
extern void lcd_float(float num);
extern void lcd_string(char *ptr);
extern void cgram(void);
////////////// UART DRIVER //////////////
extern void uart0_init(unsigned int baud);
extern void uart0_tx(unsigned char);
extern unsigned char uart0_rx(void);
extern void uart0_tx_string (signed char *p);
extern void uart0_rx_string(signed char *p,signed int len);
extern void uart0_tx_integer(signed int num);
extern void uart0_tx_float(float f);
extern void uart0_tx_hex(signed int num);
extern void uart0_binary(signed int num);
////////////// ADC driver////////////////////
extern void adc_init(void);
extern unsigned char adc_read(unsigned char ch_num);
