// name Aditya
// Student I'D: 2210994754

#include <WiFiNINA.h>
#include <ThingSpeak.h>
#include "DHT.h"

char wifiname[] = "Sonika";         
char password[] = "12345678";     
unsigned long idofchannel =2252710 ;   
const char *APIwritekey = "IWVKYVWOM21V1ASO";

WiFiClient chart;
DHT dht(2, DHT22);

void setup()
 {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  while (WiFi.status() != WL_CONNECTED)

  {
    Serial.print("Connecting to WiFi: ");
    Serial.println(wifiname);
    WiFi.begin(wifiname, password);
    delay(1000);
  }

  Serial.println("WiFi Connection sucessful");

  ThingSpeak.begin(chart);

}


void loop() 

{
  
  float temp = dht.readTemperature();
  ThingSpeak.writeField(idofchannel, 1, temp, APIwritekey);

  
  delay(30000);
}