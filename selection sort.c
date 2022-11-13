#include <stdio.h>
int main()
{
    int array[100], n, i, j, position, t;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    for (i = 0; i< (n - 1); i++) // finding minimum element (n-1) times
    {
        position = i;
        for (j = i + 1; j < n; j++)
        {
            if (array[position] > array[j])
            position = j;
        }
        if (position != i)
        {
            t = array[i];
            array[i] = array[position];
            array[position] = t;
        }
    }
    printf("Sorted list in order:\n");
    for (i = 0; i < n; i++)
        printf("%d\n", array[i]);
    return 0;
}
