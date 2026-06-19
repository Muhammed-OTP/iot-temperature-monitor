/*
 * ============================================================
 * SYSTÈME DE SURVEILLANCE DE TEMPÉRATURE
 * ============================================================
 *
 * Projet   : Système de surveillance de température IoT
 * Module   : Internet des Objets (IoT)
 * Équipe   : Moustapha Yehdih (C34613)
 *            Mohamed Salem Ebnou Echvagha Oubeid (C34794)
 * Date     : Juin 2026
 *
 * Description :
 *   Ce programme lit la température depuis un capteur TMP36,
 *   l'affiche sur le moniteur série, et contrôle des LEDs
 *   et un buzzer selon un seuil de température prédéfini.
 *
 * Composants :
 *   - Arduino Uno
 *   - Capteur TMP36 (broche analogique A0)
 *   - LED verte (broche numérique 3)
 *   - LED rouge (broche numérique 4)
 *   - Buzzer piézoélectrique (broche numérique 5)
 *   - 2x Résistances 220Ω (pour les LEDs)
 *
 * Fonctionnement :
 *   Température < seuil  → LED verte ON,  LED rouge OFF, Buzzer OFF
 *   Température >= seuil → LED verte OFF, LED rouge ON,  Buzzer ON
 *
 * Compatible : Tinkercad Simulation + Matériel réel
 * ============================================================
 */

// ============================================================
// SECTION 1 : DÉFINITION DES CONSTANTES
// ============================================================

// --- Broches (pins) ---
// Chaque composant est connecté à une broche spécifique de l'Arduino.
// Les broches analogiques (A0-A5) lisent des tensions variables (0-5V).
// Les broches numériques (0-13) envoient/reçoivent HIGH (5V) ou LOW (0V).

const int BROCHE_CAPTEUR  = A0;   // Broche analogique A0 — capteur TMP36
const int BROCHE_LED_VERTE = 3;   // Broche numérique 3 — LED verte (normal)
const int BROCHE_LED_ROUGE = 4;   // Broche numérique 4 — LED rouge (alerte)
const int BROCHE_BUZZER    = 5;   // Broche numérique 5 — buzzer piézoélectrique

// --- Paramètres du système ---
const float SEUIL_TEMPERATURE = 30.0;  // Seuil d'alerte en degrés Celsius
const int   FREQUENCE_BUZZER  = 1000;  // Fréquence du buzzer en Hertz (Hz)
const int   DELAI_LECTURE     = 1000;  // Délai entre chaque lecture en millisecondes (1 seconde)
const long  VITESSE_SERIE     = 9600;  // Vitesse de communication série en bauds


// ============================================================
// SECTION 2 : FONCTION setup()
// ============================================================
// La fonction setup() s'exécute UNE SEULE FOIS au démarrage.
// Elle sert à initialiser les broches et la communication série.

void setup() {

  // --- Initialiser la communication série ---
  // Serial.begin() ouvre le canal de communication entre l'Arduino et le PC.
  // 9600 bauds = 9600 bits par seconde (vitesse standard).
  // Cela permet d'afficher des données dans le Moniteur Série.
  Serial.begin(VITESSE_SERIE);

  // --- Configurer les broches en mode SORTIE ---
  // pinMode() définit si une broche est en entrée (INPUT) ou sortie (OUTPUT).
  // Les LEDs et le buzzer sont des SORTIES : l'Arduino leur ENVOIE un signal.
  // Le capteur TMP36 est une ENTRÉE analogique (pas besoin de pinMode pour A0).

  pinMode(BROCHE_LED_VERTE, OUTPUT);  // LED verte = sortie
  pinMode(BROCHE_LED_ROUGE, OUTPUT);  // LED rouge = sortie
  pinMode(BROCHE_BUZZER, OUTPUT);     // Buzzer = sortie

  // --- État initial : tout éteint ---
  // On s'assure que tous les actuateurs sont éteints au démarrage.
  // digitalWrite() envoie HIGH (5V = allumé) ou LOW (0V = éteint).

  digitalWrite(BROCHE_LED_VERTE, LOW);  // LED verte éteinte
  digitalWrite(BROCHE_LED_ROUGE, LOW);  // LED rouge éteinte
  noTone(BROCHE_BUZZER);               // Buzzer éteint

  // --- Message de bienvenue ---
  // On affiche un message dans le Moniteur Série pour confirmer le démarrage.
  Serial.println("============================================");
  Serial.println("  SYSTEME DE SURVEILLANCE DE TEMPERATURE");
  Serial.println("  Equipe : Moustapha Yehdih (C34613)");
  Serial.println("           Mohamed Salem E.E. Oubeid (C34794)");
  Serial.println("============================================");
  Serial.print("  Seuil d'alerte : ");
  Serial.print(SEUIL_TEMPERATURE);
  Serial.println(" C");
  Serial.println("============================================");
  Serial.println();
}


// ============================================================
// SECTION 3 : FONCTION loop()
// ============================================================
// La fonction loop() s'exécute EN BOUCLE INFINIE après setup().
// C'est le cœur du programme : elle lit, traite et réagit.

