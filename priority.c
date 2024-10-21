#include <stdio.h>
#include <limits.h>  // For using INT_MAX

void main() {
    int n, i, complete = 0, time1 = 0;

    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    int at[n], bt[n], tt[n], wt[n], id[n], p[n], visited[n];

    // Input process details
    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time of Process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time of Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter Priority of Process %d: ", i + 1);
        scanf("%d", &p[i]);
        id[i] = i + 1;  // Store process ID
        visited[i] = 0;  // Initialize visited array to mark incomplete processes
    }

    // Priority Scheduling Logic
    while (complete < n) {
        int minPriority = INT_MAX;  // Track the highest priority (lowest number)
        int selected = -1;  // Track the selected process index

        // Find the process with the highest priority that has arrived and is not completed
        for (i = 0; i < n; i++) {
            if (at[i] <= time1 && visited[i] == 0 && p[i] < minPriority) {
                minPriority = p[i];
                selected = i;
            }
        }

        if (selected != -1) {
            // Execute the selected process
            time1 += bt[selected];  // Advance time by burst time
            tt[selected] = time1 - at[selected];  // Turnaround time
            wt[selected] = tt[selected] - bt[selected];  // Waiting time
            visited[selected] = 1;  // Mark the process as completed
            complete++;  // Increment the count of completed processes
        } else {
            // If no process is available, increment time (idle time)
            time1++;
        }
    }

    // Display the process information and results
    printf("Process No\tPriority\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", id[i], p[i], at[i], bt[i], wt[i], tt[i]);
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
