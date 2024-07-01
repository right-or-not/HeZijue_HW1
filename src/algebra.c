#include "algebra.h"
#include <stdio.h>
#include <math.h>

Matrix create_submatrix(Matrix a, int i, int j)
{
    int num = a.rows;
    Matrix b = create_matrix(num - 1, num - 1);
    int i_a, j_a, i_b, j_b;
    i_a = i_b = 0;
    while (i_a < num)
    {
        if (i_a == i)
            i_a++;
        else
        {
            j_a = j_b = 0;
            while (j_a < num)
            {
                if (j_a == j)
                    j_a++;
                else
                {
                    b.data[i_b][j_b] = a.data[i_a][j_a];
                    j_a++;
                    j_b++;
                }
            }
            i_a++;
            i_b++;
        }
    }
    return b;
}

void swap_rows(double data[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE], int row_1, int row_2, int col)
{
    double temp;
    for (int i = 0; i < col; i++)
    {
        temp = data[row_1][i];
        data[row_1][i] = data[row_2][i];
        data[row_2][i] = temp;
    }
}

Matrix create_matrix(int row, int col)
{
    Matrix m;
    m.rows = row;
    m.cols = col;
    return m;
}

Matrix add_matrix(Matrix a, Matrix b)
{
    // ToDo
    if (a.rows != b.rows || a.cols != b.cols)
    {
        printf("Error: Matrix a and b must have the same rows and cols.\n");
        return create_matrix(0, 0);
    }
    else
    {
        int rows = a.rows;
        int cols = a.cols;
        Matrix ans = create_matrix(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                ans.data[i][j] = a.data[i][j] + b.data[i][j];

        return ans;
    }
}

Matrix sub_matrix(Matrix a, Matrix b)
{
    // ToDo
    if (a.rows != b.rows || a.cols != b.cols)
    {
        printf("Error: Matrix a and b must have the same rows and cols.\n");
        return create_matrix(0, 0);
    }
    else
    {
        int rows = a.rows;
        int cols = a.cols;
        Matrix ans = create_matrix(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                ans.data[i][j] = a.data[i][j] - b.data[i][j];

        return ans;
    }
}

Matrix mul_matrix(Matrix a, Matrix b)
{
    // ToDo

    if (a.cols != b.rows)
    {
        printf("Error: The number of cols of matrix a must be equal to the number of rows of matrix b.\n");
        return create_matrix(0, 0);
    }
    else
    {
        int rows = a.rows;
        int cols = b.cols;
        int num = a.cols;
        Matrix ans = create_matrix(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                for (int k = 0; k < num; k++)
                {
                    if (k == 0)
                        ans.data[i][j] = a.data[i][k] * b.data[k][j];
                    else
                        ans.data[i][j] = ans.data[i][j] + a.data[i][k] * b.data[k][j];
                }

        return ans;
    }

    return create_matrix(0, 0);
}

Matrix scale_matrix(Matrix a, double k)
{
    // ToDo
    int rows = a.rows;
    int cols = a.cols;
    Matrix ans = create_matrix(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            ans.data[i][j] = a.data[i][j] * k;

    return ans;
}

Matrix transpose_matrix(Matrix a)
{
    // ToDo
    int rows = a.cols;
    int cols = a.rows;
    Matrix ans = create_matrix(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            ans.data[i][j] = a.data[j][i];

    return ans;
}

double det_matrix(Matrix a)
{
    // ToDo

    if (a.rows != a.cols)
    {
        printf("Error: The matrix must be a square matrix.\n");
        return 0;
    }
    else
    {
        int num = a.rows;
        int ans = 0;
        if (num == 1)
            ans = a.data[0][0];
        else
        {
            int i = 0;
            int j = 0;
            for (j = 0; j < num; j++)
            {
                Matrix b = create_submatrix(a, i, j);
                ans = ans + pow(-1, i + j) * a.data[i][j] * det_matrix(b);
            }
        }
    }
}

Matrix inv_matrix(Matrix a)
{
    // ToDo
    if (a.rows != a.cols)
    {
        printf("Error: The matrix must be a square matrix.\n");
        return create_matrix(0, 0);
    }
    else if (det_matrix(a) == 0)
    {
        printf("Error: The matrix is singular.\n");
        return create_matrix(0, 0);
    }
    else
    {
        Matrix ans = create_matrix(a.rows, a.cols);
        for (int i = 0; i < a.rows; i++)
            for (int j = 0; j < a.cols; j++)
            {
                ans.data[i][j] = pow(-1, i + j) * det_matrix(create_submatrix(a, j, i)) / det_matrix(a);
            }
        return ans;
    }
}

int rank_matrix(Matrix a)
{
    // ToDo

    int rank = 0;
    int rows, cols;
    double factor;

    rows = a.rows;
    cols = a.cols;
    rank = rows;
    if (cols < rows)
        rank = cols;

    for (int i = 0; i < rank; i++)
    {
        if (fabs(a.data[i][i]) < 1e-10)
        {
            int flag = 0;
            for (int j = i + 1; j < rows; j++)
            {
                if (fabs(a.data[j][i]) > 1e-10)
                {
                    swap_rows(a.data, i, j, cols);
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                rank = rank - 1;
                continue;
            }
        }

        for (int j = i + 1; j < rows; j++)
        {
            if (fabs(a.data[j][i]) > 1e-10)
            {
                factor = a.data[j][i] / a.data[i][i];
                for (int k = i; k < cols; k++)
                {
                    a.data[j][k] = a.data[j][k] - factor * a.data[i][k];
                }
            }
        }
    }
    return rank;
}

double trace_matrix(Matrix a)
{
    // ToDo

    if (a.rows != a.cols)
    {
        printf("Error: The matrix must be a square matrix.\n");
        return 0;
    }
    else
    {
        int ans = 0;
        for (int i = 0; i < a.rows; i++)
        {
            ans = ans + a.data[i][i];
        }
        return ans;
    }
}

void print_matrix(Matrix a)
{
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.cols; j++)
        {
            // 按行打印，每个元素占8个字符的宽度，小数点后保留2位，左对齐
            printf("%-8.2f", a.data[i][j]);
        }
        printf("\n");
    }
}