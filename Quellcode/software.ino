#include <Blynk.h>
#define BLYNK_Print Serial

/***************************************************
  This is a library example for the MLX90614 Temp Sensor

  Designed specifically to work with the MLX90614 sensors in the
  adafruit shop
  ----> https://www.adafruit.com/products/1747 3V version
  ----> https://www.adafruit.com/products/1748 5V version

  These sensors use I2C to communicate, 2 pins are required to
  interface
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Adafruit_MLX90614.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <WiFiManager.h>
#include <BlynkSimpleEsp8266.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

  char auth[] = "rF0gN-Zo20v2XaCYwyDCLaqGx6aMTDcx";
  char ssid[] = "";  //Your SSID
  char pass[] = ""; // your Wifi password
  int slidervalue;

 BLYNK_WRITE(V1)
{
 double i = param.asDouble();
 int buttonstate = 0;
 
buttonstate = BLYNK_WRITE(V2);

 if (buttonstate == 1) {
    Blynk.virtualWrite(V3, i);
  }

 Serial.println(i);
  
} 

void setup() {
  Serial.begin(115200);
  //WifiManager setup
   /*WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP
    // it is a good practice to make sure your code sets wifi mode how you want it.

    Serial.begin(115200);
    
    //WiFiManager, Local intialization
    WiFiManager wm;

    // reset settings - wipe stored credentials for testing
    // these are stored by the esp library
    //wm.resetSettings();

    bool res;
     res = wm.autoConnect(); // auto generated AP name from chipid
    // res = wm.autoConnect("AutoConnectAP"); // anonymous ap

    if(!res) {
        Serial.println("Failed to connect");
        // ESP.restart();
    } 
    else {
        //if you get here you have connected to the WiFi    
        Serial.println("connected...yeey :)");
    }
    
  // Your WiFi credentials.*/

  Blynk.begin(auth, ssid, pass, "iot.informatik.uni-oldenburg.de", 8080);

  //Temperatur
  while (!Serial);

  Serial.println("Adafruit MLX90614 test");

  if (!mlx.begin()) {
    Serial.println("Error connecting to MLX sensor. Check wiring.");
    while (1);// hier an Blynk weitergeben: Keine Tasse
  };

  Serial.print("Emissivity = "); Serial.println(mlx.readEmissivity());
  Serial.println("================================================");
}

void loop() {
  Blynk.run();
  
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC());
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF());
  Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");
//  Serial.println(i+"");

  //Blynk
  Blynk.virtualWrite(V0, mlx.readObjectTempC()); // gibt an V0 die aktuelle Temperatur weiter
  
   // wenn 5 mal kein wert dann sagen, dass tasse genommen wurde
   
  Serial.println();
  delay(2000);
  
}
