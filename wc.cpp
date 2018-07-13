#include <iostream>
#define BUFFSIZE 4096

using namespace std; 
int main(int argc, char *argv[]){
  int i;
  char buffer [BUFFSIZE];

  while ((n = read(STDIN_FILENO, buffer, BUFFSIZE)) > 0){
    write(STDOUT_FILENO, buffer, n);
  }
  return n;
  /*  std:tstring letter = argv[1]; 
  switch(letter){
  case "-w":

    break;
  case "-l":

    break;
  case "-c":

    break;
  }
  for(i=0; i < argc; i++){
    cout << argv[i] <<endl;

  }
  int file = open(argv[2]);*/


}
