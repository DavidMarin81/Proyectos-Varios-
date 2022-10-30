#define D9 9
#define D10 10
#define D11 11

 
void setup() {
  // put your setup code here, to run once:
 
  
  noInterrupts();
  //pinMode(D9, OUTPUT);
  // pinMode(D10, OUTPUT);
  //pinMode(D11, OUTPUT);

  //PORTB  pins B1 B2 B3 outputs
  DDRB|=(1<<PB1)|(1<<PB2)|(1<<PB3);
  PORTB=0x04; //<<--starting logical levels of PORTB

  //this timer for generating 15900hz
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;
  OCR1A = 500;  //<<--frequency= 8mhz / (OCR1A+1)  
  
  TCCR1B |= (1 << WGM12);   // CTC mode
  TIMSK1 |= (1 << OCIE1A);  //enable interrupt
           
  TCCR1B |= (1 << CS10);    // 1 prescaler paleidzia taimery

  //this timer for generating 10000hz
  TCCR2A = 0;
  TCCR2B = 0;
  TCNT2  = 0;
  OCR2A = 24; //<<--frequency = 250khz /(OCR2A)  
  TCCR2A |=(1 << COM2A0);
  TCCR2A |= (1 << WGM21);   // CTC mode 
  TCCR2B |= (1 << CS20)|(1 << CS21);
   interrupts();   
}

 

ISR(TIMER1_COMPA_vect)          // timer compare interrupt service routine
{
 PORTB^=((1<<PB1)|(1<<PB2)); //toogle port B pins PB1 PB2  using xor
 
}

void loop() {
  // put your main code here, to run repeatedly:

}
