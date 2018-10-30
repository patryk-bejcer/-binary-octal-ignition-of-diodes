#include <stdio.h>
#include <stdlib.h>

void setup() {

  //Start from pin number 2
  
  for(int i=2; i<10; i++)
  {
      pinMode(i,OUTPUT);
  }

  Serial.begin(9600);

  Serial.println("Setup completed, program is working!");

 
}

void loop() {
  
  int randNumber;
  String randNumberBinary;
  randNumber = random(300);
  randNumberBinary = convertToBinSimulation(randNumber);
  
  Serial.println(randNumber);
  Serial.println(randNumberBinary);
  
  String temp = randNumberBinary;
  char binNumberArr[8];
  strcpy(binNumberArr, temp.c_str());

  //Start from pin number 2

  for(int i=2; i < 10; i++){

      char c = binNumberArr[i-2];
      if(c == '1') {
        //Serial.println(i);
        digitalWrite(i,HIGH);
      } else {
        //Serial.println(i);
        digitalWrite(i,LOW);
      }
  }
  delay(10000);
}

String convertToBinSimulation(int number){
  
  int zeros = String(number,BIN).length();//This will check for the length of myNum in binary.
  //Serial.println(zeros); //For myNum = 50. You will get a 6. 

  String myStr;
  
  for (int i=0; i < 8 - zeros; i++) {//This will add zero to string as need
    myStr = myStr + "0";
  }
  
  myStr = myStr + String(number,BIN);

  return myStr;
}
