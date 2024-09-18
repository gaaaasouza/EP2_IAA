#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include "utils.h"

void InsertionSort(int * v, int fim){ 
  
    int i, j, chave; 
   
    for(j = 1; j < fim + 1; j++){ 
        chave = v[j]; 
        for(i = j-1; i >= 0 && v[i] > chave; i--){ 
            v[i+1] = v[i]; 
        } 
        v[i+1] = chave; 
    } 
} 
 
void Merge(int* v, int ini, int m, int f){ 
 
    int* aux = (int*) malloc(sizeof(int)*(f+1)); 
    int j = m+1; 
    int i = ini; 
    int p;
 
    for(p = 0; i <= m && j <= f; p++){ 
        if(v[i] <= v[j]){ 
            aux[p] = v[i]; 
            i++; 
        }else{ 
            aux[p] = v[j]; 
            j++; 
        } 
    } 
        
    while(i <= m){ 
        aux[p] = v[i]; 
        i++; 
        p++; 
    } 
            
    while(j <= f){ 
        aux[p] = v[j]; 
        j++; 
        p++; 
    }

    for(p = 0, i = ini; i <= f; p++, i++){ 
        v[i] = aux[p]; 
    }

}
 
void MergeSort(int* A, int inicio, int fim){

    int metade;

    if(fim > inicio){ 
        metade = ((inicio + fim)/2); 
        MergeSort(A, inicio, metade); 
        MergeSort(A, metade+1, fim); 
        Merge(A, inicio, metade, fim); 
    } 
}