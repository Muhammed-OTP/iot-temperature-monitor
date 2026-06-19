# Préparation Soutenance Orale — 50 Questions et Réponses

## Catégorie 1 : IoT — Concepts Généraux (Questions 1–8)

---

### Q1 : Qu'est-ce que l'Internet des Objets (IoT) ?

**Réponse :** L'Internet des Objets (IoT) désigne l'interconnexion d'objets physiques avec le monde numérique via des capteurs, des processeurs et des moyens de communication. Ces objets collectent des données de leur environnement, les traitent et peuvent agir automatiquement. Par exemple, un thermostat intelligent qui mesure la température et ajuste le chauffage automatiquement.

---

### Q2 : Quelles sont les quatre couches de l'architecture IoT ?

**Réponse :**
1. **Couche de perception** — Les capteurs qui mesurent le monde physique (température, humidité, etc.)
2. **Couche réseau** — Les protocoles de communication (WiFi, Bluetooth, LoRa, Zigbee)
3. **Couche traitement** — Le microcontrôleur ou serveur qui analyse les données
4. **Couche application** — L'interface utilisateur ou le système de décision

---

### Q3 : Donnez 5 exemples d'applications IoT dans la vie quotidienne.

**Réponse :**
1. **Thermostat intelligent** (Nest) — régule la température de la maison
2. **Montre connectée** — suit le rythme cardiaque et l'activité physique
3. **Caméra de surveillance** — détecte les mouvements et envoie des alertes
4. **Réfrigérateur connecté** — surveille les stocks alimentaires
5. **Éclairage intelligent** (Philips Hue) — contrôle à distance via smartphone

---

### Q4 : Quelle est la différence entre IoT et un système embarqué classique ?

**Réponse :** Un système embarqué classique fonctionne de manière autonome sans connexion réseau (ex : une machine à laver). L'IoT ajoute la dimension de **connectivité** : les objets communiquent entre eux et avec le cloud via Internet. Notre projet est un système embarqué qui pourrait devenir IoT en ajoutant un module WiFi (ESP8266).

---

### Q5 : Quels sont les défis principaux de l'IoT ?

**Réponse :**
1. **Sécurité** — Les objets connectés sont vulnérables aux cyberattaques
2. **Vie privée** — Les capteurs collectent des données personnelles
3. **Interopérabilité** — Les appareils de différents fabricants doivent communiquer
4. **Consommation énergétique** — Les objets doivent fonctionner longtemps sur batterie
5. **Volume de données** — Des milliards d'objets génèrent des quantités massives de données

---

### Q6 : Quels protocoles de communication sont utilisés en IoT ?

**Réponse :**
- **WiFi** — Haut débit, courte portée (maison, bureau)
- **Bluetooth / BLE** — Très courte portée, faible consommation (wearables)
- **LoRa** — Longue portée, faible débit (agriculture, villes intelligentes)
- **Zigbee** — Réseau maillé, faible consommation (domotique)
- **MQTT** — Protocole de messagerie léger pour IoT (publish/subscribe)
- **HTTP/HTTPS** — Protocole web classique (APIs REST)

---

### Q7 : Votre projet est-il un vrai système IoT ? Pourquoi ?

**Réponse :** Notre projet est un **prototype IoT partiel**. Il implémente la couche de perception (capteur TMP36) et la couche de traitement (Arduino). Cependant, il lui manque la couche réseau (pas de WiFi/Bluetooth) et une couche application cloud. Pour en faire un système IoT complet, il faudrait ajouter un module WiFi (ESP8266/ESP32) pour envoyer les données vers un serveur cloud comme ThingSpeak ou Firebase.

---

### Q8 : Qu'est-ce que le edge computing en IoT ?

**Réponse :** Le edge computing consiste à traiter les données **localement** sur l'objet (au "bord" du réseau) plutôt que de tout envoyer au cloud. Notre Arduino fait du edge computing : il lit la température, la compare au seuil et prend une décision **localement**, sans avoir besoin d'Internet. C'est plus rapide et ça fonctionne même sans connexion.

---

## Catégorie 2 : Arduino — Plateforme (Questions 9–16)

---

