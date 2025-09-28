#ifndef LEETCODE_API_H // If LEETCODE_API_H is not defined
#define LEETCODE_API_H // Define it to prevent multiple inclusion
#include "math_api.h"

// Function prototype
// int maxDiff(int i);
// int replace(char *s, char from, char to);
// int minMaxDifference(int num);
// int maximumDifference(int *nums, int numsSize);
// char **divideString(char *s, int k, char fill, int *returnSize);
// char *largestGoodInteger(char *num);
// int largestPerimeter(int *nums, int numsSize);

// Macro definition
#define PI 3.14159
#define MAX(a, b) (a > b ? a : b)

int maxDiff(int num)
{
    char s[10], high[10], low[10];
    sprintf(s, "%d", num);
    strcpy(high, s);
    strcpy(low, s);

    // Step 1: Make the highest number (replace a digit with '9')
    for (int i = 0; s[i]; i++)
    {
        if (s[i] != '9')
        {
            char target = s[i];
            for (int j = 0; high[j]; j++)
            {
                if (high[j] == target)
                    high[j] = '9';
            }
            break;
        }
    }

    // Step 2: Make the lowest number (replace a digit with '1' or '0')
    if (s[0] != '1')
    {
        char target = s[0];
        for (int j = 0; low[j]; j++)
        {
            if (low[j] == target)
                low[j] = '1';
        }
    }
    else
    {
        // Find first digit (not 0 or 1) to replace with 0
        for (int i = 1; s[i]; i++)
        {
            if (s[i] != '0' && s[i] != '1')
            {
                char target = s[i];
                for (int j = 0; low[j]; j++)
                {
                    if (low[j] == target)
                        low[j] = '0';
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
int replace(char *s, char from, char to)
{
    char temp[20];
    strcpy(temp, s);
    for (int i = 0; temp[i]; i++)
    {
        if (temp[i] == from)
            temp[i] = to;
    }
    return atoi(temp);
}

int minMaxDifference(int num)
{
    char str[20];
    sprintf(str, "%d", num);

    // Max value: replace first non-'9' digit with '9'
    char *maxTarget = NULL;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] != '9')
        {
            maxTarget = &str[i];
            break;
        }
    }
    int maxVal = replace(str, maxTarget ? *maxTarget : '0', '9');

    // Min value: replace first digit with '0'
    int minVal = replace(str, str[0], '0');

    return maxVal - minVal;
}

void minMaxDifference_test(void)
{
    int num = 11891;
    int result = minMaxDifference(num);
    printf("Difference: %d\n", result); // Output: 99009
}
// Maximum Difference Between Increasing Elements 20250616
// we used 2 for loop. but somehow the editorial has 1 for loop method
/*
our submmission
int maximumDifference(int* nums, int numsSize) {
    int max =-1;
    int temp = 0;
    for(int i =0; i<numsSize; i++){
        for(int j = i+1; j<numsSize; j++){
            if(nums[j] > nums[i]){
                temp = nums[j] -nums[i];
                max = MAX(temp, max);
            }
        }
    }
    return max;
}
*/
// the way we want to learn, Approach: Prefix Minimum Value
// we knew the array is start form array index 0, so we fix the premin one. no
// need 2 for loop

int maximumDifference(int *nums, int numsSize)
{
    int premin = nums[0];
    int max = 0;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] > premin)
        {
            max = MAX(max, nums[i] - premin);
        }
        else
        {
            premin = nums[i];
        }
    }
    return max;
}

// Divide a String Into Groups of Size k, good example for string, 20250622
char **divideString(char *s, int k, char fill, int *returnSize)
{
    int n = strlen(s);
    int groupCount = (n + k - 1) / k; // total number of groups
    char **res = (char **)malloc(groupCount * sizeof(char *));
    *returnSize = groupCount;

    for (int i = 0; i < groupCount; ++i)
    {
        res[i] = (char *)malloc((k + 1) * sizeof(char)); // +1 for '\0'

        for (int j = 0; j < k; ++j)
        {
            int idx = i * k + j;
            if (idx < n)
            {
                res[i][j] = s[idx];
            }
            else
            {
                res[i][j] = fill;
            }
        }

        res[i][k] = '\0'; // null-terminate the string
    }

    return res;
}

char *largestGoodInteger(char *num)
{
    static char result[4] = ""; // 3 digits + null terminator
    char maxChar = 0;

    int len = strlen(num);
    for (int i = 0; i <= len - 3; i++)
    {
        if (num[i] == num[i + 1] && num[i] == num[i + 2])
        {
            if (num[i] > maxChar)
            {
                maxChar = num[i];
            }
        }
    }

    if (maxChar != 0)
    {
        result[0] = maxChar;
        result[1] = maxChar;
        result[2] = maxChar;
        result[3] = '\0';
    }
    else
    {
        result[0] = '\0';
    }

    return result;
}

int largestPerimeter(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), compfunc);

    for (int i = numsSize - 3; i >= 0; i--)
    {
        if (nums[i] + nums[i + 1] > nums[i + 2])
        {
            return nums[i] + nums[i + 1] + nums[i + 2];
        }
    }
    return 0;
}

void largestPerimeter_test(void)
{
    int arr[] = {2, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("largestPerimeter = %d\n", largestPerimeter(arr, n)); /* prints 5 */
}

/*


num = 9288;
printf("Max difference: %d\n", maxDiff(num)); // Output: 8700
*/
// int array[4] = {1, 5, 2, 10};
// printf("max:%d\n", maximumDifference(array, 4));

// char s[] = "abcdefg";
// int k = 3;
// char fill = '?';
// int returnSize;

// char **result = divideString(s, k, fill, &returnSize);

// for (int i = 0; i < returnSize; ++i) {
//   printf("\"%s\"\n", result[i]);
//   free(result[i]); // free each group
// }
// free(result); // free the array of pointers

// char test[] = "6777133339";
// char* ans = largestGoodInteger(test);
// printf("res: %s\n", ans);

#endif // LEETCODE_API_H