# MicroOS

An operating system for Arduino

## 1. Should I be interested?

Are you doing some serious embedded programming? Are you using arduino and looking for a nice way of streamlining development? Are you looking for a way of interfacing your larest project? Keep on reading because this might be the thing you have been looking for all along.

## 2. What is it?

MicroOS is an arduino library which acts as a sort of operating system for your Arduino or arduino compatible device such as a teensy microcontroller. Operating system might be an exaggeration if you compare the library to ChibiOS or ArduinOS. MicroOS is a very simple implementation to run multiple tasks at a fixed rate. However, the tasks don't have burst times, or their own stack which is however fine for most applications.

MicroOS has two main goals:
1. make multitasking easy (cfr. `System.addThread()`)
2. speed up embedded development (cfr. `System.setGPoutInt()`)

## 3. Getting started

To get started, download the library and paste the folder Arduino/libraries/microOS in your arduino/libraries folder. Then (re)start your arduino IDE. If all went well, the library should be in the list of available libraries and examples should be visible.

### 3.1. Blinky

The blinky example is shows the operating system in action. Once uploaded, the OS is running on your arduino. Nothing really useful is happening: there are only background processes. If all went well, the led is blinking. This shows you the OS is still running and no errors have occurred. If you open the serial terminal, you should see a bunch of characters rolling over the screen. These are serial messages intended for the [QRoboticsCenter](https://github.com/maartenverbandt/QRoboticsCenter) application. You might have a look there.

### 3.2. Multitasking

The multitasking example shows a simple example of what you can do with the library. Three tasks have been defined:
* countingTask(void)
* sensorTask(void)
* readIncrement(void)
These are added to the OS' task list by means of the function `addThread`:
```C++
System.addThread(NORMAL, 20000, &sensorTask, false); //read sensor@50Hz
System.addThread(BELOWNORMAL, 100000, &readIncrement, false); //read command@10Hz
System.addThread(LOWEST, 1000000, &countingTask, false); //update counter@1Hz
```
`addThread`'s first argument is the priority, which can be `HIGHEST`, `ABOVENORMAL`, `NORMAL`, `BELOWNORMAL` or `LOWEST`. Second is the repetition period in microseconds. So the first task is to run 50 times per second, which comes down to 1000000us/50=20000us period. As a third argument, the function which is to be run is passed. Last, we give an argument to start the task immediately or not. Best practice is to not start the task when it is added to the list, but start them all together by means of `System.start()`.

This example also shows how to send data to the pc by means of `System.setGPoutInt(int channel, int value)` and `System.setGPoutFloat(int channel, float value)`. These will appear on the pc side and can be read using the [QRoboticsCenter](https://github.com/maartenverbandt/QRoboticsCenter) application. Data coming from the pc can be read by calling the functions `System.getGPinInt(int channel)` and `System.getGPinFloat(int channel)`. Each time, there are 4 integer channels (0-3) and 8 floating point channels (0-7).

## 4. Interesting links

* [MECO-CSI](https://github.com/maartenverbandt/MECO-CSI)
A toolchain to easily interface embedded hardware with a pc
* [QRoboticsCenter](https://github.com/maartenverbandt/QRoboticsCenter)
Application to interface a microOS project directly.


