/*************************************************************************************************
                                      PROGRAMMINFO
**************************************************************************************************
Funktion: ESP32 Wasseranalyse mit dem TDS Sensor 

**************************************************************************************************
Version: 09.04.2022
**************************************************************************************************
Board: ESP32vn IoT UNO
**************************************************************************************************
C++ Arduino IDE V1.8.19
**************************************************************************************************
Einstellungen:
https://dl.espressif.com/dl/package_esp32_index.json
http://dan.drown.org/stm32duino/package_STM32duino_index.json
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_dev_index.json
**************************************************************************************************
 * TDS Sensor ESP32
    GND GND
    VCC 3.3V
    Data  GPIO 27 (or any other ESP32 ADC pin)

    OLED Display an I2C PIN 21 22
**************************************************************************************************
Zeichentabelle: https://www.utf8-zeichentabelle.de/unicode-utf8-table.pl
************************************************************************************************** */

#define TdsSensorPin 27
#define VREF 3.3              // analog reference voltage(Volt) of the ADC
#define SCOUNT  30            // sum of sample point

#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

int analogBuffer[SCOUNT];     // store the analog value in the array, read from ADC
int analogBufferTemp[SCOUNT];
int analogBufferIndex = 0;
int copyIndex = 0;

float averageVoltage = 0;
float tdsValue = 0;
float temperature = 25;       // current temperature for compensation

// Median-Filteralgorithmus
int getMedianNum(int bArray[], int iFilterLen){
  int bTab[iFilterLen];
  for (byte i = 0; i<iFilterLen; i++)
  bTab[i] = bArray[i];
  int i, j, bTemp;
  for (j = 0; j < iFilterLen - 1; j++) {
    for (i = 0; i < iFilterLen - j - 1; i++) {
      if (bTab[i] > bTab[i + 1]) {
        bTemp = bTab[i];
        bTab[i] = bTab[i + 1];
        bTab[i + 1] = bTemp;
      }
    }
  }
  if ((iFilterLen & 1) > 0){
    bTemp = bTab[(iFilterLen - 1) / 2];
  }
  else {
    bTemp = (bTab[iFilterLen / 2] + bTab[iFilterLen / 2 - 1]) / 2;
  }
  return bTemp;
}

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
unsigned long delayTime;

void setup(){
  Serial.begin(115200);
  u8g2.begin();
  pinMode(TdsSensorPin,INPUT);
}

void loop(){
  static unsigned long analogSampleTimepoint = millis();
  if(millis()-analogSampleTimepoint > 40U){     //alle 40 Millisekunden den Analogwert vom ADC lesen
    analogSampleTimepoint = millis();
    analogBuffer[analogBufferIndex] = analogRead(TdsSensorPin);    //Den Analogwert lesen und im Buffer speichern
    analogBufferIndex++;
    if(analogBufferIndex == SCOUNT){ 
      analogBufferIndex = 0;
    }
  }   
  
  static unsigned long printTimepoint = millis();
  if(millis()-printTimepoint > 800U){
    printTimepoint = millis();
    for(copyIndex=0; copyIndex<SCOUNT; copyIndex++){
      analogBufferTemp[copyIndex] = analogBuffer[copyIndex];
      
      // In einen Spannungsert konvertieren
      averageVoltage = getMedianNum(analogBufferTemp,SCOUNT) * (float)VREF / 4096.0;
      
      //Temperaturkompensationsformel: fFinalResult(25^C) = fFinalResult(current)/(1.0+0.02*(fTP-25.0)); 
      float compensationCoefficient = 1.0+0.02*(temperature-25.0);
      //Temoeratur Kompensation
      float compensationVoltage=averageVoltage/compensationCoefficient;
      
      //convert voltage value to tds value
      tdsValue=(133.42*compensationVoltage*compensationVoltage*compensationVoltage - 255.86*compensationVoltage*compensationVoltage + 857.39*compensationVoltage)*0.5;
      
      Serial.print("Sensor Spannung:");
      Serial.print(averageVoltage,2);
      Serial.print("V   ");
      Serial.print("TDS Wert:");
      Serial.print(tdsValue,0);
      Serial.println(" ppm");
    }
  }


 u8g2.setFont(u8g2_font_courR10_tf);
    u8g2.firstPage();

    do {
      
      u8g2.setCursor(1, 10);

      u8g2.print("Wasserqualit");
      u8g2.print("\xE4");
      u8g2.print("t");      
      u8g2.setCursor(30, 30);
      u8g2.print("TDS Wert:");


      u8g2.setFont(u8g2_font_courB14_tf);
      u8g2.setCursor(20, 55);
      u8g2.print(tdsValue,0);
 //     u8g2.setCursor(20, 55);
      u8g2.print(" ppm");


      } while ( u8g2.nextPage() );
     delay(delayTime);
}
