/***********************************************************************
 * Program:
 *    Lab 03, Shell Lab
 *    Brother Ball, CS 345
 * Author:
 *    Lance Bunch
 * Summary:
 *    This simulates a shell program. Implements a history feature, a replay
 *    from history feature, and overwrites the SIGQUIT signal to display
 *    the history.
 ************************************************************************/

#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <sstream>
using namespace std;

// Used for piping later on
#define READ_END 0
#define WRITE_END 1

#define MAX_LINE 80 /* 80 chars per line, per command, should be enough. */
/* The size of the history buffer */
#define HIST_SIZE 10
/* Maximum number of commands until count rolls over. */
#define MAX_NUM_CMDS 1000
// A global array of strings and a count of the number of valid strings in it.
string commands[HIST_SIZE];
int goodStringCount = 0;
char inputBuffer[MAX_LINE]; /* buffer to hold the command entered */

/*************************************************************************
* Display the contents of the history buffer of commands with the number
* of the command listed on the beginning of the line.
**************************************************************************/
void displayHistory()
{
   cout << endl;
   int start;

   if (goodStringCount > HIST_SIZE)
      start = goodStringCount - HIST_SIZE;
   else
      start = 0;

   for (int i = start; i < goodStringCount; ++i)
   {
      std::cout << " " << std::setw(3) << i << "  " << commands[i % HIST_SIZE] << std::endl;
   }

   return;
}

/*************************************************************************
* add2History() adds a command to the history buffer and increments the
* number of commands that have been entered up to a maximum count.  If the
* history buffer is full, the oldest command is overwritten.    
**************************************************************************/
void add2History(string input)
{
   commands[goodStringCount % HIST_SIZE] = input;
   goodStringCount++;

   // Roll over the count if it hits the maximum allowed for printing
   if (goodStringCount >= MAX_NUM_CMDS)
      goodStringCount = HIST_SIZE; /* Leave a full buffer of commands */
}

/*************************************************************************
* findCommandInHistory() searches backward for the first command that
* begins with a particular character (char c) in the history buffer.
* If a string is found that begins with the character, the string is
* passed back to the calling function.  If the character being looked
* for is a NULL then the most recent command is returned.  In both of
* the preceeding cases, the return value is set to true.  If no matching
* string is found, the return value is set to false.
**************************************************************************/
bool findCommandInHistory(char c, string &stringFound)
{
   int temp = goodStringCount;
   stringFound = "";

   // If the character being looked for is a null, then return the most
   // recent command, if there was one.
   if (c == '\0')
   {
      if (goodStringCount)
      {
         stringFound = commands[(goodStringCount - 1) % HIST_SIZE];
         return true;
      }
      else
      {
         return false;
      }
   }

   // Look back through the history for a command staring with the letter
   // given in the first argument to this function.
   for (temp; temp >= 0 && temp != temp - HIST_SIZE; --temp)
   {
      if (commands[temp % HIST_SIZE][0] == c)
      {
         stringFound = commands[temp % HIST_SIZE];
         return true;
      }
   }

   return false;
}

/***************************************************************************
 * SETUP
 * setup() reads in the next command line, separating it into distinct tokens
 * using whitespace as delimiters.
 *
 * setup() modifies the inputBuffer creating a set of null-terminated strings
 * and places pointers into the args[] array that point to the beginning of
 * each argument.  A NULL pointer is placed in the args[] array indicating
 * the end of the argument list.  This is what is needed for using execvp().
 *
 * A ^d input at the beginning of a line, by a user, exits the shell.
 **************************************************************************/
