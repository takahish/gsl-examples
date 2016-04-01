/**
 * This file is part of gsl-examples.
 */

/**
 * void gsl_matrix_min_index (const gsl_matrix * m, size_t * imin, size_t * jmin)
 *   This function returns the indices of the minimum value in the matrix m, storing them
 *   in imin and jmin. When there are several equal minimum elements then the first
 *   element found is returned searching in row-major order.
 */

/**
 * void gsl_matrix_max_index (const gsl_matrix * m, size_t * imax, size_t * jmax)
 *   This function returns the indices of the maximum value in the matrix m, storing them
 *   in imax and jmax. When there are several equal maximum elements then the first
 *   element found is returned, searching in row-major order.
 */

/**
 * void gsl_matrix_minmax_index (const gsl_matrix * m, size_t * imin, size_t * jmin, size_t * imax, size_t * jmax)
 *   This function returns the indices of the minimum and maximum values in the matrix
 *   m, storing them in (imin, jmin) and (imax, jmax). When there are several equal minimum
 *   or maximum elements then the first elements found are returned, searching in
 *   row-major order.
 */

#include <stdio.h>
#include <math.h>
#include <gsl/gsl_matrix.h>

int
main (void)
{
  size_t i, j, n = 100;
  size_t imin_1, jmin_1, imax_1, jmax_1, imin_2, jmin_2, imax_2, jmax_2;
  double min_1, max_1, min_2, max_2, k = 0.0, l = 0.0;
  gsl_matrix * m = gsl_matrix_alloc (n, n);

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      gsl_matrix_set (m, i, j, sin(i) + cos(j));

  gsl_matrix_min_index (m, &imin_1, &jmin_1);
  gsl_matrix_max_index (m, &imax_1, &jmax_1);

  min_1 = gsl_matrix_get (m, imin_1, jmin_1);
  max_1 = gsl_matrix_get (m, imax_1, jmax_1);

  gsl_matrix_minmax_index (m, &imin_2, &jmin_2, &imax_2, &jmax_2);

  min_2 = gsl_matrix_get (m, imin_2, jmin_2);
  max_2 = gsl_matrix_get (m, imax_2, jmax_2);

  // Minimum is -1.99995, and min_1 and min_2 are equal.
  k += min_1 - min_2;

  // Maximum is 1.99991, and max_1 and max_2 are equal.
  l += max_1 - max_2;

  gsl_matrix_free (m);

  printf ("difference k = %g (should be zero)\n", k);
  printf ("difference l = %g (should be zero)\n", l);

  return 0;
}
