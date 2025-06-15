#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Max Difference Integer 
int maxDiff(int num) {
    char s[10], high[10], low[10];
    sprintf(s, "%d", num);
    strcpy(high, s);
    strcpy(low, s);

    // Step 1: Make the highest number (replace a digit with '9')
    for (int i = 0; s[i]; i++) {
        if (s[i] != '9') {
            char target = s[i];
            for (int j = 0; high[j]; j++) {
                if (high[j] == target) high[j] = '9';
            }
            break;
        }
    }

    // Step 2: Make the lowest number (replace a digit with '1' or '0')
    if (s[0] != '1') {
        char target = s[0];
        for (int j = 0; low[j]; j++) {
            if (low[j] == target) low[j] = '1';
        }
    } else {
        // Find first digit (not 0 or 1) to replace with 0
        for (int i = 1; s[i]; i++) {
            if (s[i] != '0' && s[i] != '1') {
                char target = s[i];
                for (int j = 0; low[j]; j++) {
                    if (low[j] == target) low[j] = '0';
                }
                break;
            }
        }
    }

    int maxNum = atoi(high);
    int minNum = atoi(low);

    return maxNum - minNum;
}

// Maximum Difference by Remapping a Digit
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

    num = 9288;
    printf("Max difference: %d\n", maxDiff(num)); // Output: 8700
    return 0;
}
