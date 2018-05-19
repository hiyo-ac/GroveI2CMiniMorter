/****************************************************************
Author: hiyo
Date: 2018/05/19
Description:
　これはGROVE I2C ミニモーターをArduinoで動かすときのライブラリです。
　データシートを見ると読み書きアドレスが1ビット右シフトしているとのことで、
　CH1, CH2のアドレスをそれぞれシフトさせて定義します。
****************************************************************/

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
  byte regValue = (byte)abs(speed); // マイナス値の場合は考慮しない
  if (regValue > 63) regValue = 63; // 上限設定
  writeRegister(CTR_ADR, regValue, M_FORWARD); 
}

// Reversal function
void GroveI2CMiniMoto::reversalDrive(int speed)
{
  byte regValue = (byte)abs(speed); // マイナス値の場合は考慮しない
  if (regValue > 63) regValue = 63; // 上限設定
  writeRegister(CTR_ADR, regValue, M_REVERSE);  
}

// Stop function
void GroveI2CMiniMoto::stop()
{
  writeRegister(CTR_ADR, 0x00, M_STOP);
}

// Brake function
void GroveI2CMiniMoto::brake()
{
  writeRegister(CTR_ADR, 0x00, M_BRAKE); 
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

