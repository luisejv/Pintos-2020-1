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

static void
syscall_handler (struct intr_frame *f) 
{ 
  int syscallName = *(int*)f->esp;

  switch(syscallName){

    case SYS_HALT:{
      break;
    }

    case SYS_EXIT:{
      printf("Exiting process: %s\n", thread_current()->name);
      int status = *((int*)f->esp+1);
      sys_exit(status); 
      break;
    }

    case SYS_EXEC:{
      const char* cmd_line = (const char*)f->esp+1;
      f->eax = sys_execute(cmd_line);
    }

    case SYS_WAIT:{
      break;
    }

    case SYS_CREATE:{
      break;
    }

    case SYS_REMOVE:{
      break;
    }

    case SYS_OPEN:{
      break;
    }

    case SYS_FILESIZE:{
      break;
    }

    case SYS_READ:{
      break;
    }

    case SYS_WRITE:{
      int fd = *((int*)f->esp+1); 
      void* buffer = (void*)(*((int*)f->esp+2));
      unsigned size = *((unsigned*)f->esp+3);
      f->eax = write(fd,buffer,size);
      putbuf(buffer,size);
    }
   
    case SYS_SEEK:{
      break;
    }
    
    case SYS_TELL:{
      break;
    }

    case SYS_CLOSE:{
      break;
    }
    //Faltan implementar los others sys_calls
  }
  //printf ("system call!\n");
  thread_exit ();
}

void 
sys_halt (void){
  printf("Halt SYSCALL");
}

void 
sys_exit(int status){
  struct thread* currThread = thread_current();
  printf("%s: exit(%d)\n",currThread->name,status);    
  thread_exit();
}

pid_t
sys_execute(const char* cmd_line){
  pid_t pid = process_execute(cmd_line);
  return pid;
}

int
sys_wait (pid_t pid){
  printf("Wait SYSCALL"); 
  return 1;
}

bool
sys_create (const char * file, unsigned initial_size){
  printf("CREATE SYSCALL");
  return 1;
}

bool
sys_remove (const char *file){
  printf("REMOVE SYSCALL");
  return 1;    
} 

int
sys_open (const char * file){
  printf("OPEN SYSCALL");
  return 1;
}

int
sys_filesize (int fd){
  printf("FILESIZE SYSCALL");
  return 1;
}

int
sys_read (int fd, void * buffer, unsigned size){
  printf("READ SYSCALL");
  return 1;
}

int
write (int fd, void* buffer, unsigned size){
  printf("WRITE SYSCALL\n");
  return 1;
}

void
sys_seek (int fd, unsigned position){
  printf("SEEK SYSCALL");
}

unsigned sys_tell (int fd){
  printf("TELL SYSCALL");
  return 1;
}

void sys_close (int fd){
  printf("CLOSE SYSCALL");
}


