//**********************************************************************
//Program Name: proc_fan
//Author: Cory Mckiel
//Date Created: September 21, 2020
//Last Modified: Septermber 21, 2020
//Program Description:
//      Completing Exercise 3.9 on page 88 of Unix systems programming
//      by Robbins and Robbins for OS 4760 Fall 2020 project 1.
//
//      Program takes an argument that specifies the number of children
//      this program will create to do some dummy task. The focus is 
//      on practicing fork(), wait(), and exec() in the linux 
//      environment.
//Compilation Instructions:
//      Option 1: Using the included Makefile.
//              Type: make
//      Option 2: Using gcc.
//              Type: gcc -Wall -g proc_fan.c -o proc_fan
//**********************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_CANON 64

//Function Prototypes
int help_message(char*);

int main(int argc, char *argv[])
{
    //BEGIN: Command line processing.
    //**********************************************************************
    if ( argc < 2 ) {
        fprintf(stderr, "%s: Error: Invalid argument length.\n", argv[0]);
        return 1;
    }

    //The maximum number of children to execute at one time.
    //Must satisfy 0 < pr_limit <= 20.
    //20 was chosen arbitrarily to prevent too many processes
    //on the system at one time.
    int pr_limit;

    //Current number of active children.
    int pr_count = 0;

    int option;
    while ( (option = getopt(argc, argv, ":n:h")) != -1 ) {
        switch ( option ) {
            case 'n':
                pr_limit = atoi(optarg);
                break;
            case ':':
                fprintf(stderr, "%s: Error: Missing argument value.\n", argv[0]);
                return 1;
            case 'h':
                help_message(argv[0]);
                return 0;
            default:
                fprintf(stderr, "%s: Error: Unknown argument.\n", argv[0]);
                return 1;
        }
    }

    if ( pr_limit <= 0 || pr_limit > 20 ) {
        fprintf(stderr, "%s: Error: pr_limit must satisfy 0 < pr_limit <= 20.\n", argv[0]);
        return 1;
    }
    //END: Command line processing.
    //**********************************************************************
    //BEGIN: Generating children.

    pid_t childpid;
    char buffer[MAX_CANON];

    //Pull one line from stdin.
    if ( fgets(buffer, MAX_CANON, stdin) != NULL ) {

        //Setting up the argument vector based on lines from stdin
        char arg_one[16], arg_two[16], arg_three[16];
        sscanf(buffer, "%s %s %s", arg_one, arg_two, arg_three);
        char *arg_vector[] = {"./testsim", arg_two, arg_three, NULL};
        
        //Create one child to do the task defined by argument vector.
        if (( childpid = fork() ) < 0 ) {
            fprintf(stderr, "%s: Error: Failed to fork child.\n", argv[0]);
            return 1;
        } else if ( childpid == 0 ) {
            execv(arg_vector[0], arg_vector);
        }
    }
    //END: Generating children.
    //**********************************************************************
    //BEGIN: Finishing up.

    //Wait for the child to complete.
    wait(NULL);

    //Test print.
    printf("The pr_limit is %d.\n", pr_limit);

    return 0;
}

//Display a usage message.
int help_message(char *prog_name)
{
    printf("Usage: %s -n [number of child processes]\n", prog_name);
    return 0;
} 
