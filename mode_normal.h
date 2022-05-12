// Mode normal


void ModeNormal() {
    Initialize2(false);

    if (poeme_etoile == 0) {
        Serial.println("Poème aux étoiles");
        //Presentation();
        PoemeEtoile();
        sweepY(90, 10);
        delay(500);
        poeme_etoile = 1;
        time_poeme=millis();
    }

    if (detach) {
        attachAll();
    }
    

    // Lecture des capteurs
    long sensorValue = epaule_gauche.capacitiveSensor(100);
    long sensorValueD = epaule_droite.capacitiveSensor(100);
    a = sr04.Distance();
    Microval = digitalRead(Micropin);

    // On calcule le temps
    time = millis();
    timeLong = millis();


    // On donne les infos toutes les deux secondes
    if (time - previousTimeDistance > 2000) {

        Serial.print("Distance au robot: ");
        Serial.print(a);
        Serial.print("cm");
        Serial.println("");

        Serial.print("Epaule Gauche: ");
        Serial.print(sensorValue);
        Serial.println("");

        Serial.print("Epaule Droite: ");
        Serial.print(sensorValueD);
        Serial.println("");

        Serial.print("Temps sans interaction: ");
        Serial.println(time - previousTimeInteraction);

        Serial.print("Temps sans son: ");
        Serial.println(time - previousTimeSound);


        previousTimeDistance = millis();
        Serial.println("");


    }

    // Deux minutes après le poème, la présentation
    if (time - time_poeme > 120000 && pres== 0) {
        Serial.println("Je me présente");
        Presentation();
        delay(1000);
        pres = 1;
    }


    // Bruit de vent toutes les minutes
    if (time - previousTimeSound > 60000) {
        Serial.println("Piste 2: vent");
        myMP3.volume(30);
        myMP3.play(2);
        previousTimeSound = millis();
    }
    if (time - previousTimeSound > 8000 && time - previousTimeSound < 60000) { // obligée de faire ça pour stopper le bruit du vent...
        myMP3.pause();
    }

    // S'il y a du bruit: clignement des yeux
    if (Microval == HIGH) {
        Serial.println("Bruit");
        Bruit();
    }


     //Si les deux épaules sont touchées: Robobo s'endort  
    if (sensorValue > thr && sensorValueD > thr) {
        int timeEpaule = millis();
        Serial.println("Deux épaules");
        int j = 1;
        int d = 0;
        while (sensorValue > thr && sensorValueD > thr) {
            j = j + 1;
            Serial.print("j=");
            Serial.println(j);
            Serial.print("d=");
            Serial.println(d);
            delay(1000);
            sensorValue = epaule_gauche.capacitiveSensor(100);
            sensorValueD = epaule_droite.capacitiveSensor(100);
            Serial.print("Epaule Gauche: ");
            Serial.print(sensorValue);
            Serial.print(" Epaule Droite: ");
            Serial.println(sensorValueD);
            if (j >= 3) {
                d = 1;
                microGesture2();
            }
        }

        while (d == 1) {
           Serial.println("Dodo!");
           Dodo();
           delay(100);
           detachAll();
           detach = true;
           sensorValue = epaule_gauche.capacitiveSensor(100);
           sensorValueD = epaule_droite.capacitiveSensor(100);
           Serial.println("E");
           if (sensorValue > thr || sensorValueD > thr) {
                        d = 2; // Si on appuie sur l'une des épaules, on sort de la boucle
           }
        }
        if (detach) {
            attachAll();
        }
        Initialize2(false);
        delay(500);           
            
    }
        

     // Si l'épaule gauche est touchée 
    if (sensorValue > thr) {
        Serial.println("Epaule Gauche");
        EpauleGauche(thr);
        time = millis();
        previousTime = time;
        previousTimeInteraction = time;


        interval = random(5000, 15000);
        Serial.println("===========");
        Serial.print("Nouvel interval: ");
        Serial.println(interval);
    }

    // Si l'épaule droite est touchée 
    if (sensorValueD > thr) {
        Serial.println("Epaule Droite");
        EpauleDroite(thr);
        time = millis();
        previousTime = time;
        previousTimeInteraction = time;

        interval = random(5000, 15000);
        Serial.println("===========");
        Serial.print("Nouvel interval: ");
        Serial.println(interval);
    }


    // Si on s'approche du ROBO
    if (a < 60) {
        val = digitalRead(PIR);  // read PIR input value
        unsigned long tPIR = millis();
        if (val == HIGH) {
            if (timeLong - previousTimeLong > 7000) { // Seulement toutes les 7 secondes
                Serial.println("Vous vous être rapproché-e");
                LeverTete();
                a = sr04.Distance(); 
                // Si on est vraiment près le robot va nous regarder plus fixement
                if (a < 30) {                   
                    LeverTete2();
                    unsigned long debut = millis();
                    int i = 1;
                    while (i < 2) {
                        RegardIntense();
                        a = sr04.Distance();
                        Serial.println(a);
                        unsigned long maintenant = millis();
                        if (maintenant - tPIR >= 3500) {
                            val = digitalRead(PIR);
                            tPIR = millis();
                            Serial.println(val);
                        }
                        if ((a > 30 && val == LOW) || maintenant - debut > 30000) {
                            Serial.println("parti");
                            Serial.println(maintenant - debut);
                            i = 2;
                        }

                    }
                    // Baisser la tête à 150
                    sweepV(150, 20);
                }

                // Si on s'eloigne la tete baisse
                BaisserLaTete();


                time = millis();
                timeLong = millis();
                previousTime = time;
                previousTimeLong = timeLong;

                interval = random(5000, 15000);
                Serial.println("===========");
                Serial.print("Nouvel interval: ");
                Serial.println(interval);
            }
            previousTimeInteraction = time;
        }
        Initialize2(false);
    }


    // Clignemet
    if (time - previousClignement > intervalClignement) {
        RandomMicroGesture();
        previousClignement = millis();
        intervalClignement = 1000 * random(5, 10);
    }
    delay(500);

    // Si rien ne se passe : petit geste random (ou endormissement !)
    if (time - previousTime > interval) {

        if (time - previousTimeInteraction < TempsAvantEndormissement) { // Si ça fait pas longtemps que l'on a interagi: petit geste
            Serial.println("Temps ecoule !");

            if (time - previousTimeInteraction < TempsAvantBaillement) {
                RandomGesture();
            }

            // Si ça commence à faire longtemps : eventuellement baillement
            if (time - previousTimeInteraction > TempsAvantBaillement && time - previousTimeInteraction < TempsAvantEndormissement) {
                int j;
                j = random(1, 3);
                if (j == 1) {
                    RandomGesture();
                }
                else {
                    bailler();
                }
            }
            time = millis();
            previousTime = time;

            interval = 1000 * random(5, 15);
            Serial.println("===========");
            Serial.print("Nouvel interval: ");
            Serial.println(interval);

            Initialize2(false);
        }

        if (time - previousTimeInteraction > TempsAvantEndormissement) { // Si ça fait  longtemps que l'on a pas interagi: endormissement
            Serial.println("Je m'endors !");
            Dodo();
            int d = 1;
            dodo_time = millis();
            while (d == 1) {
                time = millis();
                Dodo();
                if (time - previousTimeInteraction < TempsAvantEndormissementComplet) {
                    Serial.println("Sommeil léger");
                    unsigned long new_time = millis();
                    Serial.println(new_time - dodo_time);
                    if (new_time - dodo_time > 3000) {
                        sweepH(110, 10);
                        delay(600);
                        sweepH(90, 10);
                        delay(100);
                        dodo_time = millis();
                        d = 1;
                    }
                }
                else {
                    Serial.println("Sommeil profond");
                    Dodo();
                    detachAll();
                    detach = true;
                }

                // Pour réveiller le robot: lui taper l'épaule
                long sensorValue = epaule_gauche.capacitiveSensor(100);
                long sensorValueD = epaule_droite.capacitiveSensor(100);
                if (sensorValue > thr || sensorValueD > thr) {
                    if (detach) {
                        attachAll();
                    }
                    d = 2;
                    openEyes(5);
                    Initialize2(false);
                    delay(500);
                    bailler();
                    time = millis();
                    previousTimeInteraction = time;
                    previousTime = time;
                }



            }

        }


    }



    // arbitrary delay to limit data to serial port
    delay(10);
    Initialize2(false);

}