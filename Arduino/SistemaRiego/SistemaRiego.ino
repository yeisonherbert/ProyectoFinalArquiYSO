int valor_humedad_suelo;
int valor_lluvia;
int valor_luminosidad;
int valor_temp_hum_ambiente;
int valor_mini_bomba;

const int pin_humedad_suelo = A1;
const int pin_lluvia = A2;
const int pin_luminosidad = A4;
const int pin_temp_hum_ambiente = 2;
const int pin_mini_bomba_rele = 7;

int iluminacion;
int humedad_suelo;


void setup() {
  Serial.begin(9600);//iniciar puerto serie
  pinMode(pin_humedad_suelo, INPUT);
  pinMode(pin_lluvia, INPUT);
  pinMode(pin_luminosidad, INPUT);
  pinMode(pin_temp_hum_ambiente, INPUT);
  pinMode(pin_mini_bomba_rele, OUTPUT);
}

void loop() {
  valor_humedad_suelo = analogRead(pin_humedad_suelo);
  valor_lluvia = analogRead(pin_lluvia);
  valor_luminosidad = analogRead(pin_luminosidad);
  valor_temp_hum_ambiente = analogRead(pin_temp_hum_ambiente);
  Serial.println("lluvia");
  Serial.println(valor_lluvia);
  
  //si condición siguiente encender rele
  if (valor_lluvia == LOW) //Existe lluvia
  {
    digitalWrite(pin_mini_bomba_rele, LOW);    // apagar el pin_mini_bomba_rele
  }
  else
  {
    iluminacion = (100.0 * valor_luminosidad) / 1024;
    humedad_suelo = (100.0 * valor_humedad_suelo) / 1024;
    Serial.println("iluminacion:");
    Serial.println(iluminacion);
    Serial.println("humedad_suelo:");
    Serial.println(humedad_suelo);
    if ( humedad_suelo <= 50 && iluminacion > 70 ) {
      digitalWrite(pin_mini_bomba_rele, HIGH);    // encender el pin_mini_bomba_rele
    }
    else
    {
      digitalWrite(pin_mini_bomba_rele, LOW);    // apagar el pin_mini_bomba_rele
    }
  }
  //apagar rele
  delay(60000);//1 minuto
}
