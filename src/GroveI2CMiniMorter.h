/****************************************************************
Author: hiyo
Date: 2018/05/19
Description:
　これはGROVE I2C ミニモーターをArduinoで動かすときのライブラリです。
　データシートを見ると読み書きアドレスが1ビット右シフトしているとのことで、
　CH1, CH2のアドレスをそれぞれシフトさせて定義します。
****************************************************************/


#ifndef GroveI2CMiniMorter_h
#define GroveI2CMiniMorter_h

#include <Arduino.h>

// Define register address
#define CTR_ADR   0x00
#define FLT_ADR   0x01

// Define bridge control
#define M_STOP    0x00
#define M_FORWARD 0x01
#define M_REVERSE 0x02
#define M_BRAKE   0x03

class GroveI2CMiniMoto
{
  public:
    GroveI2CMiniMoto(byte addr);
    void forwardDrive(int speed);
    void reversalDrive(int speed);
    void stop();
    void brake();
  private:
    void writeRegister(byte addr, byte buffer, byte data);
    void readRegister(byte addr, byte buffer, byte data);
    byte _addr;
};

#endif