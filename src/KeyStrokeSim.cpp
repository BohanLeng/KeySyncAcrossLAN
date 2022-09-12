#include "KeyStrokeSim.h"


KeyStrokeSim::KeyStrokeSim()
{

}

KeyStrokeSim::~KeyStrokeSim()
{

}

void KeyStrokeSim::Press(int key) {
    // // Create an HID hardware event source
    // CGEventSourceRef src = CGEventSourceCreate(kCGEventSourceStateHIDSystemState);

    // // Create a new keyboard key press event
    // CGEventRef evt = CGEventCreateKeyboardEvent(src, (CGKeyCode) key, true);

    // // Post keyboard event and release
    // CGEventPost (kCGHIDEventTap, evt);
    // CFRelease (evt); CFRelease (src);

    // usleep(60);
}

void KeyStrokeSim::Release(int key) {
    // // Create an HID hardware event source
    // CGEventSourceRef src = CGEventSourceCreate(kCGEventSourceStateHIDSystemState);

    // // Create a new keyboard key release event
    // CGEventRef evt = CGEventCreateKeyboardEvent(src, (CGKeyCode) key, false);

    // // Post keyboard event and release
    // CGEventPost (kCGHIDEventTap, evt);
    // CFRelease (evt); CFRelease (src);

    // usleep(60);
}

void KeyStrokeSim::Click(int key) {
    this->Press(key);
    this->Release(key);
}