# Phase 2 — Code Arduino

## Objectif
Développer le code source Arduino pour le système de surveillance de température.

## Tâches
- [x] Créer `src/temperature_monitor.ino`
- [x] Implémenter la lecture du capteur TMP36
- [x] Implémenter la logique de seuil
- [x] Implémenter le contrôle des LEDs
- [x] Implémenter l'alarme buzzer
- [x] Implémenter la sortie moniteur série
- [x] Commenter chaque ligne de code
- [x] Tester la compatibilité Tinkercad

## Composants utilisés
| Composant | Broche Arduino | Rôle |
|-----------|---------------|------|
| TMP36 | A0 | Mesure de température |
| LED Verte | D3 | Indicateur normal |
| LED Rouge | D4 | Indicateur alerte |
| Buzzer | D5 | Alarme sonore |

## Logique du système
```
SI température < seuil :
    LED verte = ALLUMÉE
    LED rouge = ÉTEINTE
    Buzzer = ÉTEINT

SI température >= seuil :
    LED verte = ÉTEINTE
    LED rouge = ALLUMÉE
    Buzzer = ACTIVÉ
```

## Statut : ✅ Terminée
