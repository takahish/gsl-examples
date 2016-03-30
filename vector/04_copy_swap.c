/**
 * This file is part of gsl-examples.
 */

/**
 * int gsl_vector_memcpy (gsl_vector * dest, const gsl_vector * src)
 *   This function copies the elements of the vector src into the vector dest. The two
 *   vectors must have the same length.
 */

/**
 * int gsl_vector_swap (gsl_vector * v, gsl_vector * w)
 *   This function exchanges the elements of the vectors v and w by copying. The two
 *   vectors must have the same length.
 */

#include <stdio.h>
#include <gsl/gsl_vector.h>

int
main (void)
{
  int i = 0;
  double k = 0.0, l = 0.0;
  size_t n = 100;

  gsl_vector * v = gsl_vector_alloc (n);
  gsl_vector * a = gsl_vector_alloc (n);
  gsl_vector * b = gsl_vector_alloc (n);

  for (i = 0; i < n; i++)
    {
      gsl_vector_set (v, i, 1.23 + i);
    }

  gsl_vector_memcpy (a, v);

  for (i = 0; i < n; i++)
    {
      double vi = gsl_vector_get (v, i);
      double ai = gsl_vector_get (a, i);
      k += (vi - ai);
    }

  for (i = 0; i < n; i++)
    {
      gsl_vector_set (b, i, 0.0);
    }

  gsl_vector_swap (b, v);

  for (i = 0; i < n; i++)
    {
      double vi = gsl_vector_get(v, i);
      l += vi;
    }

  gsl_vector_free (v);
  gsl_vector_free (a);
  gsl_vector_free (b);

  printf("difference = %g (should be zero)\n", k);
  printf("defference = %g (should be zero)\n", l);
  return 0;
}
