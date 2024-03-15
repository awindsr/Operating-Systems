#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHMSZ 1024

int main(){
	int shmid;
	key_t key;
	char *shm;
	char message[100];
	
	key = ftok(".", 'S');
	if(key == -1){
		perror("ftok");
		exit(1);
	}
	shmid = shmget(key, SHMSZ, IPC_CREAT | 0666 );
	if(shmid == -1){
		perror("shmget");
		exit(1);
	}
	printf("SHMID is %d\n", shmid);
	
	shm = shmat(shmid, NULL, 0);
	if(shm == (char *) -1){
		perror("shmat");
		exit(1);
	}
	
	printf("Enter a message: ");
	fgets(message, sizeof(message), stdin);
	message[strcspn(message, "\n")] = '\0';
	strcpy(shm, message);
	printf("Data read from memory: %s\n", shm);
	
	shmdt(shm);
	
	shmctl(shmid, IPC_RMID, NULL);
	printf("Cleared all data successfully");
} 
