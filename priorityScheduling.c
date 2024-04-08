#include <stdio.h>

void swap(int arrA[], int arrB[], int arrC[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arrA[i] > arrA[j]) {
                // Sort priority array
                int temp = arrA[i];
                arrA[i] = arrA[j];
                arrA[j] = temp;

                // Sort processID array accordingly
                temp = arrB[i];
                arrB[i] = arrB[j];
                arrB[j] = temp;

                // Sort burstTime array accordingly
                temp = arrC[i];
                arrC[i] = arrC[j];
                arrC[j] = temp;
            }
        }
    }
}

int main() {
    int length, totalWaitTime = 0, totalTurnAroundTime = 0;
    float avgWaitTime = 0, avgTurnAroundTime = 0;
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

    // Sorting processes based on priority
    swap(priorityTable, processID, burstTime, length);

    waitTime[0] = 0;
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
    totalTurnAroundTime += turnAroundTime[0];
    avgTurnAroundTime = (float)totalTurnAroundTime / length;

    printf("Total wait time is %d\nAverage wait time is %f\n", totalWaitTime, avgWaitTime);
    printf("Total Turnaround time is %d\nAverage turnaround time is %f\n", totalTurnAroundTime, avgTurnAroundTime);

    return 0;
}
