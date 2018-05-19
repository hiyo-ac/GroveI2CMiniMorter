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
#include <Wire.h>

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