### Q9 : Qu'est-ce qu'un microcontrôleur ?

**Réponse :** Un microcontrôleur est un **petit ordinateur intégré sur une seule puce**. Il contient un processeur (CPU), de la mémoire (RAM et Flash), et des ports d'entrée/sortie (I/O). Contrairement à un ordinateur classique, il est conçu pour exécuter **un seul programme** en boucle, de manière fiable et continue. L'Arduino Uno utilise le microcontrôleur ATmega328P.

---

### Q10 : Quelle est la différence entre Arduino et Raspberry Pi ?

**Réponse :**
| Critère | Arduino Uno | Raspberry Pi |
|---------|-------------|-------------|
| Type | Microcontrôleur | Mini-ordinateur |
| OS | Aucun (programme direct) | Linux (Raspbian) |
| Processeur | ATmega328P (8-bit, 16 MHz) | ARM (64-bit, 1.5 GHz) |
| RAM | 2 Ko | 1–8 Go |
| Usage | Contrôle de capteurs, tâches simples | Applications complexes, IA, serveur |
| Prix | ~5–25€ | ~35–75€ |
| Analogique | Oui (6 broches CAN) | Non (pas de CAN intégré) |

Pour notre projet, Arduino est suffisant car la tâche est simple (lire un capteur et contrôler des LEDs).

---

### Q11 : Expliquez le rôle de setup() et loop().

**Réponse :**
- **`setup()`** s'exécute **une seule fois** au démarrage de l'Arduino. On y met l'initialisation : configuration des broches (`pinMode`), démarrage de la communication série (`Serial.begin`), état initial des composants.
- **`loop()`** s'exécute **en boucle infinie** après `setup()`. C'est le cœur du programme : lire les capteurs, prendre des décisions, contrôler les actuateurs. La boucle se répète automatiquement, sans interruption.

---

### Q12 : Que fait la fonction pinMode() ?

**Réponse :** `pinMode(broche, mode)` configure une broche numérique en mode **INPUT** (entrée) ou **OUTPUT** (sortie).
- **OUTPUT** : L'Arduino **envoie** un signal (pour allumer une LED, activer un buzzer)
- **INPUT** : L'Arduino **reçoit** un signal (pour lire un bouton, un capteur numérique)

Note : Les broches analogiques (A0–A5) n'ont pas besoin de `pinMode` pour la lecture analogique.

---

### Q13 : Que fait analogRead() et que retourne-t-elle ?

**Réponse :** `analogRead(broche)` lit la tension sur une broche analogique (A0 à A5) et retourne un **entier entre 0 et 1023**. C'est le convertisseur analogique-numérique (CAN) 10 bits qui fait la conversion :
- 0 correspond à 0V
- 1023 correspond à 5V
- Chaque unité = 5V / 1024 ≈ 4.88 mV

Exemple : si la tension est 0.75V → `analogRead` retourne environ 153.

---

### Q14 : Que fait digitalWrite() ?

