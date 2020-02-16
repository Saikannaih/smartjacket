#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 8

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);
int rpin = 4;
float Celsius1 = 0;//
float Fahrenheit1 = 0;
float Celsius2 = 0;
float Fahrenheit2 = 0;
int deviceCount=0;
void setup() {
  pinMode(rpin,OUTPUT);
  sensors.begin();
  Serial.begin(9600);
  deviceCount=sensors.getDeviceCount();
  Serial.print(deviceCount,DEC);
  Serial.println("sensors");
}

void loop() {
  sensors.requestTemperatures();

  Celsius1 = 4+sensors.getTempCByIndex(0);
  Fahrenheit1 = sensors.toFahrenheit(Celsius1);

  Celsius2 = 3.5+sensors.getTempCByIndex(1);
  Fahrenheit2 = sensors.toFahrenheit(Celsius2);
  Serial.print("sensor1:");
  Serial.print(Celsius1);
  Serial.print(" C  ");
  Serial.print(Fahrenheit1);
  Serial.println(" F");
  Serial.print("sensor2:");
  Serial.print(Celsius2);
  Serial.print(" C  ");
  Serial.print(Fahrenheit2);
  Serial.println(" F");
  if (Celsius1<Celsius2+3)//here as our second sensor is not working we are going to replace celsius 2 by our body temperature
    {digitalWrite(rpin,HIGH);}
    else
    digitalWrite(rpin,LOW);
  delay(1000);
}
 
