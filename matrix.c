#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct
{
    int nrows;
    int ncols;
    int *data;
} matrix;


matrix* create_matrix(int nrows, int ncols)
{
    if (nrows < 1 || ncols < 1)
        return NULL;

    matrix* mtx = malloc(sizeof(matrix));
    if (mtx == NULL)
        return NULL;
    mtx->nrows = nrows;
    mtx->ncols = ncols;
    mtx->data = malloc(sizeof(int) * nrows * ncols);
    if (mtx->data == NULL)
        return NULL;

    return mtx;
}


int delete_matrix(matrix *mtx)
{
    if (mtx == NULL)
        return -1;

    free(mtx->data);
    free(mtx);
    return 0;
}


int print_matrix(matrix *mtx)
{
    if (!mtx)
        return -1;

    int i;
    for (i = 0; i < mtx->nrows * mtx->ncols; i++)
    {
        if (i != 0 && i % mtx->ncols == 0)
            printf("\n");
        printf("%i ", mtx->data[i]);
    }
    printf("\n\n");
    return 0;
}


int sum_matrices(matrix *mtx1, matrix *mtx2, matrix *sum)
{
    if (mtx1->nrows != mtx2->nrows 
        || mtx1->ncols != mtx2->ncols
        || sum->nrows != mtx1->nrows
        || sum->ncols != mtx1->ncols)
        return -1;

    int i;
    for (i = 0; i < mtx1->nrows * mtx1->ncols; i++)
        sum->data[i] = mtx1->data[i] + mtx2->data[i];
    return 0;
}


int transpose_matrix(matrix *in, matrix *out)
{
    if (!in || !out
        || in->nrows != out->ncols
        || in->ncols != out->nrows)
        return -1;

    int i;
    for (i = 0; i < in->nrows * in->ncols; i++)
    {
        //i / ncols is the row number, where as i % ncols is the column number
        //by multiplying the row number by the number of columns and adding the the column number
        //the index, i, is retrieved again
        //if instead, the column number is multiplied by the number of rows the index of the element
        //in the transposed matrix is retrieved.
        
        //out->data[(i % in->ncols)*out->ncols + i / in->ncols] = in->data[(i / in->ncols)*in->ncols + i % in->ncols];
        out->data[(i % in->ncols)*in->nrows + i / in->ncols] = in->data[i];
    }
    return 0;
}


int identity_matrix(matrix *mtx)
{
    if (!mtx || mtx->nrows != mtx->ncols)
        return -1;

    int i;
    for (i = 0; i < mtx->nrows * mtx->ncols; i++)
    {
        if (i / mtx->nrows == i % mtx->ncols)
            mtx->data[i] = 1;
        else
            mtx->data[i] = 0;
    }
    return 0;
}

int index_matrix(matrix *mtx)
{
    if (!mtx)
        return -1;

    int i;
    for (i = 0; i < mtx->nrows * mtx->ncols; i++)
    {
        mtx->data[i] = i;
    }
    return 0;
}


int random_matrix(matrix *mtx)
{
    if (!mtx) return -1;

    int i, randnum;
    for (i = 0; i < mtx->nrows * mtx->ncols; i++)
    {
        randnum = (rand() % 10);
        mtx->data[i] = randnum;
    }
    return 0;
}


int dot_product(matrix *vec1, matrix *vec2)
{
    if (!vec1 || !vec2
        || vec1->nrows != 1
        || vec2->ncols != 1)
        return -1;

    int i, result = 0;
    for (i = 0; i < vec1->nrows * vec1->ncols; i++)
    {
        result += vec1->data[i] * vec2->data[i];
    }
    return result;
}


int main(void)
{
    srand(time(NULL));

    matrix *m1 = create_matrix(2, 3);
    matrix *m2 = create_matrix(3, 2);
    matrix *v1 = create_matrix(3, 1);
    matrix *v2 = create_matrix(1, 3);

    random_matrix(v1);
    random_matrix(v2);
    transpose_matrix(v1, v2);
    print_matrix(v1);
    print_matrix(v2);
    printf("%i\n", dot_product(v1, v2));

    delete_matrix(m1);
    delete_matrix(m2);
    delete_matrix(v1);
    delete_matrix(v2);
    return 0;
}
