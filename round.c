#include <stdio.h>

void main() {
    int n, i, t, complete = 0, time1 = 0;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    int at[n], bt[n], tt[n], wt[n], id[n], remaining[n];

    // Input process details
    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time of Process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time of Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        id[i] = i + 1;  // Store process ID
        remaining[i] = bt[i];  // Initialize remaining burst time
    }

    printf("Enter Time Slice: ");
    scanf("%d", &t);

    // Round Robin Scheduling Logic
    while (complete < n) {
        int flag = 0;  // Flag to track if any process was executed in this iteration

        for (i = 0; i < n; i++) {
            if (at[i] <= time1 && remaining[i] > 0) {  // Check if process has arrived and is incomplete
                flag = 1;  // Mark that a process was executed

                if (remaining[i] <= t) {
                    // Process completes in this time slice
                    time1 += remaining[i];  // Advance time
                    tt[i] = time1 - at[i];  // Turnaround time = Completion time - Arrival time
                    wt[i] = tt[i] - bt[i];  // Waiting time = Turnaround time - Burst time
                    remaining[i] = 0;  // Mark process as complete
                    complete++;  // Increment the number of completed processes
                } else {
                    // Process does not complete, execute for the time slice
                    remaining[i] -= t;
                    time1 += t;  // Advance time by the time slice
                }
            }
        }

        // If no process was executed, increment time to handle idle time
        if (!flag) {
            time1++;
        }
    }

    // Display the process information and results
    printf("Process No\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", id[i], at[i], bt[i], wt[i], tt[i]);
    }

    // Calculate and print average waiting and turnaround times
    float ttsum = 0, wtsum = 0;
    for (i = 0; i < n; i++) {
        ttsum += tt[i];
        wtsum += wt[i];
    }

    printf("Average Turnaround Time = %.2f\n", ttsum / n);
    printf("Average Waiting Time = %.2f\n", wtsum / n);
}
