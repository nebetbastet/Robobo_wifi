// Oui et non


void Oui() {
    Serial.println("Oui");
    detachAll();

    arrayHi = pgm_read_word_near(arrayH5 + 1);
    arrayVi = pgm_read_word_near(arrayV5 + 1);
    arrayRi = pgm_read_word_near(arrayR5 + 1);
    arrayXi = pgm_read_word_near(arrayX5 + 1);
    arrayYi = pgm_read_word_near(arrayY5 + 1);
    //arrayLidsi = pgm_read_word_near(arrayLids5 + 1);

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



    int b = analogRead(pinBusy);
    //int z = 1;
    //while (z == 1) {
    //    delay(1000);
    //    b = analogRead(pinBusy);
    //    Serial.print("b=");
    //    Serial.println(b);
    //    if (b > 500) { delay(1); }
    //    if (b < 500) { z = 2; }
    //}

    int i = 1;

    myMP3.volume(30);
    myMP3.play(8);
    
    
    //if (b < 500) {
        attachAll();
        delay(500);

        unsigned long currentMillis = millis();
        unsigned long  previousMillis = millis();
        Serial.println("Debut");
        while (i < L5) {

            if (i == 1) {

            }
        
            currentMillis = millis();
       
        
            arrayHi = pgm_read_word_near(arrayH5 + i);
            arrayVi = pgm_read_word_near(arrayV5 + i);
            arrayRi = pgm_read_word_near(arrayR5 + i);
            arrayXi = pgm_read_word_near(arrayX5 + i);
            arrayYi = pgm_read_word_near(arrayY5 + i);
            arrayLidsi = arrayLids5[i];
            //arrayLidsi = pgm_read_word_near(arrayLids5 + i);
            arrayJawi = pgm_read_word_near(arrayJaw5 + i);


            monServoH.write(arrayHi);
            monServoV.write(arrayVi);
            monServoR.write(arrayRi);
            monServoX.write(arrayXi);
            monServoY.write(arrayYi);
            monServoLids.write(arrayLidsi);
            monServoJaw.write(arrayJawi);

            b = analogRead(pinBusy);

            if (currentMillis - previousMillis >= TIME5) {
                i = i + 1;
                previousMillis = currentMillis;
            }

            //if (i > L5 ) {
              //  detachAll();
               // detach = true;
            //}
        }

        detachAll();
        detach = true;
        
    //}

    if (i >= L5) { // oblig�e de faire �a pour stopper la musique
        myMP3.pause();
        myMP3.volume(0);



    }

 

 
}
