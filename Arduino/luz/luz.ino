const long A = 1000;     //Resistencia en oscuridad en KΩ
const int B = 15;        //Resistencia a la luz (10 Lux) en KΩ
const int Rc = 10;       //Resistencia calibracion en KΩ
const int LDRPin = A4;   //Pin del LDR

int V;
int ilum;


void setup() {
  Serial.begin(9600);
}

void loop()
{
   V = analogRead(LDRPin);         

   //ilum = ((long)(1024-V)*A*10)/((long)B*Rc*V);  //usar si LDR entre GND y A0 
   ilum = ((long)V*A*10)/((long)B*Rc*(1024-V));    //usar si LDR entre A0 y Vcc (como en el esquema anterior)
  
   Serial.println(ilum);   
   delay(1000);
}
