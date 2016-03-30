/**
 * This file is part of gsl-examples.
 */

/**
 * int gsl_vector_isnull (const gsl_vector * v)
 * int gsl_vector_ispos (const gsl_vector * v)
 * int gsl_vector_isneg (const gsl_vector * v)
 * int gsl_vector_isnonneg (const gsl_vector * v)
 *   These functions return 1 if all the elements of the vector v are zero, strictly positive,
 *   strictly negative, or non-negative respectively, and 0 otherwise.
 */

/**
 * int gsl_vector_equal (const gsl_vector * u, const gsl_vector * v)
 *   This function return 1 if the vector u and v are equal (by comparison of element
 *   values) and 0 otherwise.
 */

#include <stdio.h>
#include <gsl/gsl_vector.h>

int
main (void)
{
  int i, k = 0;
  size_t n = 100;

  gsl_vector * v = gsl_vector_alloc (n);
  gsl_vector * u = gsl_vector_alloc (n);
  gsl_vector * w = gsl_vector_alloc (n);

  for (i = 0; i < n; i++)
    {
      gsl_vector_set (v, i, 0.0);
      gsl_vector_set (u, i, 1.23 + i);
      gsl_vector_set (w, i, -1.0 * (1.23 + i));
    }

  // All the elements of v are zero (null).
  k += gsl_vector_isnull (v);

  // All the elements of u are positive.
  k += gsl_vector_ispos (u);

  // All the elements of w are negative.
  k += gsl_vector_isneg (w);

  // All the elements of u are non-negative (zero).
  k += gsl_vector_isnonneg (u);

  // The elements of w are multiplied by -1.0.
  // The vector u and w are equal.
  gsl_vector_scale (w, -1.0);
  k += gsl_vector_equal (u, w);

  gsl_vector_free (v);
  gsl_vector_free (u);
  gsl_vector_free (w);

  printf ("k = %d (should be 5)\n", k);

  return 0;
}
