#include <stdio.h>

void main() {
    int i, j, k, f, pf = 0, n, rs[25], m[10], index[10], least;
    printf("\n Enter the length of reference string -- ");
    scanf("%d", &n);
    printf("\n Enter the reference string -- ");
    for (i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }
    printf("\n Enter no. of frames -- ");
    scanf("%d", &f);
    for (i = 0; i < f; i++) {
        m[i] = -1;
        index[i] = 0;
    }
    printf("\n The Page Replacement Process is -- \n");
    for (i = 0; i < n; i++) {
        for (k = 0; k < f; k++) {
            if (m[k] == rs[i]) {
                index[k] = i + 1; // Update the index to the current time
                break;
            }
        }
        if (k == f) { // Page fault occurs
            least = 0;
            for (j = 1; j < f; j++) {
                if (index[j] < index[least]) {
                    least = j; // Find the least recently used page
                }
            }
            m[least] = rs[i]; // Replace the least recently used page
            index[least] = i + 1; // Update the index to the current time
            pf++; // Increment the page fault count
        }
        for (j = 0; j < f; j++) {
            printf("\t%d", m[j]);
        }
        if (k == f) {
            printf("\tPF No. %d", pf);
        }
        printf("\n");
    }
    printf("\n The number of Page Faults using LRU are %d", pf);
}
