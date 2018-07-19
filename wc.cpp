#include <iostream>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <cctype>
#define BUFFSIZE 4096

using namespace std; 
int main(int argc, char *argv[]){
  char letter = argv[1][1];
  char **argument = argv;
  int total = 0;
  int index = 2;
  int n;
  char buff[BUFFSIZE];
  int fd; 
  bool ifWord; 
  
 
  if(argc < 3){
    while((n = read(STDIN_FILENO, buff, BUFFSIZE)) > 0 ) {
      if(write(STDOUT_FILENO, buff, n) != n) {
	cerr << "error writing" << endl;
	exit(1);
      }//if
    }//while
  }//if
  
  while(index < argc ){
    int counter = 0;
    if(strcmp(argument[index], "-") == 0){
      while((n = read(STDIN_FILENO, buff, BUFFSIZE)) > 0 ) {
	if(write(STDOUT_FILENO, buff, n) != n) {
	  cerr << "error writing" << endl;
	  exit(1);
	}//if
      }//while
    }//if 
    else{
      switch(letter){
      case 'c':
	fd = open(argument[index], O_RDONLY);
	if(fd == -1){
	  perror("No such file exist");
	  exit(1);
	}//if
	while ((n = read(fd, buff, BUFFSIZE)) > 0){
	  counter+=n;
	}//while
	printf("Number of characters in %s is: %d\n", argument[index], counter);
	break;
	
      case 'l':
	fd = open(argument[index], O_RDONLY);
	if(fd == -1){
	  perror("No such file exist");
	  exit(2);
	  
	}//if
	while((n = read(fd, buff, BUFFSIZE)) > 0){
	  for(int i = 0; i < n; i++){
	    if(buff[i] == '\n'){
	      counter++;
	    }//inner if
	  }//for
	}//if
	printf("Number of lines in %s is %d\n", argument[index], counter);
	break;
	
      case 'w': 
	fd = open(argument[index], O_RDONLY);
	if(fd == -1){
	  perror("No such file exit");
	  exit(3);
	}//if
	while((n = read(fd, buff, BUFFSIZE)) > 0){
	  for(int i =0; i < n; i++){
	    if(isspace(buff[i])){
	      ifWord = false; 
	    }//if
	    else if(!(isspace(buff[i])) && !(ifWord)){
	      ifWord = true; 
	      counter++;
	    }//else if
	    else if(!(isspace(buff[i])) && ifWord){ 
	      continue;
	    }//else if
	  }//for
	}//while
	printf("Number of words in %s is %d\n",argument[index], counter);
	break;
      default:
	{
	  perror("No such command exist");
	}
      }//switch
    }//else
    total+=counter;
    if(argc > 3){
      printf("Total is %d\n", total);
    }//if
    index++;
  }//outer while
}//main
