unsigned long simdikizaman =0;
unsigned long eskizaman =0;
unsigned long buton_eskizaman =0;
unsigned long net_zaman=0;

int bir_sayi =0; 
int on_sayi =4;
int yuz_sayi =0;
int bin_sayi =6;

unsigned int sayma_sure = 100000;

int buton_durum =0;

int durum;
  
void setup() {
  pinMode(13,OUTPUT);//birler
  pinMode(12,OUTPUT);//onlar
  pinMode(11,OUTPUT);//yüzler
  pinMode(9,OUTPUT);//binler

  pinMode(0,OUTPUT);//a
  pinMode(1,OUTPUT);//b
  pinMode(2,OUTPUT);//c
  pinMode(3,OUTPUT);//d
  pinMode(4,OUTPUT);//e
  pinMode(5,OUTPUT);//f
  pinMode(6,OUTPUT);//g

  pinMode(7,INPUT_PULLUP);//g

  simdikizaman = micros();
  eskizaman = micros();
  buton_eskizaman = micros();
}

void loop() {
 simdikizaman = micros();
 switch(buton_durum){
      case 0:
        ileri_say();
        break;
      case 1:
        //dur
        break;
      case 2:
        geri_say();
        break;
      case 3:
        //dur
        break;
    }
  ekran_yazdir(bin_sayi,yuz_sayi,on_sayi,bir_sayi);
  
  durum =digitalRead(7);
  if(durum ==0){
    buton_durum++;
    if(buton_durum==4){
      buton_durum=0;
    }
    while(!digitalRead(7)){basamak_kapi(0);};
  }
  
}
void ileri_say(){
  if(simdikizaman - buton_eskizaman >= sayma_sure)
    {
      bir_sayi++;
      if(bir_sayi ==10){
        bir_sayi=0;
        on_sayi++;
        if(on_sayi == 10){
          on_sayi=0;
          yuz_sayi++;
          if(yuz_sayi == 10){
            yuz_sayi=0;
            bin_sayi++;
            if(bin_sayi==10){
              bin_sayi=0;
              }
            }
        }
      }
      buton_eskizaman = simdikizaman;
    }
  }
void geri_say(){
  if(simdikizaman - buton_eskizaman >= sayma_sure)
  {
     if(bir_sayi==0){
      bir_sayi=10;
      if(on_sayi==0){
        on_sayi=10;
        if(yuz_sayi==0){
          yuz_sayi=10;
          if(bin_sayi == 0){
            bin_sayi=10;
            }
            bin_sayi--;
          }
          yuz_sayi--;
        }
        on_sayi--;
      }
      bir_sayi--;
     buton_eskizaman = simdikizaman; 
    }
  }

void ekran_yazdir(int birler,int onlar,int yuzler,int binler){
  net_zaman = simdikizaman - eskizaman;
  if(net_zaman >=0 && net_zaman <= 2000){
    basamak_kapi(0);
    ekran_yazi(birler);
    basamak_kapi(1);
    }
  else if(net_zaman >2000 && net_zaman <= 4000){
    basamak_kapi(0);
    ekran_yazi(onlar);
    basamak_kapi(2);
    }
  else if(net_zaman >4000 && net_zaman <= 6000){
    basamak_kapi(0);
    ekran_yazi(yuzler);
    basamak_kapi(3);
    }
  else if(net_zaman >6000 && net_zaman <= 8000){
    basamak_kapi(0);
    ekran_yazi(binler);
    basamak_kapi(4);
    }
  else {
    eskizaman = simdikizaman;
    }
  }
void basamak_kapi(int basamak){
  switch(basamak){
    case 0:
      digitalWrite(13,LOW);
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
      digitalWrite(9,LOW);
      break;
    case 1:
      digitalWrite(13,HIGH);
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
      digitalWrite(9,LOW);
      break;
    case 2:
      digitalWrite(13,LOW);
      digitalWrite(12,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(9,LOW);
      break; 
    case 3:
      digitalWrite(13,LOW);
      digitalWrite(12,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(9,LOW);
      break;
    case 4:
      digitalWrite(13,LOW);
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
      digitalWrite(9,HIGH);
      break;
    }
  
  }

void ekran_yazi(int i){
  switch (i){
    case 0:
      sifir();
      break;
    case 1:
      bir();
      break;
    case 2:
      iki();
      break;
    case 3:
      uc();
      break;
    case 4:
      dort();
      break;
    case 5:
      bes();
      break;
    case 6:
      alti();
      break;
    case 7:
      yedi();
      break;
    case 8:
      sekiz();
      break;
    case 9:
      dokuz();
      break;
  }
  }
void sifir(){
  digitalWrite(0,HIGH);
  digitalWrite(1,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  }
void bir(){
  digitalWrite(1,HIGH);
  digitalWrite(2,HIGH);

  digitalWrite(0,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  }
void iki(){
  digitalWrite(0,HIGH);
  digitalWrite(1,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);

  digitalWrite(2,LOW);
  digitalWrite(5,LOW);
  }
void uc(){
  digitalWrite(0,HIGH);
  digitalWrite(1,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);

  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  }
void dort(){
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(1,HIGH);
  digitalWrite(2,HIGH);

  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(0,LOW);
  }
void bes(){
  digitalWrite(0,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);

  digitalWrite(1,LOW);
  digitalWrite(4,LOW);
  }
void alti(){
  digitalWrite(0,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);

  digitalWrite(1,LOW);
  }
void yedi(){
  digitalWrite(0,HIGH);
  digitalWrite(1,HIGH);
  digitalWrite(2,HIGH);

  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  }
void sekiz(){
  digitalWrite(0,HIGH);
  digitalWrite(1,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  }
void dokuz(){
  digitalWrite(0,HIGH);
  digitalWrite(1,HIGH);
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);

  digitalWrite(4,LOW);
  }
