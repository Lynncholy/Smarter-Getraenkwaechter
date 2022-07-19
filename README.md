# Smarter-Getraenkewaechter

Beschreibung:
Der Smarte Getränkewächter überwacht die Temperatur deines Getränks und erinnert dich über Blynk daran, diesen rechtzeitig zu trinken, bevor es komplett abgekühlt ist.

Der Wächter selbst besteht aus einem Infrarotsensor und einem Mikrocontroller, die in der Holzbox liegen. Auf der Oberseite der Holzbox liegen dabei ein Tassenuntersetzer, ein Switch und eine 3D-Schale für den Switch.
Sobald eine Tasse auf dem Untersetzer gestellt wird, wird auch der Switch runtergedrückt, sodass der Mikrocontroller und Sensor aktiv werden. Ab dann kann man auf dem Handy mit der App Blynk die Temperatur des Getränks beobachten und einstellen, bei welchen Temperaturen eine Benachrichtigung gesendet werden soll.

Voraussetzung:
- Micro-USB Kabel
- Gerät mit dem Programm Arduin

Nutzung:
1. den Controller über ein Micro-USB Kabel mit einem Gerät, welches Arduino installiert hat, verbinden
2. in Arduino die Bibliothek "Adafruit MLX90614 Library" von Adafruit installieren
