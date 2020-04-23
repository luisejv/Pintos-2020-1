#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"

static void syscall_handler (struct intr_frame *);

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

int
write (int fd, void* buffer, unsigned size){
  printf("Inside Write\n");
  return 1;
}

static void
syscall_handler (struct intr_frame *f) 
{ 
  int syscallName = *(int*)f->esp;

  switch(syscallName){
    case SYS_EXIT:{
      printf("Exiting the process\n");
      
      break;
    }
    case SYS_READ:{
      break;
    }
    case SYS_WRITE:{
      //El puntero sube porque se recibe la data de arriba para abajo, estando el number
      //Del syscall debajo.
      int fd = *((int*)f->esp+1); 
      void* buffer = (void*)(*((int*)f->esp+2));
      unsigned size = *((unsigned*)f->esp+3);
      
      f->eax = write(fd,buffer,size);
    }
    
    //Faltan implementar los others sys_calls
  }
  printf ("system call!\n");
  thread_exit ();
}
