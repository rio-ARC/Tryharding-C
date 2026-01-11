#include <stdio.h>

void traverseArr(int *ptr, int N, int M){
    int i,j;
    for(i=0; i<N;i++){
        for(j=0;j<M;j++){
            printf("%d ", *((ptr+i*M)+j));

        }
        printf("\n");
    }

}

int main(){
    
    int N = 3, M = 2;

    // A 2D array
    int arr[][2] = { { 1, 2 }, { 3, 4 }, { 5, 6 } };

    // Function Call
    traverseArr((int*)arr, N, M);
    return 0;
}