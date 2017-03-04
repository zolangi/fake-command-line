#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE 80 /* max length command */
#define BUFFER_SZ 80 //size of buffer
#define DEL "\n" //delimeter

/* arg parser*/
char **arg_pars(char *in)
{
  int bufferSZ = BUFFER_SZ, position = 0;
  char **args = malloc();
  char *arg;
}

int main(void)
{
  char *args[MAX_LINE/2+1]; /* command line arguments */
  int should_run = 1; /* flag to determine when to exit program */

  while(should_run) {
    char *input = (char *)(malloc(MAX_LINE * sizeof(char)));

    printf("osh> ");
    fflush(stdout);
    fgets(input, MAX_LINE, stdin);
    input[strlen(input) - 1] = '\0';
    printf("INPUT: %s\n", input);

    pid_t pid;/*because of creation of multiple processes on cs1, will have to do project without fork();
    /*create pid variable which holds process id*/
	
    if (pid == 0) {
      execvp(input, &input);
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
execvp(args[0], args){
  
}
