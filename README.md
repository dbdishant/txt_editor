strive
===

strive is a small text editor in less than 1K lines of code (counted with cloc).

Usage: 

    gcc -o strive strive.c
    ./strive `<filename>`

Keys:

    CTRL-S: Save
    CTRL-Q: Quit
    CTRL-F: Find string in file (ESC to exit search, arrows to navigate)

strive does not depend on any library (not even curses). It uses fairly standard
VT100 (and similar terminals) escape sequences. 

strive is normal file editor.
dishant beta.