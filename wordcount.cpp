#include <fcntl.h>
#include <unistd.h>
#include <cstdio>
#include <errno.h>
#include <cstdlib>
#include <dirent.h>
#include <sys/types.h>

#define BUFFERSIZE 4096

int main(int argc, char *argv[]){
  int i;
  int fd;  
  int n;
  // char buffSizeToRead[BUFFERSIZE];
  for (i = 0; i < argc; i++) {
    fd = open(argv[i], O_RDONLY);
  if(fd != -1){
    while((n = read(STDIN_FILENO, argv[i+1], BUFFERSIZE)) > 0){
      /* if(write(STDOUT_FILENO, argv[i+1], n) !=n){
	
	 }*/
      printf("%d", n); 
    }
  }else {
    perror("Error opening file");
  }  
  }
   
}
