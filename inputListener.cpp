#include "inputListener.hpp"

// Constructor Method
inputListenerClass::inputListenerClass(){
    
}
// Destructor Method
inputListenerClass::~inputListenerClass(){

}

void inputListenerClass::Setup(){
    Serial.println("Input listener setup");
    for(uint8_t pin : btnPins){
        pinMode(pin,INPUT_PULLDOWN);
    }
}

// Read button input
int8_t inputListenerClass::BtnInputListener(){
    //Serial.println("Reading input");
    while(true){
        for(uint8_t i = 0; i < 4; i++){
            bool press = digitalRead(btnPins[i]);
            if(!oldBtnVals[i] && press){
                oldBtnVals[i] = press;
                return i;
            }
            oldBtnVals[i] = press;
        }
        delay(50);
    }
}

void inputListenerClass::ButtonDebugger(){
    Serial.println("");
    for(uint8_t i = 0; i < 4; i++){
            bool press = digitalRead(btnPins[i]);
            if(press){
                Serial.print(1);
            }
            else{
                Serial.print(0);
            }
        }
}

bool isAnyButtonPressed(){
    for(uint8_t i = 0; i < 4; i++){
        if(digitalRead(btnPins[i])){
            return true;
        }
    }
    return true;
}