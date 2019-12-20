#include <stdio.h>
void combinationUtil(int arr[], int data[], int start, int end, int index, int r);
  
//http://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/
 
/*
17 NROS MAS SALIDORES: 01-02-04-05-06-08-09-10-11-23-24-28-31-36-37-40-42
 
*/
 
void printCombination(int arr[], int n, int r)
{
    int data[r]; 
    combinationUtil(arr, data, 0, n-1, 0, r);
}
  
void combinationUtil(int arr[], int data[], int start, int end, int index, int r){
    if (index == r)
    {
        for (int j=0; j<r; j++)
            printf("%d,", data[j]);
        printf("\n");
        return;
    }
  
    for (int i=start; i<=end && end-i+1 >= r-index; i++){
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}
  
int main(){
    int arr[] = {00,01,02,03,04,05,06,07,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45};
    int r = 6; //El numero 6 es la cantidad de numeros que tiene el juego, para el Loto5 y Megabola, poner 5.
    int n = sizeof(arr)/sizeof(arr[0]);    
    printCombination(arr, n, r);
}
