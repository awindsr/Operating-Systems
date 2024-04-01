#include <stdio.h>

void swap(int arrA[], int arrB[], int length){
	for(int i=0; i<length; i++){
		for(int j=i+1; j<length; j++){
			if(arrA[i] > arrA[j]){
				//swap burstTime
				int temp = arrA[i];
				arrA[i] = arrA[j];
				arrA[j] = temp;
				
				//swap process accordingly
				int temp2 = arrB[i];
				arrB[i] = arrB[j];
				arrB[j] = temp2;
			}
		}	
	}
}

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
	
	swap(burstTime, processID, length);
	turnAroundTime[0] = burstTime[0];
	
	for(int i=0; i<length; i++){
		if(i == 0){
			waitTime[i]=i;
		}
		else{	
			waitTime[i]= waitTime[i-1] + burstTime[i-1];
		}
	}
	
	 for (int i = 1; i < length; i++) {
        	turnAroundTime[i] = turnAroundTime[i-1] + burstTime[i];
      
   	 }
	
	printf("Process ID\tBurst Time\tWait Time\tTurnaround Time\n");
    	for (int i = 0; i < length; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processID[i], burstTime[i], waitTime[i], turnAroundTime[i]);
    	}
    	
    	for(int i=0; i<length; i++){
		totalWaitTime += waitTime[i];
		 totalTurnAroundTime += turnAroundTime[i];
	}
	avgWaitTime = (float)totalWaitTime / length;
	avgTurnAroundTime = (float)totalTurnAroundTime/length;
	
    	printf("Total wait time is %d\nAverage wait time is %f\n",totalWaitTime, avgWaitTime);
    	printf("Total Turn around time time is %d\nAverage turn around time is %f\n",totalTurnAroundTime, avgTurnAroundTime);

}

