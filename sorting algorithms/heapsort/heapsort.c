#include <stdio.h>
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int *tab, int n, int i){
    int max=i;
    int l=2*i+1;
    int r=2*i+2;
    if (l<n && *(tab+l)>*(tab+max))
        max=l;
    if (r<n && *(tab+r)>*(tab+max))
        max=r;
    if (max!=i){
        swap((tab+max),(tab+i));
        heapify(tab,n,max); 
    }
}
void array_print(int *tab, int n){
    for (int i=0; i < n; i++)
        printf("%d ",*(tab+i));
    printf("\n");
}
void heapsort(int *tab, int n){
    for(int i=(n/2)-1;i>=0;i--)
        heapify(tab,n,i);
    for (int i=n-1; i>0;i--){
        swap((tab+i),tab);
        heapify(tab,i,0);
    }
    
}
int main(){
    int tab[8]={6,4,2,0,8,9,13,10};
    heapsort(tab,8);
    array_print(tab,8);
    return 0;
}