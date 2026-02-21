#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
// Set the LCD address to 0x27 for a 20 chars and 3 line display
LiquidCrystal_I2C lcd(0x27, 20, 4);
SoftwareSerial gsmSerial(9, 10); // RX, TX
int gsmBaudRate = 9600;
int GasSensor = A1; // Assigning the port number used for the sensor
int gasValue; // gas sensor reading value
String message; // message to be sent
int Relay = 4;  // Assigning the port number used to control the relay
int Buzzer = 3; //buzzer to arduino pin 3
int Led = 2;  // Example 01 : Blinking LED

Void setup() {
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  GSM.begin(9600); // Initializing the GSM module
  pinMode(GasSensor, INPUT);
  pinMode(Relay, OUTPUT);// Setting the port used for the relay as output
  pinMode(Buzzer, OUTPUT); // Set buzzer - pin 3 as an output
  pinMode(Led, OUTPUT);
  lcd.init();
  // Robojax code for LCD with I2C
	// initialize the LCD, 
	lcd.begin();
	// Turn on the blacklight and print a message.
	lcd.backlight();
  // Robojax code for LCD with I2C  Lcd.setCursor(0, 0);
  Lcd.print("           ");
  Lcd.setCursor(0, 1);
  Lcd.print("Initiating… ");
  gsmSerial.begin(gsmBaudRate);
  delay(1000);
  gsmSerial.println("AT");
  delay(1000);
  Serial.println("AT+CMGF=1");
  SIM900A.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.Begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  Serial.println ("SIM900A Ready");
  delay(100);
  Serial.println ("Type s to send message or r to receive message");
}
Void loop() {
  int gasValue = analogRead(GasSensor);  // Reading the value of the sensor
  if (gasValue > 400) {
    // If a gas leak is detected
    digitalWrite(Relay, LOW);  // Closing the valve
    digitalWrite(Buzzer, LOW);
    digitalWrite(Led, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Gas Leakage: YES");
    lcd.print(gasValue);
    lcd.print("        ");
    sendSMS();
    //lcd.print(millis() / 1000);
    delay(500);
    //end of loopcode Robojax code for LCD with I2C
   } if (Serial.available()>0) switch(Serial.read()){
	    case 's':
	      SendMessage();
	      break;
	    case 'r':
	      RecieveMessage();
	      break;
	  }
	 if (SIM900A.available()>0)
	   Serial.write(SIM900A.read());
   else{
    // If no gas leak is detected
    digitalWrite(Relay, HIGH);  // Opening the valve
    digitalWrite(Buzzer, HIGH);
    digitalWrite(Led, LOW);
    //start of loop Robojax code for LCD with I2C
    lcd.clear();
    lcd.setCursor (0,1); // go to start of 2nd line
    lcd.print("             ");
      //lcd.print(millis() / 1000);
  }
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sec
  }
Void sendMessage() {
  Serial.println ("Sending Message");
  message = "Gas Leak Detected! "; // Setting the message to be sent
  SIM900A.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);
  Serial.println ("Set SMS Number");
  SIM900A.println("AT+CMGS=\"+201022364072\"\r"); //Mobile phone number to send message
  delay(1000);
  SIM900A.println(message); // Inserting the message text
  Serial.println ("Set SMS Content");
  SIM900A.println("Good morning, how are you doing?");// Messsage content
  delay(1000);
  Serial.println("gasValue");
  SIM900A.println((char)26); // Sending the message
  delay(1000);
  Serial.println ("Message has been sent ->SMS Selesai dikirim");
}
void RecieveMessage() {
	  Serial.println ("SIM900A Membaca SMS");
	  delay (1000);
	  SIM900A.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
	  delay(1000);
	  Serial.write ("Unread Message done");
	 }
