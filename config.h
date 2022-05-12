int incomingByte;      // a variable to read incoming serial data into

// All servos
Servo monServoR; // rolling neck
Servo monServoH;  // horizontal neck
Servo monServoV;  // vertical neck
Servo monServoJaw; // jaw
Servo monServoX;  // eyes X (horizontal)
Servo monServoY;  // eyes Y (vertical)  
Servo monServoLids;  // Lids


// Epaules
CapacitiveSensor   epaule_gauche = CapacitiveSensor(67, 68);       
CapacitiveSensor   epaule_droite = CapacitiveSensor(65, 66);    

// PIR
#define pinPIR 23;
int PIR = pinPIR;
int pirState = LOW; // we start, assuming no motion detected
int val = 0;

// SR04
#define pinTrig 64
#define pinEcho 63
SR04 sr04 = SR04(pinEcho, pinTrig);
long a;

// Audio 
int pinBusy = A4;
DFRobotDFPlayerMini myMP3;
int audioVal;
int audioVal1;
int audioVal2;
int audioVal3;
int song = 1;
int previousSong;

// Micro
int Micropin = 62; //A8
int Microval;


// ======== FUNCTIONS ======= //

// attach all
void attachAll() {
    monServoR.attach(pinR);
    monServoH.attach(pinH);
    monServoV.attach(pinV);
    monServoJaw.attach(pinJaw);
    monServoLids.attach(pinLids);
    monServoX.attach(pinX);
    monServoY.attach(pinY);
}

// detach all
void detachAll() {
    monServoR.detach();
    monServoH.detach();
    monServoV.detach();
    monServoJaw.detach();
    monServoLids.detach();
    monServoX.detach();
    monServoY.detach();
}



// setup
void Setup() {
    attachAll();

    epaule_gauche.set_CS_AutocaL_Millis(0xFFFFFFFF);     
    epaule_droite.set_CS_AutocaL_Millis(0xFFFFFFFF);       

    Serial.begin(115200);
    Serial2.begin(9600);
    myMP3.begin(Serial2);

    myMP3.stop();
    delay(20);



}

//// initialization
//bool closed;
//void Initialize(bool closed) {
//    monServoR.write(medR);
//    monServoH.write(medH); 
//    monServoV.write(medV);
//    monServoJaw.write(medJaw);       
//    monServoX.write(medX); 
//    monServoY.write(medY);   
//
//   if (closed) {
//        monServoLids.write(maxLids);
//   }
//   else {
//       monServoLids.write(minLids);
//   }
//
//       
//}


// rolling neck
void sweepR(int position2, int t) {
    int position1 = monServoR.read();
    if (position1 < position2) {
        for (int position = position1; position <= position2; position++) {
            monServoR.write(position);
            delay(t);
        }
    }
    if (position1 > position2) {
        for (int position = position1; position >= position2; position--) {
            monServoR.write(position);
            delay(t);
        }
    }
    monServoR.write(position2);
}
void SweepR(int t, int T, int I) {
    for (int i = 1; i <= I; i++) {
        sweepR(maxR, t);
        delay(T);
        sweepR(minR, t);
        delay(T);
        sweepR(medR, t);
        delay(T);
    }
}

// horizontal neck
void sweepH(int position2,int t) {
    int position1 = monServoH.read();
    if (position1<position2) {
      for (int position = position1; position <=position2; position ++){ 
      monServoH.write(position); 
      delay(t); 
    }
  }
    if (position1>position2) {
      for (int position = position1; position >=position2; position --){
      monServoH.write(position); 
      delay(t);  
    }   
  }
     monServoH.write(position2);
}

void SweepH(int t, int T, int I) {
  for (int i = 1; i<=I; i ++){ 
    sweepH(maxH,t);
    delay(T);
    sweepH(minH,t);
    delay(T);
    sweepH(medH,t);
    delay(T);
    }
}

// vertical neck
void sweepV(int position2,int t) {
    int position1 = monServoV.read();
    if (position1<position2) {
      for (int position = position1; position <=position2; position ++){ 
      monServoV.write(position); 
      delay(t); 
    }
  }
    if (position1>position2) {
      for (int position = position1; position >=position2; position --){
      monServoV.write(position); 
      delay(t);  
    }   
  }
     monServoV.write(position2);
}

void SweepV(int t, int T, int I) {
  for (int i = 1; i<=I; i ++){ 
    sweepV(maxV,t);
    delay(T);
    sweepV(minV,t);
    delay(T);
    sweepV(medV,t);
    delay(T);
  }
}


