// Poème aux étoiles


void PoemeEtoile() {
    Serial.println("Poème aux etoiles");
    //Initialize2(false);
    detachAll();

    arrayHi = pgm_read_word_near(arrayH3 + 1);
    arrayVi = pgm_read_word_near(arrayV3 + 1);
    arrayRi = pgm_read_word_near(arrayR3 + 1);
    arrayXi = pgm_read_word_near(arrayX3 + 1);
    arrayYi = pgm_read_word_near(arrayY3 + 1);
    //Serial.println(arrayRi);
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
    //Serial.println(monServoR.read());
    

    myMP3.stop();
    delay(100);

    if (x == 1) {
        myMP3.volume(30);
        myMP3.play(5);
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
        while (i < L3) {
            // Serial.println(i);
        
            currentMillis = millis();
       
        
            arrayHi = pgm_read_word_near(arrayH3 + i);
            arrayVi = pgm_read_word_near(arrayV3 + i);
            arrayRi = pgm_read_word_near(arrayR3 + i);
            arrayXi = pgm_read_word_near(arrayX3 + i);
            arrayYi = pgm_read_word_near(arrayY3 + i);
            arrayLidsi = pgm_read_word_near(arrayLids3 + i);
            arrayJawi = pgm_read_word_near(arrayJaw3 + i);

            //Serial.println(arrayRi);

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
            if (currentMillis - previousMillis >= TIME3) {
                i = i + 1;
                previousMillis = currentMillis;
                

            }

            if (i >= L3-1 ) {
                detachAll();
                detach = true;
            }
        }

        detachAll();
        detach = true;
        
    }

    if (i >= L3) { // obligée de faire ça pour stopper la musique
        //Serial.println("Fin");
        attachAll();
        detach = false;
        sweepY(90, 10);
        closeEyes(3);    
        Volume(30, 0, 20);
        delay(1000);
        openEyes(2);
        detachAll();
        detach = true;
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
