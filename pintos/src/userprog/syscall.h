#ifndef USERPROG_SYSCALL_H
#define USERPROG_SYSCALL_H

#include "process.h"

void syscall_init (void);

//SYSCALLS

void sys_halt (void);
void sys_exit (int);
pid_t sys_execute (const char *);
int sys_wait (pid_t);
bool sys_create (const char *, unsigned);
bool sys_remove (const char *);
int sys_open (const char *);
int sys_filesize (int);
int sys_read (int, void *, unsigned);
int sys_write (int, const void *, unsigned);
void sys_seek (int, unsigned);
unsigned sys_tell (int);
void sys_close (int);

#endif /* userprog/syscall.h */
