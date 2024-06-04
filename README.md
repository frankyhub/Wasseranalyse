# Wasseranalyse
Wasseranalyse mit einem TDS-Sensor

## Story

Mit diesem Projekt wird der TDS-Wert von Wasser in ppm auf einem OLED-Display angezeigt. Bei einer TDS Messung wird die elektrische Leitfähigkeit des Wassers gemessen, d.h. die elektrisch geladenen Moleküle (Ionen), werden gemessen. Im Fall von Trinkwasser wären das die darin am häufigsten vorkommenden leitfähigen Stoffe, z.B. Metalle, Mineralien, Salze usw. Dadurch, dass das Wasser selbst nicht geladen ist, wird ausschließlich die Leitfähigkeit und somit die Anzahl der Ionen im Wasser gemessen.
Je niedriger der TDS-Wert, umso weniger leitfähige Stoffe befinden sich im Wasser. Nach den ersten Tests sind 100ppm ein guter Wert und 2000pm ein schlechter Wert.

## Hardware
Die Stückliste für die Wasserqualitäts-Anzeige:

1 x ESP32
1 x TDS-Sensor
1 x OLED-Display 1,3"
Kleinmaterial, Schaltdrah

## Verdrahtung
ESP32 - TDS Sensor:
GND		    GND
+5V		    +5V
GPIO27		    Signal

ESP32 - OLED Display 1,3":
GND		        GND
+5V		        +5V
SCL		        SCK	
SDA		        SDA


![Bild](pic/wa.jpg)
