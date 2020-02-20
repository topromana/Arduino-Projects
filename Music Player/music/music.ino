/*
cs-53
miso-50
mosi-51
sck-52
*/

#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>
#include <SD.h> 
#include <SPI.h>
#include <UTFT.h>
#define STEREO_OR_16BIT
#define SD_ChipSelectPin 53

TMRpcm music;
extern uint8_t BigFont[];
UTFT screen(CTE32HR,38,39,40,41);

bool canPressB1 = true;
bool pressedB1 = false;
bool canPressB2 = true;
bool pressedB2 = false;
bool canPressB3 = true;
bool pressedB3 = false;
bool canPressB4 = true;
bool pressedB4 = false;
bool canPressB5 = true;
bool pressedB5 = false;
bool canPressB6 = true;
bool pressedB6 = false;
void setup() {
  Serial.begin(9600);

 
  screenSetup();
  pinMode(7, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP); 
   music.speakerPin = 11;
  if (!SD.begin(SD_ChipSelectPin)) {
      Serial.println("SD fail");
      return;
      }
  music.setVolume(5);    
  music.quality(0);

}

void screenSetup(){
  screen.InitLCD();
  screen.setFont(BigFont);
  
  screen.clrScr();
  screen.fillScr(253, 165, 2);
  screen.setColor(154, 1, 1); //rgb for yellow-ish!!!!
  screen.fillRoundRect(10, 10, 150, 150);
  screen.fillRoundRect(170, 10, 310, 150);
  screen.fillRoundRect(330, 10, 470, 150);
  screen.fillRoundRect(10, 170, 150, 310);
  screen.fillRoundRect(170, 170, 310, 310);
  screen.fillRoundRect(330, 170, 470, 310);
  screen.setColor(253, 165, 2);
  screen.setBackColor(154, 1, 1);
  screen.print("1 Clopot", 13, 70);
  screen.print("2 Clop", 173, 70);
}
void loop() {
  //button 1
  if(digitalRead(7) == LOW) {
    if(canPressB1 == true){
      pressedB1 = !pressedB1;
    }
    canPressB1 = false;
  }
  else if(digitalRead(7) == HIGH){
    canPressB1 = true;
  }
  if(pressedB1 == true ){
  
  music.play("song1.wav",0);
  pressedB1 = false;}
  
  //button2
    if(digitalRead(6) == LOW) {
    if(canPressB2 == true){
      pressedB2 = !pressedB2;
    }
    canPressB2 = false;
  }
  else if(digitalRead(6) == HIGH){
    canPressB2 = true;
  }
  if(pressedB2 == true ){

   music.play("song2.wav",0);
  pressedB2 = false;}
  
  //BUTTON3
   if(digitalRead(5) == LOW) {
    if(canPressB3 == true){
      pressedB3 = !pressedB3;
    }
    canPressB3 = false;
  }
  else if(digitalRead(5) == HIGH){
    canPressB3 = true;
  }
  if(pressedB3 == true ){
 
   music.play("song3.wav",0);
  pressedB3 = false;}

  //button 4
   if(digitalRead(4) == LOW) {
    if(canPressB4 == true){
      pressedB4 = !pressedB4;
    }
    canPressB4 = false;
  }
  else if(digitalRead(4) == HIGH){
    canPressB4 = true;
  }
  if(pressedB4 == true ){
  
    pressedB4 = false;}
  //button 5
   if(digitalRead(3) == LOW) {
    if(canPressB5 == true){
      pressedB5 = !pressedB5;
    }
    canPressB5 = false;
  }
  else if(digitalRead(3) == HIGH){
    canPressB5 = true;
  }
  if(pressedB5 == true ){
    
    pressedB5 = false;}

  //button 6
   if(digitalRead(2) == LOW) {
    if(canPressB6 == true){
      pressedB6 = !pressedB6;
    }
    canPressB6 = false;
  }
  else if(digitalRead(2) == HIGH){
    canPressB6 = true;
  }
  if(pressedB6 == true ){
 
    pressedB6 = false;}

}
