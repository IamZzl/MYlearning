/*
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int str[n];
    for (int i = 0; i < n; i++)
        scanf("%d", str + i);
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (str[j] < str[i])
            {
                min = j;
            }
        }
        if (min != i)
        {

            str[i] = str[i] ^ str[min];
            str[min] = str[i] ^ str[min];
            str[i] = str[i] ^ str[min];
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d ", str[i]);
}
*/

//Internet:
void selection_sort(int arr[], int len)
{
    int i, j, min, temp;
    for (i = 0; i < len - 1; i++)
    {
        min = i;
        for (j = i + 1; j < len; j++)
            if (arr[min] > arr[j])
                min = j;
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}