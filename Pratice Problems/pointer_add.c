#include <stdio.h>

int main(){

    int n=10;
    int arr[]= {1,2,3,4,5,78,90,54,33,21};
    int *ptr;
    ptr=arr;
    int odd=0; 
    int even=0;
    for(int i=0; i<n; i++){
        if(*ptr%2==0)
        even++;
        else
        odd++;
        *ptr++;
    }
    printf("No of Even elements: %d\n", even);
    printf("No of odd elements: %d\n", odd);
    return 0;

}