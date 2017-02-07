# Nextion-GUI-Development for Monitoring Heart Rate
This project involves Arduino, signal processing circuit for detecting heart beat and HMI files on GUI development for NEXTION Touchscreen.Brief footage of the system can be seen through "InShot_20170124_183337.mp4" video file.

The code to measure and detect the heart beat is used from PulseSensor open source codes " https://github.com/WorldFamousElectronics/PulseSensor_Amped_Arduino "and modified by me to use with Nextion 2.4" TFT screen.

Therefore you can use Pulse Sensor instead of designing a signal processing circuit for detecting a hert beat. There will be no necessity for coding modification for Pulse Sensor usage. Just connect data output of the sensor to Analog Input A0 on the arduino board. And you can use Arduino Uno for this project by simply loading the code for Arduino/Genuino Uno.

TroubleShooting:
  There are conflicts when the nextion function is running within interrupt function, return recvRetCommandFinished();, command that is within the library file takes the code unintentionally into the infinite loop. If you do not want to bother modifying the library provided by Itead, you can download my modified version that is perfectly fit for this project. 
IMPORTANT ! If you are using the modified version of the nextion library, you might have a problem using the library for other projects. I kindly remind you to use the modified library for this project ONLY. 
  
