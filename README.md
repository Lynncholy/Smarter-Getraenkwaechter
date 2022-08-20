# Smarter-Getraenkewaechter

Der Smarte Getränkewächter ist ein Gerät, welches die Temperatur von heißen Getränken misst und überwacht. Über die Handy App Blynk lässt sich die gewünschte Temperatur einstellen, bei dem der Getränkewächter eine Push-Benachrichtigung an die NutzerInnen schickt. So wird man rechtzeitig daran erinnert das Getränk auszutrinken, bevor es komplett abgekühlt ist.

Der Wächter selbst besteht aus einem Infrarotsensor und einem Mikrocontroller, die in der Holzbox liegen. Auf der Oberseite der Holzbox liegen dabei ein Tassenuntersetzer, ein Switch und eine 3D-Schale für den Switch.
Sobald eine Tasse auf dem Untersetzer gestellt wird, wird auch der Switch runtergedrückt, sodass der Mikrocontroller und Sensor aktiv werden. Ab dann kann man auf dem Handy mit der App Blynk die Temperatur des Getränks beobachten und einstellen, bei welchen Temperaturen eine Benachrichtigung gesendet werden soll.

Dieses Repository enthält alle Dateien und Materialien, die bei der Entwicklung des Projekts entstanden sind und benötigt wurden. Die Projektdokumentation befindet sich in diesem [Blog](https://wp.uni-oldenburg.de/soft-skills-und-technische-kompetenz-wise20212022-projektgruppe-11/projektdokumentation-ubersicht/).

Im Ordner [3D-Modelierung](https://github.com/Lynncholy/Smarter-Getraenkewaechter/tree/main/3D-Modelierung) befindet sich eine STL-Datei für eine Schale, die mit dem 3D Drucker ausgedruckt wurde.

Im Ordner [Blynk](https://github.com/Lynncholy/Smarter-Getraenkewaechter/tree/main/Blynk) befindet sich ein QR-Code, der mit der App Blynk gescannt werden kann, um die Benutzeroberfläche für den Getränkewächter in Blynk zu öffnen.

Im Ordner [Holzbox](https://github.com/Lynncholy/Smarter-Getraenkewaechter/tree/main/Holzbox) befinden sich alle Dateien für die Holzbox des Getränkewächters. Die Teile wurden durch Lasercutting herausgeschnitten.

Im Ordner [Quellcode](https://github.com/Lynncholy/Smarter-Getraenkewaechter/tree/main/Quellcode) befindet sich der Code, der in Arduino eingefügt werden muss, um den Mikrocontroller und den Infrarotsensor benutzen zu können.

Die Bedienungsanleitung für den Getränkewächter befindet sich [hier](https://wp.uni-oldenburg.de/soft-skills-und-technische-kompetenz-wise20212022-projektgruppe-11/2022/07/19/nutzerhandbuch/).
