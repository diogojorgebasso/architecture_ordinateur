#include<stdlib.h>
#include <stdio.h>
#include <time.h>
#include"printing_timing.c"

#define R 10000
#define T 100000000


void binarySearch(int arr[], int left, int right, int key) {

    while (left <= right) {

        // calculating mid point
        int mid = left + (right - left) / 2;

        // Check if key is present at mid
        if (arr[mid] == key) {
            break;
        }

        if (arr[mid] < key) {
            left = mid + 1;
        }

        else {
            right = mid - 1;
        }
    }
}


void printTable(int tab[], int N){
    for(int i=0; i<N; i++){
        printf("%d", &tab[i]);
    }
}

int main(void){
    srand(time(NULL)); //should be called just once.

    int N = 1048576;
    int tab[N];
    int req[R];
    for (int i=0; i<R; i++){
        int r = rand()% (T + 1);
        req[i]= r;
    }

    for (int i=0; i<N; i++){
        int r = rand()% (T + 1);
        tab[i]= r;
    }

    for(int i=0; i<N-1; i++){
        if(tab[i+1]<tab[i]){
            int tmp = tab[i+1];
            tab[i+1] = tab[i];
            tab[i]=tmp;
        }
    }

    void binarySearchCaller(int key){
        binarySearch(req, 0, R-1, key);
    }

    int medium = 0;
    for(int i=0; i<R; i++){
        medium+=return_timing(req[i], binarySearchCaller, 5, 100);
    }
    printf("%d", medium/R);

    return 0;
}