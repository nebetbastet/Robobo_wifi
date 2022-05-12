////////////// Micro geste /////////////////////////
// Micro geste 1
// regarder de gauche à droite rapidement
void microGesture1() {
        sweepX(maxX, 5);
        delay(200);
        sweepX(minX, 5);
        delay(80);
        sweepX(medX, 5);
    }

// Micro geste 2
// Clignement
void microGesture2() {
    closeEyes(5);
    openEyes(2);
}

// Micro geste 3
// Regard vers la droite
void microGesture3() {
    sweepX(maxX, 5);
    delay(150);
    sweepX(medX, 5);
}

// Micro geste 4
// Regard vers la gauche avec clignement
void microGesture4() {
    sweepX(minX, 5);
    delay(300);
    sweepLids(maxLids,5);
    delay(150);
    sweepX(medX, 5);
    sweepLids(minLids, 5);
    openEyes(2);
}


// Random
int i;
void RandomMicroGesture() {
    i = random(1, 6);
    if (i == 1) {
        microGesture1();
    }
    if (i == 2) {
        microGesture2();
    }
    if (i == 3 || i == 5) {
        microGesture3();
    }
    if (i == 4) {
        microGesture4();
    }
}

// Micro gesture bruit
// Baisse rapidement un peu la tête et cligne des yeux
void Bruit() {
    closeEyes(5);
    sweepV(130, 20);        
    sweepV(medH, 20);
    openEyes(2);
}

//////////// Petits gestes ///////////////////

// Petit geste 1
// regarder de gauche à droite
void smallGesture1(int t,int T, int I, int Max, int Min) {
    //openEyes(10);
    sweepY(minY, 1);
    delay(500);
    for (int i = 1; i <= I; i++) {
        sweepX(Max, t);
        delay(T);
        sweepX(Min, t);
        delay(T);
        sweepX(medX, t);
        delay(T);
    }
    delay(500);
    sweepY(medY, 1);
    //closeEyes(5);
}

// Petit geste 2
// Tourner la tête
void smallGesture2(int tH, int tX, int T, int angleH, int angleX) {
    sweepH(angleH, tH);
    //openEyes(10);
    sweepX(angleX, tX);
    delay(T);
    sweepX(medX, tX);
    delay(T);
    //closeEyes(5);
    sweepH(100,tH);
    sweepH(medH, tH);
}

// Petit geste 3
// Lever/baisser la tête
void smallGesture3(int tV, int tX, int T, int angleV, int angleX) {
    sweepV(angleV, tV);
    //openEyes(10);
    sweepX(angleX, tX);
    delay(T);
    sweepX(medX, tX);
    delay(T);
    //closeEyes(10);
    sweepV(medV, tV);
}
// Petit geste 4
// Lever la tête
void smallGesture4() {
    Initialize2(false);

    Serial.println("Lever la tête ");
    // Lever la tête
    sweepV(maxV, 20);
    monServoV.write(maxV);

    // Pencher légèrement la tête
    int medR2 = medR + 10;
    int diff = medH - medR;
    for (int position = medR; position <= medR2; position++) {
        int positionH = position + diff;
        // monServoR.write(position);
        monServoH.write(positionH);
        delay(10);
    }
    delay(1000);

    Serial.println("Lever les yeux ");
    //Lever les yeux
    sweepY(minY, 10);
    monServoY.write(minY);

    // Regard intense
    for (int i = 1; i <= 5; i++) {
        sweepX(100, 10);
        delay(100);
        sweepX(80, 10);
        delay(200);
        sweepX(medX, 10);
        delay(120);
    }

    // Closing eyes
    //closeEyes(10);

    // Baisser la tête
    sweepV(medV, 20);

    // Remetter la tête droite
    for (int position = medR2; position >= medR; position--) {
        int positionH = position + diff;
        //monServoR.write(position);
        monServoH.write(positionH);
        delay(10);
    }
    sweepH(90, 20);
    sweepH(medH, 20);

    // Ouvrir les yeux
    openEyes(10);

    Initialize2(false);

}

//////////// Petits gestes aléatoire ///////////////////
// random Gesture
void RandomGesture() {
    i = random(1, 6);
    Serial.println(i);
    if (i == 1) {
        Serial.println("Petit geste 1");
        smallGesture1(10, 10, 1, maxX, minX);
    }
    if (i == 2) {
        Serial.println("Petit geste 2");
        smallGesture2(20, 10, 1000, 90, maxX);
        monServoH.write(medH);
    }

    if (i == 3) {
        Serial.println("Petit geste 2b");
        smallGesture2(20, 10, 1000, 140, minX);
        monServoH.write(medH);
    }

    if (i == 4) {
        Serial.println("Petit geste 3");
        smallGesture3(10, 10, 500, 180, minX);
        sweepH(90, 10);
        sweepH(medH, 20);

    }
    if (i == 5) {
        Serial.println("Petit geste 4");
        smallGesture3(10, 10, 500, 180, minX);
        monServoH.write(medH);
        sweepH(90, 10);
        sweepH(medH, 20);
    }
}




