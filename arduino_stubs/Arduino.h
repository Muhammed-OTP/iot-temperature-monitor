#ifndef ARDUINO_H_STUB
#define ARDUINO_H_STUB

// Stub Arduino header for VSCode IntelliSense only.
// Not used for compilation — use Arduino IDE or Tinkercad.

#define HIGH 0x1
#define LOW  0x0
#define INPUT  0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#define A0 14
#define A1 15
#define A2 16
#define A3 17
#define A4 18
#define A5 19

typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;

void pinMode(int pin, int mode);
void digitalWrite(int pin, int val);
int  digitalRead(int pin);
int  analogRead(int pin);
void analogWrite(int pin, int val);
void delay(unsigned long ms);
unsigned long millis();
void tone(int pin, unsigned int frequency);
void tone(int pin, unsigned int frequency, unsigned long duration);
void noTone(int pin);

class HardwareSerial {
public:
    void begin(long baud);
    void print(const char* s);
    void print(int val);
    void print(float val, int decimals = 2);
    void print(double val, int decimals = 2);
    void println(const char* s);
    void println(int val);
    void println(float val, int decimals = 2);
    void println(double val, int decimals = 2);
    void println();
};

extern HardwareSerial Serial;

#endif
