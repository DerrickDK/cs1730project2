#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstdio>
#include <errno.h>
#include <cstdlib>
#include <dirent.h>
#include <sys/types.h>
#include <cstring>
#include <string>
#define BUFFSIZE 4096
using namespace std; 

int main(int argc, char *argv[]){
  int i; 
  
  char buff[BUFFSIZE];
  for(i = 1; i < argc; i++){    
    // int fd = open(argv[i], O_RDONLY);
    if(!(strcmp(argv[i], "-"))){
      int m;
      while((m = read(STDIN_FILENO, buff, BUFFSIZE)) > 0 ) {
	if(write(STDOUT_FILENO, buff, m) != m) {
	}
      }
      break;
    }
    int fd = open(argv[i], O_RDONLY);
    if(fd != -1){
      int n;
      while((n = read(fd, buff, BUFFSIZE)) > 0){
	write(STDOUT_FILENO, buff, n);	
      }
      //break;
    }
    else{
      perror("Bro... That's an error. Fix it");
    }
  }
} 
