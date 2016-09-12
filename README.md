# Phone-Controlled-RC-Car


This is a project to control any cheap rc car using an Arduino, a Motor Shield, and a PI Zero.


SETUP

1.Upload the sketch to your arduino

2.Connect GPIO pins
<img src="https://github.com/jdial1/Phone-Controlled-RC-Car/blob/master/PI-Zero-GPIO-PINOUT.PNG"></img>|<img src="http://artofcircuits.com/wp-content/uploads/2014/03/L293D-motor-shield-2.jpg"></img>

  Pi Zero   | Arduino Analog
  ---|---
    8     |       0
    9      |      1
    10    |       2
    11      |      4
                
3.Run the python script on your Pi Zero

4.Configure static IP address on Pi Zero

5.Start Hotspot on phone

6.Connect to hotspot with Pi Zero

7.Install NetIO <a href="https://play.google.com/store/apps/details?id=com.luvago.netio&hl=en">LINK</a>