// Jaw
void sweepJaw(int position2,int t) {
    int position1 = monServoJaw.read();
    if (position1<position2) {
      for (int position = position1; position <=position2; position ++){ 
      monServoJaw.write(position); 
      delay(t); 
    }
  }
    if (position1>position2) {
      for (int position = position1; position >=position2; position --){
      monServoJaw.write(position); 
      delay(t);  
    }   
  }
     monServoJaw.write(position2);
}

void SweepJaw(int t, int T, int I) {
  for (int i = 1; i<=I; i ++){ 
    sweepJaw(maxJaw,t);
    delay(T);
    sweepJaw(minJaw,t);
    delay(T);
  }
}


// Eyes X
void sweepX(int position2, int t) {
    int position1 = monServoX.read();
    if (position1 < position2) {
        for (int position = position1; position <= position2; position++) {
            monServoX.write(position);
            delay(t);
        }
    }
    if (position1 > position2) {
        for (int position = position1; position >= position2; position--) {
            monServoX.write(position);
            delay(t);
        }
    }
    monServoX.write(position2);
}

void SweepX(int t, int T, int I) {
    for (int i = 1; i <= I; i++) {
        sweepX(maxX, t);
        delay(T);
        sweepX(minX, t);
        delay(T);
        sweepX(medX, t);
        delay(T);
    }
}

// Eyes Y
void sweepY(int position2, int t) {
    int position1 = monServoY.read();
    if (position1 < position2) {
        for (int position = position1; position <= position2; position++) {
            monServoY.write(position);
            delay(t);
        }
    }
    if (position1 > position2) {
        for (int position = position1; position >= position2; position--) {
            monServoY.write(position);
            delay(t);
        }
    }
    monServoY.write(position2);
}

void SweepY(int t, int T, int I) {
    for (int i = 1; i <= I; i++) {
        sweepY(maxY, t);
        delay(T);
        sweepY(minY, t);
        delay(T);
        sweepY(medY, t);
        delay(T);
    }
}


// Lids
void sweepLids(int position2, int t) {
    int position1 = monServoLids.read();
    if (position1 < position2) {
        for (int position = position1; position <= position2; position++) {
            monServoLids.write(position);
            delay(t);
        }
    }
    if (position1 > position2) {
        for (int position = position1; position >= position2; position--) {
            monServoLids.write(position);
            delay(t);
        }
    }
    monServoLids.write(position2);
}

// Opening eyes
void openEyes(int t) {
    sweepX(medX, 5);
    sweepY(medY, 5);
    for (int position = monServoLids.read(); position >= minLids; position--) {
            monServoLids.write(position);
            delay(t);
        }
    monServoLids.write(minLids);
}

// Closing eyes
void closeEyes(int t) {
    sweepX(medX, 5);
    sweepY(medY, 5);
    for (int position = monServoLids.read(); position <= maxLids; position++) {
        monServoLids.write(position);
        delay(t);
    }
    monServoLids.write(maxLids);
}

// initialization2
bool closed;
void Initialize2(bool closed) {
    sweepR(medR, 10);
    sweepH(medH, 20);
    sweepV(medV, 20);
    sweepJaw(minJaw, 10);
    sweepX(medX, 20);
    sweepY(medY, 20);

    if (closed) {
        closeEyes(3);
    }
    else {
        openEyes(2);
    }


}

// position DODO
void Dodo() {
    sweepX(medX, 20);
    sweepY(medY, 20);
    closeEyes(10);
    sweepR(maxR, 10);
    sweepH(130, 20);
    sweepV(0, 20);
    sweepJaw(0, 10);
}

// Baillement
void bailler() {
    Initialize2(true);
    myMP3.volume(30);
    myMP3.play(7);
    closeEyes(3);
    sweepJaw(maxJaw, 5);
    delay(2500);
    sweepJaw(minJaw, 5);
    Initialize2(true);
}

// Sommeil
//void sommeil(int tempsLeger) {
//     Dodo();
//     timed = millis();
//    // au début: sommeil agité / léger
//    int new_time = millis();
//    Serial.println(new_time - timeDebut);
//    if (new_time - timeDebut < tempsLeger) {
//        if (new_time - dodo_time > 3000) {
//            sweepH(110, 10);
//            delay(600);
//            sweepH(90, 10);
//            delay(100);
//            dodo_time = millis();
//        }
//    }
//    // au bout d'un moment : sommeil profond. Robobo ne bouge plus
//    if (new_time - timeDebut > tempsLeger) {
//        Dodo();
//    }
//}


// Volume: reducing of increasing progressively
void Volume(int vol1, int vol2, int t) {
    if (vol1 < vol2) {
        for (int vol = vol1; vol <= vol2; vol++) {
            myMP3.volume(vol);
            delay(t);
        }
    }

    if (vol1 > vol2) {
        for (int vol = vol1; vol >= vol2; vol--) {
            myMP3.volume(vol);
            delay(t);
        }
    }
}