void setup(char inputBuffer[], char *args[], int *background)
{

   int length; // # of characters in the command line
   int i;      // loop index for accessing inputBuffer array
   int start;  // index where beginning of next command parameter is
   int ct;     // index of where to place the next parameter into args[]

   ct = 0;

   /* read what the user enters on the command line */
   length = read(STDIN_FILENO, inputBuffer, MAX_LINE);

   start = -1; /* Used as a flag to indicate that we are looking
                           * for the start of the command or an argument if
                           * it is a -1, or stores the starting position of
                           * the command or argument to be put in args[].
                           */
   if (length == 0)
      exit(0); /* ^d was entered, end of user command stream */
   // if (length < 0)
   // {
   //    perror("error reading the command");
   //    exit(-1); /* terminate with error code of -1 */
   // }
   else if (inputBuffer[0] == 'r' &&
            (inputBuffer[1] == '\0' || inputBuffer[1] == ' '))
   {
      bool goodCmd;
      std::string tmpString;
      // If an 'r' command was given and a matching command is found in the
      // history, then put the command to be repeated in the buffer.
      // If an 'r' was given with no argument the most recent command
      // should be executed.  This is indicated with a null.
      if (inputBuffer[1] == '\0')
         inputBuffer[2] = '\0';

      goodCmd = findCommandInHistory(inputBuffer[2], tmpString);

      if (goodCmd)
      {
         tmpString += '\n';
         strncpy(inputBuffer, tmpString.c_str(), MAX_LINE);
      }
      else
      {
         std::cout << "Command not found\n";
         std::cout.flush();
      }
   }

   /* examine every character in the inputBuffer */
   for (i = 0; i < length; i++)
   {
      switch (inputBuffer[i])
      {
      case ' ':
      case '\t':          /* argument separators */
         if (start != -1) /* found the end of the command or arg */
         {
            args[ct] = &inputBuffer[start]; /* set up pointer in args[] */
            ct++;
         }
         inputBuffer[i] = '\0'; /* add a null char; make a C string */
         start = -1;
         break;

      case '\n':          /* should be the final char examined */
         if (start != -1) /* if in the command or an argument */
         {
            args[ct] = &inputBuffer[start]; /* set up pointer in args[] */
            ct++;
         }
         inputBuffer[i] = '\0';
         add2History((string)inputBuffer);
         args[ct] = NULL; /* no more arguments to this command */
         break;

      default: /* some other character */
         if (start == -1 && inputBuffer[i] != '&')
            start = i; /* starting position of the command or arg */
         if (inputBuffer[i] == '&')
         {
            *background = 1;
            inputBuffer[i] = '\0';
         }
      }             /* end of switch */
   }                /* end of for loop looking at every character */
   args[ct] = NULL; /* just in case the input line was > 80 */
}

/****************************************************************************
* Display the contents of the history buffer of commands with the number
* of the command listed on the beginning of the line.
****************************************************************************/
void handle_SIGQUIT(int junk)
{
   displayHistory();
   return;
}

/****************************************************************************
* Main Function runs sets up variables and runs an infinite loop unless terminated
* by the user (ctrl - D) to similuate a shell program.
****************************************************************************/
int main(void)
{
   int background;           /* equals 1 if a command is followed by '&' */
   char *args[MAX_LINE / 2]; /* command line (of 80) has max of 40 arguments */

   while (1) /* Program terminates normally inside setup */
   {
      background = 0;

      /* set up the signal handler */
      struct sigaction handler;
      handler.sa_handler = handle_SIGQUIT; /* function the handler will call */
      sigfillset(&handler.sa_mask);
      handler.sa_flags = 1;
      sigaction(SIGQUIT, &handler, NULL); /* handler to call for SIGQUIT signal */

      printf(" COMMAND-> ");
      fflush(stdout);
      setup(inputBuffer, args, &background); /* get next command */

      /* the steps are:
       * (1) fork a child process using fork()
       * (2) the child process will invoke execvp()
       * (3) if background != 1, the parent will wait,
       *     for the command to complete; otherwise,
       *     setup() gets called to process the next command line. 
       */
      //Process Identification Variable declared to prepare for a fork.
      pid_t pid;

      // Set that variable equal to the fork
      pid = fork();

      /* A fork creates almost a "copy" of the program to run on the child process,
       * to keep track of this, the system assigns a value of '0' to the child process,
       * and a positive integer value to the parent process. So, if the value is a negitive
       * integer, something went wrong, and we need to abort the program. */
      if (pid < 0) //If unable to create new process print error
      {
         printf("Unable to execute command\n");
      }
      // If you are the child process...
      else if (pid == 0)
      {
         /* Execute the program independently of the parent. First parameter denotes file to execute, 
          * second parameter denotes paramters to the file being executed.
          * A failed execvp call returns a negitive value. The return value of execvp is returned
          * in case the user enters a command that doesn't exist */
         // Letting the user know what they entered didn't work
         if (execvp(args[0], args) < 0)
         {
            cout << args[0] << ": Command not found\n";
            return 0;
         }
      }
      // If you are the parent process...
      else
      {
         // If the user didn't enter the '&' symbol
         if (background != 1)
         {
            // The parent will wait for the child to finish
            waitpid(pid, NULL, 0);
         }
      } // else statement
   }    // While loop
} // main
