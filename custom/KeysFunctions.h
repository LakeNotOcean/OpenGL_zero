#pragma once


// This function is called whenever a "Normal" key press is received.
void keyboardFunc(unsigned char key, int x, int y);

// This function is called whenever a "Special" key press is received.
// Right now, it's handling the arrow keys.
void specialFunc(int key, int x, int y);

void mouseFunc(int button, int state, int x, int y);
void mouseMove(int x, int y);
