#define DS_cot 2
#define DS_hang 3

#define SH_CP_hang 5
#define SH_CP_cot 6

#define ST_CP 4
byte chu[][8] = {
  {0xFF,0xC0,0x80,0xB7,0xB7,0x80,0xC0,0xFF} //A
  };
byte cot = 0b10000000;
void setup() {
  Serial.begin(9600);
  pinMode(ST_CP,OUTPUT);//RCLK
  
  pinMode(DS_hang,OUTPUT);//SER hang
  pinMode(SH_CP_hang,OUTPUT);//SRCLK hang

  pinMode(SH_CP_cot,OUTPUT);//SRCLK cot
  pinMode(DS_cot,OUTPUT);//SER cot
}

void loop() {

  for(int i = 0; i < 8;i++){
    digitalWrite(ST_CP,LOW);
    shiftOut(DS_hang,SH_CP_hang,LSBFIRST,chu[0][i]);// hang 8 - hang 1
    shiftOut(DS_cot,SH_CP_cot,LSBFIRST,cot >> i); // cot 8 - cot 1
    digitalWrite(ST_CP,HIGH);
    delay(1);
  }



}
