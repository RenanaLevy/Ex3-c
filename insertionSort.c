#include <stdio.h>

#define SIZE 50

//This method moves the following i numbers one place to right.
void shift_element(int *arr, int i){
    while(i){
        --i;
        *(arr+(i+1)) = *(arr+i);
    }
}

//Insertion sort.
void insertion_sort(int *arr, int len){
    for(int i = 1; i < len; i++){
        int j = 0;
        while(*(arr + i) > *(arr + j)){
            j++;
        }
        if(arr + i != arr + j){
            int temp = *(arr + i);
            shift_element(arr + j, i-j);
            *(arr + j) = temp;
        }
    }
}

//Main.
void print_arr(int *arr){
    //printf("[");
    for(int i = 0; i < 50; i++){
        if(i == 49){
            printf("%d", *(arr+49));
        }
        else{
            printf("%d,", *(arr+i));
        }
    }
    printf("\n");
}

int main(){
    int arr[SIZE];
    for(int i = 0; i < SIZE; i++){
        //printf("please insert: ");
        scanf(" %d", (arr+i));
    }
    //print_arr(arr);
    insertion_sort(arr, 50);
    print_arr(arr);
}