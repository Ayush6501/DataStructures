#include <stdio.h>

void AcceptMatrix(int mat1[20][20], int r, int c)
{
    printf("\nEnter the matrix elements: ");
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
}

void DisplayMatrix(int mat1[20][20], int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }
}

void SparseMatrix(int mat1[20][20], int sparse[20][20], int r, int c)
{
    int zeroes = 0, r1 = 1;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(mat1[i][j] == 0)
            {
                zeroes+= 1;
            }
        }
    }
    if (zeroes > (r*c)/2)
    {
        printf("\nThe no. of zeroes is: %d", zeroes);
        printf("\nThe matrix is a Sparse matrix.\n");
        sparse[0][0] = r;
        sparse[0][1] = c;
        sparse[0][2] = (r*c) - zeroes;
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(mat1[i][j] != 0)
                {
                    sparse[r1][0] = i;
                    sparse[r1][1] = j;
                    sparse[r1][2] = mat1[i][j];
                    r1++;
                }
            }
        }
        DisplayMatrix(sparse, r1, 3);
    }
    else
    {
        printf("\nThe no. of zeroes is: %d", zeroes);
        printf("\nThe matrix is not a Sparse matrix");
    }
}

void TransposeMatrix(int sparse[20][20], int transpose[20][20])
{
    int i,j,k,n;
	transpose[0][0] = sparse[0][1];
	transpose[0][1] = sparse[0][0];
	transpose[0][2] = sparse[0][2];
	
	k = 1;
	n = sparse[0][2];
	
	for(i = 0; i < sparse[0][1]; i++)
    {
		for(j = 1; j <= n; j++)
        {
			if(i == sparse[j][1])
			{
				transpose[k][0] = i;
				transpose[k][1] = sparse[j][0];
				transpose[k][2] = sparse[j][2];
				k++;
			}
        }
    }
    DisplayMatrix(transpose, k, 3);
}

void FastTranspose(int sparse[20][20], int ftranspose[20][20])
{
    int i, j;
    const int column = sparse[0][1];

    ftranspose[0][0] = sparse[0][1];
	ftranspose[0][1] = sparse[0][0];
	ftranspose[0][2] = sparse[0][2];
    int s[20];
    int t[20];
    int q = sparse[0][2];

    for (i = 0; i < column; i++)
    {
        s[i] = 0;
    }

    for (i = 1; i <= q; i++)
    {
        s[sparse[i][1]] = s[sparse[i][1]] + 1;
    }

    t[0] = 1;

    for (i = 1; i <= column; i++)
    {
        t[i] = t[i - 1] + s[i - 1];
    }

    for (i = 1; i <= q; i++)
    {
        j = sparse[i][1];

        ftranspose[t[j]][0] = sparse[i][1];
        ftranspose[t[j]][1] = sparse[i][0];
        ftranspose[t[j]][2] = sparse[i][2];
        t[j] = t[j] + 1;
    }
    for (i = 0; i <= q; i++)
    {
        printf("%d %d %d\n", ftranspose[i][0], ftranspose[i][1], ftranspose[i][2]);
    }
}

int main()
{
    int row, column, choice, r1 = 1;
    int sparsematrix[20][20], matrix1[20][20], transpose[20][20], ftranspose[20][20];
    do 
    {
        printf("\n***** MENU *****");
        printf("\n1. Accept Matrix \n2. Display Matrix \n3. Sparse Matrix\n4. Transpose Matrix\n5. Fast Transpose\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            printf("Enter no. of rows and columns: ");
            scanf("%d %d", &row, &column);
            AcceptMatrix(matrix1, row, column);
            break;

            case 2:
            DisplayMatrix(matrix1, row, column);
            break;

            case 3:
            SparseMatrix(matrix1, sparsematrix, row, column);
            break;

            case 4:
            TransposeMatrix(sparsematrix, transpose);
            break;

            case 5:
            FastTranspose(sparsematrix, ftranspose);
            break;
        }
    }while (choice != 6);
    return 0;
}


