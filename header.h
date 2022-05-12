// threshold for captors
int thr = 500;

//Temps d'attente entre les clignements d'yeux
long previousClignement = 3000;
long intervalClignement = 5000;

//Temps d'attente entre les petits random gestes
unsigned long time;
unsigned long previousTime = 0;
unsigned long interval = 3000;

//Temps d'attente entre deux grands gestes
unsigned long timeLong;
unsigned long previousTimeLong = 0;

// mouvement lors du sommeil léger
unsigned long dodo_time = 0;

// Temps d'attente pour afficher la distance
//unsigned long timeDistance;
unsigned long previousTimeDistance = 0;

// Temps d'attente pour le sommeil (au départ)
unsigned long TempsAvantEndormissementCompletAuDepart = 60000; // 1 minute

// Temps d'attente pour le sommeil (mode normal)
unsigned long previousTimeInteraction = 0;
unsigned long TempsAvantBaillement = 120000; // 2min
unsigned long TempsAvantEndormissement = 240000; // 2min
unsigned long TempsAvantEndormissementComplet = TempsAvantEndormissement + 20000; // +20s

// Temps d'attente pour déclencher lecture du son
unsigned long previousTimeSound = 0;


// Booléen pour détacher servo
bool detach = false;

// Paramètres phrases
unsigned long time_poeme;
int pres = 0;
int poeme_etoile = 0;

// Index musique début
int h; // musique début
