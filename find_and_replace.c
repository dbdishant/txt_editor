#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "key_actions.h" // Include your existing header
#include "strive.h"      // Assuming strive.c has common global structures

extern struct editorConfig E; 



void editorReplace(int fd) {
    char find[256], replace[256];
    int qlen = 0;

    // Prompt for the string to find
    editorSetStatusMessage("Find: ");
    editorRefreshScreen();
    while (1) {
        int c = editorReadKey(fd);
        if (c == ESC) {  // Exit on Escape
            editorSetStatusMessage("");
            return;
        } else if (c == ENTER) {
            find[qlen] = '\0';
            break;
        } else if (c == BACKSPACE || c == CTRL_H) {  // Handle Backspace
            if (qlen > 0) {
                qlen--;
                find[qlen] = '\0'; }
        } else if (isprint(c)) {
            if (qlen < 255) {
                find[qlen++] = c;
                find[qlen] = '\0';
            }
        }
        editorSetStatusMessage("Find: %s", find);
        editorRefreshScreen();
    }

    // Prompt for the string to replace with
    qlen = 0;
    editorSetStatusMessage("Replace with: ");
    editorRefreshScreen();
    while (1) {
        int c = editorReadKey(fd);
        if (c == ESC) {  // Exit on Escape
            editorSetStatusMessage("");
            return;
        } else if (c == ENTER) {
            replace[qlen] = '\0';
            break;
        } else if (c == BACKSPACE || c == CTRL_H) {  // Handle Backspace
            if (qlen > 0) {
                qlen--;
                find[qlen] = '\0'; }
        } else if (isprint(c)) {
            if (qlen < 255) {
                replace[qlen++] = c;
                replace[qlen] = '\0';
            }
        }
        editorSetStatusMessage("Replace with: %s", replace);
        editorRefreshScreen();
    }

    // Perform the replacement
    int replacements = 0;
    for (int i = 0; i < E.numrows; i++) {
        char *match = strstr(E.row[i].chars, find);
        while (match) {
            int pos = match - E.row[i].chars;

            // Remove the 'find' substring
            for (int j = 0; j < strlen(find); j++) {
                editorRowDelChar(&E.row[i], pos);
            }

            // Insert the 'replace' substring
            for (int j = 0; j < strlen(replace); j++) {
                editorRowInsertChar(&E.row[i], pos + j, replace[j]);
            }

            replacements++;
            match = strstr(E.row[i].chars + pos + strlen(replace), find);
        }
    }

    editorSetStatusMessage("Replaced %d occurrences of '%s' with '%s'.", replacements, find, replace);
}


