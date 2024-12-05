**PROJECT 3**
Text Editor: Strive
----

**Contributors**
1. Dishant Bhatnagar - B01031585
2. Rahul Rana - B01038965
3. Sagar Sidhwa - B01035191
4. Saloni Wandile - B01037294

**Description**
This is a lightweight, terminal-based text editor designed to provide essential editing functionalities in a compact and efficient manner. Strive is a small text editor in less than 1K lines of code (counted with cloc).
---

**Usage** 
**`Command-Line Arguments`**
    make clean
    make
    ./strive `<filename>`
---

**Keys**:

            Ctrl+S:          Save file

            Ctrl+U:          Save As

            Ctrl+F:          Find

            Ctrl+R:          Replace

            Ctrl+W:          Word count

            Ctrl+X:          Character count

            Ctrl+Q:          Quit

            Arrow Keys:      Navigate text

            Page Up/Down:    Scroll through pages

            Home/End:        Move cursor to start/end of line
---


**`Features`**

1. File Operations

    Save (Ctrl+S): Save the current content to the file.

    Save As (Ctrl+U): Save the current content with a new filename.

    Open: Automatically loads the file provided as a command-line argument when starting the editor.

2. Text Manipulation

    Insert Text: Start typing to insert text at the cursor's position.

    Backspace/Delete: Use Backspace or Delete to remove characters.

    Insert Newline (Enter): Press Enter to insert a new line.

3. Navigation

    Arrow Keys: Navigate through the text by moving the cursor.

    Page Up/Page Down: Scroll through the text by pages.

    Home/End: Move the cursor to the beginning or end of the current line.

4. Search

    Find (Ctrl+F): Search for a specific string in the text.

    Replace (Ctrl+R): Find and replace text (if implemented).

    Navigate Matches: Use the arrow keys during search to move between matches.

5. Word and Character Count

    Word Count (Ctrl+W): Display the total number of words in the document.

    Character Count (Ctrl+X): Display the total number of characters in the document.
---