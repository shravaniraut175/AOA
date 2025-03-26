#include <stdio.h>
#include <string.h>

char text[100], pattern[20];
int n, m, i, j;

void naiveStringMatch();

void main() {
    printf("Enter the text: ");
    gets(text);

    printf("Enter the pattern: ");
    gets(pattern);

    naiveStringMatch();
}

void naiveStringMatch() {
    n = strlen(text);
    m = strlen(pattern);

    printf("Pattern found at positions: ");
    int found = 0;

    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }

        if (j == m) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found)
        printf("No match found.");
    
    printf("\n");
}
