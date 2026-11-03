#include <stdio.h>

int main() {
    int frames[10], pages[50];
    int f, n, i, j, k, pos, farthest;
    int faults = 0, found, flag;

    printf("OPTIMAL PAGE REPLACEMENT ALGORITHM\n");

    printf("Enter no.of Frames:\t");
    scanf("%d", &f);

    printf("Enter no.of reference string ");
    scanf("%d", &n);

    printf("\nEnter reference string... ");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    for(i = 0; i < f; i++)
        frames[i] = -1;

    printf("\nThe given reference string:\n");
    for(i = 0; i < n; i++)
        printf("%d ", pages[i]);

    printf("\n");

    for(i = 0; i < n; i++) {
        printf("\nRef no %d ->\t", pages[i]);

        found = 0;
        flag = 0;

        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(found == 0) {
            for(j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    frames[j] = pages[i];
                    faults++;
                    found = 1;
                    flag = 1;
                    break;
                }
            }
        }

        if(found == 0) {
            farthest = -1;
            pos = -1;

            for(j = 0; j < f; j++) {
                for(k = i + 1; k < n; k++) {
                    if(frames[j] == pages[k]) {
                        if(k > farthest) {
                            farthest = k;
                            pos = j;
                        }
                        break;
                    }
                }

                if(k == n) {
                    pos = j;
                    break;
                }
            }

            frames[pos] = pages[i];
            faults++;
            flag = 1;
        }

        for(j = 0; j < f; j++) {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }

        if(flag == 1)
            printf("-> F");

        printf("\n");
    }

    printf("\nNo.of page faults: %d\n", faults);

    return 0;
}
