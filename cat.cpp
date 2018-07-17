#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstdio>
#include <errno.h>
#include <cstdlib>
#include <dirent.h>
#include <sys/types.h>
#include <cstring>
#define BUFFSIZE 4
using namespace std; 

int main(int argc, char *argv[]){
  int i; 
  char buff[BUFFSIZE];
  char **arguments;
  arguments =argv;

  for(i = 1; i < argc; i++){
    if(strcmp(arguments[i],"-") == 0){
      int n;
      char buff[BUFFSIZE];
      while((n = read(STDIN_FILENO, buff, BUFFSIZE)) > 0 ) {
	if(write(STDOUT_FILENO, buff, n) != n) {
	  cerr << "error writing" << endl;
	  exit(1);
	}//inner if
      }//while
    }//outer if
    else{
    int fd = open(arguments[i], O_RDONLY);
    if(fd != -1){
      int n;
      while((n = read(fd, buff, BUFFSIZE)) > 0){
	write(STDOUT_FILENO, buff, n);
      }
    }else{
      perror("Error");
    }
    }//else
  }
}//main
