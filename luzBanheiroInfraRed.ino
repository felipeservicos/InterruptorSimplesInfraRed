#include <LowPower.h>

//#include <avr/power.h>
//#include <avr/interrupt.h>      // library for interrupts handling
#include <IRremote.h>
#include <IRremoteInt.h>
#include <boarddefs.h>
#include <ir_Lego_PF_BitStreamEncoder.h>



int RECV_PIN = 2;  
float armazenavalor;  
int pinorele = 10;
bool estado = false;  

  
IRrecv irrecv(RECV_PIN);  
decode_results results;  
  
void setup()  
{  

//  noInterrupts ();
//  CLKPR = bit (CLKPCE);
//  CLKPR = clock_div_2; // jogando o clock para 8mhz
//  interrupts ();
  
  pinMode(pinorele, OUTPUT);   
 
  Serial.begin(9600);  
  irrecv.enableIRIn(); // Inicializa o receptor IR  
}  
   
void loop()  
{  
  

  
  if (irrecv.decode(&results))  
  { 

     
//    Serial.print("Valor lido : ");  
//    Serial.println(results.value, HEX);  
    armazenavalor = (results.value); 
//    Serial.print("armazena valor:");
//    Serial.println(armazenavalor);


//     if (armazenavalor == 0xFF807F || armazenavalor == 0xFF906F) //Verifica se a tecla 5 foi acionada  

     if (armazenavalor != 0xFFFFFFFF || armazenavalor != 0xFFFFFF) //Verifica se qq tecla foi acionada exceto cod 255  

   {  

    if (estado == false) 
    {  
      digitalWrite(pinorele, estado);
      estado=true;    
    }  else{
      digitalWrite(pinorele, estado);
      estado=false;    
      
   }


  }
 
    delay(1000);
    irrecv.resume(); //Le o próximo valor 
//  LowPower.powerStandby(SLEEP_60MS, ADC_OFF, BOD_OFF);
  
}
delay(200);
}