**Réponse :** `digitalWrite(broche, valeur)` envoie un signal **numérique** sur une broche :
- `HIGH` = 5V (la broche est sous tension → la LED s'allume)
- `LOW` = 0V (la broche est à la masse → la LED s'éteint)

C'est un signal tout-ou-rien, contrairement à `analogWrite` qui peut envoyer des valeurs intermédiaires (PWM).

---

### Q15 : Quelle est la différence entre tone() et digitalWrite() ?

**Réponse :**
- `digitalWrite()` envoie un signal **constant** (HIGH ou LOW). Utilisé pour allumer/éteindre une LED.
- `tone()` génère un **signal carré** oscillant à une fréquence donnée (Hz). Utilisé pour faire sonner un buzzer piézoélectrique.

`tone(5, 1000)` fait vibrer le buzzer sur la broche 5 à 1000 oscillations par seconde = son à 1000 Hz. `noTone(5)` arrête le son.

---

### Q16 : Pourquoi utilise-t-on delay(1000) dans le code ?

**Réponse :** `delay(1000)` met le programme en pause pendant 1000 millisecondes (= 1 seconde). On l'utilise pour :
1. **Espacer les lectures** — Lire le capteur 1 fois par seconde est suffisant
2. **Lisibilité** — Le moniteur série ne se remplit pas trop vite
3. **Stabilité** — Donne le temps au capteur de se stabiliser

**Limitation :** Pendant `delay()`, l'Arduino ne fait **rien d'autre**. Pour un système multi-tâches, on utiliserait `millis()` à la place.

---

## Catégorie 3 : Capteurs et Mesure (Questions 17–24)

---

### Q17 : Qu'est-ce qu'un capteur ?

**Réponse :** Un capteur est un composant qui **convertit une grandeur physique** (température, lumière, pression, etc.) en un **signal électrique** (tension, courant) interprétable par un microcontrôleur. C'est l'équivalent des sens humains pour un système électronique. Le TMP36 convertit la température en une tension proportionnelle.

---

### Q18 : Comment fonctionne le capteur TMP36 ?

**Réponse :** Le TMP36 est un capteur de température **analogique**. Il produit une tension de sortie **proportionnelle** à la température :
- À 0°C, il produit 0.5V (500 mV)
- Chaque degré Celsius ajoute 10 mV (0.01V)
- Formule : T(°C) = (Vout - 0.5) × 100

Exemple : Si Vout = 0.75V → T = (0.75 - 0.5) × 100 = 25°C

Sa plage de mesure est de -40°C à +125°C avec une précision de ±1°C.

---

### Q19 : Quelle est la différence entre un capteur analogique et numérique ?

**Réponse :**
- **Capteur analogique** (TMP36) : produit une tension **continue** et variable (ex : 0.73V). L'Arduino doit la convertir en valeur numérique via le CAN. Simple mais sensible au bruit.
- **Capteur numérique** (DHT11) : envoie directement des **données numériques** (ex : "25.3°C") via un protocole de communication. Plus précis mais nécessite souvent une bibliothèque externe.

Notre choix du TMP36 (analogique) simplifie le code — pas de bibliothèque nécessaire.

---

### Q20 : Qu'est-ce que le CAN (Convertisseur Analogique-Numérique) ?

**Réponse :** Le CAN (ou ADC en anglais) est un circuit intégré dans l'Arduino qui convertit une **tension analogique continue** en une **valeur numérique discrète**. L'Arduino Uno a un CAN 10 bits :
- 10 bits = 2^10 = 1024 niveaux
- Plage d'entrée : 0V à 5V
- Résolution : 5V / 1024 ≈ 4.88 mV par pas

C'est comme un thermomètre qui ne peut afficher que des valeurs entières : 25°C, 26°C, mais pas 25.3°C.

---

### Q21 : Pourquoi le TMP36 et pas le DHT11 ?

**Réponse :**
| Critère | TMP36 | DHT11 |
|---------|-------|-------|
| Type | Analogique | Numérique |
| Mesure | Température seule | Température + humidité |
| Bibliothèque | Aucune nécessaire | Bibliothèque DHT requise |
| Précision | ±1°C | ±2°C |
| Complexité code | Très simple | Plus complexe |
| Disponibilité Tinkercad | Oui | Oui |

Nous avons choisi le TMP36 pour sa **simplicité** : pas de bibliothèque externe, code plus court, et suffisant pour notre objectif pédagogique.

---

### Q22 : Expliquez la formule de conversion température = (tension - 0.5) × 100.

**Réponse :** Cette formule vient de la fiche technique du TMP36 :
1. Le TMP36 produit **500 mV (0.5V) à 0°C** — c'est l'offset
2. Il ajoute **10 mV par degré Celsius** — c'est la sensibilité

Donc :
- On soustrait l'offset : `tension - 0.5` → donne la tension correspondant aux degrés au-dessus de 0°C
- On multiplie par 100 : car 10 mV = 0.01V par °C, et 1/0.01 = 100

Vérification : à 25°C → Vout = 0.5 + (25 × 0.01) = 0.75V → T = (0.75 - 0.5) × 100 = 25°C ✓

---

### Q23 : Quelle est la précision de votre système de mesure ?

**Réponse :** La précision globale dépend de deux facteurs :
1. **Précision du capteur TMP36** : ±1°C (donnée constructeur)
2. **Résolution du CAN** : 4.88 mV par pas → 4.88 mV / 10 mV par °C ≈ ±0.49°C

La précision totale est d'environ **±1.5°C**, ce qui est suffisant pour détecter un dépassement de seuil, mais pas pour des mesures médicales ou industrielles de précision.

---

### Q24 : Le capteur peut-il mesurer des températures négatives ?

**Réponse :** Oui ! Le TMP36 peut mesurer de **-40°C à +125°C**. À -40°C, il produit 0.1V (100 mV). Notre formule fonctionne aussi pour les températures négatives :
- À -10°C : Vout = 0.5 + (-10 × 0.01) = 0.4V → T = (0.4 - 0.5) × 100 = -10°C ✓

Note : Le LM35, un capteur similaire, ne peut pas mesurer en dessous de 0°C sans circuit supplémentaire.

---

## Catégorie 4 : LEDs et Actuateurs (Questions 25–30)

---

### Q25 : Qu'est-ce qu'une LED et comment fonctionne-t-elle ?

**Réponse :** Une LED (Light Emitting Diode = Diode Électroluminescente) est un composant semi-conducteur qui émet de la lumière lorsqu'un courant électrique le traverse. Elle a deux pattes :
- **Anode (+)** — la patte longue — connectée au signal
- **Cathode (-)** — la patte courte — connectée à GND

La LED est **polarisée** : si on la branche à l'envers, elle ne s'allume pas (et ne s'endommage pas). La couleur dépend du matériau semi-conducteur utilisé.

---

### Q26 : Pourquoi utilise-t-on une résistance avec chaque LED ?

**Réponse :** Sans résistance, le courant serait trop élevé et la LED brûlerait. La résistance **limite le courant** selon la loi d'Ohm :

I = (Varduino - Vled) / R = (5V - 2V) / 220Ω ≈ 13.6 mA

Ce courant (13.6 mA) est sûr pour la LED (maximum typique : 20 mA). Sans résistance, le courant pourrait atteindre 60+ mA et détruire la LED ou endommager la broche Arduino (maximum 40 mA par broche).

---

### Q27 : Pourquoi avoir choisi 220Ω et pas une autre valeur ?

**Réponse :** 220Ω est un bon compromis :
- **Trop faible (ex: 100Ω)** → courant trop élevé = LED trop lumineuse, risque de dommage
- **Trop élevé (ex: 1kΩ)** → courant trop faible = LED très faible
- **220Ω** → ~13.6 mA = luminosité correcte et sûre

C'est la valeur recommandée par la documentation Arduino et les tutoriels. En pratique, toute valeur entre 150Ω et 330Ω fonctionne bien.

---

### Q28 : Comment fonctionne un buzzer piézoélectrique ?

**Réponse :** Un buzzer piézoélectrique contient un **cristal piézoélectrique** qui se déforme quand on lui applique une tension. En envoyant un signal carré qui alterne rapidement entre HIGH et LOW (grâce à `tone()`), le cristal vibre et produit un **son**.

La fréquence du signal détermine la hauteur du son :
- 500 Hz = son grave
- 1000 Hz = son moyen (notre choix)
- 4000 Hz = son aigu

---

### Q29 : Quelle est la différence entre un buzzer actif et passif ?

**Réponse :**
- **Buzzer actif** : contient un oscillateur intégré. Il suffit d'envoyer du courant (HIGH/LOW) pour qu'il sonne à une fréquence fixe. Pas besoin de `tone()`.
- **Buzzer passif** (piézoélectrique) : n'a pas d'oscillateur. Il faut lui envoyer un signal oscillant avec `tone(broche, fréquence)`. On peut donc choisir la fréquence du son.

Dans Tinkercad, le composant "Piezo" est un buzzer passif, ce qui nous permet de contrôler la fréquence.

---

### Q30 : Pourquoi utiliser deux LEDs au lieu d'une seule ?

**Réponse :** Deux LEDs de couleurs différentes offrent une **indication visuelle immédiate** :
- **Vert** = tout va bien (convention universelle : feu vert = OK)
- **Rouge** = problème, attention (convention universelle : feu rouge = danger)

Avec une seule LED, il faudrait interpréter allumé/éteint, ce qui est moins intuitif. Les deux couleurs permettent de comprendre l'état du système **d'un seul coup d'œil**, même à distance.

---

## Catégorie 5 : Conception du Circuit (Questions 31–36)

---

### Q31 : Qu'est-ce qu'une breadboard et à quoi sert-elle ?

**Réponse :** Une breadboard (plaque d'essai) est une plaque perforée qui permet de **connecter des composants électroniques sans soudure**. Les trous sont reliés électriquement :
- **Lignes horizontales** (au centre) : connectées par groupes de 5
- **Rails latéraux** (+ et -) : connectés en colonnes sur toute la longueur → pour l'alimentation (5V) et la masse (GND)

C'est l'outil de base pour le prototypage rapide. On peut facilement ajouter, retirer ou déplacer des composants.

---

### Q32 : Pourquoi les composants sont-ils tous reliés à GND ?

**Réponse :** En électricité, un circuit doit être **fermé** pour que le courant circule. GND (Ground = masse) est le point de référence commun (0V) du circuit. Chaque composant a besoin de deux connexions :
1. Le **signal** ou l'alimentation (côté "positif") → provient d'une broche Arduino
2. La **masse** (GND) → le retour du courant

Sans connexion à GND, le circuit est ouvert et aucun courant ne circule. C'est comme débrancher un appareil : même si le câble d'alimentation est connecté, sans le neutre, il ne fonctionne pas.

---

### Q33 : Pourquoi le TMP36 est sur A0 et pas sur D3 ?

**Réponse :** Le TMP36 est un capteur **analogique** : il produit une tension variable (ex : 0.73V) et non un simple HIGH/LOW. Les broches **analogiques** (A0–A5) ont un convertisseur analogique-numérique (CAN) qui peut mesurer cette tension avec une résolution de 1024 niveaux. Les broches **numériques** (D0–D13) ne peuvent lire que deux états : HIGH (>3V) ou LOW (<1.5V). Elles ne peuvent pas mesurer une tension de 0.73V avec précision.

---

### Q34 : Que se passe-t-il si on branche le TMP36 à l'envers ?

**Réponse :** Si on inverse les broches VCC et GND du TMP36 :
- Le capteur ne sera pas alimenté correctement
- Il pourrait **chauffer** (la tension sera appliquée à l'envers)
- Les valeurs lues seront **incohérentes** (souvent -50°C ou des valeurs aberrantes)
- Le capteur pourrait être **endommagé** de manière permanente

**Signe typique** : si le moniteur série affiche une température de -50°C ou une valeur qui augmente rapidement, le TMP36 est probablement inversé.

---

### Q35 : Combien de courant consomme votre circuit total ?

**Réponse :**
| Composant | Courant |
|-----------|---------|
| Arduino Uno (base) | ~50 mA |
| TMP36 | ~0.05 mA (50 µA) |
| LED (une seule allumée) | ~13.6 mA |
| Buzzer piézo | ~5–30 mA |
| **Total approximatif** | **~70–95 mA** |

L'alimentation USB fournit jusqu'à 500 mA, donc notre circuit est largement dans les limites. L'Arduino peut aussi fournir un maximum de 200 mA sur la broche 5V.

---

### Q36 : Pourquoi ne pas connecter le buzzer directement sans résistance ?

**Réponse :** Un buzzer piézoélectrique a une **impédance élevée** (haute résistance interne), donc le courant qui le traverse est naturellement faible (~5–30 mA). Il n'a pas besoin de résistance de protection, contrairement aux LEDs qui ont une résistance interne très faible. C'est la raison pour laquelle on connecte le buzzer directement à la broche D5 de l'Arduino.

---

## Catégorie 6 : Logique du Programme (Questions 37–42)

---

### Q37 : Pourquoi avoir choisi un seuil de 30°C ?

**Réponse :** 30°C est un seuil **pratique pour la démonstration** :
- C'est au-dessus de la température ambiante normale (~20–25°C)
- C'est facilement atteignable dans Tinkercad (curseur du TMP36)
- C'est une valeur réaliste : dans l'industrie, 30°C peut indiquer une surchauffe d'un serveur informatique

En production, le seuil serait adapté au contexte : 37.5°C pour la fièvre humaine, 70°C pour un moteur, 4°C pour un réfrigérateur.

---

### Q38 : Comment modifier le seuil de température ?

**Réponse :** Il suffit de changer la valeur de la constante `SEUIL_TEMPERATURE` dans le code :
```
const float SEUIL_TEMPERATURE = 30.0;  // Changer cette valeur
```
Par exemple, pour un seuil à 25°C : `const float SEUIL_TEMPERATURE = 25.0;`

C'est une **limitation** du système actuel : il faut reprogrammer l'Arduino pour changer le seuil. Une amélioration serait d'utiliser un potentiomètre ou des boutons pour ajuster le seuil dynamiquement.

---

### Q39 : Pourquoi utiliser des constantes (const) plutôt que des valeurs directes ?

**Réponse :** Utiliser des constantes (`const int BROCHE_LED_VERTE = 3;`) au lieu de valeurs directes (`digitalWrite(3, HIGH);`) offre plusieurs avantages :
1. **Lisibilité** — `BROCHE_LED_VERTE` est plus compréhensible que `3`
2. **Maintenance** — Pour changer de broche, on modifie une seule ligne
3. **Sécurité** — `const` empêche la modification accidentelle de la valeur
4. **Mémoire** — Le compilateur remplace les constantes par leurs valeurs, donc pas de mémoire RAM supplémentaire utilisée

---

### Q40 : Que se passe-t-il si la température oscille autour du seuil ?

**Réponse :** Si la température fluctue autour de 30°C (ex : 29.9°C → 30.1°C → 29.8°C), le système va **alterner rapidement** entre les états normal et alerte. La LED va clignoter et le buzzer va s'activer/se désactiver de façon saccadée. C'est le problème du **"bouncing"** ou **oscillation de seuil**.

**Solution possible** : Implémenter une **hystérésis** — par exemple :
- Passer en alerte à 30°C
- Revenir en normal seulement en dessous de 28°C
Cela crée une "zone morte" qui évite les oscillations.

---

### Q41 : Pourquoi la conversion utilise 5.0/1024.0 et pas 5.0/1023.0 ?

**Réponse :** C'est un débat classique en électronique :
- **5.0/1024.0** : considère que 0 compte comme un niveau (0 à 1023 = 1024 valeurs)
- **5.0/1023.0** : considère que 1023 correspond exactement à 5V

Les deux approches donnent des résultats quasi identiques (différence < 0.005V). La documentation Arduino utilise 1024.0 comme convention. En pratique, la différence est négligeable par rapport à la précision du capteur (±1°C).

---

### Q42 : Le programme peut-il gérer plusieurs capteurs ?

**Réponse :** Oui, l'Arduino Uno a **6 broches analogiques** (A0–A5), donc on pourrait connecter jusqu'à 6 capteurs TMP36. Il faudrait :
1. Ajouter une variable pour chaque capteur (`analogRead(A1)`, `analogRead(A2)`, etc.)
2. Ajouter la conversion pour chaque lecture
3. Comparer chaque température au seuil
4. Adapter les actuateurs (un jeu de LEDs par capteur, ou une logique combinée)

---

## Catégorie 7 : Déploiement Réel (Questions 43–46)

---

### Q43 : Le code fonctionnerait-il avec un Arduino réel ?

**Réponse :** **Oui, sans aucune modification.** Le code est 100% compatible avec un Arduino Uno réel. Les étapes seraient :
1. Ouvrir `temperature_monitor.ino` dans l'Arduino IDE
2. Connecter l'Arduino via USB
3. Sélectionner la carte (Arduino Uno) et le port (COM3 ou similaire)
4. Cliquer sur "Téléverser"
5. Ouvrir le Moniteur Série (9600 bauds)

Le câblage physique serait identique à celui décrit dans le guide Tinkercad.

---

### Q44 : Quelles différences y aurait-il entre la simulation et le réel ?

**Réponse :**
| Aspect | Tinkercad (simulation) | Matériel réel |
|--------|----------------------|---------------|
| Température | Curseur manuel | Température ambiante réelle |
| Bruit | Aucun | Fluctuations sur le signal analogique |
| Buzzer | Son simulé (léger) | Son réel (fort) |
| Délais | Parfaits | Légèrement variables |
| Câblage | Clic-glisser | Fils physiques (risque de mauvais contact) |

En réel, il faudrait peut-être ajouter un **condensateur de découplage** (100nF) entre VCC et GND du TMP36 pour réduire le bruit.

---

### Q45 : Comment alimenter le système sans ordinateur ?

**Réponse :** Plusieurs options :
1. **Adaptateur secteur** (7–12V DC) → broche jack de l'Arduino
2. **Batterie 9V** → broche jack ou broche Vin de l'Arduino
3. **Power bank USB** → port USB de l'Arduino
4. **Pile AA (4×)** → 6V sur broche Vin (minimum 7V recommandé)

Pour un déploiement longue durée, une batterie LiPo rechargeable avec un panneau solaire serait idéale.

---

### Q46 : Comment rendre ce projet résistant aux intempéries ?

**Réponse :** Pour un déploiement en extérieur :
1. **Boîtier étanche** (IP65 minimum) — imprimé en 3D ou acheté
2. **Capteur protégé** — placer le TMP36 sous un abri ventilé
3. **Conformal coating** — vernis de protection sur le circuit
4. **Alimentation protégée** — batterie dans le boîtier, panneau solaire externe
5. **Connecteurs étanches** — pour les câbles qui sortent du boîtier

---

## Catégorie 8 : Améliorations et Perspectives (Questions 47–50)

---

### Q47 : Comment ajouteriez-vous une connexion WiFi ?

**Réponse :** On remplacerait l'Arduino Uno par un **ESP32** (ou on ajouterait un module ESP8266) :
1. Le code resterait similaire (même langage C/C++)
2. On ajouterait la bibliothèque WiFi
3. On enverrait les données à un service cloud (ThingSpeak, Firebase)
4. On pourrait créer un tableau de bord web pour visualiser les données à distance

Exemple simplifié : `WiFi.begin("réseau", "mot_de_passe")` puis `http.POST(température)`.

---

### Q48 : Comment ajouteriez-vous un écran LCD ?

**Réponse :** On ajouterait un **écran LCD 16×2 avec module I2C** :
1. Connecter SDA → A4, SCL → A5 (bus I2C)
2. Inclure la bibliothèque `LiquidCrystal_I2C`
3. Afficher la température sur l'écran :
```
lcd.setCursor(0, 0);
lcd.print("Temp: ");
lcd.print(temperature);
lcd.print(" C");
```

L'I2C n'utilise que 2 broches, ce qui laisse les autres libres pour d'autres composants.

---

### Q49 : Comment intégrer l'IA dans ce projet ?

**Réponse :** En tant qu'étudiants en Master IA, plusieurs pistes :
1. **Prédiction** — Entraîner un modèle de machine learning pour prédire les tendances de température (séries temporelles)
2. **Détection d'anomalies** — Utiliser un algorithme non supervisé pour détecter des patterns de température inhabituels
3. **Seuil adaptatif** — Apprendre automatiquement le seuil optimal selon les données historiques
4. **Traitement sur le edge** — Utiliser TinyML (TensorFlow Lite pour microcontrôleurs) pour faire de l'inférence directement sur l'Arduino

---

### Q50 : Si vous deviez refaire ce projet, que changeriez-vous ?

**Réponse :**
1. **Utiliser un ESP32** au lieu de l'Arduino Uno → WiFi intégré, plus de puissance
2. **Ajouter un écran OLED** → affichage local sans PC
3. **Utiliser le DHT22** → température + humidité, meilleure précision
4. **Implémenter l'hystérésis** → éviter les oscillations au seuil
5. **Stocker les données** → carte SD ou cloud pour l'historique
6. **Ajouter un bouton** → pour ajuster le seuil sans reprogrammer
7. **Créer une application mobile** → pour le suivi à distance
8. **Utiliser millis()** au lieu de **delay()** → pour un système multitâche

---

*Document préparé pour la soutenance orale — Projet IoT — Master M1 IA — Juin 2026*
