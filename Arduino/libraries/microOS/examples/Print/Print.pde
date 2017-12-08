#include <microOS.h>

void print_time(void) {
    System.print("time: "); System.println(millis());
}

void setup() {
	System.addThread(NORMAL, 250000, &print_time, false); //loop @4Hz
    System.start();
}

void loop() {
    System.run();
}
