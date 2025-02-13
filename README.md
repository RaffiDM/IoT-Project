# IoT-based Plant Monitoring System

An IoT-based plant monitoring system that uses a DHT11 sensor to measure air temperature and humidity, as well as a soil moisture sensor to monitor soil conditions. Sensor data is displayed on the LCD and sent to the ThingSpeak platform for remote monitoring via a web interface.

## 🎥 Demonstration Video

[Click here to view a video demonstration](https://drive.google.com/file/d/1tCe8BH0bTPcf2D5vWNAoq-kIpiHsfWGw/view?usp=sharing)

## 📸 Preview Web Interface

![Preview Web Interface](https://github.com/RaffiDM/IoT-Project/blob/main/assets/img/Preview1.png?raw=true) 
![Preview Web Interface](https://github.com/RaffiDM/IoT-Project/blob/main/assets/img/Preview2.png?raw=true) 



## 📁 Project Structure

```
IoT-Project/
├── IoT-Project.ino
├── index.html
├── README.md
└── assets/
    ├── css/
    │   └── style.css
    └── img/
```

## 🔧 Required Components

- NodeMCU ESP8266
- DHT11 Sensor
- Soil Moisture Sensor
- LCD I2C 16x2
- Jumper Cables
- Breadboard

## 📋 Feature

- Monitoring air temperature and humidity using the DHT11 sensor
- Monitoring soil moisture
- Real-time data display on 16x2 LCD
- Automatic data sending to ThingSpeak
- Web interface for remote monitoring
- Update data every 20 seconds

## ⚙️ Configuration

1. Open `IoT-Project.ino` file
2. Configure WiFi Credentials:
   ```cpp
   const char* ssid = "WIFI_NAME";
   const char* password = "WIFI_PASSWORD";
   ```
3. ThingSpeak Configuration:
   ```cpp
   unsigned long myChannelNumber = CHANNEL_NUMBER;
   const char* myWriteAPIKey = "API_KEY";
   ```

## 📌 Pin Configuration

- DHT11: D5
- Soil Moisture Sensor: A0
- LCD I2C: 
  - SDA: D2
  - SCL: D1

## 🚀 How to Use

1. Connect all components according to the configuration pins
2. Upload `IoT-Project.ino` code to NodeMCU using Arduino IDE
3. Make sure the NodeMCU is connected to the WiFi network
4. Open the web interface to view real-time monitoring data
5. Data can also be accessed via the ThingSpeak platform

## 📊 Monitoring Data

Sensor data can be monitored via:
1. LCD installed on the tool
2. Local web interface
3. ThingSpeak Platform

## 🛠️ Troubleshooting

- Make sure all the required libraries are installed in the Arduino IDE
- Check WiFi connection if data is not being sent to ThingSpeak
- Check the I2C address of the LCD if the LCD display does not appear

## 📚 Libraries Used

- LiquidCrystal_I2C
- DHT
- ESP8266WiFi
- ThingSpeak

## 📝 Author

**Raffi Dzaky Mahendra**
