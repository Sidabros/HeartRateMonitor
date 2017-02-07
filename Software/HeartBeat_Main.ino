#include <Nextion.h>
SoftwareSerial HMISerial(10,11);

int pulsePin = 0;               
int blinkPin = 13;              
char buffer[20] = {0};


NexText t1 = NexText(2, 5, "t2"); 
NexProgressBar j2  = NexProgressBar(1, 2, "j2");
NexPage page1    = NexPage(1, 0, "page1");
NexPage page2    = NexPage(2, 0, "page2");
volatile int BPM;                   
volatile int Signal;               
volatile int IBI = 600;             
volatile boolean Pulse = false;    
volatile boolean QS = false;        

volatile unsigned short int kn = 1;      
volatile unsigned short int bpmOld=0;    

void setup(){
  pinMode(blinkPin,OUTPUT);         
  nexInit();            
  interruptSetup();               
 analogReference(INTERNAL);  

}

void loop(){

  if (QS == true)
  {                       
        sendDataToProcessing('B',BPM);          
        QS = false;                      
   }
  delay(20);                           
}


void sendDataToProcessing(char symbol, int data ){
 if(BPM>=45)
 {
    if(BPM == bpmOld)
    { 
          itoa(BPM, buffer, 10);
          t1.setText(buffer);
    }
    bpmOld=BPM;
 }       
}
