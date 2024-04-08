 #include <SoftwareSerial.h>
#define GSM_RX_PIN 11      // Define the RX pin for GSM module
#define GSM_TX_PIN 12
#define BT_RX 8
#define BT_TX 9
char data;
String data2;
SoftwareSerial gsm_serial(GSM_TX_PIN, GSM_RX_PIN);             // RX, TX
SoftwareSerial bt(BT_RX, BT_TX);
void setup() {
  Serial.begin(9600);         // Serial monitor
  gsm_serial.begin(9600);
  bt.begin(38400);// GSM module
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
   if (bt.available()||gsm_serial.available())
    {
      data = bt.read();
      data2= gsm_serial.read();
      Serial.print(bt);
      digitalWrite(LED_BUILTIN, (data == 'a'));
      if (data == 'a'||data2=="where are you?")
      {
        sendLocation();
      }
     }
}
void sendLocation() {
  // Construct the AT command to send location via GSM
  Serial.println("sending loc");
  String locationData = "AT+CMGS=\"+918897008307\"\r\n"; // Replace +1234567890 with the recipient's phone number
  gsm_serial.println(locationData);
  delay(1000);
  // Construct the message with latitude and longitude
  String message = "https://maps.google.com/?q=16.568174,81.525140&entry=gps";
  gsm_serial.print(message);
  Serial.print(message);
  delay(1000);

  Serial.println("sending loc");
  String locationData2 = "AT+CMGS=\"+917995549189\"\r\n"; // Replace +1234567890 with the recipient's phone number
  gsm_serial.println(locationData2);
  delay(1000);
  // Construct the message with latitude and longitude
  String message2 = "https://maps.google.com/?q=16.568174,81.525140&entry=gps";
  gsm_serial.print(message2);
  Serial.print(message2);
  delay(1000);
  // Send CTRL+Z to indicate end of message
  gsm_serial.write(0x1A);
  delay(1000);
  
  Serial.println("sending loc");
  String locationData3= "AT+CMGS=\"+919573368818\"\r\n"; // Replace +1234567890 with the recipient's phone number
  gsm_serial.println(locationData3);
  delay(1000);
  // Construct the message with latitude and longitude
  String message3 = "https://maps.google.com/?q=16.568174,81.525140&entry=gps";
  gsm_serial.print(message3);
  Serial.print(message3);
  delay(1000);
  // Send CTRL+Z to indicate end of message
  gsm_serial.write(0x1A);
  delay(1000);
  
  Serial.println("sending loc");
  String locationData4= "AT+CMGS=\"+919391174334\"\r\n"; // Replace +1234567890 with the recipient's phone number
  gsm_serial.println(locationData3);
  delay(1000);
  // Construct the message with latitude and longitude
  String message4 = "https://maps.google.com/?q=16.568174,81.525140&entry=gps";
  gsm_serial.print(message4);
  Serial.print(message4);
  delay(1000);
  // Send CTRL+Z to indicate end of message
  gsm_serial.write(0x1A);
  delay(1000);
}
