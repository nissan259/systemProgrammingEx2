#include "my_mat.h"
#include <stdio.h>
void A(int matrix[Matrix_Size][Matrix_Size])
//void A(int *matrix)
{
       for(int i=0;i<Matrix_Size;i++)
    {
                     //   printf("guy\n");

        for (int  j = 0; j < Matrix_Size; j++)
        {
                scanf("%d",&matrix[i][j]);   
        }  
    }
}
void check (int dist[Matrix_Size][Matrix_Size],char check_char) {
    int work_matrix[Matrix_Size][Matrix_Size];

    // Initialize work_matrix with infint values
    for (int i = 0; i < Matrix_Size; i++) {
        for (int j = 0; j < Matrix_Size; j++) {
            work_matrix[i][j] = infint;
        }
    }

    // Copy non-zero values from dist to work_matrix
    for (int i = 0; i < Matrix_Size; i++) {
        for (int j = 0; j < Matrix_Size; j++) {
            if (dist[i][j] != 0) {
                work_matrix[i][j] = dist[i][j];
            }
            if (i == j) {
                work_matrix[i][j] = 0;
            }
        }
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < Matrix_Size; k++) {
        for (int i = 0; i < Matrix_Size; i++) {
            for (int j = 0; j < Matrix_Size; j++) {
                if (work_matrix[i][j] > (work_matrix[i][k] + work_matrix[k][j])
                    && (work_matrix[k][j] != infint && work_matrix[i][k] != infint))
                    work_matrix[i][j] = work_matrix[i][k] + work_matrix[k][j];
            }
        }
    }
    int i,j=0;
     scanf("%d",&i);
        scanf("%d",&j);
        if (check_char=='B')
        {
             if(work_matrix[i][j]==infint||work_matrix[i][j]==0)
 {
        printf("False\n");
 }
        else
        {
          printf("True\n");
        }
        }
            if (check_char=='C')
        {
             if(work_matrix[i][j]==infint||work_matrix[i][j]==0)
 {
        printf("-1\n");
 }
        else
        {
          printf("%d\n",work_matrix[i][j]);
        }
        }
    //         for(int i=0;i<Matrix_Size;i++)
    // {
    //     for (int  j = 0; j < Matrix_Size; j++)
    //     {
    //             printf("%d",work_matrix[i][j]);   
    //     }  
    // }
}