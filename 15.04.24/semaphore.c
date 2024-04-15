#include <stdio.h>
#include <stdlib.h>

int empty = 3, full = 0, mutex = 1;

void wait(int *s) {
        (*s)--;
    
}

void signal(int *s) {
        (*s)++;
    
}

void producer() {
    printf("produced\n");
        wait(&mutex);
        signal(&full);
        wait(&empty);
        signal(&mutex);
}

void consumer() {
        printf("consumed\n");
        wait(&mutex);
        wait(&full);
        signal(&empty);
        signal(&mutex);
}

int main() {
    int userChoice;
    do {
        
        printf("Enter your choice:\n1.Produce\t2.Consume\t3.Exit\n");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1: {
                if (mutex == 1 && empty != 0) {
                    producer();
                } else {
                    printf("Buffer full\n");
                }
                break;
            }
            case 2: {
                if (mutex == 1 && full != 0) {
                    consumer();
                } else {
                    printf("Buffer empty\n");
                }
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice\n");
                break;
            }
        }
    }while(userChoice!=3);

    return 0;
}

