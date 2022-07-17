#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
  
void forkexample()
{
    int x = 1;
    
    fork();
  
    if (fork() == 0)
        printf("Child has x = %d\n", ++x);
    else
        printf("Parent has x = %d\n", --x);
}
int main()
{
    forkexample();
    fork();
    return 0;
}