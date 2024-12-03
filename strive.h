#ifndef STRIVE_H
#define STRIVE_H

#include <time.h>

// Shared structures
typedef struct erow {
    int idx;            /* Row index in the file, zero-based. */
    int size;           /* Size of the row, excluding the null term. */
    int rsize;          /* Size of the rendered row. */
    char *chars;        /* Row content. */
    char *render;       /* Row content "rendered" for screen (for TABs). */
    unsigned char *hl;  /* Syntax highlight type for each character in render.*/
    int hl_oc;          /* Row had open comment at end in last syntax highlight check. */
} erow;

struct editorConfig {
    int cx, cy;             /* Cursor x and y position in characters */
    int rowoff;             /* Offset of row displayed. */
    int coloff;             /* Offset of column displayed. */
    int screenrows;         /* Number of rows that we can show */
    int screencols;         /* Number of cols that we can show */
    int numrows;            /* Number of rows */
    int rawmode;            /* Is terminal raw mode enabled? */
    erow *row;              /* Rows */
    int dirty;              /* File modified but not saved. */
    char *filename;         /* Currently open filename */
    char statusmsg[80];     /* Status message */
    time_t statusmsg_time;  /* Time of status message */
};

extern struct editorConfig E;  // Global editor configuration

// Function declarations
void editorSetStatusMessage(const char *fmt, ...);
int editorSave(void);

#endif /* STRIVE_H */
