#include <stdio.h>

void main() {
    int n, i, j, temp;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    int at[n], bt[n], tt[n], wt[n], id[n];  // Arrays for input and output data

    // Input process details
    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time of Process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time of Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        id[i] = i + 1;  // Store process IDs
    }

    // Sort based on arrival time (and process ID for stability)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1] || (at[j] == at[j + 1] && id[j] > id[j + 1])) {
                // Swap arrival time
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // Swap burst time
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap process IDs
                temp = id[j];
                id[j] = id[j + 1];
                id[j + 1] = temp;
            }
        }
    }

    int time1 = 0, completed = 0;

    // FCFS scheduling logic
    while (completed < n) {
        int flag = 0;
        for (i = 0; i < n; i++) {
            if (at[i] <= time1 && tt[i] == 0) {  // Process not yet completed
                time1 += bt[i];  // Advance time by burst time
                tt[i] = time1 - at[i];  // Calculate turnaround time
                wt[i] = tt[i] - bt[i];  // Calculate waiting time
                completed++;
                flag = 1;
                break;  // Move to the next time unit
            }
        }
        if (!flag) {
            time1++;  // Increment time if no process is ready
        }
    }

    // Output the process schedule and results
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
