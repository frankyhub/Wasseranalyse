<a name="oben"></a>

<div align="center">

|[:skull:ISSUE](https://github.com/frankyhub/Paper-Circuit-BOT/issues?q=is%3Aissue)|[:speech_balloon: Forum /Discussion](https://github.com/frankyhub/Paper-Circuit-BOT/discussions)|[:grey_question:WiKi](https://github.com/frankyhub/Paper-Circuit-BOT/wiki)||
|--|--|--|--|
| | | | |
<a href="https://github.com/frankyhub/Paper-Circuit-BOT/issues">![GitHub issues](https://img.shields.io/github/issues/frankyhub/Paper-Circuit-BOT)![GitHub closed issues](https://img.shields.io/github/issues-closed/frankyhub/Paper-Circuit-BOT)|<a href="https://github.com/frankyhub/Paper-Circuit-BOT/discussions">![GitHub Discussions](https://img.shields.io/github/discussions/frankyhub/Paper-Circuit-BOT)|<a href="https://github.com/frankyhub/Paper-Circuit-BOT/releases">![GitHub release (with filter)](https://img.shields.io/github/v/release/frankyhub/Paper-Circuit-BOT)|![Static Badge](https://img.shields.io/badge/RepoNr.:-%20034-blue)|
|![GitHub Created At](https://img.shields.io/github/created-at/frankyhub/Paper-Circuit-BOT)| <a href="https://github.com/frankyhub/Paper-Circuit-BOT/pulse" alt="Activity"><img src="https://img.shields.io/github/commit-activity/m/badges/shields" />| <a href="https://github.com/frankyhub/Paper-Circuit-BOT/graphs/traffic"><img alt="ViewCount" src="https://views.whatilearened.today/views/github/frankyhub/github-clone-count-badge.svg">  |<a href="https://github.com/frankyhub?tab=stars"> ![GitHub User's stars](https://img.shields.io/github/stars/frankyhub)||


</div>

## Story

Mit diesem Projekt wird der TDS-Wert von Wasser in ppm auf einem OLED-Display angezeigt. Bei einer TDS Messung wird die elektrische Leitfähigkeit des Wassers gemessen, d.h. die elektrisch geladenen Moleküle (Ionen), werden gemessen. Im Fall von Trinkwasser wären das die darin am häufigsten vorkommenden leitfähigen Stoffe, z.B. Metalle, Mineralien, Salze usw. Dadurch, dass das Wasser selbst nicht geladen ist, wird ausschließlich die Leitfähigkeit und somit die Anzahl der Ionen im Wasser gemessen.
Die TDS-Konzentration wird üblicherweise in Teilen pro Million (ppm) oder Milligramm pro Liter (mg/L) gemessen und je nach Anwendung ist ein anderer Wert erstrebenswert. Während bspw. der TDS-Gehalt für Trinkwasser weniger als 500 ppm betragen sollte, sollte der TDS-Gehalt in Hydrokultursystemen mit Fruchtpflanzen wie Tomaten und Gurken bei etwa 1000-1200 ppm liegen. Indem wir diese Werte regelmäßig messen, können wir reagieren und z.B. Nährstoffe hinzufügen.

## Hardware

Die Stückliste für die Wasserqualitäts-Anzeige:

| Anzahl | Bezeichnung | 
| -------- | -------- | 
|  1 |  ESP32  |
|  1 |  TDS-Sensor  |
|  1 |  OLED-Display 1,3"  |
|   | Kleinmaterial, Schaltdraht   |
| ---  | ---   |



<img src="pic/wa2.png" width="500"> 
<br> <br>


#### Bild: TDS-Sensor




## Verdrahtung

ESP32 - TDS Sensor:

| ESP32 | TDS Sensor | 
| -------- | -------- | 
|  GND | GND  |
|  +5V |  +5V  |
|  GPIO27 |  Signal  |
| ---  | ---   |


ESP32 - OLED Display 1,3":

| ESP32 | OLED Display 1,3| 
| -------- | -------- | 
|  GND | GND  |
|  +5V |  +5V  |
|  SCL	 |  SCK	  |
|  SDA	 |  SDA	  |
| ---  | ---   |

<img src="pic/wa1.jpg" width="500"> 
<br> <br>

---

<div style="position:absolute; left:2cm; ">   
<ol class="breadcrumb" style="border-top: 2px solid black;border-bottom:2px solid black; height: 45px; width: 900px;"> <p align="center"><a href="#oben">nach oben</a></p></ol>
</div>  

---



