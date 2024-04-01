#include <stdio.h>

void swap(int arrA[], int arrB[], int arrC[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
        
            if (arrA[i] > arrA[j]) {
                // Sort 
                int temp = arrA[i];
                arrA[i] = arrA[j];
                arrA[j] = temp;   

                // Sort process accordingly
                int temp2 = arrB[i];
                arrB[i] = arrB[j];
                arrB[j] = temp2;

                int temp3 = arrC[i];
                arrC[i] = arrC[j];
                arrC[j] = temp3;
            }
        }
    }
}

void main() {
    int length, totalWaitTime=0, totalTurnAroundTime=0;
	float avgWaitTime=0, avgTurnAroundTime=0;
    printf("Enter the total number of processes: ");
    scanf("%d", &length);

    int processID[length], burstTime[length], waitTime[length], turnAroundTime[length], priorityTable[length];

    for (int i = 0; i < length; i++) {
        printf("Enter the burst time of process %d: ", i);
        scanf("%d", &burstTime[i]);
        printf("Enter the priority of process %d: ", i);
        scanf("%d", &priorityTable[i]);
        processID[i] = i;
    }

    swap(priorityTable, processID, burstTime, length);
    turnAroundTime[0] = burstTime[0];

    for (int i = 1; i < length; i++) {
        waitTime[i] = waitTime[i - 1] + burstTime[i - 1];
        turnAroundTime[i] = turnAroundTime[i-1] + burstTime[i];
        totalTurnAroundTime += turnAroundTime[i];
    }

    printf("Process ID\tBurst Time\tPriority\tWait Time\tTurnaround Time\n");
    for (int i = 0; i < length; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processID[i], burstTime[i], priorityTable[i], waitTime[i], turnAroundTime[i]);
    }

    for (int i = 0; i < length; i++) {
        totalWaitTime += waitTime[i];
    }
    	avgWaitTime = (float)totalWaitTime / length;
	avgTurnAroundTime = (float)totalTurnAroundTime/length;
	
    	printf("Total wait time is %d\nAverage wait time is %f\n",totalWaitTime, avgWaitTime);
    	printf("Total Turn around time time is %d\nAverage turn around time is %f\n",totalTurnAroundTime, avgTurnAroundTime);
}

