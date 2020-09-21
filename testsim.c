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
#include <unistd.h>

int main(int argc, char *argv[])
{
    if ( argc != 2 ) {
        fprintf(stderr, "%s: Error: Invalid arguments.\n", argv[0]);
        return 1;
    }

    printf("Hello from child with pid %ld!\n", (long)getpid());
    printf("The message is %s.\n", argv[1]);

    return 0;
}
