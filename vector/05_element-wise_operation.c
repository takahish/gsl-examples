/**
 * This file is part of gsl-examples.
 */

/**
 * int gsl_vector_add (gsl_vector * a, const gsl_vector * b)
 *   This function adds the elements of vector b to the elements of vector a. The result
 *   a_i <- a_i + b_i is stored in a and b remains unchanged. The two vectors must have the
 *   same length.
 */

/**
 * int gsl_vector_sub (gsl_vector * a, const gsl_vector * b)
 *   This function subtracts the elements of vector b from the elements of vector a. The
 *   result a_i <- a_i - b_i is stored in a and b remains unchanged. The two vectors must
 *   have the same length.
 */

/**
 * int gsl_vector_mul (gsl_vector * a, const gsl_vector * b)
 *   This function multiplies the elements of vector a by the elements of vector b. The
 *   result a_i <- a_i * b_i is stored in a and b remains unchanged. The two vectors must
 *   have the same length.
 */

/**
 * int gsl_vector_div (gsl_vector * a, const gsl_vector * b)
 *   This function divides the elements of vector a by the elements of vector b. The result
 *   a_i <- a_i / b_i is stored is stored in a and b remains unchanged. The two vectors must
 *   have the same length.
 */

/**
 * int gsl_vector_scale (gsl_vector * a, const double x)
 *   This function multiplies the elements of vector a by the constant factor x. The result
 *   a_i <- a_i * x is stored in a.
 */

/**
 * int gsl_vector_add_constant (gsl_vector * a, const double x)
 *   This function adds the constant value x to the elements of the vector a. The result
 *   a_i <- a_i + x is stored in a.
 */

#include <stdio.h>
#include <gsl/gsl_vector.h>

int
main (void)
{
  int i = 0;
  double k, l, m, o, p, q = 0.0;
  size_t n = 100;

  gsl_vector * a = gsl_vector_alloc (n);
  gsl_vector * b = gsl_vector_alloc (n);
  gsl_vector * c = gsl_vector_alloc (n);

  for (i = 0; i < n; i++)
    {
      gsl_vector_set (a, i, 1.0);
      gsl_vector_set (b, i, 2.0);
      gsl_vector_set (c, i, 3.0);
    }

  gsl_vector_add (a, b);

  for (i = 0; i < n; i++)
    {
      double ai = gsl_vector_get (a, i);
      double ci = gsl_vector_get (c, i);
      // ai is equivalent to ci.
      k += (ci - ai);
    }

  gsl_vector_sub (a, b);

  for (i = 0; i < n; i++)
    {
      double ai = gsl_vector_get (a, i);
      double ci = gsl_vector_get (c, i);
      // Difference between ai and ci is 2.0.
      l += (ci - (ai + 2.0));
    }

  gsl_vector_mul (a, b);

  for (i = 0; i < n; i++)
    {
      double ai = gsl_vector_get (a, i);
      double ci = gsl_vector_get (c, i);
      // ai is equivalent to bi (2.0), because ai is 1.0.
      // Difference between ai and ci is 1.0.
      m += (ci - (ai + 1.0));
    }

  gsl_vector_div (a, b);

  for (i = 0; i < n; i ++)
    {
      double ai = gsl_vector_get (a, i);
      double ci = gsl_vector_get (c, i);
      // ai is equivalent to 1.0, because ai was equivalent to bi (2.0).
      // Diffrence between ai and ci is 2.0.
      o += (ci - (ai + 2.0));
    }

  gsl_vector_scale (a, 2.0);

  for (i = 0; i < n; i ++)
    {
      double ai = gsl_vector_get (a, i);
      double ci = gsl_vector_get (c, i);
      // Diffrence between ai and ci is 1.0.
      p += (ci - (ai + 1.0));
    }

  gsl_vector_add_constant (a, 1.0);

  for (i = 0; i < n; i ++)
    {
      double ai = gsl_vector_get (a, i);
      double ci = gsl_vector_get (c, i);
      // ai is equivalent to ci.
      q += (ci - ai);
    }

  gsl_vector_free (a);
  gsl_vector_free (b);
  gsl_vector_free (c);

  printf("difference k = %g (should be zero)\n", k);
  printf("difference l = %g (should be zero)\n", l);
  printf("difference m = %g (should be zero)\n", m);
  printf("difference o = %g (should be zero)\n", o);
  printf("difference p = %g (should be zero)\n", p);
  printf("difference q = %g (should be zero)\n", q);

  return 0;
}
