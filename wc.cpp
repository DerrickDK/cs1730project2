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

  if(argument && (argc < 3)){
    int n;
    char buff[BUFFSIZE];
    while((n = read(STDIN_FILENO, buff, BUFFSIZE)) > 0 ) {
      if(write(STDOUT_FILENO, buff, n) != n) {
	cerr << "error writing" << endl;
	exit(1);
      }
    }
  }//if

  while(index < argc ){
    int counter = 0;
    switch(letter){
    case 'c':
      {
	int fd, n;
	char buff[BUFFSIZE];
	fd = open(argument[index], O_RDONLY);
	if(fd == -1){
	  perror("No such file exist");
	  exit(1);
	}
	while ((n = read(fd, buff, BUFFSIZE)) > 0){
	  counter+=n;
	}
	printf("Number of characters in %s is: %d\n", argument[index], counter);
	break;
      }
    case 'l':
      {
	int fd, n; 
	char buff[BUFFSIZE];
	fd = open(argument[index], O_RDONLY);
	if(fd == -1){
	  perror("No such file exist");
	  exit(2);

	}
	while((n = read(fd, buff, BUFFSIZE)) > 0){
	  cout << n << endl;
	  for(int i = 0; i < n; i++){
	    if(buff[i] == '\n'){
	      counter++;
	    }
	  }
	}
	printf("Number of lines in %s is %d\n", argument[index], counter);
	break;
      }
  case 'w'://a word is a sequence of NON- white spaces
    {      
      int fd, n; 
      char buff[BUFFSIZE];
      bool ifWord = false; 
      fd = open(argument[index], O_RDONLY);
      if(fd == -1){
	perror("No such file exit");
	exit(3);
      }
      while((n = read(fd, buff, BUFFSIZE)) > 0){
	for(int i =0; i < n; i++){
	  if(isspace(buff[i])){
	     ifWord = false; 
	  }
	  else if(!(isspace(buff[i])) && !(ifWord)){
	    ifWord = true; 
	    counter++;
	  }
	  else if(!(isspace(buff[i])) && ifWord){ 
	    continue;
	  }
	}//for
      }//while
      printf("Number of words in %s is %d\n",argument[index], counter);
      break;
    }
  default:
    {
      perror("No such command exist");
    }
  }//switch
  total+=counter;
  if(argc > 3){
    printf("Total is %d\n", total);
  }
  index++;
  }//outer while
}//main
