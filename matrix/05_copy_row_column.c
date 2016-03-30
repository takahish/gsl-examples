/**
 * This file is part of gsl-examples.
 */

/**
 * int gsl_matrix_get_row (gsl_vector * v, const gsl_matrix * m, size_t i)
 *   This function copies the elements of the i-th row of the matrix m into the vector v.
 *   The length of the vector must be the same as the length of the row.
 */

/**
 * int gsl_matrix_get_col (gsl_vector * v, const gsl_matrix * m, size_t, j)
 *   This function copies the elements of the j-th column of the matrix m into the vector
 *   v. The length of the vector must be the same as the length of the column.
 */

/**
 * int gsl_matrix_set_row (gsl_matrix * m, size_t i, const gsl_vector * v)
 *   This function copies the elements of the vector v into the i-th row of the matrix m.
 *   The length of the vector must be the same as the length of the row.
 */

/**
 * int gsl_matrix_set_col (gsl_matrix * m, size_t j, const gsl_vector * v)
 *   This function copies the elements of the vector v into the j-th column of the matrix
 *   m. The length of the vector must be the same as the length of the column.
 */

#include <stdio.h>
#include <math.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>

int
main (void)
{
  size_t i, j;
  size_t n = 100;

  gsl_vector * v = gsl_vector_alloc (n);
  gsl_vector * u = gsl_vector_alloc (n);
  gsl_matrix * m = gsl_matrix_alloc (n, n);

  double vj, ui, mij, k = 0.0, l = 0.0;

  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
        {
          gsl_matrix_set (m, i, j, sin(i) + cos(j));
        }
    }

  gsl_matrix_get_row (v, m, 63);

  for (j = 0; j < n; j++)
    {
      vj = gsl_vector_get (v, j);
      mij = gsl_matrix_get (m, 63, j);
      k += (mij - vj);
    }

  gsl_matrix_get_col (u, m, 63);

  for (i = 0; i < n; i++)
    {
      ui = gsl_vector_get (u, i);
      mij = gsl_matrix_get (m, i, 63);
      l += (mij - ui);
    }

  gsl_matrix_set_row (m, 36, v);

  // Vector v and row[36] (row[63]) are equal.
  for (j = 0; j < n; j++)
    {
      vj = gsl_vector_get (v, j);
      mij = gsl_matrix_get (m, 36, j);
      k += (mij - vj);
    }

  gsl_matrix_set_col (m, 36, u);

  // Vector u and col[36] (col[63]) are equal.
  for (i = 0; i < n; i++)
    {
      ui = gsl_vector_get (u, i);
      mij = gsl_matrix_get (m, i, 36);
      l += (mij - ui);
    }

  gsl_vector_free (v);
  gsl_vector_free (u);
  gsl_matrix_free (m);

  printf ("differences k = %g (should be zero)\n", k);
  printf ("differences l = %g (should be zero)\n", l);

  return 0;
}
