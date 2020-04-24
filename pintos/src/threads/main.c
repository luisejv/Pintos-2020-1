#include <stdio.h>
//For thread_foreach
#include <threads/thread.h>
static void my_function(struct thread* t, void* aux)
{
printf("Thread %d in <%s> function", t->tid, aux);
}
void foo(void)
{
/* In this function threads 1 and 3 exits and dies */
thread_foreach(my_function, "foo");
}
int main(void)
{
/* Instantiates and initializes 3 threads */
thread_foreach(my_function, "main");
foo();
return 0;
}
