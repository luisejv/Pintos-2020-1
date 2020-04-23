#ifndef USERPROG_SYSCALL_H
#define USERPROG_SYSCALL_H

#include "process.h"

void syscall_init (void);
int write(int, void*, unsigned);
void exit(int status);
pid_t exec(const char* cmd_line); 

#endif /* userprog/syscall.h */
