#include <stdio.h>

void main(){
	int length, totalWaitTime=0, totalTurnAroundTime=0;
	float avgWaitTime=0, avgTurnAroundTime=0;
	printf("Enter the total number of processes:");
	scanf("%d", &length);
	
	int processID[length], burstTime[length], waitTime[length], turnAroundTime[length];
	
	for(int i=0; i<length; i++){
		printf("Enter the burst time of process %d\n", i);
		scanf("%d", &burstTime[i]);
		processID[i] = i;
	}
	
	for(int i=0; i<length; i++){
		waitTime[i] = 0;
		for(int j=0; j<i; j++){
			waitTime[i] += burstTime[j];
		}
	}
	
	 for (int i = 0; i < length; i++) {
        turnAroundTime[i] = waitTime[i] + burstTime[i];
        totalTurnAroundTime += turnAroundTime[i];
   	 }
	
	printf("Process ID\tBurst Time\tWait Time\tTurnaround Time\n");
    	for (int i = 0; i < length; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processID[i], burstTime[i], waitTime[i], turnAroundTime[i]);
    	}	
    	
    	for(int i=0; i<length; i++){
		totalWaitTime += (float)waitTime[i];
	}
	avgWaitTime = (float)totalWaitTime / length;
	avgTurnAroundTime = (float)totalTurnAroundTime/length;
	
    	printf("Total wait time is %d\nAverage wait time is %f\n",totalWaitTime, avgWaitTime);
    	printf("Total Turn around time time is %d\nAverage turn around time is %f\n",totalTurnAroundTime, avgTurnAroundTime);
}

