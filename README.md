# DONKEY.ZACH
Hack-A-Week 3: Racing game inspired by Bill Gate's and Neil Konzen's 
legendary game DONKEY.BAS. I also tweaked up the gameplay to make it a bit more
engaging.

### Usage:
- Executable file is named 'donkey.zach' by default (see makefile)
- To run, execute it as follows from the donkey.zach directory:

`./donkey.zach`

### Features:
- Captivating storyline
- Realistic graphics
- Movement in two whole dimensions rather than back and forth
- Works with both qwerty and dvorak-style keyboards

### What it does:
- Uses the ncurses library to render ASCII-based text art
- Checks for collisions between the donkeys and the racecar
- Changes gameplay based on the size of your terminal window
- Makes sure you can't drive your car off the edge of the screen

### What it doesn't do:
- Render ASCII art in color
- Adapt if you change screen dimensions mid-game

### Reasons for not doing things:
- I kinda like the current style. 
- The work/reward ratio does not seem worth it for such a short-term project

### Example Gameplay:

### Opening Screen:

![alt text][outputimage]
[outputimage]: https://github.com/ztaira14/bleep/blob/master/diagrams/openingscreen.png "Opening Screen"

### Gameplay:

![alt text][outputimage2]
[outputimage2]: https://github.com/ztaira14/bleep/blob/master/diagrams/gameplay.png "Gameplay"

### Closing Screen:

![alt text][outputimage3]
[outputimage3]: https://github.com/ztaira14/bleep/blob/master/diagrams/closingscreen.png "Closing Screen"
