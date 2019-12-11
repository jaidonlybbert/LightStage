const int grnDataPin = 2;
const int grnLoadPin = 3;
const int resetPin = 4;
const int rdylDataPin = 5;
const int rdylLoadPin = 9;
const int rdyrDataPin = 6;
const int rdyrLoadPin = 10;
const int whtDataPin = 7;
const int whtLoadPin = 11;
const int blueDataPin = 8;
const int blueLoadPin = 12;
const int loadPins[] = {3, 9, 10, 11, 12};


class PinSet {
  int dataPin;
  int loadPin;
  int numLeds;
  
  public:
    PinSet(int dataPin, int loadPin, int numLeds) {
      this->dataPin = dataPin;
      this->loadPin = loadPin;
      this->numLeds = numLeds;
    }
};


class PinState {
  public:
    int numPins;
    int* ptr_stateArray;
    PinState(int numPins) {
      int state[numPins];
      this->ptr_stateArray = &state[0]; // point to first element of array
    }
    
    void update(const int *ptr_valueArray) {  // take address of first element of external array, and store as pointer
      for (int i = 0; i < this->numPins; i++) {
        *(this->ptr_stateArray + i) = *(ptr_valueArray + i); // copy external array to class member
      }
    }
};
  


void serialUpdate(int dataPin, int loadPin, int pinStatus[]) {
  for (int i = 0; i < 5; i++) {
    if (pinStatus[i] == 1) {
      digitalWrite(dataPin, HIGH);
    } else if (pinStatus[i] == 0) {
      digitalWrite(dataPin, LOW);
    }
    
    delay(1);
    digitalWrite(loadPin, HIGH);
    delay(1);
    digitalWrite(loadPin, LOW);
    delay(1000);
  }
}


void setup() {
  for (int i = 2; i < 13; i++) {
    pinMode(i, OUTPUT);
  }
  
  int stateArray[5] = {1, 0, 1, 0, 1};
  PinState grnState(5);
  PinSet grnSet(grnDataPin, grnLoadPin, 5);
  

}


void loop() {
  digitalWrite(4, LOW);
  delay(10);
  digitalWrite(4, HIGH);
 
  int pinStatus[] = {1, 0, 1, 0, 1};
  serialUpdate(grnDataPin, grnLoadPin, pinStatus);
  
  serialUpdate(rdylDataPin, rdylLoadPin, pinStatus);
}
