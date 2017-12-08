#include "forward_list.h"

void setup() {
    Serial.begin(9600);
    Serial.println("Starting list test");

    // Create list
    forward_list<int> l;
    l.push_front(10);
    l.push_front(20);
    
    if(l.size() != 2) {
        Serial.print("Error: list size should be 2 but is: "); Serial.println(l.size());
    }
    
    l.push_front(30);
    if(l.size() != 3) {
        Serial.print("Error: list size should be 3 but is: "); Serial.println(l.size());
    }

    // iterate list
    forward_iterator<int> i = l.begin();
    Serial.println("The expected print is: 30;20;10;");
    while(i.has_next()) {
        Serial.print(i.next()); Serial.print(";");
    }
    Serial.println("");

    // done
    Serial.println("Testing done");
}

void loop() {


}
