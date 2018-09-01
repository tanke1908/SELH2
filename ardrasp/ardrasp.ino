#define lectura 14 // Pin analogico 0 para la lectura del Fototransistor
#define salida 13  // Pin para salida de producto a rasp
#define estado 12 //pin de led
#define serv 11  //pin del servo pwm

#include <Servo.h>

int Value = 0;     // Inicializamos el valor del sensor
int vsal = 0;
Servo myServo;  // create a servo object


void setup () {
  
   Serial.begin(9600);
   pinMode(estado, OUTPUT); //estado de la maquina
   myServo.attach(serv); // attaches the servo on pin 9 to the servo object
   pinMode(salida, OUTPUT);
   
}

void loop () {

   //-----------------------------------------------lectura rasp---------------------------
  
  if (Serial.available()) { //Si está disponible
    
     char c = Serial.read(); 
     
     if (c == 'H') { 
        digitalWrite(estado, HIGH);
        myServo.write(90);
     }
     else if (c == 'L') { 
        digitalWrite(estado, LOW);
        myServo.write(0);
     }
     
  }

  //-----------------------------------------------proceso v1---------------------------

  Value = analogRead(lectura);            
  
  if(Value > 0)
  {
    digitalWrite(salida, HIGH);
    vsal = 0;
  }
  else
  {
    digitalWrite(salida, LOW);
    vsal = 1;
  }

  Serial.print("sensor = " );                       
  Serial.print(Value);   
  Serial.print(" ---- salida = " );                       
  Serial.println(vsal);     

  delay(100); 


   
}



//------------------------------------------------------------------------------------------------------------------------*************************


















