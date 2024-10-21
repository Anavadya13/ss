#include <stdio.h>
#include <limits.h>  // For INT_MAX

void main() {
    int n, i;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    int at[n], bt[n], tt[n], wt[n], id[n], completed[n];  // Arrays to store details

    // Input arrival and burst times
    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time of Process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time of Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        id[i] = i + 1;  // Store process ID
        completed[i] = 0;  // Mark all processes as incomplete initially
    }

    int time1 = 0, complete = 0;

    // SJF Scheduling Logic
    while (complete < n) {
        int min_bt = INT_MAX;
        int index = -1;

        // Find the process with the smallest burst time among the arrived processes
        for (i = 0; i < n; i++) {
            if (at[i] <= time1 && !completed[i] && bt[i] < min_bt) {
                min_bt = bt[i];
                index = i;
            }
        }

        if (index != -1) {
            // Execute the selected process
            time1 += bt[index];  // Advance time by the burst time of the selected process
            tt[index] = time1 - at[index];  // Calculate turnaround time
            wt[index] = tt[index] - bt[index];  // Calculate waiting time

            completed[index] = 1;  // Mark the process as complete
            complete++;  // Increment the number of completed processes
        } else {
            // If no process is ready, increment the time
            time1++;
        }
    }

    // Display process information and results
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
