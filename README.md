
# 🚜 AGRICULTURAL SOWING MACHINE & MONITORING SYSTEM (AGRO SMMS)

[![Platform](https://img.shields.io/badge/Platform-ESP32-blue)](https://www.espressif.com/en/products/socs/esp32) 
[![Language](https://img.shields.io/badge/Language-C++-green)](https://www.arduino.cc/en/software) 
[![Research DOI](https://img.shields.io/badge/DOI-10.56726/IRJMETS52128-red)](https://www.doi.org/10.56726/IRJMETS52128)

**Smart Farming Meets Innovation**
AGRO SMMS is a **robotic precision agriculture system** that modernizes traditional sowing methods. Combining automation, environmental sensing, and real-time analytics, it ensures **accurate seed placement**, **optimized soil conditions**, and **higher yields**, paving the way for **sustainable agriculture**.



---

## 🔧 How It Works

1. **🌱 Field Preparation & Seed Loading** – Prepare the soil and load seeds into the robotic system.
2. **⚙️ Calibration** – Adjust settings for **uniform seed spacing** and **optimal depth**.
3. **🚀 Precision Sowing** – Automated sowing ensures **accurate germination**.
4. **📊 Real-Time Monitoring** – Tracks **soil moisture**, **temperature**, and **humidity**.
5. **🧠 Intelligent Feedback Loop** – Adjusts seed distribution and sowing parameters on-the-go.
6. **📈 Post-Analysis** – Generates reports to improve future crop management decisions.

---

## 🌟 Key Features

* 🤖 **Automated Robotic Sowing** with **remote-controlled web interface**
* 🌡️ **Environmental Monitoring** for temperature, humidity, and soil moisture
* 🌐 **IoT-Enabled** with ESP32 wireless communication
* 💧 **Smart Irrigation Management** using soil moisture data
* 📦 **Modular Design** for flexible upgrades

---

## 🛠️ Tech Stack & Tools

| Component          | Description                                            |
| ------------------ | ------------------------------------------------------ |
| 🖥️ Arduino IDE    | Programming interface for ESP32 & sensors              |
| 🧠 ESP32           | Microcontroller with WiFi/BLE                          |
| 💡 Sensors         | Soil Moisture (REES52), Temperature & Humidity (DHT11) |
| 📶 IoT Integration | Remote monitoring & web-based control                  |
| 🧾 C++             | Embedded logic & sensor handling                       |

---

## 🖥 Hardware & System Design

### a. Hardware Overview

* **Seed Hopper & Tube System** – Precise seed storage and placement
* **Seed Metering Mechanism** – Controls seed distribution accurately
* **Furrow Openers & Adjustable Wheels** – Ensures uniform depth and spacing
* **12V Servo Motors & Drive Mechanism** – Motorized movement for sowing
* **Wireless Monitoring** – ESP32 transmits sensor data for real-time feedback

---

### b. ESP32 Pin Connections

```
        ESP32
   ----------------
   |              |
   |  DHT11   -> DHT_SENSOR_PIN 14
   |  Moisture Sensor -> MOISTURE_SENSOR_PIN 12
   |
   |  Motor A:
   |     ENA -> 0
   |     IN1 -> 5
   |     IN2 -> 18
   |
   |  Motor B:
   |     IN3 -> 19
   |     IN4 -> 21
   |     ENB -> 2
   |
   |  Built-in LED -> LED_BUILTIN
   ----------------
```

---

## 📊 Sensor Data Example

| Time (min) | Soil Moisture (%) | Temperature (°C) |
| ---------- | ----------------- | ---------------- |
| 0          | 45                | 28               |
| 10         | 50                | 28.5             |
| 20         | 55                | 29               |
| 30         | 53                | 28.7             |

---


## 🌐 Web Interface Preview 

<img width="300" height="300" alt="image" src="https://github.com/user-attachments/assets/4ee4d191-42ba-4bf9-aac0-7ee2363477ba" />

---
## 💡 Results & Impact

* Improved **crop yields** and **resource utilization**
* Enabled **data-driven decision-making**
* Promoted **precision agriculture** and **sustainable practices**
* Simplified **problem diagnosis** and field management

---

## 🔮 Future Enhancements

* Solar-powered operation for remote fields
* Mobile app for live monitoring and alerts
* AI-based crop growth prediction and automated adjustment
* Integration with additional environmental sensors

---

## 📂 Code & Files

* [Sensors-Final.ino](Sensors-Final.ino) – Arduino & ESP32 motor and sensor control code
* AGROTECH.jpg – Project image

---

## 📰 Research Paper Reference

**Title:** Agricultural Sowing Machine and Monitoring System
**Journal:** International Research Journal of Modernization in Engineering Technology and Science (IRJMETS)
**Volume/Issue:** 06/04/April-2024
**Impact Factor:** 7.868
**DOI:** [https://www.doi.org/10.56726/IRJMETS52128](https://www.doi.org/10.56726/IRJMETS52128)

**Abstract:**
The system integrates machine learning and IoT to optimize agricultural research. It analyzes crop interactions, improves yield, and supports sustainable practices. Using AI algorithms and large datasets, it enables **precision sowing**, **real-time monitoring**, and **data-driven decision making**, addressing global food demands and climate change challenges.

**Keywords:** ESP32, Seed Sowing, Temperature Sensor, Soil Moisture Sensor, 12V Servo Motors
---
### ✅ Project Impact

“Empowering farmers with precision agriculture and smart monitoring for a sustainable future.”
---
