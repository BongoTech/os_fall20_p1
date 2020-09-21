//**********************************************************************
//Program name: testsim
//Author: Cory Mckiel
//Date Created: September 21, 2020
//Last Modified: September 21, 2020
//Program Description:
//      This program completes a dummy task. It is meant to be
//      exec'd from proc_fan.
//
//      Must be called with one string argument.
//Compilation Instructions:
//      Option 1: Using Makefile.
//          Type: make
//      Option 2: Using gcc.
//          Type: gcc -Wall -g testsim.c -o testsim
//**********************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if ( argc != 3 ) {
        fprintf(stderr, "%s: Error: Invalid arguments.\n", argv[0]);
        return 1;
    }

    int sleep_time = atoi(argv[1]);
    int repeat_factor = atoi(argv[2]);
    int i = 0;

    printf("pid %d: Executing Tasks.\n", getpid());

    for ( i = 0; i < repeat_factor; i++ ) {
        sleep(sleep_time);
    }

    printf("pid %d: Finished Tasks.\n", getpid());

    return 0;
}
