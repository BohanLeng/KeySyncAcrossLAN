#include "KeyboardListener.h"

CGEventRef myCGEventCallback(CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *refcon)
{
    // Paranoid sanity check.
    // if ((type != kCGEventKeyDown) && (type != kCGEventKeyUp))
    //     return event;

    // The incoming keycode.
    CGKeyCode key = (CGKeyCode)CGEventGetIntegerValueField(event, kCGKeyboardEventKeycode);

    //Keypress code goes here.
    // KeyStrokeDetected(key);
    // printKeyCode(key);
    ((KeyboardListener *) refcon) -> KeyStrokeDetected(key);
    ((KeyboardListener *) refcon) -> StopKeyDetection();

    // We must return the event for it to be useful.
    return event;
}

KeyboardListener::KeyboardListener(CGKeyCode key_to_listen)
{
    // Create an event tap. We are interested in key presses.
    eventMask = CGEventMaskBit(kCGEventKeyUp);
    eventTap = CGEventTapCreate(kCGSessionEventTap, kCGHeadInsertEventTap, kCGEventTapOptionDefault, eventMask, myCGEventCallback, this);
    if (!eventTap) {
        fprintf(stderr, "failed to create event tap\n");
        exit(1);
    }

    // Create a run loop source.
    runLoopSource = CFMachPortCreateRunLoopSource(kCFAllocatorDefault, eventTap, 0);

    // Add to the current run loop.
    runLoopRef = CFRunLoopGetCurrent();
    CFRunLoopAddSource(runLoopRef, runLoopSource, kCFRunLoopCommonModes);

    StartKeyDetection();

}

KeyboardListener::~KeyboardListener()
{

}

void KeyboardListener::KeyStrokeDetected(CGKeyCode keycode)
{
    std::cout << "CGKeyCode= " << keycode << '\n';
}

void KeyboardListener::StartKeyDetection() {
    // Enable the event tap.
    CGEventTapEnable(eventTap, true);

    // Set it all running.
    CFRunLoopRun();
}

void KeyboardListener::StopKeyDetection() {

    CFRunLoopStop(runLoopRef);
}
