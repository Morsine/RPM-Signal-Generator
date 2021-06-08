int NbTopsFan; int Calc;


//Connection to control board's PWM output
int hallsensor = 2; typedef struct{
 
//Defines the structure for multiple fans and 
//their dividers 
char fantype;
unsigned int fandiv; }fanspec;
 
//Definitions of the fans
//This is the varible used to select the fan and it's divider,
//set 1 for unipole hall effect sensor
//and 2 for bipole hall effect sensor
fanspec fanspace[3]={{0,1},{1,2},{2,8}}; char fan = 1;
 
void rpm ()
//This is the function that the interupt calls
{ NbTopsFan++; }
 
/********** DEFINITIONS **********/ 


boolean accel = false; 
int x; 
long previousMillis = 0;
unsigned long currentMillis=0;


/********** SETUP **********/ 


void setup() { 
Serial.begin(9600);
// PWM output pin
pinMode(5, OUTPUT); 
pinMode(hallsensor, INPUT);
Serial.begin(9600);
attachInterrupt(0, rpm, RISING);
} 


/********** MAIN LOOP **********/ 

void loop() { 
  NbTopsFan = 0;
 
//Enables interrupts
sei();
 
//Wait 1 second
delay (1000);
 
//Disable interrupts
cli();
 
//Times NbTopsFan (which is apprioxiamately the fequency the fan 
//is spinning at) by 60 seconds before dividing by the fan's divider
Calc = ((NbTopsFan * 60)/fanspace[fan].fandiv);
 
//Prints the number calculated above
Serial.print (Calc, DEC);
Serial.print (" rpm\r\n");
Serial.print (Calc);
 
//Prints " rpm" and a new line
Serial.print (" rpm\r\n");

if (Calc == 0){
  Calc == 5;
}
else {
  tone(5,Calc); 
}


  }
