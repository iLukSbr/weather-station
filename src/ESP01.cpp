/* ESP-01 Wi-Fi module */

#include "pch.h"
#include "ESP01.h"

ESP01::ESP01() : countTrueCommand(0), countTimeCommand(0), found(false)
{
}

ESP01::~ESP01(){

}

void ESP01::print() const{
    
}

void ESP01::read(){

}

void ESP01::send(char* data){
    
}

void ESP01::start(){

}

//Manda os comandos no serial do RX|TX
bool ESP01::sendCommand(String command, int maxTime, String readReplay) {
  /*---------------------SERIAL PRINT-----------------
  Serial.print(countTrueCommand);
  Serial.print(". at command => ");
  Serial.print(command);
  Serial.print(" ");
  ----------------------------------------------------*/
  char finde[readReplay.length()];
  readReplay.toCharArray(finde, readReplay.length());

  while (countTimeCommand < (maxTime * 1)) {
    Serial3.println(command);
    delay(500);

    if (Serial3.find(finde)) {
      found = true;
      break;
    }
    countTimeCommand++;
  }
  if (found == true) {
    Serial.println("Success");
    countTrueCommand++;
    countTimeCommand = 0;
    found = false;
    return true;
  }

  if (found == false) {
    Serial.println("Fail");
    countTrueCommand = 0;
    countTimeCommand = 0;
    return false;
  }

  found = false;
  return false;
}

void ESP01::init(unsigned long baudRate) {
  Serial3.begin(baudRate);
  while(!Serial3){}
  // Serial3.print("AT+UART_CUR=9600,8,1,0,0\r\n");
  delay(1000);
  // Serial3.begin(9600);
}

void ESP01::sendData(int tamdoc, StaticJsonDocument<384>& doc) {
  int delayp = 100;
  /*   SERIAL PRINT

  Serial.println(F("POST /sensores HTTP/1.1"));
  Serial.println(F("Host: api-oficinas.onrender.com"));
  //Serial.println(F("Connection: keep-alive"));//22
  Serial.println(F("Accept: application/json"));
  Serial.println(F("Content-Type: application/json"));
  Serial.print(F("Content-Length: "));
  Serial.println(String(tamdoc));
  Serial.println();
  */
  
  Serial3.println(F("POST /sensores HTTP/1.1"));
  delay(delayp);
  Serial3.println(F("Host: api-oficinas.onrender.com"));
  delay(delayp);

  /* KEEP ALIVE
  //Serial3.println(F("Connection: keep-alive"));
  //delay(delayp);*/
  

  /* ---------------------- PRINT SERIAL RX|TX------------------------------------------*/
  Serial3.println(F("Accept: application/json"));
  delay(delayp);
  Serial3.println(F("Content-Type: application/json"));
  delay(delayp); 
  Serial3.print(F("Content-Length: "));
  delay(delayp);
  Serial3.println(String(tamdoc));
  delay(delayp);
  Serial3.println();
  delay(delayp); 
  serializeJson(doc,Serial3);
  delay(delayp);
  serializeJson(doc,Serial);
  delay(delayp);
  // PRINT RESPOSTA
  printResponse();
  // delay(5000);
  countTrueCommand++;
}

void ESP01::printResponse() {
  while (Serial3.available()) {
    Serial.println();
    String tmpResp = Serial3.readString();
    Serial.println(tmpResp);
  }
}