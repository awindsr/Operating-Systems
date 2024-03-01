#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	pid_t child_pid;
	child_pid = fork();
	
	if(child_pid == 0){
		printf("Child process\n");
		printf("Child Process: PID is %d\n", getpid());
		printf("Parent process: PID is %d\n", getppid());
		int num;
		printf("Enter a number: \n");
		scanf("%d", &num);
		if(num%2==0){
			printf("Number is even.");
		}
		else{
			printf("Number is odd.");
		}
	}
	else if(child_pid>0){
		wait(NULL);
		printf("Parent process\n");
		printf("Child Process: PID is %d\n", getpid());
		printf("Parent process: PID is %d\n", getppid());
		
		int limit; 
		printf("Enter a number:\n");
		scanf("%d", &limit);
		
		for(int i=1; i<=limit; i++){
			printf("%d\t", i);
		}	
	}
	
	
	else{
		perror("Fork failed.");
		return 1;
	}
	return 0;
}
