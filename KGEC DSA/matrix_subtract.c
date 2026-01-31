#include <stdio.h>
int main(){
    int r,c;
    printf("Enter rows and columns of matrix: ");
    scanf("%d %d", &r, &c);
    int a[r][c], b[r][c], s[r][c];
    printf("Enter elements of matrix A:\n");
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d ", &a[i][j]);
    printf("Enter elements of matrix B:\n");
    for(int i=0; i<r; i++) for(int j=0; j<c; j++) scanf("%d ", &b[i][j]);
    printf("Difference of matrices A and B:\n");
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            s[i][j] = a[i][j] - b[i][j];
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }
    return 0;
}