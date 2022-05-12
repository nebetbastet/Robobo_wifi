// Mode Lacrimosa
int x2 = 1;

void ModeLacrimosa() {
    Serial.println("Piste 6: Lacrimosa");
    //Initialize2(false);
    detachAll();

    arrayHi = pgm_read_word_near(arrayH4 + 1);
    arrayVi = pgm_read_word_near(arrayV4 + 1);
    arrayRi = pgm_read_word_near(arrayR4 + 1);
    arrayXi = pgm_read_word_near(arrayX4 + 1);
    arrayYi = pgm_read_word_near(arrayY4 + 1);
    Serial.println(arrayRi);
    attachAll();
    sweepH(arrayHi,50);
    sweepV(arrayVi,50);
    sweepR(50,20);
    sweepX(arrayXi,10);
    sweepY(arrayYi,10);
    sweepLids(maxLids,2);
    monServoLids.write(maxLids);
    sweepJaw(minJaw,10);
    detachAll();
    Serial.println(monServoR.read());
    

    myMP3.stop();
    delay(100);

    if (x2 == 1) {
        myMP3.volume(30);
        myMP3.play(6);
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

    int i = 8;
    
    
    if (b < 500) {
        attachAll();

        unsigned long currentMillis = millis();
        unsigned long  previousMillis = millis();
        Serial.println("Debut");
        while (i < L4) {
        
            currentMillis = millis();
       
        
            arrayHi = pgm_read_word_near(arrayH4 + i);
            arrayVi = pgm_read_word_near(arrayV4 + i);
            arrayRi = pgm_read_word_near(arrayR4 + i);
            arrayXi = pgm_read_word_near(arrayX4 + i);
            arrayYi = pgm_read_word_near(arrayY4 + i);
            arrayLidsi = pgm_read_word_near(arrayLids4 + i);
            arrayJawi = pgm_read_word_near(arrayJaw4 + i);

            Serial.println(arrayLidsi);

            monServoH.write(arrayHi);
            monServoV.write(arrayVi);
            monServoR.write(arrayRi);
            monServoX.write(arrayXi);
            monServoY.write(arrayYi);
            monServoLids.write(arrayLidsi);
            monServoJaw.write(arrayJawi);

            b = analogRead(pinBusy);
            // delay(10000); // test
            //for (int i = 8; i < L; i++) {
            if (currentMillis - previousMillis >= TIME4) {
                i = i + 1;
                previousMillis = currentMillis;
                Serial.println(i);
            }

            if (i >= L4-5 ) {
                detachAll();
            }
        }

        detachAll();
        
    }

    if (i >= L4) { // obligée de faire ça pour stopper la musique
        //Serial.println("Fin");
        //detachAll();
        myMP3.pause();
        //arrayHi = pgm_read_word_near(arrayH + 1);
        //arrayVi = pgm_read_word_near(arrayV + 1);
        //arrayRi = pgm_read_word_near(arrayR + 1);
        //arrayXi = pgm_read_word_near(arrayX + 1);
        //arrayYi = pgm_read_word_near(arrayY + 1);

        //attachAll();
        //sweeph(medh, 20);
        //sweepv(minv, 20);
        //sweepr(medr, 20);
        //sweepx(medx, 10);
        //sweepy(medy, 10);
        //sweeplids(maxlids, 2);
        //monservolids.write(maxlids);
        //sweepjaw(minjaw, 10);

        myMP3.volume(0);



    }

 

 
}
