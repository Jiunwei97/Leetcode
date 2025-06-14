#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int replace(char *s, char from, char to) {
    char temp[20];
    strcpy(temp, s);
    for (int i = 0; temp[i]; i++) {
        if (temp[i] == from)
            temp[i] = to;
    }
    return atoi(temp);
}

int minMaxDifference(int num) {
    char str[20];
    sprintf(str, "%d", num);

    // Max value: replace first non-'9' digit with '9'
    char *maxTarget = NULL;
    for (int i = 0; str[i]; i++) {
        if (str[i] != '9') {
            maxTarget = &str[i];
            break;
        }
    }
    int maxVal = replace(str, maxTarget ? *maxTarget : '0', '9');

    // Min value: replace first digit with '0'
    int minVal = replace(str, str[0], '0');

    return maxVal - minVal;
}

int main() {
    int num = 11891;
    int result = minMaxDifference(num);
    printf("Difference: %d\n", result);  // Output: 99009
    return 0;
}
