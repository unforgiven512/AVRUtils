/*
 * AVRUtils.ino -- a very simple demonstration of the library's functionality
 */

#include <AVRUtils.h>


#define SERIAL_BAUD_RATE 115200
#define SERIAL_WAIT_FOR_CONNECTION 1
#define USE_CHARBUF 0
#define LED_PIN 13


volatile uint32_t reading_number;

#if (USE_CHARBUF == 1)
char data_output[200];
#endif

AVRUtils avr;



void setup() {
	Serial.begin(SERIAL_BAUD_RATE);

#if (SERIAL_WAIT_FOR_CONNECTION == 1)
	while (!Serial);
#endif

	avr.begin();
}

void loop() {
	digitalWrite(LED_PIN, HIGH);
	delay(500);
	digitalWrite(LED_PIN, LOW);
	delay(500);

#if (USE_CHARBUF == 1)
	sprintf(data_output, "\n\n-------------------------\nReading #:\t%ul\nAVR TempF:\t%fF\nVoltage:\t%f\n", reading_number++, avr.getAVRTemp(), avr.getAVRVcc());
	Serial.print(data_output);
#else
	Serial.println(F("\n\n------------------------------"));
	Serial.print(F("Reading #: "));
	Serial.println(reading_number++);

	Serial.print(F("AVR temp is "));
	Serial.print(avr.getAVRTemp());
	Serial.println(F(" *F"));

	Serial.print(F("AVR Vcc is "));
	Serial.print(avr.getAVRVcc());
	Serial.println(F(" mV"));
#endif
}
