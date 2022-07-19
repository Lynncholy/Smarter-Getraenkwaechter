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
char pass[] = ""; // your WiFi password
int slidervalue = 0;
int teaProfile = 0;
int coffeeProfile = 0;
int otherDrinkProfile = 0;
int chooseProfilePressed = 0;
int saveProfilePressed = 0;
int profile = 0; //1, 2 or 3
int activeProfile = 0;

BLYNK_WRITE(V1)
{
  double i = param.asDouble();
  slidervalue = i;
  profile = slidervalue;
  Blynk.virtualWrite(V3, profile);

  Serial.println(i);

}

//saving profile (not functional)
BLYNK_WRITE(V5)
{
  int i = param.asInt();
  chooseProfilePressed = i;
  if ((chooseProfilePressed == 1) && (teaProfile == profile)) { //if press the choose button, value of teaprofile is displayed
          //profile = teaProfile;
          Blynk.virtualWrite(V3, teaProfile);
        }
}

BLYNK_WRITE(V6)
{
  int i = param.asInt();
  saveProfilePressed = i;
  if ((saveProfilePressed == 1) && (profile == 1)) { //if you press the save button, value of slider is saved to chosen profile
    teaProfile = slidervalue;
  }
  if ((saveProfilePressed == 1) && (profile == 2)) { //if you press the save button, value of slider is saved to chosen profile
    coffeeProfile = slidervalue;
  }
  if ((saveProfilePressed == 1) && (profile == 3)) { //if you press the save button, value of slider is saved to chosen profile
    otherDrinkProfile = slidervalue;
  }
}

BLYNK_WRITE (V4) {
  profile = param.asInt();
  switch (param.asInt()) {
    case 1: {
        break;
      }
    case 2: {
        coffeeProfile = slidervalue;
        break;
      }

    case 3: {
        otherDrinkProfile = slidervalue;
        break;
      }

  }
}

//---------------------------

void setup() {
  Serial.begin(115200);
  //WifiManager setup
  WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP
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

  if (!res) {
    Serial.println("Failed to connect");
    // ESP.restart();
  }
  else {
    //if you get here you have connected to the WiFi
    Serial.println("connected...yeey :)");
  }

  // Your WiFi credentials.

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

  //to monitor variables
  Serial.print("slidervalue ="); Serial.print(slidervalue);
  Serial.print("teaProfile ="); Serial.print(teaProfile);
  Serial.print("coffeeProfile ="); Serial.print(coffeeProfile);
  Serial.print("chooseProfilePressed ="); Serial.print(chooseProfilePressed);
  Serial.print("saveProfilePressed ="); Serial.print(saveProfilePressed);
  Serial.print("profile ="); Serial.print(profile);
  Serial.println();
  Serial.print("chosenProfile for switch = "); Serial.print(profile);


  //Blynk
  Blynk.virtualWrite(V0, mlx.readObjectTempC()); //displays current temperature on V0 (Blynk)

  if (mlx.readObjectTempC() < slidervalue) // Notificate if current temperature is below set temperature
  {
    Blynk.notify("Achtung! Deine Wunschtemperatur wurde jetzt erreicht!");
  }


  Serial.println();
  delay(2000);

}
