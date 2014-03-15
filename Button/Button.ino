#define first_listening   0
#define second_listening  1
#define third_listening   2


const int buttonPin = 2;  
const int redPin    = 13;
const int greenPin  = 12;  
const int yellowPin = 11;  

int buttonState = first_listening; 
int readValue = 0;

void setup() {
  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(buttonPin, INPUT);     
  
  Serial.begin(9600); 
            
}

void loop(){
   
   switch (buttonState) {
     
        case first_listening:
            Serial.println("first_listening");  
            while (digitalRead(buttonPin) == LOW){}//waiting for pressing the button
            //when pressing the button , waiting for unpressing it
            while (digitalRead(buttonPin) == HIGH) {
                digitalWrite(yellowPin, LOW);
                
                //blink red led
                digitalWrite(redPin, HIGH);
                delay(500);
                digitalWrite(redPin, LOW);
                delay(500);
                digitalWrite(redPin, HIGH);
            }
            buttonState = second_listening;      
            break;
            
        case second_listening:
            Serial.println("second_listening");
            while (digitalRead(buttonPin) == LOW){}//waiting for pressing the button
            //when pressing the button , waiting for unpressing it
            while (digitalRead(buttonPin) == HIGH) {
                digitalWrite(redPin, LOW);
                //blink red led
                digitalWrite(greenPin, HIGH);
                delay(500);
                digitalWrite(greenPin, LOW);
                delay(500);
                digitalWrite(greenPin, HIGH);

            }
            buttonState = third_listening; 
                     
            break;
            
        case third_listening:
            Serial.println("third_listening"); 
            while (digitalRead(buttonPin) == LOW){}//waiting for pressing the button
            //when pressing the button , waiting for unpressing it
            while (digitalRead(buttonPin) == HIGH) {
                digitalWrite(greenPin, LOW);
                //blink red led
                digitalWrite(yellowPin, HIGH);
                delay(500);
                digitalWrite(yellowPin, LOW);
                delay(500);
                digitalWrite(yellowPin, HIGH);
        
            }
            buttonState = first_listening;              
            break;       
    }
  
}
