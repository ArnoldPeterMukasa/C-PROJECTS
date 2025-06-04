#include <stdio.h>
#include <stdbool.h>

#define PROCESSES 5
#define RESOURCES 3

int available[RESOURCES] = {3, 3, 2}; // Available resources
int maximum[PROCESSES][RESOURCES] = { // Maximum demand of each process
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}};
int allocation[PROCESSES][RESOURCES] = { // Resources currently allocated
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}};
int need[PROCESSES][RESOURCES]; // Resources needed to complete execution

void calculateNeed() {
    for (int i = 0; i < PROCESSES; i++) {
        for (int j = 0; j < RESOURCES; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

bool isSafeState() {
    bool finish[PROCESSES] = {0};
    int work[RESOURCES];
    for (int i = 0; i < RESOURCES; i++) {
        work[i] = available[i];
    }

    int safeSeq[PROCESSES];
    int count = 0;

    while (count < PROCESSES) {
        bool found = false;
        for (int p = 0; p < PROCESSES; p++) {
            if (!finish[p]) {
                bool canAllocate = true;
                for (int r = 0; r < RESOURCES; r++) {
                    if (need[p][r] > work[r]) {
                        canAllocate = false;
                        break;
                    }
                }

                if (canAllocate) {
                    for (int r = 0; r < RESOURCES; r++) {
                        work[r] += allocation[p][r];
                    }
                    safeSeq[count++] = p;
                    finish[p] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            return false; // Not a safe state
        }
    }

    printf("Safe sequence is: ");
    for (int i = 0; i < PROCESSES; i++) {
        printf("%d ", safeSeq[i]);
    }
    printf("\n");
    return true;
}

bool detectDeadlock() {
    bool finish[PROCESSES] = {0};
    int work[RESOURCES];
    for (int i = 0; i < RESOURCES; i++) {
        work[i] = available[i];
    }

    while (1) {
        bool progress = false;
        for (int i = 0; i < PROCESSES; i++) {
            if (!finish[i]) {
                bool canRun = true;
                for (int j = 0; j < RESOURCES; j++) {
                    if (need[i][j] > work[j]) {
                        canRun = false;
                        break;
                    }
                }
                if (canRun) {
                    progress = true;
                    finish[i] = true;
                    for (int j = 0; j < RESOURCES; j++) {
                        work[j] += allocation[i][j];
                    }
                }
            }
        }
        if (!progress) {
            break;
        }
    }

    for (int i = 0; i < PROCESSES; i++) {
        if (!finish[i]) {
            return true; // Deadlock detected
        }
    }
    return false;
}

int main() {
    calculateNeed();

    printf("Checking if the system is in a safe state...\n");
    if (isSafeState()) {
        printf("The system is in a safe state.\n");
    } else {
        printf("The system is NOT in a safe state.\n");
    }

    printf("\nChecking for deadlock...\n");
    if (detectDeadlock()) {
        printf("Deadlock detected.\n");
    } else {
        printf("No deadlock detected.\n");
    }

    return 0;
}