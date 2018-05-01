# Military_Spy_Robo
Instructables to make Prototype for a Military Spy Robot


HEY EVERYONE I HAVE MADE A PROTOTYPE FOR MILITARY SPY ROBOT!

HERE ARE THE INSTRUCTIONS:

1. TRANSMITTER:

I have use TX 433 MHZ module and a joystick module for transmission, as it is easy to use and can be easily work with ardunio, I have used ardunio UNO but you can use nano also.
The code for the same I have included with the name as "transmitter.ino".
Now here are the connections:

i) The xpin of the joystick module -- A1;
ii) The yPiin of joystick module  -- A0;
iii) The button pin -- 2;
iv) data pin of Transmitter -- 12;

and Vcc and gnd are the same.


2. RECIEVER:

I have used RF 315 MHZ module on the reciever side, and the DC motors are used for the movement purpose, with the help of a H-bridge.
The code for the same has been included "reciever.ino".

Connections:

// for H-bridge to ardunio 
i) enA -- 2;
ii) in1 -- 3;
iii) in2 -- 5;
iv) enB -- 7;
v) in 3 --6;
vi) in 4 -- 9;

//Reciever module;
vii) Data pin -- 12;

And the vcc and gnd are the same.

I am also usin an android app for the movement of servo motor and the rotation of the camera.
I have incuded the "app.apk" file. You can download it and connect the connections with the bluetooth module and ardunio and contol that motor through that app.
Also for making that app I have used a MIT app Companion. I have included the "app.aia" file for the same in case you wana modify it.

Connections for the Bluetooth, Ultasonic sensor and servo:
//Bluetooth HC-05
i) Tx -- 10
ii) Rx -- 11

//Ultrasonic sensor
iii) trig -- 3;
iv) echo -- 5;

//servo
v) servo pin --9;
vcc and gnd are the same.

The code for the same is included in "BL_Read_Write.ino".

I have aslo included a video "demo" to show the working of my model.

And a video of a 3D - model I made.


THANK YOU !!
HOPE YOU LIKE IT!

If you have any Queries you can mail me @ sakshi17092@iiitd.ac.n


