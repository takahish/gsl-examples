/**
 * This file is part of gsl-examples.
 */

/**
 * gsl_vector_view gsl_matrix_colum (gsl_matrix * m, size_t j)
 * gsl_vector_const_view gsl_matrix_const_column (const gsl_matrix * m, size_t j)
 *   These functions retrun a vector view of the j-th column of the matrix m. The data
 *   pointer of the new vector is set to null if j is out of range.
 *   The function gsl_vector_const_column is equivalent to gsl_matrix_column but
 *   can be used for matrices which are declared const.
 */

/**
 * float gsl_blas_snrm2 (const gsl_vector_float * x)
 * double gsl_blas_dnrm2 (const gsl_vector * x)
 *  These functions compute the Euclidean norm of ||x|| = root(sigma x_i^2) of the vector x.
 */

#include <math.h>
#include <stdio.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>

int
main (void)
{
  size_t i, j;

  gsl_matrix *m = gsl_matrix_alloc (10, 10);

  for (i = 0; i < 10; i++)
    for (j = 0; j < 10; j++)
      gsl_matrix_set (m, i, j, sin (i) + cos (j));

  for (j = 0; j < 10; j++)
    {
      gsl_vector_view column = gsl_matrix_column (m, j);
      double d;

      d = gsl_blas_dnrm2 (&column.vector);

      printf ("matrix column %zu, norm = %g\n", j, d);
    }

  gsl_matrix_free (m);

  return 0;
}
