#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "key_actions.h" // Include your existing header
#include "strive.h"      // Assuming strive.c has common global structures

extern struct editorConfig E; // Use the global editor configuration

void editorSaveAs(void)
{
    char new_filename[256];

    editorSetStatusMessage("Save As: Enter new filename (ESC to cancel):");
    editorRefreshScreen();

    int i = 0;
    while (1)
    {
        int c = editorReadKey(STDIN_FILENO);

        if (c == ESC)
        {
            editorSetStatusMessage("Save As cancelled.");
            return;
        }
        else if (c == ENTER)
        {
            if (i == 0)
            {
                editorSetStatusMessage("Filename cannot be empty!");
                return;
            }
            new_filename[i] = '\0';
            break;
        }
        else if (isprint(c))
        {
            if (i < sizeof(new_filename) - 1)
            {
                new_filename[i++] = c;
                new_filename[i] = '\0';
                editorSetStatusMessage("Save As: %s", new_filename);
            }
        }
        else if (c == BACKSPACE || c == CTRL_H)
        {
            if (i > 0)
                new_filename[--i] = '\0';
            editorSetStatusMessage("Save As: %s", new_filename);
        }
        editorRefreshScreen();
    }

    // Update filename and save
    free(E.filename);
    E.filename = malloc(strlen(new_filename) + 1);
    if (E.filename)
    {
        strcpy(E.filename, new_filename);
    }
    editorSave();
}
