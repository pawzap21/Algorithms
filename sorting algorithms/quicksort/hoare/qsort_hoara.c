#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_arr(int* first, int* last){
    for(; first < last; first++){
        printf("%d\n", *first);
    }
}

int* partition_hoara(int* first, int* last){
    int x = *first;
    int* i = first - 1;
    int* j = last + 1;
    while(1){
        do{
            i++;
        } while(*i < x);

        do{
            j--;
        } while(*j > x);

        if(i >= j)
            return j;

        swap(i, j);
    }
}

void qsort_hoare(int* first, int* last){
    if(first < last){
        int* div = partition_hoara(first, last);
        qsort_hoare(first, div);
        qsort_hoare(div + 1, last);
    }
}

int main(){
    int tab[10] = {0, 1, 6, 123, 36, 27, 2345, 7564, 2, 10};
    srand(time(NULL));
    print_arr(tab, tab + 10);
    printf("\n");
    qsort_hoare(tab, tab + 9);
    print_arr(tab, tab + 10);
    return 0;
}