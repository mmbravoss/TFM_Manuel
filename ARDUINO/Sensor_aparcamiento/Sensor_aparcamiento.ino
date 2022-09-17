const int EchoPin = 5;
const int TriggerPin = 6;
const int LedRojo = 7;
const int LedAmarillo = 8;
const int LedVerde = 9;
int buzzer = 12;
long Tiempo;
long Distancia;

void setup() {
   Serial.begin(9600);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
   digitalWrite(TriggerPin, LOW);
   pinMode(LedRojo, OUTPUT);
   pinMode(LedAmarillo,OUTPUT);
   pinMode(LedVerde,OUTPUT);
   pinMode(buzzer,OUTPUT);
}
 
void loop() {
  digitalWrite(TriggerPin, HIGH); //Se envia el pulso de activacion del sensor
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);
  
  Tiempo = pulseIn(EchoPin, HIGH); // Obtengo el tiempo del sensor
  
  Distancia = 0.0343*Tiempo/2; //Calculo la distancia

  Serial.print("Distancia:");
  Serial.println(Distancia); //Muestro la distancia en el monitor serie
  delay(100);
  
if (Distancia<= 60 && Distancia>=16) 
   {
   digitalWrite(LedVerde , LOW);
   digitalWrite(LedRojo , LOW);
   digitalWrite(LedAmarillo , HIGH);
   delay(100);
     for (int i=0;i<5;i++)
     {
     digitalWrite(buzzer,HIGH);
     delay(50);
     digitalWrite(buzzer,LOW);
     delay(50);
     }
    }
    
else if (Distancia <= 15)
   {
   digitalWrite(LedVerde , LOW);
   digitalWrite(LedRojo , HIGH);
   digitalWrite(LedAmarillo , LOW);
   delay(100);
     for (int i=0;i<5;i++)
     {
     digitalWrite(buzzer,HIGH);
     delay(10);
     digitalWrite(buzzer,LOW);
     delay(10);
     }
   }
else {
   digitalWrite(LedVerde , HIGH);
   digitalWrite(LedRojo , LOW);
   digitalWrite(LedAmarillo , LOW);
   delay(200);
  }
}
