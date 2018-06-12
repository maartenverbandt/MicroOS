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

### 3.3. Parameters: persistent variables

Parameters are persistent variables which allow the user to configure a piece of code for a particular robot. For example, you have some code that interfaces a wheel encoder. Suppose you are interested in the travelled distance in meters, then you just have to multiply the number of encoder ticks with a _hardware_specific_ scalar. Suppose you want to use the same code on a different platform, then it pays of to make the scalar a parameter making the code configurable and adjustable without reflashing the microcontroller.

Parameters can be 32-bit integers or 32-bit floats and all have a string identifier allowing the user to distinguish between them. A two-step approach is required to use a parameter. First, the parameter is defined:
```
Parami *pi = System.intStorage()->add("var_i"); //adds an integer parameter
Paramf *pf = System.floatStorage()->add("var_f"); //adds a float parameter
```
Once a parameter is declared, reading its value can be done in various ways. The easiest is probably using the identifier:
```
int value;
System.intStorage()->value("var_i",value); //writes the value of "var_i" to the local variable value
```
Though transparent and simple, it is not the most efficient way because the program is forced to do a search for the parameter. If its value is needed frequently, it is better to store a pointer to the parameter so that it is readily accessible. This is done via:
```
Paramf *pf2;
System.floatStorage()->get("var_f", pf2);
float value = pf2->value();
```
To set a variable, one uses the `setValue()` function of a variable or the storage:
```
pf2->setValue(1.7);
System.intStorage()->setValue("var_i",2);
```
Once again, calling the parameter directly is more efficient because the search within the different parameters is avoided.
Once a variable is set, it is not yet saved to the EEPROM. This allows the user to experiment without forgetting the initial configuration and extends the EEPROMs lifetime as it has a limit amount of write cycles. If you want to store the new parameter value, making it persistent, one needs to call:
```
pf2->store();
System.intStorage()->storeValue("var_i");
```
If you want to store all values at once, you can simply call:
```
System.intStorage()->store();
```
However, usually you will not need to call the `store()` function in any way because this is usually a command given by the operator of the system. Typically, the user will use [QRoboticsCenter](https://github.com/maartenverbandt/QRoboticsCenter) to change the value of the parameters and once satisfied, sends the `store` command to the system, which is handled internally by MicroOS. 

## 4. Interesting links

* [MECO-CSI](https://github.com/maartenverbandt/MECO-CSI)
A toolchain to easily interface embedded hardware with a pc
* [QRoboticsCenter](https://github.com/maartenverbandt/QRoboticsCenter)
Application to interface a microOS project directly.


