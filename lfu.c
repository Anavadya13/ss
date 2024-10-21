#include <stdio.h>

int main() {
    int rs[50], i, j, k, m, f, cntr[20], a[20], min, pf = 0, flag;

    printf("\nEnter number of page references -- ");
    scanf("%d", &m);

    printf("\nEnter the reference string -- ");
    for (i = 0; i < m; i++)
        scanf("%d", &rs[i]);

    printf("\nEnter the available number of frames -- ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        cntr[i] = 0;
        a[i] = -1;
    }

    printf("\nThe Page Replacement Process is –\n");
    for (i = 0; i < m; i++) {
        flag = 0;
        for (j = 0; j < f; j++) {
            if (rs[i] == a[j]) {
                cntr[j]++;
                flag = 1;
                break;
            }
        }

        if (flag == 0) { // Page fault occurs
            min = 0;
            for (k = 1; k < f; k++) {
                if (cntr[k] < cntr[min])
                    min = k;
            }
            a[min] = rs[i];
            cntr[min] = 1;
            pf++;
        }

        for (j = 0; j < f; j++) {
            if (a[j] != -1)
                printf("\t%d", a[j]);
            else
                printf("\t-");
        }
        if (flag == 0)
            printf("\tPF No. %d", pf);

        printf("\n");
    }

    printf("\n\nTotal number of page faults -- %d", pf);

    return 0;
}
