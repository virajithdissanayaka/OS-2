#include<stdio.h>
#include<unistd.h>

int main()
{
    int pipe_array[2];
    int status;
    char received_string[18];

    status = pipe(pipe_array);

    if(status==-1)
    {
        printf("An Error occured with opening pipe\n");
    }
    else
    {
        int id = fork();
        if(id==-1)
        {
            printf("An Error occured with fork\n");
        }
        else if(id>0)
        {
            close(pipe_array[0]);
            write(pipe_array[1], "Hello from parent",sizeof(received_string));
            close(pipe_array[1]);
        }
        else 
        {
            close(pipe_array[1]);
            read(pipe_array[0], received_string,sizeof(received_string)); 

            printf("Message: %s",received_string);

            close(pipe_array[0]);
        }
    
    
    }
    return 0;
}