 #include "DHT.h"
 #include <ESP32Servo.h>

 #define DHTPIN 4
 #define DHTTYPE DHT11

 DHT dht(DHTPIN, DHTTYPE);
 Servo servo;

 int pinServo = 2;
 int relevador = 23;


void setup() {

  //Inicializacion de monitor serial y mensaje de testeo de DHT11.
  Serial.begin(115200);
  Serial.println(F("DHTxx Test"));
  dht.begin();

  //Configuracion de posicion del servo.
  servo.attach(pinServo,500,2500);

  //Definir como salida el pin 23.
  pinMode(relevador,OUTPUT);

}
//Inicializar la posicion (en grados) del sevo.
int pos = 0;

void loop() {
  delay(15000);

  //Variables para almacenar datos de humedad y temperatura.
  float h = dht.readHumidity();
  float t = dht.readTemperature(); 

  //Verificacion del sensor DHT11.
  if ( isnan(h) || isnan(t) ){
    Serial.println(F("Error al detectar el sensor DTH11, favor de verificar sus conexiones......."));
    return;
  }

  /*
  Si la humedad se encuentra arriba del 70% y la temperatura mayor a 30 grados,
  hara que el relevador permita el paso de corriente y abrira la puerta.
  */

  //Muestreo de la temperatura actual
  
  Serial.print(F("Humedad: "));
  Serial.print(h);
  Serial.print(F("% Temperatura: "));
  Serial.print(t);
  Serial.println(F("°C "));

  //Funcionamiento del sistema
  if ( h >= 70.30 && t >= 30 ){
    Serial.println("EL cuarto se encuentra con temperaturas altas y un alto porcentaje de humedad, se abrira la puerta y se activara el abanico");
    
    //Ciclo que posicionara el servo de 0 a 180
    for (pos = 0; pos <= 180; pos = pos + 1)
    {
      servo.write(pos);
    }
    digitalWrite(relevador,HIGH);
  }

  else{
    
    Serial.println("\nEl cuarto se encuentra en las optimas condiciones");
    for (pos = 180; pos >= 0; pos = pos - 1){
      servo.write(pos);
  }
  digitalWrite(relevador,LOW);

  }
}