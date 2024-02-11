#include <stdio.h>
#include "my_mat.h" 

int main()
{
  int matrix[Matrix_Size][Matrix_Size];
      for(int i=0;i<Matrix_Size;i++)
    {
        for (int  j = 0; j < Matrix_Size; j++)
        {
        matrix[i][j]=0;
        }
    }
    char check_char;
    scanf ("%c",&check_char);
    // while (scanf("%c",&check_char)!='D')
     while (check_char!='D')
    {
      if(check_char=='A')
      {
       // printf("out\n");
        A(matrix);
        // printf("enter to A" );
      }
       if(check_char=='B')
       {
      //  printf("enter i and j\n");
        check(matrix,check_char);
    //   for(int i=0;i<Matrix_Size;i++)
    // {
    //     for (int  j = 0; j < Matrix_Size; j++)
    //     {
    //         printf("%d\n",matrix[i][j]);
    //     }

    // }
        // if(matrix[i][j]==infint||matrix[i][j]==0)
        // printf("False\n");
        // else
        // {
        //    printf("True\n");
        // }

       }
        if(check_char=='C')
       {
        check(matrix,check_char);       
       }

       scanf("%c",&check_char);
    }
}