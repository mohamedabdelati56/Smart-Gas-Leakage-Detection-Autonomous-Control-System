# 🛡️ Smart Gas Leakage Detection & Autonomous Control System (IoT/GSM)

An advanced safety solution built with **Arduino UNO** to detect gas leakages (LPG, Butane, Smoke) and take immediate autonomous actions to prevent fire hazards.

---

## 📖 Overview
This project is an integrated safety system designed for environments where Wi-Fi might be unreliable. It monitors gas concentration in real-time and, upon detecting a leak, it triggers a local alarm, updates a **16x4 LCD**, sends an **SMS alert** via **GSM**, and physically shuts off the gas supply using a **12V Solenoid Valve**.

---

## 🛠️ Hardware Components
The system utilizes high-quality components to ensure stability and high current handling:

* **Microcontroller:** Arduino UNO SMD.
* **Gas Sensor:** MQ-2 Module (Combustible gas & smoke detection).
* **Communication:** GSM GPRS Module SIM900A.
* **Display:** 16x4 LCD with I2C Serial Interface.
* **Actuators:** * 12V Electric Gas Solenoid Valve (Shut-off mechanism).
    * 5V Single Channel Relay Module (Valve control).
* **Alarms:** 5V Active Buzzer & 5mm Bi-color LED.
* **Power:** 12V 5A DC Power Adapter (To handle GSM spikes and Valve power).
* **Prototyping:** 400-point Breadboard, 10x 174W Resistors, and Jumper Wires (M-M/F-F).



---

## 🚀 Key Features
* **Autonomous Shut-off:** Automatically closes the main gas valve via a relay when a leak is detected.
* **Remote SMS Notification:** Sends an emergency SMS to a pre-configured mobile number using the SIM900A module.
* **Enhanced Visualization:** Displays real-time PPM levels and system status on a 16x4 character display.
* **Robust Power Design:** Optimized to run high-current peripherals (GSM & Valve) using a 5A external supply.
* **Local Audio-Visual Alerts:** Instant feedback through a buzzer and LED indicators.

---

## ⚙️ System Logic & Workflow
1.  **Sensing:** The MQ-2 sensor constantly monitors the air.
2.  **Analysis:** Arduino processes the analog signal and compares it against a safety threshold.
3.  **Action (Leak Detected):** * **Relay** switches **ON** to close the **Solenoid Valve**.
    * **GSM Module** sends an "EMERGENCY: GAS LEAK!" SMS.
    * **Buzzer** activates and **LCD** shows a "DANGER" warning.
4.  **Recovery:** The system remains locked until the gas level drops below the threshold for safety.



---

## 🔧 Installation & Setup
1.  **Clone the Repo:**
    ```bash
    git clone [https://github.com/mohamedabdelati56/Smart-Gas-Leakage-Detection-Autonomous-Control-System.git](https://github.com/mohamedabdelati56/Smart-Gas-Leakage-Detection-Autonomous-Control-System.git)
    ```
2.  **Hardware Wiring:** Follow the schematics provided in the `/assets` folder.
3.  **Library Installation:** Ensure you have `LiquidCrystal_I2C` and `SoftwareSerial` libraries installed in your Arduino IDE.
4.  **Configuration:** Update the mobile number in the code:
    ```cpp
    char target_phone_number[] = "+201022364072"; 
    ```
5.  **Upload:** Connect your Arduino UNO and hit **Upload**.

---

## ⚠️ Important Notes
* **Power Supply:** Do NOT power the SIM900A via the Arduino's 5V pin. Use the provided **12V 5A adapter** to avoid system resets during SMS transmission.
* **Calibration:** Rotate the potentiometer on the back of the MQ-2 sensor to adjust the sensitivity based on your environment.

---

## 📄 License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

**Developed by [Your Name/Username]** *Feel free to star ⭐ this repository if you found it helpful!*