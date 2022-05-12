// Reine de la Nuit


void Presentation() {
    Serial.println("Je suis la reine de la nuit");
    detachAll();

    arrayHi = pgm_read_word_near(arrayH2 + 1);
    arrayVi = pgm_read_word_near(arrayV2 + 1);
    arrayRi = pgm_read_word_near(arrayR2 + 1);
    arrayXi = pgm_read_word_near(arrayX2 + 1);
    arrayYi = pgm_read_word_near(arrayY2 + 1);
    //arrayLidsi = pgm_read_word_near(arrayLids2 + i);

    attachAll();
    sweepH(arrayHi,50);
    sweepV(arrayVi,50);
    sweepR(50,20);
    sweepX(arrayXi,10);
    sweepY(arrayYi,10);
    sweepLids(minLids,2);
    monServoLids.write(minLids);
    sweepJaw(minJaw,10);
    detachAll();
    

    myMP3.stop();
    delay(100);

    if (x == 1) {
        myMP3.volume(30);
        myMP3.play(4);
    }
    
    int b = analogRead(pinBusy);
    int z = 1;
    while (z == 1) {
        delay(1000);
        b = analogRead(pinBusy);
        Serial.print("b=");
        Serial.println(b);
        if (b > 500) { delay(1); }
        if (b < 500) { z = 2; }
    }

    int i = 14;
    
    
    if (b < 500) {
        attachAll();

        unsigned long currentMillis = millis();
        unsigned long  previousMillis = millis();
        Serial.println("Debut");
        while (i < L2) {
        
            currentMillis = millis();
       
        
            arrayHi = pgm_read_word_near(arrayH2 + i);
            arrayVi = pgm_read_word_near(arrayV2 + i);
            arrayRi = pgm_read_word_near(arrayR2 + i);
            arrayXi = pgm_read_word_near(arrayX2 + i);
            arrayYi = pgm_read_word_near(arrayY2 + i);
            arrayLidsi = arrayLids2[i];
            //arrayLidsi = pgm_read_word_near(arrayLids2 + i);
            arrayJawi = pgm_read_word_near(arrayJaw2 + i);


            monServoH.write(arrayHi);
            monServoV.write(arrayVi);
            monServoR.write(arrayRi);
            monServoX.write(arrayXi);
            monServoY.write(arrayYi);
            monServoLids.write(arrayLidsi);
            monServoJaw.write(arrayJawi);

            b = analogRead(pinBusy);

            if (currentMillis - previousMillis >= TIME2) {
                i = i + 1;
                previousMillis = currentMillis;
            }

            if (i >= L2-1 ) {
                detachAll();
                detach = true;
            }
        }

        detachAll();
        detach = true;
        
    }

    if (i >= L2) { // obligée de faire ça pour stopper la musique
        myMP3.pause();
        myMP3.volume(0);



    }

 

 
}
