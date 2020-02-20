 #include <Servo.h>
 #include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, 4, NEO_GRB + NEO_KHZ800);
SoftwareSerial mySerial(9, 10); // RX, TX///pt uno e 9,10

// Pins of motor 1
#define mpin00 5
#define mpin01 6
// Pins of motor 2
#define mpin10 3
#define mpin11 11
Servo srv;
String str;
String msg;
String right;
String left;
int sw;
void setup()
{
 sw = 0;
  right = "right";
  left = "left";
  // Open serial communications and wait for port to open:
  Serial.begin(38400);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(38400);
  mySerial.println("Hello, world?");

  digitalWrite(mpin00, 0);
 digitalWrite(mpin01, 0);
 digitalWrite(mpin10, 0);
 digitalWrite(mpin11, 0);
 pinMode (mpin00, OUTPUT);
 pinMode (mpin01, OUTPUT);
 pinMode (mpin10, OUTPUT);
 pinMode (mpin11, OUTPUT);
 // LED pin
  
pinMode(13, OUTPUT);
 strip.begin();
  strip.setBrightness(30); //adjust brightness here
  strip.show(); // Initialize all pixels to 'off'
}

void StartMotor (int m1, int m2, int forward, int speed)
{
 if (speed==0) // stop
 {
 digitalWrite(m1, 0);
 digitalWrite(m2, 0);
 }
 else
 {
 if (forward)
 {
 digitalWrite(m2, 0);
 analogWrite(m1, speed); // use PWM
  }
 else
 {
 digitalWrite(m1, 0);
 analogWrite(m2, speed);
 }
 }
}

void delayStopped(int ms)
{
 StartMotor (mpin00, mpin01, 0, 0);
 StartMotor (mpin10, mpin11, 0, 0);
 delay(ms);
}

void playWithServo(int pin)
{
 srv.attach(pin);
 srv.write(0);
 delay(1000);
 //srv.write(180);
 //delay(1000);
 srv.write(90);
 delay(1000);
 srv.detach();
}

void parkRightFront(){
  

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//parcare dreapta cu fata
 delayStopped(400);
  StartMotor (mpin00, mpin01, 1, 95);
 StartMotor (mpin10, mpin11, 1, 95);
 delay(350);
 
 StartMotor (mpin00, mpin01, 1, 95);
 StartMotor (mpin10, mpin11, 0, 80);
 delay(310);

  delayStopped(100);
  
  StartMotor (mpin00, mpin01, 1, 65);
  StartMotor (mpin10, mpin11, 1, 50);
  delay(1300);
  delayStopped(1000);


}

void exitParkLeftFront(){

 //iese din parcare care a fost facuta stanga cu fata
 delayStopped(400);
  StartMotor (mpin00, mpin01, 0, 95);
 StartMotor (mpin10, mpin11, 0, 95);
 delay(450);
 
 StartMotor (mpin00, mpin01, 1, 65);
 StartMotor (mpin10, mpin11, 0, 100);
 delay(510);

  delayStopped(100);
  
  StartMotor (mpin00, mpin01, 0, 65);
  StartMotor (mpin10, mpin11, 0, 50);
  delay(1300);
  delayStopped(1000);
  
}

void exitParkRightFront(){
   //iesirea cealalta
  //toate iesirile pot fi folosite ca parcari cu spatele
   delayStopped(400);
  StartMotor (mpin00, mpin01, 0, 95);
 StartMotor (mpin10, mpin11, 0, 95);
 delay(250);
 
 StartMotor (mpin00, mpin01, 0, 85);
 StartMotor (mpin10, mpin11, 1, 70);
 delay(310);

  delayStopped(100);
  
  StartMotor (mpin00, mpin01, 0, 70);
  StartMotor (mpin10, mpin11, 0, 50);
  delay(1300);
  delayStopped(1000);
}


void parkLeftFront(){

   
 //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  //parcare stanga cu fata
 //la vreao 10 cm de loc, cu roata in drept cu linia
 delayStopped(400);
  StartMotor (mpin00, mpin01, 1, 80);
 StartMotor (mpin10, mpin11, 1, 80);
 delay(250);

   StartMotor (mpin00, mpin01, 0, 60);
 StartMotor (mpin10, mpin11, 1, 70);
 delay(410);

  delayStopped(100);
  
  StartMotor (mpin00, mpin01, 1, 60);
  StartMotor (mpin10, mpin11, 1, 50);
  delay(1300);
  delayStopped(5000);


}

