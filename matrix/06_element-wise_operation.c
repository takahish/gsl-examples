/**
 * This file is part of gsl-examples.
 */

/**
 * int gsl_matrix_add (gsl_matrix * a, const gsl_matrix * b)
 *   This function adds the elements of matrix b to the elements of matrix a. The result
 *   a(i,j) <- a(i,j) + b(i,j) is stored in a and b remains unchanged. The two matrices
 *   must have the same dimensions.
 */

/**
 * int gsl_matrix_sub (gsl_matrix * a, const gsl_matrix * b)
 *   This function subtracts the elements of matrix b from the elements of matrix a. The
 *   result a(i,j) <- a(i,j) - b(i,j) is stored in a and b remains unchanged. The two
 *   matrices must have the same dimensions.
 */

/**
 * int gsl_matrix_mul_elements (gsl_matrix * a, const gsl_matrix * b)
 *   This function multiplies the elements of matrix a by the elements of matrix b. The
 *   result a(i,j) <- a(i,j) * b(i,j) is stored in a and b remains unchanged. The two
 *   matrices must have the same dimensions.
 */

/**
 * int gsl_matrix_div_elements (gsl_matrix * a, const gsl_matrix * b)
 *   This function divides the elements of matrix a by the elements of matrix b. The result
 *   a(i,j) <- a(i,j)/b(i,j) is stored in a and b remains unchanged. The two matrices must
 *   have the same dimensions.
 */

/**
 * int gsl_matrix_scale (gsl_matrix * a, const double x)
 *   This function multiplies the elements of matrix a by the constant factor x. The result
 *   a(i,j) <- a(i,j) * x is stored in a.
 */

/**
 * int gsl_matrix_add_constant (gsl_matrix * a, const double x)
 *   This function adds the constant value x to the elements of the matrix a. The result
 *   a(i,j) <- a(i,j) + x is stored in a.
 */

#include <stdio.h>
#include <math.h>
#include <gsl/gsl_matrix.h>

int
main (void)
{
  size_t i, j, n = 100;
  double aij, bij, cij;
  double k = 0.0, l = 0.0, o = 0.0, p = 0.0, q = 0.0, r = 0.0;

  gsl_matrix * a = gsl_matrix_alloc (n, n);
  gsl_matrix * b = gsl_matrix_alloc (n, n);
  gsl_matrix * c = gsl_matrix_alloc (n, n);

  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
        {
          gsl_matrix_set (a, i, j, sin(i) + cos(j));
          gsl_matrix_set (b, i, j, sin(i) + cos(j));
          gsl_matrix_set (c, i, j, (sin(i) + cos(j)) * 2.0);
        }
    }

  gsl_matrix_add (a, b);

  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
        {
          aij = gsl_matrix_get (a, i, j);
          cij = gsl_matrix_get (c, i, j);
          // aij and cij are equal.
          k += (cij - aij);
        }
    }

  gsl_matrix_sub (a, b);

  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
        {
          aij = gsl_matrix_get (a, i, j);
          cij = gsl_matrix_get (c, i, j);
          // aij * 2.0 and cij are equal.
          l += (cij - aij * 2.0);
        }
    }

  gsl_matrix_div_elements (a, b);

  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
        {
          aij = gsl_matrix_get (a, i, j);
          // aij is one.
          o += (aij - 1.0);
        }
    }

  gsl_matrix_mul_elements (a, b);

  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
        {
          aij = gsl_matrix_get (a, i, j);
          cij = gsl_matrix_get (c, i, j);
          // aij * 2.0 and cij are equal.
          p += (cij - aij * 2.0);
        }
    }

  gsl_matrix_scale (a, 2.0);

  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
        {
          aij = gsl_matrix_get (a, i, j);
          cij = gsl_matrix_get (c, i, j);
          // aij and cij are equal.
          q += (cij - aij);
        }
    }

  gsl_matrix_add_constant (a, 3.0);

  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
        {
          aij = gsl_matrix_get (a, i, j);
          cij = gsl_matrix_get (c, i, j);
          // aij - 3.0 and cij are equal.
          r += (cij - aij + 3.0);
        }
    }

  gsl_matrix_free (a);
  gsl_matrix_free (b);
  gsl_matrix_free (c);

  printf ("difference k = %g (should be zero)\n", k);
  printf ("difference l = %g (should be zero)\n", l);
  printf ("difference o = %g (should be zero)\n", o);
  printf ("difference p = %g (should be zero)\n", p);
  printf ("difference q = %g (should be zero)\n", q);
  printf ("difference r = %g (should be zero)\n", r);

  return 0;
}
