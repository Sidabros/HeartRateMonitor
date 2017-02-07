
volatile int rate[10];                    
volatile unsigned long sampleCounter = 0;       
volatile unsigned long lastBeatTime = 0;          
volatile int thresh = 512;                
volatile int amp = 100;                 
volatile boolean firstBeat = true;       
volatile boolean secondBeat = true;       

void interruptSetup(){     
 
  delay(4000);
  TCCR2A = 0x02;     
  TCCR2B = 0x06;    
  OCR2A = 0X7C;      
  TIMSK2 = 0x02;     
  sei();          
} 



ISR(TIMER2_COMPA_vect){                         
    cli();                                      
    Signal = analogRead(pulsePin);              
    sampleCounter += 2;                         
    int N = sampleCounter - lastBeatTime;       

if (N > 250){                                   /
  if ( (Signal > thresh) && (Pulse == false) && (N > (IBI/5)*3) ){        
    Pulse = true;                              
    digitalWrite(blinkPin,HIGH);                
     j2.setValue(100);
    IBI = sampleCounter - lastBeatTime;         
    lastBeatTime = sampleCounter;              
         
         if(firstBeat){                         
             firstBeat = false;                 
             return;                           
            }   
         if(secondBeat){                        
            secondBeat = false;                
               for(int i=0; i<=9; i++){       
                    rate[i] = IBI;                      
                    }
            }
          
    word runningTotal = 0;                    

    for(int i=0; i<=8; i++){               
          rate[i] = rate[i+1];              
          runningTotal += rate[i];          
        }
        
    rate[9] = IBI;                         
    runningTotal += rate[9];              
    runningTotal /= 10;                
    BPM = 60000/runningTotal;              
    QS = true;                            
    if(kn==1)
    {
      page2.show();
      kn=0;
    }
    }                       
}

  if (Signal < thresh && Pulse == true){    
      digitalWrite(blinkPin,LOW);    
       j2.setValue(0);
      Pulse = false;                    
     }
  
  if (N > 2500){                  
      thresh = 512;                       
      lastBeatTime = sampleCounter;            
      firstBeat = true;                    
      secondBeat = true;                   
      
      if(kn==0)
      {
         page1.show();
         kn =1;
      }
     }
  
  sei();                                     
}



