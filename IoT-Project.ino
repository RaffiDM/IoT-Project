#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

// DHT11 sensor settings
#define DHTPIN D5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Soil moisture sensor pin
#define SOIL_MOISTURE_PIN A0

// WiFi credentials
const char* ssid = "WIFI_NAME";          // Replace with your WiFi SSID
const char* password = "WIFI_PASSWORD";  // Replace with your WiFi Password

// ThingSpeak settings
unsigned long myChannelNumber = CHANNEL_NUMBER;  // Replace with your ThingSpeak Channel Number
const char* myWriteAPIKey = "API_KEY";  // Replace with your ThingSpeak Write API Key

WiFiClient client;

void setup(){
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();

  // initialize DHT sensor
  dht.begin();

  // initialize serial communication
  Serial.begin(115200);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize ThingSpeak
  ThingSpeak.begin(client);
}

void loop(){
  // read temperature and humidity from DHT11
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // read soil moisture level
  int soilMoistureValue = analogRead(SOIL_MOISTURE_PIN);

  // check if any reads failed and exit early (to try again)
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // print data to serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  Serial.print("Soil Moisture: ");
  Serial.println(soilMoistureValue);

  // display temperature and humidity on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(humidity);
  lcd.print(" %");

  delay(2000); // wait 2 seconds before updating the display

  // display soil moisture on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture:");
  lcd.setCursor(0, 1);
  lcd.print(soilMoistureValue);

  delay(2000); // wait 2 seconds before updating the display

  // Send data to ThingSpeak
  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);
  ThingSpeak.setField(3, soilMoistureValue);

  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if (x == 200) {
    Serial.println("Channel update successful.");
  } else {
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }

  delay(20000); // ThingSpeak allows updates every 15 seconds
}
