//HEADERS
#include <Servo.h>
#define pass (void)0
//DECLARANDO_VAR
    float cm ,duracao; // comprimento da onda

// SET_SENSOR
    byte pinoTransmissor=9; // trig
    byte pinoReceptor=8; //echo

//SET_LED RGB
	const byte R = 12;
	const byte B = 11;
  	const byte G = 10;

//SET_PUSH_BOTON
  const int botao = 6; 
  int estadoBotao = 0;

//SET_SERVO
	#define pinServo 13
	Servo s;
	int angulo = 0;
//MOTOR AND POT
int pin_motor = 5;
float motor;

void setup(){
    // LED and PUSH BOTON
    pinMode(R, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(B, OUTPUT);
    // sensor
    pinMode(pinoTransmissor, OUTPUT); // transmissor
    pinMode(pinoReceptor, INPUT);     // receptor
    //porta serial
    Serial.begin(9600);
    //servo
    s.attach(pinServo);
  	Serial.begin(9600);
  	s.write(0);
  	//boton
 
  
  
    
    }

void loop(){
  estadoBotao = digitalRead(botao);          
	Serial.println(estadoBotao);
  if (estadoBotao == HIGH){
    gira();
    blue();
   	Serial.print("PRESS");
    cm =  distancia();
    if(cm >0 && cm<=30){ 
      red();
      dispense();
     
      
    }
    else if (cm >100 && cm<=200) {
        green();
        volta();

    }
    else if (cm>200) {
        blue();
        volta();

    }
    else {
        volta();
        apaga();
    }   
    Serial.print(cm);
    Serial.println(" cm");
    delay(500);
  
  }//CHAVE IF
  
  
    		}//CHAVE LOOP

float distancia(){  
  digitalWrite(pinoTransmissor, LOW);
  delayMicroseconds(5); 
  digitalWrite(pinoTransmissor, HIGH); 
  delayMicroseconds(10);
  digitalWrite(pinoTransmissor, LOW);
  duracao = pulseIn(pinoReceptor, HIGH);
  float calcDistancia= (duracao/2) * 0.0343; 
  if (calcDistancia>=331){ 
      calcDistancia=0;
  }
  return calcDistancia;  
    }



void red(){
    analogWrite(R, 255);
    analogWrite(G, 0);
    analogWrite(B, 0);
  }
void green(){
    analogWrite(R, 0);
    analogWrite(G, 255);
    analogWrite(B, 0);
  }  
void blue(){
    analogWrite(R, 0);
    analogWrite(G, 0);
    analogWrite(B, 255);
  }  
void apaga(){
    analogWrite(R, 0);
    analogWrite(G, 0);
    analogWrite(B, 0);
  } 

void gira(){
    angulo = 250;
    s.write(angulo); 
    delay(2000);
   
 	}

void volta(){
    angulo = 0;
    s.write(angulo); 
    delay(2000);
 	}

void dispense(){
  motor = analogRead(A0)/4;
  analogWrite (pin_motor, motor);
  Serial.print("Motor:");
  Serial.println(motor);
  delay(2000);
  analogWrite(pin_motor, 0);
  tone(7, 100, 200);
  delay(200);
  tone(7, 100, 200);
}