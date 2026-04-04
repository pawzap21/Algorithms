#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* partition(int* first, int* last){
    int x = *last;
    int *i = first - 1;
    for(int *j = first; j < last; j++){
        if(*j <= x){
            i++;
            swap(i, j);
        }
    }
    swap((i + 1), last);
    return (i + 1);
}

void qsort_lomuto(int *first, int *last){
    int* q;
    if(first < last){
        q = partition(first, last);
        qsort_lomuto(first, q - 1);
        qsort_lomuto(q + 1, last);
    }
}

void print_arr(int *first, int *last){
    for(int *i = first; i < last; i++){
        printf("%d\n", *i);
    }
}

int main(){
    srand(time(NULL));
    int tab[10] = {2, 6, 1, 2, 8, 1, -8, 45, 12, 60};
    print_arr(tab, tab + 10);
    qsort_lomuto(tab, tab + 9); // Poprawka logiczna: last powinien wskazywać na ostatni element
    printf("\n Po sortowaniu:\n");
    print_arr(tab, tab + 10);
    return 0;
}