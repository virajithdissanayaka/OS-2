#include<stdio.h>
#include<unistd.h>

int main()
{
    int id1 = fork();
    
    if(id1==0){
        printf("CHILD1\n");
    }
    else if(id1>0){

        int id2 = fork();

        if(id2==0){
            printf("CHILD2\n");
        }
        else if(id2>0){
            printf("PARENT\n");
        }
        
    }
}