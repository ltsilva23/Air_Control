//Inclusao das bibliotecas
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "RTClib.h"
#include "time.h"

//Inicializacao do display
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int LED_PIN_LIG = 8; //pino definido para conexao com o led verde ligado
int LED_PIN_DES = 9;   //pino definido para conexao com o led vermelho desligado

//
RTC_DS1307 rtc;

//
//Declaração dos dias da semana
char daysOfTheWeek[7][12] = {"Domingo", "Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado"};

// Executado apenas uma vez
void setup () {
  lcd.begin(16,2); // Iniciando o display LCD passando nos parâmetros o seu tamanho: 16 colunas x 2 linhas                
  lcd.clear();   // Limpa o LCD     
  if (!rtc.begin()) {                          //Se o RTC nao for inicializado, faz
    lcd.println("RTC NAO INICIALIZADO"); //Imprime o texto

  }
  //rtc.adjust(DateTime(2022, 12, 21, 13, 07, 00)); //Ajusta o tempo do RTC para a data e hora definida pelo usuario.
  delay(1000); // Intervalo de 100 Milissegundos

  pinMode(LED_PIN_LIG, OUTPUT); // configura o pino digital 8 como saída
  pinMode(LED_PIN_DES, OUTPUT); // configura o pino digital 9 como saída
}

//Funções que será executada repetidamente
void loop() {
  relogio();
  Led_Verde();
  Led_vermelho();
}


void relogio ()
{

  DateTime now = rtc.now();// Faz a leitura de dados de data e hora
  lcd.setCursor( 1, 0);
  lcd.print(daysOfTheWeek[now.dayOfTheWeek()]); //Imprime dia da semana(0 = domingo, 1 = segunda, ... e 6 = sabado.)
  lcd.print(",");
  lcd.print(now.day(), DEC);//Imprime dia
  lcd.print("/"); //Imprime barra
  lcd.print(now.month(), DEC);//Imprime mes
  lcd.print('/'); //Imprime barra
  lcd.println(now.year(), DEC); //Imprime ano
  lcd.setCursor( 1, 1);
  lcd.print(now.hour(), DEC);//Imprime hora
  lcd.print(':');
  lcd.print(now.minute(), DEC); //Imprime os minutos
  lcd.print(':');
  lcd.print(now.second(), DEC);  //Imprime os segundos
  lcd.println();
  delay(1000); //1 Segundo
}

void Led_Verde() {
  DateTime now = rtc.now();// Faz a leitura de dados de data e hora
  int dia = now.dayOfTheWeek();// dia 0 = dom e 6 = sab

  if ((now.hour() == 18) && (now.minute() == 51) && ( dia == 0 || dia == 4 || dia == 7)) { // ligar dom, qui, sabado

    lcd.setCursor( 0, 1);
    lcd.print("Air Control ON.");
    delay(200);
    digitalWrite(LED_PIN_LIG, HIGH);// ativa o pino digital 8
    digitalWrite(LED_PIN_DES, LOW);// desativa o pino digital 9

  } else {
    digitalWrite(LED_PIN_LIG, LOW);// desativa o pino digital 8
  }


}
void Led_vermelho() {
  DateTime now = rtc.now();// Faz a leitura de dados de data e hora
  int dia = now.dayOfTheWeek();// dia 0 = dom e 6 = sab

  if  ((now.hour() == 18) && (now.minute() == 52) && (dia == 1 || dia == 4 || dia == 5)) { // desligar seg, qui, sex
    lcd.setCursor( 0, 1);
    lcd.println("Air Control OFF.");
    delay(200);
    digitalWrite(LED_PIN_LIG, LOW);// desativa o pino digital 8
    digitalWrite(LED_PIN_DES, HIGH);// ativa o pino digital 9
  }
  else {
    digitalWrite(LED_PIN_DES, LOW);// desativa o pino digital 9
  }

}



