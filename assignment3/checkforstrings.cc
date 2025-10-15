// Copyright 2025 bhipp
#include<iostream>
using std::cout;
using std::endl;
#include<fstream>
using std::ifstream;
#include<cstring>

int main(int argc, char * argv[] ) {
  if ( argc != 2 ) {
    cout << "Must be run with the name of a file to check" << endl;
    return 2;
  }
  ifstream student(argv[1]);
  char line[1000] = "";
	char * next_token;
  int line_count = 1;
  int num_issues = 0;
  while ( student.good() ) {
    student.getline(line, 1000);
    for ( int i = 0; i < 1000 && line[i] != '\0'; ++i ) {
      if ( line[i] == '/' && line[i+1] == '/' ) {  // for single line 
                                                   // comments, wipe out
                                                   // rest of the line
        while( i < 1000 )
          line[i++] = '\0';
       }
      if ( line[i] == '"' && (i == 0 || line[i-1] != '\'') ) {  // wipe out quoted text
        do {
          line[i++] = '\0';
        } while ( i < 1000 && line[i] != '"' );
        line[i] = '\0';
      }
    } 
    next_token = strtok(line, " ;\t");
    while ( next_token != nullptr ) {
      if ( strcmp(next_token, "string") == 0 ||
           strcmp(next_token, "std::string") == 0 ) {
        ++num_issues;
        cout << "Check for possible string variable on line " 
             << line_count << endl;
      }
      next_token = strtok(NULL, " ;\t");
    }
    ++line_count;
  }
  if ( num_issues == 0 )
    cout << "automated test found no string variables\n";

  cout << "\n" << endl;
  return 0;
}
