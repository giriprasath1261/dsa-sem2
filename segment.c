#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = (ss+se)/2;
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}

int *constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    int *st = new int[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}


int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *st = constructST(arr, n);
    // printf("Sum of values in given range = %dn",
            // getSum(st, n, 1, 3));
    // updateValue(arr, st, n, 1, 10);
    // printf("Updated sum of values in given range = %dn",
             // getSum(st, n, 1, 3));
    return 0;
}
