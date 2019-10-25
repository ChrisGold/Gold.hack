# Gold.hack

Gold.hack ist ein Roguelike ("Rogue"-ähnlich) Spiel. Der Spieler erkundet das finsteres Verlies des Zauberers Aurelian und kämpft dabei gegen Monster. Es wird im Rahmen der Veranstaltung [PADI](https://graphics.tu-bs.de/teaching/ws1920/padi) an der TU-Braunschweig von mir, Christian Goldapp, entwickelt.

Das Verlies besteht aus einer konfigurierbaren Zahl von Ebenen. Jede Ebene wird zufällig generiert. Auf jeder Ebene finden sich in Gängen und Räumen verschiedene Monster, die der Spieler mit Nahkampfwaffen, Bögen, und Magie bekämpft. Hierbei sammelt der Spieler Gold, dass benutzt werden kann um an bestimmten Altaren die Figur zu verstärken.

## Spielablauf

Das Spiel läuft simultan-rundenbasiert ab. Das heißt, in Schritten führt jede Figur eine Handlung gleichzeitig aus. Daraufhin werden alle Auswirkungen der Handlungen auf die Welt angewendet, und die nächste Handlungsrunde steht an. Der Spieler kann Handlungssequenzen starten, und auch wieder abbrechen. Damit wird beispielsweise das Ablaufen von längeren Strecken weniger eintönig.

Im Netzwerk-Multiplayer kann der Spieler einen oder zwei Freunde einladen, mit denen zusammen das Verlies erkundet wird. Die Spieler handeln ebenfalls simultan-rundenbasiert; daher findet ein Zug erst statt, wenn alle eine Handlung ausgewählt haben. Wenn alle Spieler eine Sequenz ausgewählt haben, läuft das Spiel dementsprechend genauso lange, wie noch alle Sequenzen Handlungen enthalten.

Handlungen sind:

* Ein Feld gehen
* Mit der Welt interagieren
* Ein Angriff mit der Waffe
* Einen Zauber wirken
* Einen verzehrbaren Gegenstand verzehren
* Warten, und nichts tun

## Umgesetzte Features

### Schwierigkeitsgrad C

* Singleplayer
* Menü
* Sound
* 3+ Level
* Speichern / Laden des Fortschritts
* Schwierigkeitsgrade

### Schwierigkeitsgrad B

* Controllerunterstützung
* Ingame chat
* Levelgeneration aus einer Textdatei
* Betriebsystemunabhängig

### Schwierigkeitsgrad A

* Netzwerk-Multiplayer
* Charakter-Entwicklung
* Quest-Management
* Levelgeneration im Spiel

### Schwierigkeitsgrad S

* Eigene Shader
* prozedural generierte Welt
