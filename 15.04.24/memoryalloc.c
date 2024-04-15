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
};

nt main() {
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
    }

    printf("\nFirst Fit Allocation:\n");
    allocateFirstFit(memory, processes, num_blocks, num_processes);
    displayMemory(memory, num_blocks);

    printf("\nBest Fit Allocation:\n");
    allocateBestFit(memory, processes, num_blocks, num_processes);
    displayMemory(memory, num_blocks);

    printf("\nWorst Fit Allocation:\n");
    allocateWorstFit(memory, processes, num_blocks, num_processes);
    displayMemory(memory, num_blocks);

    return 0;
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
    for (int i = 0; i < num_processes; ++i) {
        int best_fit_index = -1;
        for (int j = 0; j < num_blocks; ++j) {
            if (processes[i].size <= memory[j].size && memory[j].flag == 0) {
                if (best_fit_index == -1 || memory[j].size < memory[best_fit_index].size) {
                    best_fit_index = j;
                }
            }
        }
        if (best_fit_index != -1) {
            memory[best_fit_index].flag = 1;
            processes[i].allocated_block_index = best_fit_index;
        }
    }
}

void allocateWorstFit(struct MemoryBlock memory[], struct Process processes[], int num_blocks, int num_processes) {
    for (int i = 0; i < num_processes; ++i) {
        int worst_fit_index = -1;
        for (int j = 0; j < num_blocks; ++j) {
            if (processes[i].size <= memory[j].size && memory[j].flag == 0) {
                if (worst_fit_index == -1 || memory[j].size > memory[worst_fit_index].size) {
                    worst_fit_index = j;
                }
            }
        }
        if (worst_fit_index != -1) {
            memory[worst_fit_index].flag = 1;
            processes[i].allocated_block_index = worst_fit_index;
        }
    }
}
































