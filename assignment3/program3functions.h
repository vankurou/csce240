// Copyright 2025 David Doughty
#ifndef PROGRAM3FUNCTIONS_H_
#define PROGRAM3FUNCTIONS_H_

#include "p3compares.h"

// Removes all occurrences of value from array. Remaining elements are
// moved toward the front.
void RemoveValues(int array[], int size, int value);

// Shifts the contents of array to the left by shift positions; Positive
// shift means left rotation; negative means right rotation
void ShiftArray(int array[], int size, int shift);

// Returns true if the two cstrings are anagrams, Otherwise letters are treated case
// insensitively. Only alphabetic characters and digits are considered as
// characters; other characters (including spaces and punctuation) are
// ignored when matching
bool IsAnagram(const char a[], const char b[], bool case_sensitive = false);

// Replaces single-character token1 occurrences in source with the two
// character sequence token2token3. The destination array must be large
// enough to contain the cstring.
// Returns true on success; false and leaves array unchanged if dest_size
// is not sufficient
bool Replace1With2(char array[], int dest_size, char token1, char token2,
                   char token3);

// Swaps rows and columns of a square array with kSquareSize columns
void SwapRowsAndColumns(int array[][kSquareSize]);

#endif  // PROGRAM3FUNCTIONS_H_
