//Author: Yeison Herbert Churquipa Yanqui

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid     = "iPhone de Yeison Herbert";
const char* password = "12345678";
int analogPin = A0;
int lectura = 0;
const char* serverName = "http://172.20.10.13/GrupoDos/post-esp-data.php";
String apiKeyValue = "123";
String sensorName = "FC28";
String sensorLocation = "Jardin3";

void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {

  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    http.begin(client, serverName);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    lectura = analogRead(analogPin);

    String httpRequestData = "api_key=" + apiKeyValue + "&sensor=" + sensorName + "&ubicacion=" + sensorLocation + "&valor=" + lectura;
    Serial.print("httpRequestData: ");
    Serial.println(httpRequestData);

    int httpResponseCode = http.POST(httpRequestData);

    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
  delay(30000);
}