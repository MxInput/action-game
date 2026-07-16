# Action Game Build Journal

## Jul 15, 2026, 6:58 PM

So far I've added an LCD that will display the action the player needs to do as well as a microphone, joystick, and button that will act as input. I also added a buzzer that will sound off when the player does the correct thing. Then I'll attempt to include a LED that will also blink but I think I made some mistake with wiring it that I'll try to resolve.

---

## Jul 15, 2026, 9:21 PM

I fixed the wiring with the LED by removing the wiring that I had between it and the power and instead just using one between it and the digital output. Now I'm trying to figure out why the button keeps printing 0 regardless of whether I'm clicking it or not.

---

## Jul 15, 2026, 9:44 PM

I got the microphone to detect inputs and am working on making the buzzer produce sound. However, I'm still stuck on what I'm doing wrong that makes the button not activate.

---

## Jul 15, 2026, 9:59 PM

I've been trying to get the input to work for the joystick but so far it is printing 0 regardless of when I change the position of the stick. I'm not sure why but I think it's probably a issue with how I wired it.

---

## Jul 15, 2026, 10:29 PM

I got the LCD working so it now displays what I wrote as a test. I'm still confused though on what I'm doing wrong in regards to the button and joystick and will focus on that so I can then start working on the game part of this project.

---

## Jul 15, 2026, 11:41 PM

I finally got the button to work after I took it off of the breadboard I have no idea why it wasn't working before but I'm happy it's at least working now. I still haven't gotten the joystick to work and am worried it could just be broken.

---

## Jul 15, 2026, 11:58 PM

I've started working on the actual game part of my project which generates random actions for the user to do and they do it before telling them they've completed the game. I think there is an issue with randomizing the actions though as it appears to give me the same on each time so far.

---

## Jul 16, 2026, 12:13 AM

I've gotten closer to finishing the game as now the inputs are being recognized and triggering their respective states. However, I'm still having the randomization issue that I can't be sure if it's a program error or something I'm doing wrong since at one point it seemed to fixed but now it still seems to be happening.

---

## Jul 16, 2026, 12:45 AM

I fixed the randomization issue. I think it had to do with my inputs being registered to quick so the action didn't have enough time to be displayed. Now I'm working on making additional output to better the game like the led flashing and buzzer making sound.

---

## Jul 16, 2026, 1:03 AM

The game is essentially finished I think since it takes the player inputs and gives them a response based on it. It additionally has multiple outputs like the buzzer and led which activate when the player does an action before time is up.