void signalRight(){
 /* for(int i = 0; i < 3; i++){
   strip.setPixelColor(12, strip.Color(255, 210, 0));
   strip.show();
   delay(700);
   strip.setPixelColor(12, strip.Color(0, 0, 0));
   strip.show();
   delay(700);
   }*/
 for(int j = 15; j >= 0; j--){
strip.setPixelColor(j, strip.Color(0, 0, 0));}
   for(int i = 0; i< 3; i++){
      for(int j = 0; j < 16; j++){
         strip.setPixelColor(j, strip.Color(255, 210, 0));
         strip.show();
         delay(30);
         strip.setPixelColor(j, strip.Color(0, 0, 0));
         strip.show();
         delay(30);
          
          }
   }

}


void signalLeft(){
  /*for(int i = 0; i < 3; i++){
   strip.setPixelColor(4, strip.Color(255, 210, 0));
   strip.show();
   delay(700);
   strip.setPixelColor(4, strip.Color(0, 0, 0));
   strip.show();
   delay(700);}*/
    for(int j = 15; j >= 0; j--){
strip.setPixelColor(j, strip.Color(0, 0, 0));}
         strip.show();
         delay(30);
   for(int i = 0; i< 3; i++){
      for(int j = 15; j >= 0; j--){
         strip.setPixelColor(j, strip.Color(255, 210, 0));
         strip.show();
         delay(30);
         strip.setPixelColor(j, strip.Color(0, 0, 0));
         strip.show();
         delay(30);
          
          }
   }
   
}


void avarii(){
  /* strip.setPixelColor(12, strip.Color(255, 210, 0));
   strip.setPixelColor(4, strip.Color(255, 210, 0));
   strip.show();
   delay(1000);
   strip.setPixelColor(12, strip.Color(0, 0, 0));
   strip.setPixelColor(4, strip.Color(0, 0, 0));
   strip.show();
   delay(1000);*/
 for(int j = 15; j >= 0; j--){
strip.setPixelColor(j, strip.Color(0, 0, 0));}
   for(int i = 0; i< 3; i++){
      for(int j = 7; j >= 1; j--){
         strip.setPixelColor(j, strip.Color(255, 210, 0));
         strip.setPixelColor(15 - j + 1, strip.Color(255, 210, 0));
         strip.show();
         delay(50);
         
         strip.setPixelColor(j, strip.Color(0, 0, 0));
          strip.setPixelColor(15 - j + 1, strip.Color(0, 0, 0));
         strip.show();
         delay(50);
         
          
          }
   }
}

void rainbow() {
  uint16_t i, j;
 
  for(j=0; j<226; j+=20) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(j ,j+10, j+20 ));
    }
    strip.show();
    //delay(10);
  }
}
 

void go_fw(){

   StartMotor (mpin00, mpin01, 1, 60);
   StartMotor (mpin10, mpin11, 1, 60);
   delay(450);
  
}
void loop() // run over and over
{
  //go_fw();
  if (mySerial.available()){
// go_fw();
    if(msg.equals("go")){
     rainbow();
      go_fw();
    }
      // signalLeft();
   // Serial.writeString(mySerial.readString());
    msg = mySerial.readString();
   // Serial.println("cacacaacaaaa");
    Serial.println(msg);
    msg.trim();


    if(msg.equals("PFR")){ 
      sw = 1;
      signalRight();
      parkRightFront();
      
    }

    if(msg.equals("PFL")){ 
      sw = 1;
      signalLeft();
      parkLeftFront();
      
    }

    if(msg.equals("EPFR")){
      avarii();
       exitParkRightFront();
       sw = 0;
    }

    if(msg.equals("EPFL")){
      avarii();
       exitParkLeftFront();
       sw = 0;
    }

     if(msg.equals("PBR")){ 
      sw = 1;
      avarii();
      exitParkRightFront();
      
    }

    if(msg.equals("PBL")){ 
      sw = 1;
      avarii();
      exitParkLeftFront();
      
    }

    if(msg.equals("EPBR")){
      signalRight();
       parkRightFront();
       sw = 0;
    }

    if(msg.equals("EPBL")){
       signalLeft();
       parkLeftFront();
       sw = 0;
    }



    

  
    if(msg.equals(right)){
      signalRight();
      }
       if(msg.equals(left)){
        signalLeft();
      } 
      
      }
   /* if(strcmp(msg,"red")){
    Serial.println("should be red");
       strip.setPixelColor(10, strip.Color(255, 0, 0));
      strip.show();
       delay(1000);}
   else{
    Serial.println("should not be red");
    strip.setPixelColor(10, strip.Color(0, 0, 0));
      strip.show();}
    
    }*/
  
}
