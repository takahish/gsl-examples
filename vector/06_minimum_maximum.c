/**
 * This file is part of gsl-examples.
 */

/**
 * double gsl_vector_min (const gsl_vector * v)
 *   This function returns the minimum value in the vector v.
 */

/**
 * double gsl_vector_max (const gsl_vector * v)
 *   This function returns the maximum value in the vector v.
 */

/**
 * void gsl_vector_minmax (const gsl_vector * v, double * min_out, double * max_out)
 *   This function returns the minimum and maximum values in the vector v, storing
 *   them in min_out and max_out.
 */

#include <stdio.h>
#include <gsl/gsl_vector.h>

int
main (void)
{
  int i = 0;
  double min, max, min_out, max_out, k = 0.0;
  size_t n = 100;

  gsl_vector * v = gsl_vector_alloc (n);

  for (i = 0; i < n; i++)
    {
      gsl_vector_set (v, i, 1.23 + i);
    }

  min = gsl_vector_min(v);
  max = gsl_vector_max(v);

  gsl_vector_minmax(v, &min_out, &max_out);

  k += (min - min_out);
  k += (max - max_out);

  gsl_vector_free(v);

  printf("difference = %g (should be zero)\n", k);

  return 0;
}
