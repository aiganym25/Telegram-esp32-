#include <Arduino.h>
#include <UniversalTelegramBot.h>
#include <WiFiClientSecure.h>//в библиотеке ардуиноджейсон
#include <WiFi.h>


#define WIFI_SSID "ssid" //network ssid name
#define WIFI_PASSWORD "password" //network key

#define BOTtoken "XXXXXXXXXX:XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
#define CHAT_ID "XXXXXXXXXX"

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

const int PushButton = 0;

void setup() {

  Serial.begin(115200);

  pinMode(PushButton,INPUT);

// connecting to wifi 
  Serial.println("Connecting to WiFi.."); 
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("...");
  }
  Serial.print("IP: ");
  Serial.println(WiFi.localIP()); // Print ESP32 Local IP Address

  client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  
}

void loop() {

  int Push_button_state = digitalRead(PushButton);

  if (Push_button_state == LOW ) { 
    bot.sendMessage(CHAT_ID, "The button was pushed");
  }
}


