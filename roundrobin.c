#include <stdio.h>

int main() {
    int length, totalTime = 0, count = 0;
    float avgWaitTime = 0, totalWaitTime=0, avgTurnAroundTime;
    
    printf("Enter the total number of processes: ");
    scanf("%d", &length);
    int processID[length], burstTime[length], waitTime[length], turnAroundTime[length], timeQuant = 0, remainingTime[length], remainingProcessCount = length;

    for (int i = 0; i < length; i++) {
        printf("Enter the burst time of process %d: ", i);
        scanf("%d", &burstTime[i]);
        processID[i] = i;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &timeQuant);
    turnAroundTime[0] = burstTime[0];
    
    for (int i = 0; i < length; i++) {
        remainingTime[i] = burstTime[i];
    }

    while (remainingProcessCount > 0) {
        for (int i = 0; i < length; i++) {
            if (remainingTime[i] <= timeQuant && remainingTime[i] > 0) {
                totalTime += remainingTime[i];
                turnAroundTime[i] = totalTime;
                remainingTime[i] = 0;
                remainingProcessCount--;
		waitTime[i] = totalTime - burstTime[i];
		totalWaitTime += waitTime[i];
            }
            else if (remainingTime[i] > 0) {
                remainingTime[i] -= timeQuant;
                totalTime += timeQuant;
            }
        }
    }
    
    printf("Process ID\tBurst Time\tWait Time\tTurnaround Time\n");
    	for (int i = 0; i < length; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processID[i], burstTime[i], waitTime[i], turnAroundTime[i]);
    	}

 
    avgWaitTime = (float)totalWaitTime / length;
    avgTurnAroundTime = (float)totalTime / length;

    printf("Total wait time is %f\nAverage wait time is %f\n", totalWaitTime, avgWaitTime);
    printf("Total Turnaround time is %d\nAverage turnaround time is %f\n", totalTime, avgTurnAroundTime);

    return 0;
}
