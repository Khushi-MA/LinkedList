#include <stdio.h>
void scanmatrix(int *A, int row, int column);
void printmatrix(int *A, int row, int column);
void multiplyMatrices(int *first, int *second, int *result, int r1, int c1, int r2, int c2);

int main()
{
    int matrix[50][50], result[50][50], row, column, row2, column2, i, j, newmat[50][50];
    printf("\nenter the numebr of rows:  ");
    scanf("%d", &row);
    printf("enter the number of columns  ");
    scanf("%d", &column);

    printf("\nenter the elements of matrrix:\n");
    scanmatrix(matrix, row, column);
    printf("\nmatrix is:");
    printmatrix(matrix, row, column);

    printf("\nenter another matrix with %d rows to multiply the previous one with", column);
    row2 = column;
    printf("\nenter the number of columns for the new matrix");
    scanf("%d", &column2);

    printf("\nrow2: %d, column2: %d", row2, column2);

    printf("\nenter elements of new matrix");
    scanmatrix(newmat, row2, column2);
    printf("\nnew matrix is:");
    printmatrix(newmat, row2, column2);

    multiplyMatrices(matrix, newmat, result, row, column, row2, column2);
    printf("\nmultiplied matrix:");
    printmatrix(result, row, column2);

    return 0;
}

void printmatrix(int *A, int row, int column)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        printf("\n");
        for (j = 0; j < column; j++)
        {
            printf("%d ", *((A + i) + j));
        }
    }
}

void scanmatrix(int *A, int row, int column)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            scanf("%d", ((A + i) + j));
        }
    }
}

// function to multiply two matrices
void multiplyMatrices(int *first, int *second, int *result, int r1, int c1, int r2, int c2)
{

    // Initializing elements of matrix mult to 0.
    for (int i = 0; i < r1; ++i)
    {
        for (int j = 0; j < c2; ++j)
        {
            *((result + i)+j) = 0;
        }
    }

    // Multiplying first and second matrices and storing it in result
    for (int i = 0; i < r1; ++i)
    {
        for (int j = 0; j < c2; ++j)
        {
            for (int k = 0; k < c1; ++k)
            {
                *((result + i) + j) += *((first + i) + j) * (*((second + i) + j));
            }
        }
    }
}
