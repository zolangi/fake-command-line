#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE 80 // max length command
#define BUFFER_SIZE 80 //size of buffer
#define DELIMETER "\n" //delimeter

//check if command includes &.
int hasAmpersand(char in[])
{
  int index = 0;
  while(in[index] != '\n'){
    if(in[index] == '&'){
      return 1;
    }
    index++;
  }
  return 0;
}

int main(void)
{
  char *args[MAX_LINE/2+1]; // command line arguments
  int should_run = 1; // flag to determine when to exit program
  pid_t pid = 0;//create pid variable which holds process id parent

  while(should_run) {

    char *input = (char *)(malloc(MAX_LINE * sizeof(char)));// what is this??? initial input?

    printf("osh> "); //prompt
    fflush(stdout); //flushes output
    fgets(input, MAX_LINE, stdin); //gets input and length of it



    input[strlen(input) - 1] = '\0'; //what is this???
    printf("INPUT: %s\n", input);//what is this??

    //here we wouldve had had to include pid = fork() to create a child process

    //if it does have an &, then we want both child and parent to execute
    if(hasAmpersand(input)){
      //if child process, execute
      if (pid == 0) {
        printf("X\n");
        execvp(args[0], args);
        exit(0);
      }
      //if parent process, execute
      else if (pid > 0) {
        printf("Y\n");
      }
      //if parent process, but no child, execute
      else{
        printf("Z\n");
      }
    }
    //if it does not have an &, then we want the parent to wait for the child to finish executing
    else{
      //if child process, execute
      if (pid == 0) {
        printf("R\n");
        execvp(args[0], args);
        exit(0);
      }
      //if parent process, wait and then execute
      else if (pid > 0) {
        wait(NULL);
        printf("S\n");
      }
      //if parent process, but no child, execute
      else{
        printf("T\n");
      }
    }
    /*
    * After reading user input, the steps are:
    *(2) the child process will invoke execvp()
    *(3) if command included &, parent will invoke wait()
    */
  }
  return 0;
}

/* args array will be passed to the execvp() function
 * prototype:execvp(char *command, char *params[]);*/
execvp(char *command, char *params[]){

}
