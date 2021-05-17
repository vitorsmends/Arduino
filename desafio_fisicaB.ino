#include <LiquidCrystal.h>

const int rs = 11, en = 10, d4 = 9, d5 = 8, d6 = 7, d7 = 6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int led = 0;
int pir_entrada = 12;
int pir_saida = 13;
int cont = 0;
int alarme = 5;

void setup(){
  pinMode(pir_entrada,INPUT);
  pinMode(pir_saida,INPUT);
  pinMode(led,OUTPUT);
  pinMode(alarme,OUTPUT); 
  lcd.begin(16, 2);
  Serial.begin(9600);

}

void loop(){

  verifica_entrada();
  verifica_saida();
  delay(100);
  verifica_pessoas(cont);

}

void verifica_entrada(){
  int val = digitalRead(pir_entrada);
  
  if(val==HIGH){
    lcd.clear();
    digitalWrite(led,HIGH);
    cont++;
    lcd.print(cont);
    Serial.println(cont);
    delay(2000);
  }
  else{
    lcd.clear();
    lcd.print(cont);
    digitalWrite(led,LOW);
    
  }

}

void verifica_saida(){
  int val = digitalRead(pir_saida);
  
  if(val==HIGH){
    lcd.clear();
    digitalWrite(led,HIGH);
    cont--;
    lcd.print(cont);
    delay(2000);
    Serial.println(cont);
  }
  else{
    lcd.clear();
    lcd.print(cont);
    digitalWrite(led,LOW);
    
  }

}

void verifica_pessoas(int pop){
  if(pop == 18){
    while(cont==18){
    verifica_saida();
  	lcd.print("LIMITE ATINGIDO");
    digitalWrite(alarme, HIGH);
    delay(2000);}
  }
  
}