
//Surya Merin Philip
//S3D
//51
#include <stdio.h>

int merge(int a[], int l, int m, int r) {
    int i, j, k;
    i = l;
    k = 0;
    j = m+1;
    int temp, b[100];
    while (i<=m && j<=r) {
        if (a[i]<a[j]) {
            b[k++] = a[i];
            i++;
        } else {
            b[k++] = a[j];
            j++;
        }
    }
    while (i<=m) {
        b[k++] = a[i++];
    }
    while (j<=r) {
        b[k++] = a[j++];
    }
    for (i=l; i<=r; i++) {
        a[i] = b[i-l];
    }
}
int mergeSort(int a[], int l, int r) {
    if (l<r) {
        int m = l+(r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        
        merge(a, l, m, r);
    }
}
int printArray(int a[], int size) {
    int i=0;
    for (i=0; i<size; i++) {
        printf("%d\n", a[i]);
    }
}
int main() {
    int i, a[100], size;
    printf("Enter size of the array : ");
    scanf("%d", &size);
    printf("Enter array\n");
    for (i=0; i<size; i++) {
        scanf("%d", &a[i]);
    }
    mergeSort(a, 0, size-1);
    printf("\nSorted Array\n");
    printArray(a, size);
}
OUTPUT
Enter size of the array : 5
Enter array
8
4
1
6
3

Sorted Array
1
3
4
6
8
