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

    //The number_of_children processes that this program will spawn.
    //Must be >0. 
    int number_of_children;
    int option;

    while ( (option = getopt(argc, argv, ":n:h")) != -1 ) {
        switch ( option ) {
            case 'n':
                number_of_children = atoi(optarg);
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

    if ( number_of_children <= 0 ) {
        fprintf(stderr, "%s: Error: number_of_children cannot be negative.\n", argv[0]);
        return 1;
    }
    //END: Command line processing.
    //**********************************************************************

    //Test print.
    printf("The number_of_children is %d.\n", number_of_children);

    return 0;
}

//Display a usage message.
int help_message(char *prog_name)
{
    printf("Usage: %s -n [number of child processes]\n", prog_name);
    return 0;
} 
