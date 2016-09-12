# Phone-Controlled-RC-Car


This is a project to control any cheap rc car using an Arduino, a Motor Shield, and a PI Zero.

<img src="https://github.com/jdial1/Phone-Controlled-RC-Car/blob/master/PI-Zero-GPIO-PINOUT.PNG"></img>

  Pi Zero   | Arduino Analog
  ---|---
    8     |       0
    9      |      1
    10    |       2
    11      |      4
    
    
# SETUP
------------------



  ## Arduino
  ------
  1.Upload the sketch to your Arduino

  2.Connect GPIO pins



  ## Pi Zero
  ------
  1.Run the python script on your Pi Zero

  2.Configure static IP address on Pi Zero


 
  ## Phone
  -------
  1.Start Hotspot on phone

  2.Connect to hotspot and set to autoconnect

  3.Turn off phone hotspot

  4.Install NetIO <a href="https://play.google.com/store/apps/details?id=com.luvago.netio&hl=en">LINK</a>

  5.Import controls to NetIO



# USAGE
------------------------
  1.Start Hotspot on phone and wait for Pi Zero to connect

  2.Use netIO to control car
