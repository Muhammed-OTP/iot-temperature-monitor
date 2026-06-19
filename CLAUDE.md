# Système de Surveillance de Température — IoT

## Projet
Projet académique IoT — Master M1 Intelligence Artificielle
Module : Internet des Objets (IoT)

## Équipe
- **Moustapha Yehdih** (C34613)
- **Mohamed Salem Ebnou Echvagha Oubeid** (C34794)

## Date limite
19/06/2026 — 23:59

## Stack technique
- **Microcontrôleur** : Arduino Uno
- **Capteur** : TMP36 (capteur de température analogique)
- **Actuateurs** : LED verte, LED rouge, Buzzer piézoélectrique
- **Simulation** : Tinkercad Circuits
- **Rapport** : LaTeX
- **Présentation** : HTML / CSS / JS
- **Langage embarqué** : C/C++ (Arduino IDE)

## Structure du projet
```
iot-temperature-monitor/
├── CLAUDE.md              # Ce fichier
├── PHASES.md              # Plan de phases
├── README.md              # Documentation principale
├── src/
│   └── temperature_monitor.ino   # Code Arduino
├── report/
│   └── report.tex         # Rapport LaTeX
├── presentation/
│   └── index.html          # Présentation HTML/CSS/JS
├── docs/
│   ├── tinkercad_guide.md  # Guide de câblage Tinkercad
│   └── oral_defense.md     # Préparation soutenance orale
├── diagrams/               # Schémas d'architecture
└── screenshots/            # Captures Tinkercad
```

## Workflow Git
- Branche unique : `main`
- Workflow : modifier → stage → commit → push
- Pas de PR, pas de branches secondaires
- Messages de commit en français

## Commandes
```bash
# Compiler (si Arduino CLI installé)
arduino-cli compile --fqbn arduino:avr:uno src/temperature_monitor.ino

# Téléverser
arduino-cli upload -p COM3 --fqbn arduino:avr:uno src/temperature_monitor.ino
```

## Langue
Tout le projet est en **français**.
