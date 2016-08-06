/*
  BME280_SPI.h - for ESP-WROOM-02 ( esp8266 ) or Arduino
  Beta version 1.0
  
License MIT [Modified person is Mgo-tec.]

Original License is BSD [Copyright (c) 2012, Adafruit Industries]

BSD License:
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holders nor the
names of its contributors may be used to endorse or promote products
derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef BME280_SPI_h_
#define BME280_SPI_h_
#include "Arduino.h"

class BME280_SPI
{
public:
  BME280_SPI(uint8_t sclk, uint8_t mosi, uint8_t miso, uint8_t cs);
  
  void BME280_SPI_Init(uint8_t Stanby_t, uint8_t filter, uint8_t overS_T, uint8_t overS_P, uint8_t overS_H, uint8_t mode);
  void WriteRegister(uint8_t reg_address, uint8_t data);
  void ReadCalibration(void);
  double Read_Temperature();
  double Read_Pressure();
  double Read_Humidity();
  double ReadAltitude(double SeaLevel_Pres, double pressure);
  
  int32_t compensate_T(int32_t adc_T);
  uint32_t compensate_P(int32_t adc_P);
  uint32_t compensate_H(int32_t adc_H);
  uint16_t read16bit(uint8_t reg);
  uint8_t read8bit(uint8_t reg);
  void SpiWrite(uint8_t data);
  uint8_t SpiRead();

private:
  uint8_t _sclk, _mosi, _miso, _cs;
};

#endif