void loop() {

  // --- Étape 1 : Lire la valeur brute du capteur ---
  // analogRead() lit la tension sur la broche A0.
  // Elle retourne un entier entre 0 et 1023.
  //   0    = 0V
  //   1023 = 5V
  // C'est le Convertisseur Analogique-Numérique (CAN) 10 bits de l'Arduino.

  int valeurBrute = analogRead(BROCHE_CAPTEUR);

  // --- Étape 2 : Convertir la valeur brute en tension (Volts) ---
  // L'Arduino fonctionne sur 5V avec une résolution de 10 bits (1024 niveaux).
  // Formule : tension = valeurBrute × (5.0 / 1024.0)
  // Exemple : si valeurBrute = 150, tension = 150 × 0.00488 = 0.732V

  float tension = valeurBrute * (5.0 / 1024.0);

  // --- Étape 3 : Convertir la tension en température (°C) ---
  // Le TMP36 a une caractéristique linéaire :
  //   - À 0°C, il produit 0.5V (500mV)
  //   - Chaque degré ajoute 10mV (0.01V)
  // Formule : température = (tension - 0.5) × 100
  // Exemple : si tension = 0.732V → (0.732 - 0.5) × 100 = 23.2°C

  float temperature = (tension - 0.5) * 100.0;

  // --- Étape 4 : Afficher les données sur le Moniteur Série ---
  // Serial.print() affiche du texte SANS retour à la ligne.
  // Serial.println() affiche du texte AVEC retour à la ligne.

  Serial.print("Valeur brute : ");
  Serial.print(valeurBrute);           // Valeur CAN (0-1023)
  Serial.print("  |  Tension : ");
  Serial.print(tension, 2);            // Tension avec 2 décimales
  Serial.print(" V  |  Temperature : ");
  Serial.print(temperature, 1);        // Température avec 1 décimale
  Serial.print(" C  |  Statut : ");

  // --- Étape 5 : Logique de décision (seuil) ---
  // On compare la température au seuil prédéfini.
  // Selon le résultat, on active les actuateurs appropriés.

  if (temperature < SEUIL_TEMPERATURE) {

    // *** CAS NORMAL : température sous le seuil ***

    digitalWrite(BROCHE_LED_VERTE, HIGH);  // Allumer la LED verte
    digitalWrite(BROCHE_LED_ROUGE, LOW);   // Éteindre la LED rouge
    noTone(BROCHE_BUZZER);                 // Éteindre le buzzer
    // noTone() arrête la génération de signal sur la broche du buzzer.

    Serial.println("NORMAL");

  } else {

    // *** CAS ALERTE : température au-dessus ou égale au seuil ***

    digitalWrite(BROCHE_LED_VERTE, LOW);   // Éteindre la LED verte
    digitalWrite(BROCHE_LED_ROUGE, HIGH);  // Allumer la LED rouge
    tone(BROCHE_BUZZER, FREQUENCE_BUZZER); // Activer le buzzer à 1000 Hz
    // tone(broche, fréquence) génère un signal carré à la fréquence donnée.
    // 1000 Hz produit un son aigu et perceptible.

    Serial.print("*** ALERTE *** (seuil = ");
    Serial.print(SEUIL_TEMPERATURE);
    Serial.println(" C)");

  }

  // --- Étape 6 : Attendre avant la prochaine lecture ---
  // delay() met le programme en pause pour le nombre de millisecondes donné.
  // 1000 ms = 1 seconde.
  // Cela évite de lire le capteur trop rapidement et de saturer le moniteur série.

  delay(DELAI_LECTURE);
}


// ============================================================
// SECTION 4 : NOTES TECHNIQUES
// ============================================================
/*
 * FONCTIONS ARDUINO UTILISÉES :
 *
 * 1. Serial.begin(vitesse)
 *    → Initialise la communication série à la vitesse donnée (bauds).
 *    → Doit être appelée dans setup().
 *
 * 2. pinMode(broche, mode)
 *    → Configure une broche en INPUT (entrée) ou OUTPUT (sortie).
 *    → Les broches analogiques n'ont pas besoin de pinMode.
 *
 * 3. analogRead(broche)
 *    → Lit la tension sur une broche analogique (A0-A5).
 *    → Retourne un entier entre 0 (0V) et 1023 (5V).
 *    → Résolution : 10 bits → 5V / 1024 ≈ 4.88 mV par unité.
 *
 * 4. digitalWrite(broche, valeur)
 *    → Envoie HIGH (5V) ou LOW (0V) sur une broche numérique.
 *    → HIGH = allumé, LOW = éteint (pour une LED).
 *
 * 5. tone(broche, fréquence)
 *    → Génère un signal carré à la fréquence donnée (Hz).
 *    → Fait vibrer le buzzer piézoélectrique.
 *
 * 6. noTone(broche)
 *    → Arrête le signal généré par tone().
 *
 * 7. delay(millisecondes)
 *    → Pause le programme pendant la durée spécifiée.
 *    → 1000 ms = 1 seconde.
 *
 * 8. Serial.print() / Serial.println()
 *    → Envoie du texte vers le moniteur série (PC).
 *    → println() ajoute un retour à la ligne.
 *
 *
 * CAPTEUR TMP36 — FICHE TECHNIQUE :
 *
 *   Brochage (vue de face, partie plate vers vous) :
 *     Broche 1 (gauche)  = VCC (+5V ou +3.3V)
 *     Broche 2 (centre)  = Signal analogique (vers A0)
 *     Broche 3 (droite)  = GND (masse)
 *
 *   Plage de mesure : -40°C à +125°C
 *   Précision : ±1°C (à 25°C)
 *   Tension de sortie : 10mV par °C, avec offset de 500mV
 *   Formule : T(°C) = (Vout - 0.5) × 100
 *
 *
 * CÂBLAGE RÉSUMÉ :
 *
 *   TMP36 VCC     → Arduino 5V
 *   TMP36 Signal  → Arduino A0
 *   TMP36 GND     → Arduino GND
 *   LED Verte (+) → Résistance 220Ω → Arduino D3
 *   LED Verte (-) → Arduino GND
 *   LED Rouge (+) → Résistance 220Ω → Arduino D4
 *   LED Rouge (-) → Arduino GND
 *   Buzzer (+)    → Arduino D5
 *   Buzzer (-)    → Arduino GND
 */
