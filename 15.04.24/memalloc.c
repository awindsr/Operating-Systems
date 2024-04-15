#include <stdio.h>

#define MAX_MEMORY_BLOCKS 100
#define MAX_PROCESSES 100

struct MemoryBlock {
    int size;
    int flag; 
};

struct Process {
    int size;
    int allocated_block_index; 
    int allocated;
};

void initializeMemory(struct MemoryBlock memory[], int num_blocks) {
    for (int i = 0; i < num_blocks; ++i) {
        scanf("%d", &memory[i].size);
        memory[i].flag = 0;
    }
}

void displayMemory(struct MemoryBlock memory[], struct Process processes[], int num_blocks, int num_processes) {
    printf("Memory Blocks:\n");
    for (int i = 0; i < num_blocks; ++i) {
        printf("Block %d: Size %d, Allocated: %s\n", i + 1, memory[i].size, memory[i].flag ? "Yes" : "No");
    }
    
    printf("\nProcess Allocation:\n");
    for (int i = 0; i < num_processes; ++i) {
        if (processes[i].allocated_block_index != -1) {
            printf("Process %d: Size %d, Allocated to Block %d\n", i + 1, processes[i].size, processes[i].allocated_block_index + 1);
        } else {
            printf("Process %d: Size %d, Not Allocated\n", i + 1, processes[i].size);
        }
    }
}

void allocateFirstFit(struct MemoryBlock memory[], struct Process processes[], int num_blocks, int num_processes) {
    for (int i = 0; i < num_processes; ++i) {
        for (int j = 0; j < num_blocks; ++j) {
            if (processes[i].size <= memory[j].size && memory[j].flag == 0) {
                memory[j].flag = 1; 
                processes[i].allocated_block_index = j;
                break; 
            }
        }
    }
}

void allocateBestFit(struct MemoryBlock memory[], struct Process processes[], int num_blocks, int num_processes) {
    // Initialize all processes as not allocated
    for (int i = 0; i < num_processes; ++i) {
        processes[i].allocated = 0;
    }

    // Initialize all memory blocks as available
    for (int i = 0; i < num_blocks; ++i) {
        memory[i].flag = 0;
    }

    // Iterate through each process
    for (int i = 0; i < num_processes; ++i) {
        int best_fit_index = -1;
        // Find the best fit memory block for the current process
        for (int j = 0; j < num_blocks; ++j) {
            if (processes[i].size <= memory[j].size && memory[j].flag == 0) {
                if (best_fit_index == -1 || memory[j].size < memory[best_fit_index].size) {
                    best_fit_index = j;
                }
            }
        }
        // Allocate the process to the best fit memory block if found
        if (best_fit_index != -1) {
            memory[best_fit_index].flag = 1;
            processes[i].allocated_block_index = best_fit_index;
            processes[i].allocated = 1; // Process allocated
        } else {
            printf("Process %d: Size %d, Not Allocated\n", i + 1, processes[i].size);
        }
    }
}




int main() {
    struct MemoryBlock memory[MAX_MEMORY_BLOCKS];
    struct Process processes[MAX_PROCESSES];
    int num_blocks, num_processes;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &num_blocks);

    printf("Enter the sizes of memory blocks:\n");
    initializeMemory(memory, num_blocks);

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the sizes of processes:\n");
    for (int i = 0; i < num_processes; ++i) {
        scanf("%d", &processes[i].size);
        processes[i].allocated_block_index = -1;
        processes[i].allocated = 0; // Initially not allocated
    }

    printf("\nFirst Fit Allocation:\n");
    allocateFirstFit(memory, processes, num_blocks, num_processes);
    displayMemory(memory, processes, num_blocks, num_processes);

    printf("\nBest Fit Allocation:\n");
    allocateBestFit(memory, processes, num_blocks, num_processes);
    displayMemory(memory, processes, num_blocks, num_processes);

   // printf("\nWorst Fit Allocation:\n");
   // allocateWorstFit(memory, processes, num_blocks, num_processes);
    //displayMemory(memory, processes, num_blocks, num_processes);

    return 0;
}

