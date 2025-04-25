#define DS_cot 2
#define DS_hang 3

#define SH_CP_hang 5
#define SH_CP_cot 6

#define ST_CP 4
void setup() {
  pinMode(ST_CP,OUTPUT);//RCLK
  
  pinMode(DS_hang,OUTPUT);//SER hang
  pinMode(SH_CP_hang,OUTPUT);//SRCLK hang

  pinMode(SH_CP_cot,OUTPUT);//SRCLK cot
  pinMode(DS_cot,OUTPUT);//SER cot

}

void loop() {
  //cot -
  digitalWrite(ST_CP,LOW);
  shiftOut(DS_cot,SH_CP_cot,LSBFIRST,0b11111111);
  digitalWrite(ST_CP,HIGH);
  //hang -
  digitalWrite(ST_CP,LOW);
  shiftOut(DS_hang,SH_CP_hang,LSBFIRST,0b00000000);
  digitalWrite(ST_CP,HIGH);

}
