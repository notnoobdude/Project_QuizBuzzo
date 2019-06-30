#define button1 1 //the number of the button 1
#define button2 2
#define button3 3
#define button4 4
#define button5 5
#define button6 6
#define buzzerPin 7
#define LED1 8
#define LED2 9
#define LED3 10
#define LED4 11
#define LED5 12
#define LED6 13
#define uint8 unsigned char
uint8 flag = 0; //used to indicate the state of button4 key
uint8 b1State, b2State, b3State, b4State, b5State, b6State = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  //initialize button1, button2, and button3 as input, combined with pullup
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);
  pinMode(button6, INPUT_PULLUP);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED6, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  //read the state of the button4
  b6State = digitalRead(button6); //b6state = digitalRead(button6);
  //when button6 pressed
  if(b6State == 0)
  {
    if(b6State == 0) //confirm that the button is pressed
    {
      flag = 1;  //if so, flag is 1
      digitalWrite(LED6, HIGH); //turn the host LED on
      delay(200);
    }
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW); 
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  }

  if(1 == flag)
  {
    //read the state of the button of buttons
    b1State = digitalRead(button1);
    b2State = digitalRead(button2);
    b3State = digitalRead(button3);
    b4State = digitalRead(button4);
    b5State = digitalRead(button5);
    b6State = digitalRead(button6);
    
    //If button1, press the first
    if(b1State == 0)
    {
      flag = 0;
      digitalWrite(LED1, HIGH);//turn on LED1 only
      Alarm(); //buzzer sound
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      while(digitalRead(button6)); //detect the button4 
    }


    if(b2State == 0)
    {
      flag = 0;
     digitalWrite(LED2, HIGH);
      Alarm(); //buzzer sound
      digitalWrite(LED1, LOW); //turn on LED1 only
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      while(digitalRead(button6)); //detect the button4 
    }

    if(b3State == 0)
    {
      flag = 0;
      digitalWrite(LED3, HIGH);
      Alarm(); //buzzer sound
      digitalWrite(LED1, LOW); //turn on LED1 only
      digitalWrite(LED2, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      while(digitalRead(button6)); //detect the button4 
    }

   if(b4State == 0)
   {
    flag = 0;
      digitalWrite(LED4, HIGH);
      Alarm(); //buzzer sound
      digitalWrite(LED1, LOW); //turn on LED1 only
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      while(digitalRead(button6)); //detect the button4 
    }

    if(b5State == 0)
   {
    flag = 0;
    digitalWrite(LED5, HIGH);
    Alarm(); //buzzer sound
    digitalWrite(LED1, LOW); //turn on LED1 only
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED6, LOW);
    while(digitalRead(button6)); //detect the button4 
   }
    
  }
}

void Alarm()
{
  for(int i=0;i<100;i++)
  {
    digitalWrite(buzzerPin, HIGH); //buzzer sound
    delay(10);
    digitalWrite(buzzerPin, LOW); //buzzer sound
    delay(2);
  }
}
