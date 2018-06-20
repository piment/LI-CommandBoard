#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, 2, NEO_GRB + NEO_KHZ800);
volatile int btn[15] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
const int leds[15] = {23,25,27,29,31,33,35,37,39,41,43,45,47,49,51};
volatile int last_total = 0;

void setup() {
  strip.begin();
  strip.setBrightness(20);
  strip.show();
  
  for(int i = 23; i <= 51; i += 2){
    pinMode(i, OUTPUT);
    digitalWrite(i, 0);
  }
  
  for(int i = 22; i <= 50; i += 2){
    pinMode(i, INPUT_PULLUP);
  }
  
  for(int i = 8; i < 14; i++){
    pinMode(i, INPUT);
  }
  
  for(int i = 0; i < 12; i++){
    strip.setPixelColor(i, strip.Color(250, 10, 0));
    strip.show();
    delay(30);
  }
}

void checkBtn(){
  btn[0] = digitalRead(22);
  btn[1] = digitalRead(24);
  btn[2] = digitalRead(26);
  btn[3] = digitalRead(28);
  btn[4] = digitalRead(30);
  btn[5] = digitalRead(32);
  btn[6] = digitalRead(34);
  btn[7] = digitalRead(36);
  btn[8] = digitalRead(38);
  btn[9] = digitalRead(40);
  btn[10] = digitalRead(42);
  btn[11] = digitalRead(44);
  btn[12] = digitalRead(46);
  btn[13] = digitalRead(48);
  btn[14] = digitalRead(50);
}
void loop() {
  // put your main code here, to run repeatedly:
  int total = 0;    
    
  for(int i = 8; i < 14; i++){
    if(digitalRead(i) == 1){
      total += 1;
    }
  }

  if(total != last_total){
    for(int i = 0; i < 12; i++){
      strip.setPixelColor(i, strip.Color(250, 10, 0));
      strip.show();
      delay(30);
    }
  }
  
  for(int i = 0; i < total * 2; i++){
    if(total > 0 && total != last_total){
      if(total == 6){
        strip.setPixelColor(i, strip.Color(200, 250, 0));
        strip.show();
        delay(30);
        strip.setPixelColor(i, strip.Color(100, 250, 0));
        strip.show();
      }
      else{
        strip.setPixelColor(i, strip.Color(200, 250, 0));
        strip.show();
        delay(30);
        strip.setPixelColor(i, strip.Color(100, 250, 0));
        strip.show();
      }
    }
  }
  if(total == 6 && total != last_total){
    for(int i = 0; i < 12; i++){
      strip.setPixelColor(i, strip.Color(50, 200, 250));
    }
    strip.show();
    
  }
  
  last_total = total;
   
  checkBtn(); 

  for (int i = 0; i < 15; i++){
    if(btn[i] == 0){
      digitalWrite(leds[i], 1);
    }
    else{
      digitalWrite(leds[i], 0);
    }
  }
}
