/*
 * Visit for more information: https://shop.m5stack.com/products/btc-standing-base-for-m5-core-with-sht30
 * Show temperature and humidity data from built-in SHT30 sensor
 * NB: this base unit does not have a pressure sensor
 * and you are not able to connect the ENVIII Unit to the M5Stack device
 * as there will be an I2C address conflict
 * modified and adapted from M5Stack original code
 * Date:      4 April 23
 * Version:   1.01
 * John
 * www.reflectingMe.uk is my www site.
 */
#include <M5Stack.h>
#include "M5_ENV.h"

SHT3X sht30; // create an instance of the SHT30 sensor class

float tmpC = 0.0;
float tmpF = 0.0;
float hum = 0.0;

void setup()
{
  M5.begin();            // Init M5Stack
  M5.Power.begin();      // Init power
  M5.lcd.setTextSize(3); // Set the text size to 3 for initial text
  Wire.begin();          // Wire init, adding the I2C bus

  M5.lcd.setTextColor(YELLOW);                                            // Initial text set to Yellow
  M5.Lcd.setTextDatum(CC_DATUM);                                          // Set text alignment to center
  M5.Lcd.drawString("M5Stack", M5.Lcd.width() / 2, 10);                   // Draw centered text
  M5.lcd.setTextSize(2);                                                  // Set the text size to 2
  M5.lcd.setTextColor(WHITE);                                             // white text
  M5.Lcd.drawString("M5Stack BCT Standing Base", M5.Lcd.width() / 2, 40); // Draw centered text
  M5.lcd.setTextColor(GREENYELLOW);                                       // green/yellow text
  M5.Lcd.drawString("with internal", M5.Lcd.width() / 2, 60);             // Draw centered text
  M5.Lcd.drawString("SHT30 Sensor", M5.Lcd.width() / 2, 80);              // Draw centered text
}

void loop()
{                         // check if sensor connected within if - else
  if (sht30.get() == 0)   // Obtain the data from sht30.
  {                       // then store data in variables declared above.
    tmpC = sht30.cTemp;   // Store the DegC temperature obtained from sht30.
    tmpF = sht30.fTemp;   // Store the Degf temperature obtained from sht30.
    hum = sht30.humidity; // Store the humidity obtained from the sht30.
  }
  else
  {
    tmpC = 0, tmpF = 0, hum = 0;
  }
  m5.lcd.drawRoundRect(10, 100, m5.lcd.width() - 20, 135, 10, YELLOW); // draw outline border
  m5.lcd.fillRoundRect(20, 110, 280, 35, 10, LIGHTGREY);               // draw background rectangles
  m5.lcd.fillRoundRect(20, 150, 280, 35, 10, LIGHTGREY);               // for each data item
  m5.lcd.fillRoundRect(20, 190, 280, 35, 10, LIGHTGREY);               // from the SHT30
  M5.lcd.setTextColor(BLACK);                                          // black text
  M5.lcd.setCursor(90, 120);                                           // position cursor for deg C
  M5.Lcd.printf("Temp C: %2.1f  \r\n", tmpC);                          // print deg C to screen
  M5.lcd.setCursor(90, 160);                                           // position cursor for deg f
  M5.Lcd.printf("Temp F: %2.1f  \r\n", tmpF);                          // print deg f to screen
  M5.lcd.setCursor(90, 200);                                           // position cursor for humidity
  M5.Lcd.printf("Humidity: %2.0f%%  \r\n", hum);                       // print humidity to screen
  delay(2000);
}
