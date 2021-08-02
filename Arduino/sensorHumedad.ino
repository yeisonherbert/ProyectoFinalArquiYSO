int analogPin = A0;
int lectura = 0;

void setup() {
  Serial.begin(9600);
}
void loop() {
  lectura = analogRead(analogPin);
  Serial.println("La lectura es: ");
  Serial.println(lectura);
  // lecturas entre 1000 - 1023 //seco
  if (lectura >= 1000)
  {
    Serial.println("El SENSOR esta DESCONECTADO o FUERA DEL SUELO");
  }
  else if (lectura < 1000 && lectura >= 600)
  {
    Serial.println("El SUELO esta SECO");
  }
  else if (lectura < 600 && lectura >= 370)
  {
    Serial.println("El SUELO esta HUMEDO");
  }
  else
  {
    Serial.println("El SENSOR esta en AGUA");
  }
   delay(5000); 
}