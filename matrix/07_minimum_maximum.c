/**
 * This file is part of gsl-examples.
 */

/**
 * double gsl_matrix_min (const gsl_matrix * m)
 *   This function returns the minimum value in the matrix m.
 */

/**
 * double gsl_matrix_max (const gsl_matrix * m)
 *   This function returns the maximum value in the matrix m.
 */

/**
 * void gsl_matrix_minmax (const gsl_matrix * m, double * min_out,  double * max_out)
 *   This function returns the minimum and maximum values in the matrix m, storing
 *   them in min_out and max_out.
 */

#include <stdio.h>
#include <math.h>
#include <gsl/gsl_matrix.h>

int
main (void)
{
  size_t i, j, n = 100;
  double min, max, min_out, max_out, k = 0.0, l = 0.0;
  gsl_matrix * m = gsl_matrix_alloc (n, n);

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      gsl_matrix_set (m, i, j, sin(i) + cos(j));

  min = gsl_matrix_min (m);
  max = gsl_matrix_max (m);

  gsl_matrix_minmax (m, &min_out, &max_out);

  // Minimum is -1.99995, and min and min_out are equal.
  k += min - min_out;

  // Maximum is 1.99991, and max and max_out are equal.
  l += max - max_out;

  gsl_matrix_free (m);

  printf ("difference k = %g (should be zero)\n", k);
  printf ("difference l = %g (should be zero)\n", l);

  return 0;
}
