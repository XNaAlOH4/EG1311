NUS EG1311

Group 4

Straight out the gate, I will abandon the Template code and Wiring they provided due to inefficient wiring and programming.

First Reduce the number of wires: Done.
Then use the Batteries to directly power the IC: to be complete
Next, rewire the motors so that 1 end is at 1 output while the other is at another.
This allows us to reverse the direction by simply swapping states of 2 pins

Now for the code, Get rid of Serial, we don't need to communicate with the computer.
Don't delay as we only have 30 seconds.

In theory we should detect a small distance 3 time thorughout the forward course, 1 When we reach the slope, 2 when we dismount the slope, lastly is at the wall.

Using a counter, keep track of the number of times, we see an object directly infront, once it reaches 3, reverse.

Note:
Pin 5 Green MOTOR1
Pin 6 Blue  MOTOR2

Pin 12 Purple ECHO
Pin 13 Green  TRIG

Both Motors Wiring(Wheel face up)
L: White, R: Brown

We need to swap 1 of them due to rotation flipping when direction flip
# Swapping has been completed

Left Wheel(Cat ears point away from user)
Motor (L:White, R:Brown)

Right Wheel
Motor (L:Brown, R:White)

Wire up MOTOR1 to 1A and MOTOR2 to 2A
# Done

Now wire White of motor to 2Y 

Things to go over with grp mates:
1. Orange wire is to connect to battery for higher PWR output
2. Use rubber band for launch? Servo to tension + release?
3. 
