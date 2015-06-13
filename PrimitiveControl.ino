#define wv1p 3
#define wv1n 5
#define wv2p 6
#define wv2n 9
#define wv3p 10
#define wv3n 11

char incomingByte;
void setup(){
  Serial.begin(9600);
  
   pinMode(wv1p,OUTPUT);
   pinMode(wv2p,OUTPUT);
   pinMode(wv3p,OUTPUT);
   pinMode(wv1n,OUTPUT);
   pinMode(wv2n,OUTPUT);
   pinMode(wv3n,OUTPUT);
}
void loop(){
   while(Serial.available()){    
    incomingByte = Serial.read();
    Serial.println(incomingByte);
    if(incomingByte=='u'){
        analogWrite(wv1p,0);
        analogWrite(wv1n,0);
        analogWrite(wv2p,0);
        analogWrite(wv2n,0);
        analogWrite(wv3p,0);
        analogWrite(wv3n,0);
        analogWrite(wv1p,255);
        analogWrite(wv1n,0);
        analogWrite(wv2p,0);
        analogWrite(wv2n,255);
      }
    else if(incomingByte=='l'){
      analogWrite(wv1p,0);
        analogWrite(wv1n,0);
        analogWrite(wv2p,0);
        analogWrite(wv2n,0);
        analogWrite(wv3p,0);
        analogWrite(wv3n,0);
        analogWrite(wv1p,255);
        analogWrite(wv1n,0);
        analogWrite(wv2p,255);
        analogWrite(wv2n,0);
        analogWrite(wv3p,255);
        analogWrite(wv3n,0);
    }
    else if(incomingByte=='r'){
        analogWrite(wv1p,0);
        analogWrite(wv1n,0);
        analogWrite(wv2p,0);
        analogWrite(wv2n,0);
        analogWrite(wv3p,0);
        analogWrite(wv3n,0);
        analogWrite(wv1p,0);
        analogWrite(wv1n,255);
        analogWrite(wv2p,0);
        analogWrite(wv2n,255);
        analogWrite(wv3p,0);
        analogWrite(wv3n,255);
    }
    else if(incomingByte=='d'){
        analogWrite(wv1p,0);
        analogWrite(wv1n,0);
        analogWrite(wv2p,0);
        analogWrite(wv2n,0);
        analogWrite(wv3p,0);
        analogWrite(wv3n,0);
        analogWrite(wv1n,255);
        analogWrite(wv1p,0);
        analogWrite(wv2n,0);
        analogWrite(wv2p,255);
    }
    else if(incomingByte == 's'){
        analogWrite(wv1p,0);
        analogWrite(wv1n,0);
        analogWrite(wv2p,0);
        analogWrite(wv2n,0);
        analogWrite(wv3p,0);
        analogWrite(wv3n,0);
    }
   } 
  
}
 /* else if(!Serial.available()){analogWrite(wv1p,0);
        analogWrite(wv1n,0);
        analogWrite(wv2p,0);
        analogWrite(wv2n,0);
        analogWrite(wv3p,0);
        analogWrite(wv3n,0);}
}
/*
void straight()
{
  digitalWrite(wv1p,HIGH);
  digitalWrite(wv2n,HIGH);
  digitalWrite(wv1n,LOW);
  digitalWrite(wv2p,LOW);
}
void down()
{digitalWrite(wv1p,LOW);digitalWrite(wv2n,LOW);
digitalWrite(wv1n,HIGH);digitalWrite(wv2p,HIGH);
}
void left()
{digitalWrite(wv1p,HIGH);digitalWrite(wv2p,HIGH);digitalWrite(wv3p,HIGH);
digitalWrite(wv1n,LOW);digitalWrite(wv2n,LOW);digitalWrite(wv3n,LOW);
}
void right()
{digitalWrite(wv1n,HIGH);digitalWrite(wv2n,HIGH);digitalWrite(wv3n,HIGH);
digitalWrite(wv1p,LOW);digitalWrite(wv2p,LOW);digitalWrite(wv3p,LOW);
}
*/
