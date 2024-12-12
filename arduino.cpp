#include <SoftwareSerial.h>

SoftwareSerial bluetooth (4, 2); // TX==4, RX==2 modulo bluetooth
const moisture (A0);
int porcentagem = 0;
long VD=5000;
long ultimaChecagem=0;
long contds=0;

void setup()
{
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop()
{
  int moisture = 0;
  moisture = analogRead(A0);
//transformar a úmidade em porcentagem. sendo 293 100% úmido e 1023 0% úmido
  porcentagem=map(moisture,293,1024,100,0);
  
  delay(20000);//delay de um minuto
  //(como é em millisegundos eu pego a quantidade de minutos, transformo em segundos e multiplico por 1000)
  //Ex:(3min*60s*1000) assim o delay será de 3 minutos
    if (ultimaChecagem<millis()-VD){
    ultimaChecagem=millis();
  }
    else if (moisture < 500) {
    bluetooth.print("PERIGO! ");
    bluetooth.print(porcentagem);
    bluetooth.println("% úmido");
  } else if (moisture < 700) {
    bluetooth.print("Atenção! ");
    bluetooth.print(porcentagem);
    bluetooth.println("% úmido");
  } else if (moisture < 900) {
    bluetooth.print("Pouco Úmido: ");
    bluetooth.print(porcentagem);
    bluetooth.println("% úmido");
  } else if (moisture < 307.2) {
    bluetooth.print("Seco: "); 
    bluetooth.print(porcentagem);
    bluetooth.println("% úmido");
  }
}
