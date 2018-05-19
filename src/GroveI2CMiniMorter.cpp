/****************************************************************
Author: hiyo
Date: 2018/05/19
Description:
　これはGROVE I2C ミニモーターをArduinoで動かすときのライブラリです。
　データシートを見ると読み書きアドレスが1ビット右シフトしているとのことで、
　CH1, CH2のアドレスをそれぞれシフトさせて定義します。
****************************************************************/

#include <Arduino.h>
#include <Wire.h>
#include "GroveI2CMiniMorter.h"

// Define the regsiter address
GroveI2CMiniMoto::GroveI2CMiniMoto(byte addr)
{
  _addr = addr;
}

// Forward function
void GroveI2CMiniMoto::forwardDrive(int speed)
{
  byte data = 0x01;                // Hブリッジの論理制御より
  byte regValue = (byte)abs(speed); // マイナス値の場合は考慮しない
  if (regValue > 63) regValue = 63; // 上限設定
  writeRegister(0x00, regValue, data); 
}

// Reversal function
void GroveI2CMiniMoto::reversalDrive(int speed)
{
  byte data = 0x02;                // Hブリッジの論理制御より
  byte regValue = (byte)abs(speed); // マイナス値の場合は考慮しない
  if (regValue > 63) regValue = 63; // 上限設定
  writeRegister(0x00, regValue, data);  
}

// Stop function
void GroveI2CMiniMoto::stop()
{
  byte data = 0x00;                // Hブリッジの論理制御より
  writeRegister(0x00, 0x00, data);
}

// Brake function
void GroveI2CMiniMoto::brake()
{
  byte data = 0x03;                // Hブリッジの論理制御より
  writeRegister(0x00, 0x00, data); 
}

// Private function for Regsiter control
void GroveI2CMiniMoto::writeRegister(byte reg, byte buffer, byte data)
{
    int vdata = buffer << 2 | data;
    Wire.beginTransmission(_addr);
    Wire.write(reg);
    Wire.write(vdata);
    Wire.endTransmission(true);
}

void GroveI2CMiniMoto::readRegister(byte reg, byte buffer, byte data)
{
    //Unimplemented
}

