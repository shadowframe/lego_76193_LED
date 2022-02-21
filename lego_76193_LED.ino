int SER_Pin = 8;   //pin 14 on the 75HC595
int RCLK_Pin = 9;  //pin 12 on the 75HC595
int SRCLK_Pin = 10; //pin 11 on the 75HC595

//How many of the shift registers - change this
#define number_of_74hc595s 2

//do not touch
#define numOfRegisterPins number_of_74hc595s * 8

boolean registers[numOfRegisterPins];

void setup(){
  Serial.begin(9600);
  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);


  //reset all register pins
  clearRegisters();
  writeRegisters();
}               


//set all register pins to LOW
void clearRegisters(){
  for(int i = numOfRegisterPins - 1; i >=  0; i--){
     registers[i] = LOW;
  }
} 


//Set and display registers
//Only call AFTER all values are set how you would like (slow otherwise)
void writeRegisters(){

  digitalWrite(RCLK_Pin, LOW);

  for(int i = numOfRegisterPins - 1; i >=  0; i--){
    digitalWrite(SRCLK_Pin, LOW);

    int val = registers[i];

    digitalWrite(SER_Pin, val);
    digitalWrite(SRCLK_Pin, HIGH);

  }
  digitalWrite(RCLK_Pin, HIGH);

}

//set an individual pin HIGH or LOW
void setRegisterPin(int index, int value){
  registers[index] = value;
}


void loop(){

  // Cockpit LILA Lights
  setRegisterPin(0, HIGH);
  setRegisterPin(1, HIGH);
  setRegisterPin(2, HIGH);
  setRegisterPin(3, HIGH);

  // Wing Left BLUE Lights
  setRegisterPin(4, LOW);
  setRegisterPin(5, LOW);
  setRegisterPin(6, LOW);
  setRegisterPin(7, LOW);

  // Wing Right BLUE Lights
  setRegisterPin(8, LOW);
  setRegisterPin(9, LOW);
  setRegisterPin(10, LOW);
  setRegisterPin(11, LOW);

  // Backwing Left BLUE Lights
  setRegisterPin(12, LOW);

  // Backwing Right BLUE Lights
  setRegisterPin(13, LOW);

  // Headlight RED Light
  setRegisterPin(14, LOW);

  // not used
  setRegisterPin(15, LOW);

  Serial.println("hell");

  writeRegisters();  //MUST BE CALLED TO DISPLAY CHANGES
  //Only call once after the values are set how you need.

  delay(1000);

  // Cockpit LILA Lights
  setRegisterPin(0, LOW);
  setRegisterPin(1, LOW);
  setRegisterPin(2, LOW);
  setRegisterPin(3, LOW);

  // Wing Left BLUE Lights
  setRegisterPin(4, LOW);
  setRegisterPin(5, LOW);
  setRegisterPin(6, LOW);
  setRegisterPin(7, LOW);

  // Wing Right BLUE Lights
  setRegisterPin(8, LOW);
  setRegisterPin(9, LOW);
  setRegisterPin(10, LOW);
  setRegisterPin(11, LOW);

  // Backwing Left BLUE Lights
  setRegisterPin(12, LOW);

  // Backwing Right BLUE Lights
  setRegisterPin(13, LOW);

  // Headlight RED Light
  setRegisterPin(14, LOW);

  // not used
  setRegisterPin(15, LOW);

  Serial.println("dunkel");

  
  writeRegisters();  //MUST BE CALLED TO DISPLAY CHANGES
  //Only call once after the values are set how you need.

   delay(1000);
}

void cockpitOn() {
  // turn the Cockpitlights on
  // Cockpit LILA Lights
  setRegisterPin(0, HIGH);
  setRegisterPin(1, HIGH);
  setRegisterPin(2, HIGH);
  setRegisterPin(3, HIGH);
}

void cockpitOff() {
  // turn the CockpitLights off
  // Cockpit LILA Lights
  setRegisterPin(0, LOW);
  setRegisterPin(1, LOW);
  setRegisterPin(2, LOW);
  setRegisterPin(3, LOW);
}

void wingLeftOn() {
  // turn the wingLeftLights on
  // Wing Left BLUE Lights
  setRegisterPin(4, HIGH);
  setRegisterPin(5, HIGH);
  setRegisterPin(6, HIGH);
  setRegisterPin(7, HIGH); 
}

void wingLeftOff() {
  // turn the wingLeftLights off
  // Wing Left BLUE Lights
  setRegisterPin(4, LOW);
  setRegisterPin(5, LOW);
  setRegisterPin(6, LOW);
  setRegisterPin(7, LOW); 
}

void wingRightOn() {
  // turn the wingRightLights on
  // Wing Right BLUE Lights
  setRegisterPin(8, HIGH);
  setRegisterPin(9, HIGH);
  setRegisterPin(10, HIGH);
  setRegisterPin(11, HIGH); 
}

void wingRightOff() {
  // turn the wingRightLights off
  // Wing Right BLUE Lights
  setRegisterPin(8, LOW);
  setRegisterPin(9, LOW);
  setRegisterPin(10, LOW);
  setRegisterPin(11, LOW);
}