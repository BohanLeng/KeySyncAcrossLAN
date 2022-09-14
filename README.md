# KeySyncAcrossLAN

A CLI tool to sync keyboard strokes using TCP/IP in a LAN.

For example, during my band's rehearsal, our drummer starts a song by pressing space in his Logic Pro. I want this keystroke synced to other members' MacBooks, starting the auto-scrolling of the music charts in the MuseScore app.

## First usable version

The feature described is now supported from one server to one client. 

- The project can be compiled by `$ cd` to the project folder, and then
  1. `$ mkdir build`
  2. `$ cd build`
  3. `$ cmake ..`
  4. `$ make `

- To test the project on a Mac, `$ cd` to the "./bin", and
  1. `$ ./KeySync -s 9190`
  2. Create another terminal window. Then execute `$ ./KeySync -c 127.0.0.1 9190`
  3. Press any key in any process, only **R** will be synced, causing another **SPACE**, in current settings.



*Developed by Leyland Leng*
