// Copyright 2025 David Doughty
#include "program3functions.h"
#include <iostream>

// RemoveValues implementation
void RemoveValues(int array[], int size, int value) {
  int write = 0;
  for ( int read = 0; read < size; ++read ) {
    if ( array[read] != value ) {
      array[write++] = array[read];
    }
  }
  for ( int i = write; i < size; ++i ) {
    array[i] = -999;
  }
}

// ShiftArray implementation
void ShiftArray(int array[], int size, int shift) {
  if ( size <= 0 ) {
    return;
  }
  int s = shift % size;
  if ( s < 0 ) {
    s += size;
  }
  if ( s == 0 ) {
    return;
  }
  int* temp = new int[size];
  for ( int i = 0; i < size; ++i ) {
    temp[i] = array[(i + s) % size];
  }
  for ( int i = 0; i < size; ++i ) {
    array[i] = temp[i];
  }
  delete [] temp;
}

namespace {

// Helper to determine if character is alphabetic or digit
bool IsAlnumChar(char c) {
  return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ||
         (c >= 'a' && c <= 'z');
}

}

// IsAnagram implementation
bool IsAnagram(const char a[], const char b[], bool case_sensitive) {
  // Count frequency of characters using a 256-sized bucket to be safe
  int count_a[256] = {0};
  int count_b[256] = {0};

  int i = 0;
  while ( a[i] != '\0' ) {
    char c = a[i];
    if ( IsAlnumChar(c) ) {
      if ( !case_sensitive && c >= 'A' && c <= 'Z' ) {
        c = c - 'A' + 'a';
      }
      ++count_a[static_cast<unsigned char>(c)];
    }
    ++i;
  }

  i = 0;
  while ( b[i] != '\0' ) {
    char c = b[i];
    if ( IsAlnumChar(c) ) {
      if ( !case_sensitive && c >= 'A' && c <= 'Z' ) {
        c = c - 'A' + 'a';
      }
      ++count_b[static_cast<unsigned char>(c)];
    }
    ++i;
  }

  for ( int j = 0; j < 256; ++j ) {
    if ( count_a[j] != count_b[j] ) {
      return false;
    }
  }
  return true;
}

// Replace1With2 implementation
bool Replace1With2(char array[], int dest_size, char token1, char token2,
                   char token3) {
  // compute length of source string
  int len = 0;
  while ( array[len] != '\0' ) {
    ++len;
  }

  // count occurrences of token1
  int count = 0;
  for ( int i = 0; i < len; ++i ) {
    if ( array[i] == token1 ) {
      ++count;
    }
  }

  int new_len = len + count;  // each occurrence expands by 1
  if ( new_len + 1 > dest_size ) {
    return false;
  }

  // perform replacement from end to avoid overwriting
  int read = len - 1;
  int write = new_len - 1;
  array[new_len] = '\0';
  while ( read >= 0 ) {
    if ( array[read] == token1 ) {
      array[write--] = token3;
      array[write--] = token2;
    } else {
      array[write--] = array[read];
    }
    --read;
  }
  return true;
}

// SwapRowsAndColumns implementation
void SwapRowsAndColumns(int array[][kSquareSize]) {
  for ( int i = 0; i < kSquareSize; ++i ) {
    for ( int j = i + 1; j < kSquareSize; ++j ) {
      int tmp = array[i][j];
      array[i][j] = array[j][i];
      array[j][i] = tmp;
    }
  }
}
