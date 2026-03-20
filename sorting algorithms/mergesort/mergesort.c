#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int size1,int size2, int tab1[], int tab2[], int wynik[]){
    int merge_size=size1+size2;
    int merged[merge_size];
    int i=0, j=0,x=0;
    while (i<size1 && j<size2){
        if(tab1[i]<=tab2[j]){
            merged[x]=tab1[i];
            i++;
        }
        else{
            merged[x]=tab2[j];
            j++;
        }
        x++;
    }
    if(i==size1){
        for(int z=j;z<size2;z++){
            merged[x]=tab2[z];
            x++;
        }
    }
    else{
        for(int z=i;z<size1;z++){
            merged[x]=tab1[z];
            x++;
        }
    }
    for (int z=0; z<x;z++){
        wynik[z]=merged[z];
    }
}
void divide(int tab[], int a, int b) {
    if (a >= b) return; 
    int mid = a + (b - a)/ 2;
    int size1 = mid - a + 1;
    int size2 = b - mid;

    int tab1[size1], tab2[size2];

    for (int i = 0; i < size1; i++) {
        tab1[i] = tab[a + i];
    }
    for (int j = 0; j < size2; j++) {
        tab2[j] = tab[mid + 1 + j];
    }

    if (size1 > 1) {
        divide(tab1, 0, size1 - 1);
    }
 
    if (size2 > 1) {
        divide(tab2, 0, size2 - 1);
    }

   
    merge(size1, size2, tab1, tab2, tab);
}
void wypisz(int tab[],int rozmiar){
    for (int i=0; i<rozmiar; i++){
        printf("%d \n", tab[i]);
    }
}
int main(){
    srand(time(NULL));
    int n=50;
    int tab[n];
    for (int i=0; i<n;i++){
        tab[i]=rand();
    }
    int size=sizeof(tab)/sizeof(*(tab));
    int wynikowa[size];
    divide(tab,0,49);
    wypisz(tab,n);

    return 0;
}