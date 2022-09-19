#include "KeyboardListener.h"

CGEventRef myCGEventCallback(CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *refcon)
{
    // Paranoid sanity check.
    // if ((type != kCGEventKeyDown) && (type != kCGEventKeyUp))
    //     return event;

    // The incoming keycode.
    CGKeyCode key = (CGKeyCode)CGEventGetIntegerValueField(event, kCGKeyboardEventKeycode);

    KeyboardListener *listener = (KeyboardListener *)refcon;

    //Keypress code goes here.

    CGKeyCode *keys = listener->GetListeningKeys();
    for (int i = 0; i < sizeof(keys); i++)
        if (key == keys[i])
        {
            listener->KeyStrokeDetected(key);
            // listener -> StopKeyDetection();
            break;
        }

    // We must return the event for it to be useful.
    return event;
}

KeyboardListener::KeyboardListener(SocketApp *socketAppRef, CGKeyCode *keys_to_listen) : m_app(socketAppRef), keys_listening(keys_to_listen)
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

}

KeyboardListener::~KeyboardListener()
{

}

CGKeyCode* KeyboardListener::GetListeningKeys()
{
    return keys_listening;
}

void KeyboardListener::KeyStrokeDetected(CGKeyCode keycode)
{
    std::cout << "CGKeyCode = " << keycode << '\n';
    m_app->TriggerAction();
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


