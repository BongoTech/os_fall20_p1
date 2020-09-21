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
#include <unistd.h>

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
