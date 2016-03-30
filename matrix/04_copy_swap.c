/**
 * This file is part of gsl-examples.
 */

/**
 * int gsl_matrix_memcpy (gsl_matrix * dest, const gsl_matrix * src)
 *   This function copies the elements of the matrix src into the matrix dest. The two
 *   matrices must have the same size.
 */

/**
 * int gsl_matrix_swap (gsl_matrix * m1, gsl_matrix * m2)
 *   This function exchanges the elements of the matrices m1 and m2 by copying. The
 *   two matrices must have the same size.
 */

#include <stdio.h>
#include <math.h>
#include <gsl/gsl_matrix.h>

int
main (void)
{
  size_t i, j;
  size_t n = 100;

  gsl_matrix * a = gsl_matrix_alloc (n, n);
  gsl_matrix * b = gsl_matrix_alloc (n, n);
  gsl_matrix * c = gsl_matrix_alloc (n, n);

  double aij = 0.0, bij = 0.0, cij = 0.0, k = 0.0, l = 0.0;

  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
        {
          gsl_matrix_set (a, i, j, sin(i));
          gsl_matrix_set (c, i, j, cos(j));
        }
    }

  gsl_matrix_memcpy (b, a);

  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
        {
          aij = gsl_matrix_get (a, i, j);
          bij = gsl_matrix_get (b, i, j);
          k += (bij - aij);
        }
    }

  gsl_matrix_swap (b, c);

  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
        {
          aij = gsl_matrix_get (a, i, j);
          cij = gsl_matrix_get (c, i, j);
          l += (cij - aij);
        }
    }

  gsl_matrix_free (a);
  gsl_matrix_free (b);
  gsl_matrix_free (c);

  printf ("differences k = %g (should be zero)\n", k);
  printf ("differences l = %g (should be zero)\n", l);

  return 0;
}
