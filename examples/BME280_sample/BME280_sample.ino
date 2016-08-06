#include <BME280_SPI.h>

const uint8_t sclk = 14;
const uint8_t mosi =13; //Master Output Slave Input ESP8266=Master,BME280=slave 
const uint8_t miso =12; //Master Input Slave Output
const uint8_t cs_bme = 15; //CS pin

BME280_SPI bme280spi(sclk, mosi, miso, cs_bme);

uint32_t M_time1;

void setup() {
  Serial.begin(115200);
  
  uint8_t t_sb = 5; //stanby 1000ms
  uint8_t filter = 0; //filter O = off
  uint8_t osrs_t = 4; //OverSampling Temperature x4
  uint8_t osrs_p = 4; //OverSampling Pressure x4
  uint8_t osrs_h = 4; //OverSampling Humidity x4
  uint8_t Mode = 3; //Normal mode
 
  bme280spi.BME280_SPI_Init(t_sb, filter, osrs_t, osrs_p, osrs_h, Mode);
  delay(1000);

  Serial.println();

  M_time1 = 2000;

}
//******************メインループ************************************
void loop() {
  double temperature = 0.0, pressure = 0.0, humidity = 0.0;
  
  if(millis()-M_time1 > 2000){
    temperature = bme280spi.Read_Temperature();
    pressure = bme280spi.Read_Pressure();
    humidity = bme280spi.Read_Humidity();
    
    Serial.println("-----------------------");
    Serial.print("Temperature = "); Serial.print(temperature); Serial.println(" *C");
    Serial.print("Humidity = "); Serial.print(humidity); Serial.println(" %");
    Serial.print("Pressure = "); Serial.print(pressure); Serial.println(" hPa");

    M_time1 = millis();
  }
}
