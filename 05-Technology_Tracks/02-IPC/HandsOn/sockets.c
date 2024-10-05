#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MSG_CHILD "Hi from child process, How are you?"
#define MSG_PARENT "Hi child, I am fine"

int main()
{
    int sockets[2]; //sockets
    int child;  // store result of fork in
    char buf[1024]; //buffer for the message
	
    //create socket pair for parent and child
	if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockets) < 0) {
        perror("opening stream socket pair");
        exit(1);
    }

    //from the main process create child process (both will start here)
    if ((child = fork()) == -1)
        perror("fork");
    else if (child) {       
		//this means child is created so this is the parent process
		
        //TODO: Read message from child
        recv(sockets[1],buf,sizeof(buf),0);
		// log the recieved message to the screen
        printf("-->%s\n", buf);
		
		//TODO: Send message to child
        send(sockets[1],MSG_PARENT,sizeof(MSG_PARENT),0);
		//close the socket
        close(sockets[1]);
    } else {                
		//this means child = 0 so this is the child process

		//TODO: Write message to Parent
		send(sockets[0],MSG_CHILD,sizeof(MSG_CHILD),0);
		//TODO: Read message from parent
        recv(sockets[0],buf,sizeof(buf),0);
		// log the recieved message to the screen
        printf("-->%s\n", buf);
		//close the socket
        close(sockets[0]);
    }
}
