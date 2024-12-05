#include <ctype.h>
#include "strive.h"

extern struct editorConfig E;

// Function to count words and characters in the file
void countWordsAndCharacters(int *word_count, int *char_count) {
    *word_count = 0;
    *char_count = 0;

    // Loop through each row in the editor
    for (int i = 0; i < E.numrows; i++) {
        erow *row = &E.row[i];
        int in_word = 0;

        // Iterate through each character in the row
        for (int j = 0; j < row->size; j++) {
            (*char_count)++;  // Increment character count

            if (isspace(row->chars[j])) {
                if (in_word) {
                    (*word_count)++;
                    in_word = 0;
                }
            } else {
                in_word = 1;
            }
        }

        // Count the last word in the row if it ends without a space
        if (in_word) {
            (*word_count)++;
        }
    }
}

// Function to display word and character count in the status bar
void displayWordAndCharacterCount() {
    int word_count = 0, char_count = 0;
    countWordsAndCharacters(&word_count, &char_count);
    editorSetStatusMessage("Words: %d | Characters: %d", word_count, char_count);
}
