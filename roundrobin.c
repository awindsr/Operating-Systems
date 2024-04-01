#include <stdio.h>

int main() {
    int length, totalTime = 0, count = 0, remainingProcessCount = 0;
    float avgWaitTime = 0;
    int processID[length], burstTime[length], waitTime[length], turnAroundTime[length], timeQuant = 0;

    printf("Enter the total number of processes: ");
    scanf("%d", &length);

    for (int i = 0; i < length; i++) {
        printf("Enter the burst time of process %d: ", i);
        scanf("%d", &burstTime[i]);
        processID[i] = i;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &timeQuant);
    turnAroundTime[0]=burstTime[0];

    for (int i = 0; i < length; i++) {
        if (burstTime[i] <= timeQuant && burstTime[i] > 0) {
            totalTime += burstTime[i];
            burstTime[i] = 0;
            count++;
        } else if (burstTime[i] > timeQuant) {
            burstTime[i] -= timeQuant;
            totalTime += timeQuant;
        }
    }

    for (int i = 1; i < length; i++) {
        waitTime[i] = totalTime - burstTime[i];
        turnAroundTime[i] = turnAroundTime[i-1] + burstTime[i];
        avgWaitTime += waitTime[i];
    }
    
    printf("Process ID\tBurst Time\tWait Time\tTurnaround Time\n");
    	for (int i = 0; i < length; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processID[i], burstTime[i], waitTime[i], turnAroundTime[i]);
    	}

    avgWaitTime /= length;

    printf("Average waiting time: %f\n", avgWaitTime);

    return 0;
}

