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
        printf("%i ", mtx->data[i]);
        if (i % mtx->nrows == mtx->nrows - 1)
            printf("\n");
    }
    printf("\n");
    return 0;
}


int add_matrices(matrix *m1, matrix *m2)
{
    if (m1->nrows != m2->nrows || m1->ncols != m2->ncols)
        return -1;

    int i;
    for (i = 0; i < m1->nrows * m1->ncols; i++)
        m1->data[i] += m2->data[i];
    return 0;
}


int scale_matrix(matrix *mtx, int scaler)
{
    if (!mtx) return -1;

    int i;
    for (i = 0; i < mtx->nrows * mtx->ncols; i++)
        mtx->data[i] *= scaler;
    return 0;
}


int identity_matrix(matrix *mtx)
{
    if (!mtx || mtx->nrows != mtx->ncols) return -1;

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


int main(void)
{
    srand(time(NULL));

    matrix *m1 = create_matrix(2, 2);
    matrix *m2 = create_matrix(2, 2);
    matrix *m3 = create_matrix(3, 3);

    random_matrix(m1);
    random_matrix(m2);
    print_matrix(m1);
    print_matrix(m2);

    add_matrices(m1, m2);
    print_matrix(m1);

    scale_matrix(m1, 2);
    print_matrix(m1);

    identity_matrix(m2);
    print_matrix(m2);

    random_matrix(m3);
    scale_matrix(m3, 9);
    print_matrix(m3);

    delete_matrix(m1);
    delete_matrix(m2);
    delete_matrix(m3);
    return 0;
}
