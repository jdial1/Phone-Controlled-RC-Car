# Phone-Controlled-RC-Car


Control any cheap rc car using an Arduino, a Motor Shield, and a PI Zero.


# SETUP

  -----
  Arduino
   -----
  1.Upload the sketch to your Arduino

  2.Connect GPIO pins


  Pi Zero   | Arduino Analog 
  ---|---
    8     |       0
    9      |      1
    10    |       2
    11      |      4

<img src="https://github.com/jdial1/Phone-Controlled-RC-Car/blob/master/Pi-Zero-GPIO-PINOUT.PNG" Width=10%></img>

-----
 Pi Zero
 -----
 
  1.Configure static IP address on Pi Zero
  ```bash
  ifconfig wlan0 down
  ifconfig wlan0 192.168.1.25
  ifconfig wlan0 up
  ```
  
  
  2.Set python script to start on boot
  
  ```bash
  sudo crontab -e
  @reboot python /home/pi/downloads/server.py &
  ```

 -----
  Phone
  -----
  1.Start Hotspot on phone

  2.Connect Pi Zero to hotspot and set to autoconnect

  3.Turn off phone hotspot

  4.Install NetIO <a href="https://play.google.com/store/apps/details?id=com.luvago.netio&hl=en">LINK</a>

  5.Import controls to NetIO



# USAGE
------------------------
  1.Start Hotspot on phone and wait for Pi Zero to connect

  2.Use netIO to control car
