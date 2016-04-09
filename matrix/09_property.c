/**
 * This file is part of gss-examples.
 */

/**
 * int gsl_matrix_isnull (const gsl_matrix * m)
 * int gsl_matrix_ispos (const gsl_matrix * m)
 * int gsl_matrix_isneg (const gsl_matrix * m)
 * int gsl_matrix_isnonneg (const gsl_matrix * m)
 *   These functions return 1 if all the elements of the matrix m are zero, strictly positive,
 *   strictly negative, or non-negative respectively, and 0 otherwise. To test whether a
 *   matrix is positive-definite, use the Cholesky decomposition.
 */

/**
 * gsl_matrix_equal (const gsl_matrix * a, const gsl_matrix * b)
 *   This function returns 1 if the matrices a and b are equal (by comparison of element
 *   values) and 0 otherwise.
 */

#include <stdio.h>
#include <math.h>
#include <gsl/gsl_matrix.h>

int
main (void)
{
  int i, j, k = 0;
  size_t n = 100;

  gsl_matrix * a = gsl_matrix_alloc (n, n);
  gsl_matrix * b = gsl_matrix_alloc (n, n);
  gsl_matrix * c = gsl_matrix_alloc (n, n);

  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
        {
          gsl_matrix_set (a, i, j, 0.0);
          gsl_matrix_set (b, i, j, sin(i) + cos(j) + 3.0);
          gsl_matrix_set (c, i, j, -1.0 * (sin(i) + cos(j) + 3.0));
        }
    }

  // All the elements of a are zero (null).
  k += gsl_matrix_isnull (a);

  // All the elements of b are positive.
  k += gsl_matrix_ispos (b);

  // All the elements of c are negative.
  k += gsl_matrix_isneg (c);

  // All the elements of b are non-negative (zero).
  k += gsl_matrix_isnonneg (b);

  // The elements of c are multiplied by -1.0.
  // The matrix b and c are equal.
  gsl_matrix_scale (c, -1.0);
  k += gsl_matrix_equal (b, c);

  gsl_matrix_free (a);
  gsl_matrix_free (b);
  gsl_matrix_free (c);

  printf ("k = %d (should be 5)\n", k);

  return 0;
}
