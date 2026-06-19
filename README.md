# 🌡️ Système de Surveillance de Température

**Projet IoT — Master M1 Intelligence Artificielle**

## 📋 Description

Ce projet implémente un **système de surveillance de température en temps réel** utilisant un microcontrôleur Arduino Uno et un capteur de température TMP36. Le système mesure continuellement la température ambiante, affiche les valeurs sur le moniteur série, et déclenche des alertes visuelles (LEDs) et sonores (buzzer) lorsque la température dépasse un seuil prédéfini.

## 👥 Équipe

| Nom | ID Étudiant |
|-----|-------------|
| Moustapha Yehdih | C34613 |
| Mohamed Salem Ebnou Echvagha Oubeid | C34794 |

## 🏗️ Architecture du Système

```
┌─────────────┐     ┌──────────────┐     ┌──────────────────┐
│   Capteur   │────▶│  Arduino Uno │────▶│   Actuateurs     │
│   TMP36     │     │  (Traitement)│     │  LEDs + Buzzer   │
│ (Entrée)    │     │              │     │  (Sortie)        │
└─────────────┘     └──────┬───────┘     └──────────────────┘
                           │
                           ▼
                    ┌──────────────┐
                    │  Moniteur    │
                    │  Série (PC)  │
                    └──────────────┘
```

## 🔧 Composants

| Composant | Quantité | Rôle |
|-----------|----------|------|
| Arduino Uno | 1 | Microcontrôleur principal |
| TMP36 | 1 | Capteur de température analogique |
| LED Verte | 1 | Indicateur température normale |
| LED Rouge | 1 | Indicateur température élevée |
| Buzzer piézoélectrique | 1 | Alarme sonore |
| Résistance 220Ω | 2 | Protection des LEDs |
| Breadboard | 1 | Plaque d'essai |
| Fils de connexion | ~10 | Câblage |

## ⚡ Logique du Système

```
SI température < 30°C :
    ✅ LED verte ALLUMÉE
    ⬛ LED rouge ÉTEINTE
    🔇 Buzzer ÉTEINT

SI température ≥ 30°C :
    ⬛ LED verte ÉTEINTE
    🔴 LED rouge ALLUMÉE
    🔊 Buzzer ACTIVÉ
```

## 📁 Structure du Projet

```
iot-temperature-monitor/
├── README.md                    # Ce fichier
├── CLAUDE.md                    # Configuration projet
├── PHASES.md                    # Plan de phases
├── src/
│   └── temperature_monitor.ino  # Code source Arduino
├── report/
│   └── report.tex               # Rapport LaTeX
├── presentation/
│   └── index.html               # Présentation HTML/CSS/JS
├── docs/
│   ├── tinkercad_guide.md       # Guide Tinkercad
│   └── oral_defense.md          # Préparation soutenance
├── diagrams/                    # Schémas
├── screenshots/                 # Captures d'écran
└── phases/                      # Détail des phases
```

## 🚀 Démarrage Rapide

### Simulation (Tinkercad)
1. Ouvrir [Tinkercad Circuits](https://www.tinkercad.com/circuits)
2. Créer un nouveau circuit
3. Suivre le guide : `docs/tinkercad_guide.md`
4. Copier le code depuis `src/temperature_monitor.ino`
5. Lancer la simulation

### Matériel Réel (Arduino IDE)
1. Connecter l'Arduino Uno via USB
2. Ouvrir `src/temperature_monitor.ino` dans l'IDE Arduino
3. Sélectionner la carte : **Arduino Uno**
4. Sélectionner le port : **COM3** (ou équivalent)
5. Cliquer sur **Téléverser**
6. Ouvrir le **Moniteur Série** (9600 bauds)

## 📄 Livrables

- [x] Code source Arduino
- [x] Rapport académique (LaTeX)
- [x] Présentation (HTML/CSS/JS)
- [x] Guide Tinkercad
- [x] Préparation soutenance orale

## 📚 Références

- [Documentation Arduino](https://www.arduino.cc/reference/fr/)
- [Fiche technique TMP36](https://www.analog.com/en/products/tmp36.html)
- [Tinkercad Circuits](https://www.tinkercad.com/circuits)

---

*Projet réalisé dans le cadre du module IoT — Master M1 IA — 2025/2026*
