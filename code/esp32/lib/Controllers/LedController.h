
#ifndef LedController_h
#define LedController_h

#include <Arduino.h>
#include <Wire.h>
#include "settings.h"

class LedController {
public:
    LedController();
    ~LedController();
    void begin();

    void setLeds(byte port0, byte port1);
    void runLedPattern(int patternNum);

    void setLed(int ledNum, bool state);
    void toggleLed(int ledNum);

    void allOn();
    void allOff();

    byte getPort0State() const { return _port0State; };
    byte getPort1State() const { return _port1State; };

private:

    bool getLedMaskAndPort(int ledNum, byte &ledmask, byte* &portState);

    byte _port0State;
    byte _port1State;
};

#endif