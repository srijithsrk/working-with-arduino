/* 
   Udemy Course: Crazy about Arduino - Your End-to-End Workshop - Level 2 
   Website: https://www.udemy.com/crazy-about-arduino-your-end-to-end-workshop-level-2/
   Description: Step-1- Matrix Keypad  
   Author: Idan Gabrieli
*/
// ******************************************
#include <Keypad.h>
// ******************************************
// Keypad variables declaration
// ******************************************
const byte keypadRows = 4; //number of rows on the keypad
const byte keypadCols = 4; //number of columns on the keypad

// keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[keypadRows][keypadCols]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

//Mapping the keypad connections to the arduino terminals 
byte rowPins[keypadRows] = {9,8,7,6}; 
byte colPins[keypadCols]= {5,4,3,2};  

//Creating and initializes an instance of the Keypad class called "myKeypad" using the constructor 
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, keypadRows, keypadCols);

// ******************************************
void setup()
{
// setting keypad parameters   
  myKeypad.setHoldTime(100);            // Key held time in ms
  myKeypad.setDebounceTime(100);        // Key Debounce time in ms
// initialize serial port
  Serial.begin(9600);       
}
// ******************************************
void loop()
{
  readKeypadButton();
//  readKeypadNumber();
}
// ******************************************
// Keypad Functions 
// ******************************************
void readKeypadButton()
{
  char key = myKeypad.getKey();
  if (key != NO_KEY)  // Check if a key was pressed  
  {
    Serial.print(key); // print key value to the serial monitoring screen 
  }
}
// ******************************************
void readKeypadNumber()
{
  char key;
  String intString ="";
  Serial.println("*****************************************");  
  Serial.println("Please enter a number,");
  Serial.println("when finish please press #");
  do {
        key = myKeypad.getKey();     
        if (key != NO_KEY) {  
          Serial.println(key);
          if (key!='#') intString=intString+key;  // store the new character 
        }
 } while (key!='#');
  Serial.print("The Number is:");
  Serial.println(intString.toInt());
  delay(1000);
}
// ******************************************