////////////// Petits et micro Gestes aléatoires /////////////////////////
void RandomGesture2() {
    i = random(1, 12);
    Serial.println(i);
    if (i == 1) {
        Serial.println("Petit geste 1");
        smallGesture1(10, 10, 1, maxX, minX);
        Initialize2(false);
    }
    if (i == 2) {
        Serial.println("Petit geste 2");
        smallGesture2(20, 10, 1000, 90, maxX);
        monServoH.write(medH);
        Initialize2(false);
    }

    if (i == 3) {
        Serial.println("Petit geste 2b");
        smallGesture2(20, 10, 1000, 140, minX);
        monServoH.write(medH);
        Initialize2(false);
    }

    if (i == 4) {
        Serial.println("Petit geste 3");
        smallGesture3(10, 10, 500, 180, minX);
        sweepH(90, 10);
        sweepH(medH, 20);
        Initialize2(false);

    }
    if (i == 5) {
        Serial.println("Petit geste 4");
        smallGesture3(10, 10, 500, 180, minX);
        monServoH.write(medH);
        sweepH(90, 10);
        sweepH(medH, 20);
        Initialize2(false);
    }

    if (i == 6) {
        microGesture1();
        Initialize2(false);
    }
    if (i == 7) {
        microGesture2();
        Initialize2(false);
    }
    if (i == 8) {
        microGesture3();
        Initialize2(false);
    }
    if (i == 9) {
        microGesture4();
        Initialize2(false);
    }

    if (i == 10) {
        Bruit();
        Initialize2(false);
    }

    if (i == 11) {
        bailler();
        delay(100);
        Initialize2(false);
    }
}


//////////// Epaules ///////////////////
// Epaule Gauche
void EpauleGauche(int threshold) {
    long sensorValue =  epaule_gauche.capacitiveSensor(100);
    //smallGesture2(20, 10, 1000, 150, minX);
    //monServoH.write(medH);
    openEyes(10);
    sweepH(160, 10);
    sweepX(minX, 5);
    delay(1000);
    sweepX(medX, 10);

    int i=1;
    int j = 0;
    int J = 4;
    while (i < 2) {
        j = j + 1;
      sweepX(70, 20);
      delay(20);
      sweepX(medX, 15);
      sweepX(70, 10);
      delay(20);
      sweepX(medX, 15);
      delay(500); 


      if (j == J) {
          closeEyes(5);
          delay(10);
          openEyes(2);
          j = 0;
          J = random(3, 6);
      }
                
    sensorValue =  epaule_gauche.capacitiveSensor(100); 
    Serial.println(sensorValue); 
    if (sensorValue<threshold) {
      i=2;
      }
    }     

     closeEyes(5);
     delay(50);
     openEyes(2);
     sweepH(90, 10);  
     sweepH(medH, 20);  
        
 }       

// Epaule Droite
void EpauleDroite(int threshold) {
     long sensorValueD =  epaule_droite.capacitiveSensor(100); 
    //smallGesture2(20, 10, 1000, 150, minX);
    //monServoH.write(medH);
    openEyes(10);
    sweepH(minH, 10);
    sweepX(maxX, 5);
    delay(1000);
    sweepX(medX, 10);

    int i=1;
    int J = 4;
    int j = 0;
    sensorValueD = epaule_droite.capacitiveSensor(100);
    Serial.println(sensorValueD);
    if (sensorValueD < threshold) {
        i = 2;
    }
    while (i < 2) {
       j = j+1;
      sweepX(105, 20);
      delay(10);
      sweepX(medX, 10);
      delay(20);
      sweepX(105, 20);
      sweepX(medX, 15);
      delay(500);

      if (j == J) {
          closeEyes(5);
          delay(10);
          openEyes(2);
          j = 0;
          J = random(3, 6);
      }

    sensorValueD =  epaule_droite.capacitiveSensor(100); 
    Serial.println(sensorValueD); 
      if (sensorValueD<threshold) {
      i=2;
      }
    }     
    closeEyes(5);
    delay(50);
    openEyes(2);
    sweepH(medH, 20);  

 }         
   



////////////// Grands Gestes /////////////////////////

///  Lève la tête et regarde en l'air
void LeverTete() {
    Initialize2(false);

    Serial.println("Lever la tête ");
    // Lever la tête
    sweepV(150, 5);
    monServoV.write(150);
    delay(1000);

    // Tourner la tête
    for (int i = 1; i <= 1; i++) {
        monServoH.write(medH);
        sweepH(140, 15);
        delay(100);
        sweepH(medH, 15);
        delay(100);
    }
}
///  Lève la tête au max
void LeverTete2() {
    sweepH(90, 20);

    // Lever la tête
    sweepV(maxV, 20);
    monServoV.write(180);
    delay(1000);

    //delay(1000);
    //sweepH(medH, medH+20, 10);
   

}

//////////// Fonctions ///////////////////
void RegardIntense() {
    // Regard intense

    Serial.println("Lever les yeux ");
    sweepY(minY, 5);
    monServoY.write(minY);
    delay(100);

    for (int i = 1; i <= 5; i++) {
        monServoX.write(medX);
        sweepX(100, 10);
        delay(100);
        sweepX(80, 10);
        delay(200);
        sweepX(medX, 10);
        delay(120);
    }

    sweepY(medY, 5);
    delay(200);
}

void BaisserLaTete() {
    // Closing eyes
    closeEyes(10);

    // Baisser la tête
    sweepV(medV, 20);

    // Remetter la tête droite
    sweepH(medH, 20);
    // sweepH(medH,90, 20);
   //  sweepH(90, medH, 20);

    // Ouvrir les yeux
    openEyes(10);


    Initialize2(false);

}