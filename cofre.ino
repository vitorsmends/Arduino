#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <stdio.h>
#include <string.h>

//-------------------------------------keypad
char customKey, start;
const byte ROWS = 4; // linhas
const byte COLS = 4; // colunas

char keys[ROWS][COLS] = {
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};

byte rowPins[ROWS] = {11,10,9,8};
byte colPins[COLS] = {3,2,1,0};
//
//-------------------------------------display
const int rs = 12, en = 13, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
char pass[3];
int cmp, cont, tentativas;

Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup(){
  
  lcd.begin(16, 2);
  strcpy(pass, "0000");
  tentativas = 0;
  Serial.println(tentativas);
			  }

void loop(){
	lcd.setCursor(0,0);
  	lcd.print("Digite a senha");
  	customKey = customKeypad.getKey();
	
    switch(customKey){
      
		case '0'...'9':
          lcd.setCursor(0,1);
          if(cont < 4){
            pass[cont] = customKey;
            lcd.print(pass);
            cont++;		}
      		else{
          	verifica();	}
      
            break;
      	
      	case 'C':
      		lcd.clear();
      		strcpy(pass, "0000");
      		cont = 0;
      		break;
      
      	case '#':
      		verifica();
      		break;
      	

    		}

  }


void correct(){
  lcd.clear();
  strcpy(pass, "0000");
  cont = 0;
  lcd.setCursor(0,0);
  lcd.print("Destrancado");
  delay(2000);
  tentativas = 0;
}

void incorrect(){
  lcd.clear();
  strcpy(pass, "0000");
  cont = 0;
  lcd.setCursor(0,0);
  lcd.print("SENHA NEGADA!");
  delay(2000);
  lcd.clear();
  if(tentativas == 3) auto_destruir();
}

void verifica(){
  cmp = strcmp("2507", pass);
  lcd.setCursor(5,0);
  if(cmp == 0) correct();
  else incorrect();
  tentativas++;
  Serial.println(tentativas);
}

void auto_destruir(){
 int i;
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("auto destruicao em:  ");
 
 for(i = 3; i > 0; i--){ 
 	lcd.print(i);
 }
  
}

