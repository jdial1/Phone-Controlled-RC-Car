# Phone Controlled Car


Control any cheap rc car using an Arduino, a Motor Shield, and a PI Zero.
# REQUIREMENTS

*Raspberry Pi Zero

*Wifi Dongle

*Arduino

*Arduino Motor Shield

*Android Phone

*Cheap RC Car

# SETUP


Pi Zero
-----
  1. Install Raspian through NOOBS-> <a href="https://www.raspberrypi.org/downloads/noobs/">LINK</a>

  2. Download python script and set to start on boot -> <a href="https://github.com/jdial1/Phone-Controlled-RC-Car/blob/master/Ras%20Pi%20Zero/Python%20server%20script">LINK</a>
  
    ```bash
    sudo crontab -e
    @reboot python /home/pi/downloads/server.py &
    ```
    
  3. Configure static IP address on Pi Zero
  
    ```bash
    ifconfig wlan0 down
    ifconfig wlan0 192.168.1.25
    ifconfig wlan0 up
    ```


Arduino
-----
  1. Upload the sketch to your Arduino -> <a href="https://github.com/jdial1/Phone-Controlled-RC-Car/blob/master/Arduino/Arduino%20RC%20Car%20Sketch">LINK</a>

  2. Connect Back motor to M4 and front motor to M1

  3. Connect GPIO pins

<img src="https://github.com/jdial1/Phone-Controlled-RC-Car/blob/master/images/Pi-Zero-GPIO-PINOUT.PNG" Width=10%></img><img src="https://github.com/jdial1/Phone-Controlled-RC-Car/blob/master/images/Pi-table.PNG" Width=30%></img>




Phone
-----
  1. Start Hotspot on phone

  2. Connect Pi Zero to hotspot and set to autoconnect

  3. Turn off phone hotspot

  4. Install NetIO -><a href="https://play.google.com/store/apps/details?id=com.luvago.netio&hl=en">LINK</a>

  5. Import controls to NetIO -> <a href=" http://netio.davideickhoff.de/editor#">LINK</a>



# USAGE

  1. Start Hotspot on phone and wait for Pi Zero to connect

  2. Use netIO to control car
