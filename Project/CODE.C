
#define BLYNK_TEMPLATE_ID "YOUR TEMPLATE ID"
#define BLYNK_TEMPLATE_NAME "plant watering system"
#define BLYNK_AUTH_TOKEN "YOUR BLYNK AUTH TOKEN" 

/*Plant watering system with new blynk update
   https://srituhobby.com //ignore
*/

//Include the library files //Install the libraries first.
#include <LiquidCrystal_I2C.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <DFRobot_DHT11.h>

//Initialize the LCD display
LiquidCrystal_I2C lcd(0x27, 16, 2);

char auth[] = "your auth token";//Enter your Auth token
char ssid[] = "your 2.4ghz connection name";//Enter your WIFI name
char pass[] = "wifi password";//Enter your WIFI password

BlynkTimer timer;
bool Relay = 0;
bool Relay2 = 0;

//Define component pins
#define sensor A0
#define waterPump D3
#define nwaterpump D0

//dht
#define DHTPIN D4 // DHT11 sensor pin
#define DHTTYPE DHT11 // DHT11 sensor type

//dht setup
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(waterPump, OUTPUT);
  digitalWrite(waterPump, HIGH);
  pinMode(nwaterpump, OUTPUT);
  digitalWrite(nwaterpump, HIGH);
  lcd.init();
  lcd.backlight();

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

  lcd.setCursor(1, 0);
  lcd.print("hello humans!");
  for (int a = 0; a <= 15; a++) {
    lcd.setCursor(a, 1);
    lcd.print(".");
    delay(500);
  }
  lcd.clear();

  //Call the function
  timer.setInterval(100L, soilMoistureSensor);
}

//Get the button value
BLYNK_WRITE(V1) {
  Relay = param.asInt();

  if (Relay == 1) {
    digitalWrite(waterPump, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Motor is ON ");
  } else {
    digitalWrite(waterPump, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Motor is OFF");
  }
}

//get 2nd motor value 
 BLYNK_WRITE(V3) {
  Relay2 = param.asInt();

  if (Relay2 == 1) {
    digitalWrite(nwaterpump, LOW);
    lcd.setCursor(0, 1);
    lcd.print("N Motor is ON ");
  } else {
    digitalWrite(nwaterpump, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("N Motor is OFF");
  }
}


//Get the soil moisture values
void soilMoistureSensor() {
  int value = analogRead(sensor);
  value = map(value, 0, 1024, 0, 100);
  value = (value - 100) * -1;

  Blynk.virtualWrite(V0, value);
  lcd.setCursor(0, 0);
  lcd.print("Moisture :");
  lcd.print(value);
  lcd.print(" ");

}

void loop() {
  Blynk.run();//Run the Blynk library
  timer.run();//Run the Blynk timer


  //dht loop
  Blynk.run();

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C\t");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Blynk.virtualWrite(V4, temperature); // Send temperature value to Virtual Pin V1
  Blynk.virtualWrite(V5, humidity); // Send humidity value to Virtual Pin V2
 

  delay(3000); // Read sensor data every 5 seconds
}

