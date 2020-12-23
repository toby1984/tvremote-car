#include "joystick.h"
#include "radio_sender.h"
#include "crc.h"
#include "util/delay.h"
#include "uart.h"

void main(void) {
    joystick_readings reading;
    uint8_t msg[3];

    uart_init();
    joystick_init();
    radio_sender_init();

    uart_print("\r\nonline\r\n");

	while(1) {
		joystick_read(&reading);
		uart_print("\r\nread joystick\r\n");

		msg[0] = reading.x;
		msg[1] = reading.y;
		msg[2] = 0; // we're using CRC8, shift-in 8 zero bits at the end of the message

        uart_print("\r\nCalculating CRC\r\n");		
		msg[2] = crc8(&msg[0],3);

        uart_print("\r\ncalculated CRC\r\n");

		uint32_t hex = (uint32_t) msg[0] << 16 | (uint32_t) msg[1] << 8 | msg[0];
		uart_print("\r\nMessage: 0x");
		uart_puthex( hex );

		radio_send(&msg[0],3);
		_delay_ms(250);
		_delay_ms(250);		
		_delay_ms(250);
		_delay_ms(250);			
	}
}