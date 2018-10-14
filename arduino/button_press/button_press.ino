// Include the Bounce2 library found here :
// https://github.com/thomasfredericks/Bounce2
#include <Bounce2.h>

#define BUTTON_MINUS 12
#define BUTTON_MIDDLE 8
#define BUTTON_PLUS 7

Bounce debouncerMinus = Bounce(); // Instantiate a Bounce object
Bounce debouncerMiddle = Bounce(); // Instantiate a Bounce object
Bounce debouncerPlus = Bounce(); // Instantiate a Bounce object

void setup() {
  
  debouncerMinus.attach(BUTTON_MINUS,INPUT_PULLUP); // Attach the debouncer to a pin with INPUT_PULLUP mode
  debouncerMinus.interval(25); // Use a debounce interval of 25 milliseconds
  debouncerMiddle.attach(BUTTON_MIDDLE,INPUT_PULLUP); // Attach the debouncer to a pin with INPUT_PULLUP mode
  debouncerMiddle.interval(25); // Use a debounce interval of 25 milliseconds
  debouncerPlus.attach(BUTTON_PLUS,INPUT_PULLUP); // Attach the debouncer to a pin with INPUT_PULLUP mode
  debouncerPlus.interval(25); // Use a debounce interval of 25 milliseconds  
  
  Serial.begin(9600);
}

void loop() {

   debouncerMinus.update(); // Update the Bounce instance
   debouncerMiddle.update(); // Update the Bounce instance
   debouncerPlus.update(); // Update the Bounce instance
   
   if ( debouncerMinus.fell() ) {  // Call code if minus button transitions from HIGH to LOW
    Serial.print(0);  
   }
   if ( debouncerMiddle.fell() ) {  // Call code if middle button transitions from HIGH to LOW
    Serial.print(1);  
   }
   if ( debouncerPlus.fell() ) {  // Call code if plus transitions from HIGH to LOW
    Serial.print(2);  
   }
}
