This is a fork of Mirko Pavleski's simple capacitance sensor. 
The key difference is here we are using a standard 16x2 LCD 
screen, with an I2C interface for the screen. The orininal 
ST7565 screen though nice is not something I have on hand.

Differences from Original Code:

Simplified Measurement Handling:<br>
 The Cyfry function in the original code handled the conversion and formatting of the capacitance value. The new code does this directly within the loop function.

Direct Display:<br>
        The new code displays the measurement directly on the LCD without intermediate processing, reducing complexity.

Range Handling:<br>
        The new code uses simpler range checks (if statements) to determine the units (pF, nF, uF) and display them accordingly.

Improved Readability:<br>
        The new code is more readable and easier to follow as it combines measurement, processing, and display in a straightforward manner.

<br>
This code should work effectively for measuring capacitance and displaying the result on an LCD screen. It also includes handling for cases where no connection is detected, providing clear feedback on the LCD.
<br>

OG Project link:
https://www.hackster.io/mircemk/how-to-make-simplest-possible-autorange-capacitance-meter-ea7f00

Capacitance library is available in the library manager, or online here:
https://github.com/codewrite/arduino-capacitor

The LCD backpack:
https://www.adafruit.com/product/292

Hey, this code is totaly different!
yeah, well once I figured out exactly what the OG code was doing, I decided I didnt want to do it the same way.
Quite arguably, it is more jank. But it occupies less memory and program space. There is absolutely room for improovement here. 
like a single line clear function comes to mind.
