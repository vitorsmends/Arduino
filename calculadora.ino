#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <stdio.h>
//-------------------------------------keypad
char customKey, start;
const byte ROWS = 4; // linhas
const byte COLS = 4; // colunas

char keys[ROWS][COLS] = {
{'1','2','3','+'},
{'4','5','6','-'},
{'7','8','9','*'},
{'C','0','=','/'}
};

byte rowPins[ROWS] = {11,10,9,8};
byte colPins[COLS] = {3,2,1,0};
//
//-------------------------------------display
const int rs = 12, en = 13, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
double first = 0;
double second = 0;
double third = 0;
double total = 0;

Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup(){
  
  lcd.begin(16, 2);

  for(int i=0;i<=20;i++){
  lcd.setCursor(5,0);
  lcd.print("Calculadora - Joao Vitor");
  delay(100);
  lcd.scrollDisplayLeft();
  delay(100);}
  

  
  lcd.clear();
  lcd.setCursor(0,0);
					
			  }

void loop(){
  	customKey = customKeypad.getKey();
  
  switch(customKey){
    case '0'...'9':
      lcd.setCursor(0,0);
      first = first * 10 + (customKey - '0');
      lcd.print(first);
      break;

    case '+':
        if(first != 0){
            lcd.setCursor(15,1);
            lcd.print("+");
            second = SecondNumber();
            total = first + second;
            lcd.setCursor(0,3);
            lcd.print(total);
          	first = 0;
          	second = 0;
            }
            else if(first == 0){
            third = ThirdNumber(total, '+');
            total = total + third;
            lcd.setCursor(0,3);
            lcd.print(total);
            third = 0;
            }
	break;

    case '-':
        if(first != 0){
            lcd.setCursor(15,1);
            lcd.print("-");
            second = SecondNumber();
            total = first - second;
            lcd.setCursor(0,3);
            lcd.print(total);
          	first = 0;
          	second = 0;
            }
            else if(first == 0){
            third = ThirdNumber(total, '-');
            total = total - third;
            lcd.setCursor(0,3);
            lcd.print(total);
            third = 0;
            }
	break;

    case '*':
        if(first != 0){
            lcd.setCursor(15,1);
            lcd.print("*");
            second = SecondNumber();
            total = first * second;
            lcd.setCursor(0,3);
            lcd.print(total);
          	first = 0;
          	second = 0;
            }
            else if(first == 0){
            third = ThirdNumber(total, '*');
            total = total * third;
            lcd.setCursor(0,3);
            lcd.print(total);
            third = 0;
            }
	break;

    case '/':
        if(first != 0){
            lcd.setCursor(15,1);
            lcd.print("/");
            second = SecondNumber();
            total = first / second;
            lcd.setCursor(0,3);
            lcd.print(total);
          	first = 0;
          	second = 0;
            }
            else if(first == 0){
            third = ThirdNumber(total, '/');
            total = total / third;
            lcd.setCursor(0,3);
            lcd.print(total);
            third = 0;
            }
	break;

    case 'C':
      total = 0;
      first = 0, second = 0;
      lcd.clear();
      break;
      }

  
}


long SecondNumber(){
  while( 1 ){
    customKey = customKeypad.getKey();
    if(customKey >= '0' && customKey <= '9'){
        second = second * 10 + (customKey - '0');
        lcd.setCursor(0,1);
        lcd.print(second);
        }

    if(customKey == '=') break;
            } 
  return second;
					}

long ThirdNumber(double r, char op){
  lcd. clear();
  lcd.setCursor(0,0);
  lcd.print(r);
  lcd.setCursor(15,1);
  lcd.print(op);
  while( 1 ){
    customKey = customKeypad.getKey();
    if(customKey >= '0' && customKey <= '9'){
        third = third * 10 + (customKey - '0');
        lcd.setCursor(0,1);
        lcd.print(third);
        }
        
    if(customKey == '=') break;
        }
  return third;
					}