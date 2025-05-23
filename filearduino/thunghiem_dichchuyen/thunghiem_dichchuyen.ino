#define DS_cot 2
#define DS_hang 3

#define SH_CP_hang 5
#define SH_CP_cot 6

#define ST_CP 4
byte chu[][8] = {
  {0xFF,0xC0,0x80,0xB7,0xB7,0x80,0xC0,0xFF}, //A
  {0xFF,0x80,0x80,0xB6,0xB6,0x80,0xC9,0xFF}, //B
  {0xFF,0xC1,0x80,0xBE,0xBE,0x9C,0xDD,0xFF}, //C
  {0xFF,0x80,0x80,0xBE,0xBE,0x80,0xC1,0xFF}, //D
  {0xFF,0x80,0x80,0xB6,0xB6,0xBE,0xBE,0xFF},//E
  {0xFF,0x80,0x80,0xB7,0xB7,0xBF,0xBF,0xFF},//F
  {0xFF,0xC1,0x80,0xBE,0xBA,0x98,0xD9,0xFF},//G
  {0xFF,0x80,0x80,0xF7,0xF7,0x80,0x80,0xFF},//H
  {0xFF,0xFF,0xBE,0x80,0x80,0xBE,0xFF,0xFF},//I
  {0xFF,0xF9,0xF8,0xBE,0x80,0x81,0xBF,0xFF},//J
  {0xFF,0x80,0x80,0xE3,0xC9,0x9C,0xBE,0xFF},//K
  {0xFF,0x80,0x80,0xFE,0xFE,0xFE,0xFE,0xFF},//L
  {0xFF,0x80,0x80,0xCF,0xE7,0xCF,0x80,0x80},//M
  {0xFF,0x80,0x80,0xCF,0xE7,0xF3,0x80,0x80},//N
  {0xFF,0xC1,0x80,0xBE,0xBE,0x80,0xC1,0xFF},//O
  {0xFF,0x80,0x80,0xBB,0xBB,0x83,0xC7,0xFF},//P
  {0xFF,0xC3,0x81,0xBD,0xBD,0x80,0xC2,0xFF},//Q
  {0xFF,0x80,0x80,0xB3,0xB1,0x84,0xCE,0xFF},//R
  {0xFF,0xCD,0x84,0xB6,0xB6,0x90,0xD9,0xFF},//S
  {0xFF,0x9F,0xBF,0x80,0x80,0xBF,0x9F,0xFF},//T
  {0xFF,0x81,0x80,0xFE,0xFE,0x80,0x80,0xFF},//U
  {0xFF,0x83,0x81,0xFC,0xFC,0x81,0x83,0xFF},//V
  {0xFF,0x80,0x80,0xF9,0xF3,0xF9,0x80,0x80},//W
  {0xFF,0x9C,0x88,0xE3,0xF7,0xE3,0x88,0x9C},//X
  {0xFF,0x8F,0x87,0xF0,0xF0,0x87,0x8F,0xFF},//Y
  {0xFF,0xBC,0xB8,0xB2,0xA6,0x8E,0x9E,0xFF},//Z
  {0xFF,0xFE,0xEE,0x80,0x80,0xFE,0xFE,0xFF},//1
  {0xFF,0xDC,0x98,0xBA,0xB6,0x86,0xCE,0xFF},//2
  {0xFF,0xDD,0x9C,0xB6,0xB6,0x80,0xC9,0xFF},//3
  {0xFF,0xF3,0xEB,0xDB,0x80,0x80,0xFB,0xFF},//4
  {0xFF,0x8D,0x8C,0xAE,0xAE,0xA0,0xB1,0xFF},//5
  {0xFF,0xC1,0x80,0xB6,0xB6,0x90,0xD9,0xFF},//6
  {0xFF,0x9F,0x9F,0xB8,0xA0,0x87,0x9F,0xFF},//7
  {0xFF,0xC9,0x80,0xB6,0xB6,0x80,0xC9,0xFF},//8
  {0xFF,0xCD,0x84,0xB6,0xB6,0x80,0xC1,0xFF},//9
  {0xFF,0xC1,0x80,0xAE,0xB6,0x80,0xC1,0xFF},//0
  {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},//space
  
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
  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);// hang 8 - hang 1
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b10000000); // cot 8 - cot 1
  digitalWrite(ST_CP,HIGH);
  delay(1);

  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);// hang 8 - hang 1
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b01000000); // cot 8 - cot 1
  digitalWrite(ST_CP,HIGH);
  delay(1);
    
  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);// hang 8 - hang 1
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b00100000); // cot 8 - cot 1
  digitalWrite(ST_CP,HIGH);
  delay(1);

  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);// hang 8 - hang 1
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b00010000); // cot 8 - cot 1
  digitalWrite(ST_CP,HIGH);
  delay(1);

  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);// hang 8 - hang 1
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b00001000); // cot 8 - cot 1
  digitalWrite(ST_CP,HIGH);
  delay(1);
  
  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);// hang 8 - hang 1
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b00000100); // cot 8 - cot 1
  digitalWrite(ST_CP,HIGH);
  delay(1);

  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);// hang 8 - hang 1
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b00000010); // cot 8 - cot 1
  digitalWrite(ST_CP,HIGH);
  delay(1);

  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);// hang 8 - hang 1
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b00000001); // cot 8 - cot 1
  digitalWrite(ST_CP,HIGH);
  delay(1);
  
////////////////////////
  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b10000000); // cot 8 - cot 1
  digitalWrite(ST_CP,HIGH);
  delay(1);

  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b01000000); // cot 8 - cot 1
  digitalWrite(ST_CP,HIGH);
  delay(1);
    
  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b00100000); // cot 8 - cot 1
  digitalWrite(ST_CP,HIGH);
  delay(1);

  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b00010000); // cot 8 - cot 1
  digitalWrite(ST_CP,HIGH);
  delay(1);

  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b00001000); // cot 8 - cot 1
  digitalWrite(ST_CP,HIGH);
  delay(1);
  
  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b00000100); // cot 8 - cot 1
  digitalWrite(ST_CP,HIGH);
  delay(1);

  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b00000010); // cot 8 - cot 1
  digitalWrite(ST_CP,HIGH);
  delay(1);

  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b00000001); // cot 8 - cot 1
  digitalWrite(ST_CP,HIGH);
  delay(1);
////////////////////////////////////
  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b10000000); // cot 8 - cot 1
  digitalWrite(ST_CP,HIGH);
  delay(1);

  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b01000000); // cot 8 - cot 1
  digitalWrite(ST_CP,HIGH);
  delay(1);
    
  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b00100000); // cot 8 - cot 1
  digitalWrite(ST_CP,HIGH);
  delay(1);

  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b00010000); // cot 8 - cot 1
  digitalWrite(ST_CP,HIGH);
  delay(1);

  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b00001000); // cot 8 - cot 1
  digitalWrite(ST_CP,HIGH);
  delay(1);
  
  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b00000100); // cot 8 - cot 1
  digitalWrite(ST_CP,HIGH);
  delay(1);

  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b00000010); // cot 8 - cot 1
  digitalWrite(ST_CP,HIGH);
  delay(1);

  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b11111111);// hang 8 - hang 1
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b00000001); // cot 8 - cot 1
  digitalWrite(ST_CP,HIGH);
  delay(1);
}
