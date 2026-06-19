# Guide Complet Tinkercad — Système de Surveillance de Température

## Table des matières
1. [Présentation de Tinkercad](#1-présentation-de-tinkercad)
2. [Créer un nouveau projet](#2-créer-un-nouveau-projet)
3. [Liste des composants](#3-liste-des-composants)
4. [Placement des composants](#4-placement-des-composants)
5. [Câblage détaillé pin par pin](#5-câblage-détaillé-pin-par-pin)
6. [Copier le code Arduino](#6-copier-le-code-arduino)
7. [Lancer la simulation](#7-lancer-la-simulation)
8. [Tester les scénarios](#8-tester-les-scénarios)
9. [Dépannage](#9-dépannage)

---

## 1. Présentation de Tinkercad

**Tinkercad Circuits** est un simulateur en ligne gratuit par Autodesk. Il permet de :
- Assembler des circuits virtuels (Arduino, capteurs, LEDs, etc.)
- Écrire et exécuter du code Arduino
- Simuler le comportement du circuit sans matériel physique

**Avantage** : Pas besoin d'acheter de composants. Tout se fait dans le navigateur.

---

## 2. Créer un nouveau projet

1. Aller sur **tinkercad.com**
2. Se connecter (ou créer un compte gratuit)
3. Cliquer sur **Circuits** dans le menu de gauche
4. Cliquer sur **Créer un circuit**
5. Un espace de travail vide s'ouvre

---

## 3. Liste des composants

Chercher et glisser ces composants depuis le panneau de droite :

| # | Composant | Rechercher dans Tinkercad |
|---|-----------|--------------------------|
| 1 | Arduino Uno | "Arduino Uno R3" |
| 2 | Breadboard (plaque d'essai) | "Breadboard" (petite) |
| 3 | Capteur de température | "TMP36" ou "Temperature Sensor" |
| 4 | LED verte | "LED" (changer la couleur en vert) |
| 5 | LED rouge | "LED" (couleur rouge par défaut) |
| 6 | Buzzer | "Piezo" |
| 7 | Résistance 220Ω | "Resistor" (changer à 220 ohms) |
| 8 | Résistance 220Ω | "Resistor" (deuxième, 220 ohms) |

**Astuce** : Pour changer la couleur d'une LED, cliquez dessus et modifiez la couleur dans le panneau de propriétés.

**Astuce** : Pour changer la valeur d'une résistance, cliquez dessus et entrez 220 dans le champ "Résistance".

---

## 4. Placement des composants

Placez les composants dans cet ordre sur l'espace de travail :

```
┌──────────────────────────────────────────────────────────┐
│                    ESPACE DE TRAVAIL                      │
│                                                           │
│  ┌─────────────┐        ┌──────────────────────────────┐ │
│  │             │        │        BREADBOARD             │ │
│  │   ARDUINO   │        │                              │ │
│  │     UNO     │        │  [TMP36]  [R1] [LED V]       │ │
│  │             │        │          [R2] [LED R]        │ │
│  │             │        │          [BUZZER]            │ │
│  │             │        │                              │ │
│  └─────────────┘        └──────────────────────────────┘ │
│                                                           │
└──────────────────────────────────────────────────────────┘
```

### Disposition sur la breadboard :
1. **TMP36** : Placez-le sur la breadboard, partie plate vers vous
   - Broche gauche = VCC (alimentation)
   - Broche centre = Signal (sortie)
   - Broche droite = GND (masse)

2. **LED Verte** : Placez-la à droite du TMP36
   - Patte longue (anode +) = vers la résistance
   - Patte courte (cathode -) = vers GND

3. **LED Rouge** : Placez-la à côté de la LED verte
   - Même orientation que la LED verte

4. **Résistances 220Ω** : Une pour chaque LED, en série avec l'anode

5. **Buzzer** : Placez-le en bas de la breadboard
   - Borne (+) = vers Arduino
   - Borne (-) = vers GND

---

## 5. Câblage détaillé pin par pin

### Tableau de câblage complet

| # | De (origine) | Vers (destination) | Couleur fil | Rôle |
|---|-------------|-------------------|-------------|------|
| 1 | Arduino **5V** | Breadboard rail **+** (rouge) | 🔴 Rouge | Alimentation +5V |
| 2 | Arduino **GND** | Breadboard rail **-** (bleu) | ⚫ Noir | Masse commune |
| 3 | TMP36 broche **gauche** | Breadboard rail **+** | 🔴 Rouge | Alimentation capteur |
| 4 | TMP36 broche **centre** | Arduino **A0** | 🟡 Jaune | Signal température |
| 5 | TMP36 broche **droite** | Breadboard rail **-** | ⚫ Noir | Masse capteur |
| 6 | Arduino **D3** | Résistance 220Ω (borne 1) | 🟢 Vert | Signal LED verte |
| 7 | Résistance 220Ω (borne 2) | LED Verte anode **(+)** | 🟢 Vert | Protection LED |
| 8 | LED Verte cathode **(-)** | Breadboard rail **-** | ⚫ Noir | Masse LED verte |
| 9 | Arduino **D4** | Résistance 220Ω (borne 1) | 🔴 Rouge | Signal LED rouge |
| 10 | Résistance 220Ω (borne 2) | LED Rouge anode **(+)** | 🔴 Rouge | Protection LED |
| 11 | LED Rouge cathode **(-)** | Breadboard rail **-** | ⚫ Noir | Masse LED rouge |
| 12 | Arduino **D5** | Buzzer borne **(+)** | 🟠 Orange | Signal buzzer |
| 13 | Buzzer borne **(-)** | Breadboard rail **-** | ⚫ Noir | Masse buzzer |

### Schéma textuel du câblage

```
                        ARDUINO UNO
                    ┌─────────────────┐
                    │                 │
              5V ───┤ 5V         D13 ├
             GND ───┤ GND        D12 ├
                    │ GND        D11 ├
                    │             D10 ├
                    │              D9 ├
                    │              D8 ├
                    │              D7 ├
                    │              D6 ├
      Buzzer(+) ────┤ D5          D5 ├─── Buzzer(+)
    LED Rouge ──R───┤ D4          D4 ├
    LED Verte ──R───┤ D3          D3 ├
                    │              D2 ├
                    │              D1 ├
                    │              D0 ├
     TMP36 sig ─────┤ A0             ├
                    │ A1             ├
                    │ A2             ├
                    │ A3             ├
                    │ A4             ├
                    │ A5             ├
                    └─────────────────┘

    TMP36 (vue de face, partie plate vers vous) :
    ┌───────┐
    │       │
    │ TMP36 │
    │       │
    └─┬─┬─┬─┘
      │ │ │
      │ │ └── GND (→ rail - de la breadboard)
      │ └──── Signal (→ Arduino A0)
      └────── VCC (→ rail + de la breadboard)

    LED (vue de côté) :
    Anode (+, patte longue) ──── Résistance 220Ω ──── Arduino Dx
    Cathode (-, patte courte) ── GND (rail -)

    Buzzer :
    Borne (+) ──── Arduino D5
    Borne (-) ──── GND (rail -)
```

---

## 6. Copier le code Arduino

1. Cliquer sur le bouton **Code** (en haut de l'écran Tinkercad)
2. Changer le mode de **Blocs** à **Texte**
3. **Supprimer** tout le code existant
4. **Copier** tout le contenu du fichier `src/temperature_monitor.ino`
5. **Coller** dans l'éditeur Tinkercad

---

## 7. Lancer la simulation

1. Cliquer sur le bouton **Démarrer la simulation** (en haut à droite)
2. Observer :
   - Le **Moniteur Série** affiche les valeurs (cliquer sur l'icône du moniteur série en bas)
   - La **LED verte** s'allume (température normale)
3. Pour tester l'alerte :
   - **Cliquer sur le capteur TMP36** dans la simulation
   - Un **curseur** apparaît pour modifier la température
   - **Glisser le curseur** au-dessus de 30°C
4. Observer le changement :
   - La LED verte s'éteint
   - La **LED rouge** s'allume
   - Le **buzzer** émet un son
   - Le moniteur série affiche **"*** ALERTE ***"**

---

## 8. Tester les scénarios

### Scénario 1 : Température normale (< 30°C)
- Régler le TMP36 sur **25°C**
- **Résultat attendu** :
  - ✅ LED verte allumée
  - ⬛ LED rouge éteinte
  - 🔇 Buzzer silencieux
  - Moniteur série : `Statut : NORMAL`

### Scénario 2 : Température limite (= 30°C)
- Régler le TMP36 sur **30°C**
- **Résultat attendu** :
  - ⬛ LED verte éteinte
  - 🔴 LED rouge allumée
  - 🔊 Buzzer actif
  - Moniteur série : `Statut : *** ALERTE ***`

### Scénario 3 : Température élevée (> 30°C)
- Régler le TMP36 sur **40°C**
- **Résultat attendu** :
  - ⬛ LED verte éteinte
  - 🔴 LED rouge allumée
  - 🔊 Buzzer actif
  - Moniteur série : `Statut : *** ALERTE ***`

### Scénario 4 : Retour à la normale
- Régler le TMP36 de **40°C** à **20°C**
- **Résultat attendu** :
  - ✅ LED verte se rallume
  - ⬛ LED rouge s'éteint
  - 🔇 Buzzer s'arrête
  - Moniteur série : `Statut : NORMAL`

---

## 9. Dépannage

| Problème | Solution |
|----------|----------|
| Rien ne se passe | Vérifier que le code est en mode **Texte**, pas **Blocs** |
| LED ne s'allume pas | Vérifier la polarité (anode/cathode) et la résistance |
| Température affiche -50°C | Le TMP36 est peut-être câblé à l'envers |
| Buzzer ne sonne pas | Vérifier la connexion sur D5 et GND |
| Moniteur série vide | Cliquer sur l'icône du moniteur série en bas |
| Valeurs erratiques | Vérifier que le signal TMP36 est bien sur A0 |

---

*Guide rédigé pour le projet IoT — Master M1 IA — 2025/2026*
