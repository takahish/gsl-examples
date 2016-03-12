/**
 * This file is part of gsl-examples.
 */

/**
 * gsl_matrix * gsl_matrix_alloc (size_t n1, size_t n2)
 *   This function creates a matrix of size n1 rows by n2 column, returning a pointer
 *   to a newly initialized matrix struct. A new block is allocated for the elements of
 *   the matrix, and stored in the block component of the matrix struct. The block is
 *   "owned" by the matrix, and will be deallocated when the matrix is deallocated.
 */

/**
 * void gsl_matrix_free (gsl_matrix * m)
 *   This function frees a previously allocated matrix m. If the matrix was created using
 *   gsl_matrix_alloc then the block underlying the matrix will also be deallocated. If
 *   the matrix has been created from another object then the memory is still owned by
 *   that object and will not be deallocated.
 */

/**
 * double gsl_matrix_get (const gsl_matrix * m, const size_t i, const size_t j)
 *   This function returns the (i,j)-th element of matrix m. If i or j lie outside the
 *   allowed range of 0 to n1 - 1 and 0 to n2 - 1 then the error handler is invoked and 0
 *   is returned. An inline version of this function is used when HAVE_INLINE is defined.
 */

/**
 * void gsl_matrix_set (gsl_matrix * m, const size_t i, const size_t j, double x)
 *   This function sets the value of the (i,j)-th element of a matrix m to x. If i or j lies
 *   outside the allowed range of 0 to n1 - 1 and 0 to n2 - 1 then the error handler is
 *   invoked. An inline version of this function is used when HAVE_INLINE is defined.
 */

#include <stdio.h>
#include <gsl/gsl_matrix.h>

int
main (void)
{
  int i, j;
  gsl_matrix * m = gsl_matrix_alloc (10, 3);

  for (i = 0; i < 10; i++)
    for (j = 0; j < 3; j++)
      gsl_matrix_set (m, i, j, 0.23 + 100*i + j);

  for (i = 0; i < 100; i++)  /* OUT OF RANGE ERROR */
    for (j = 0; j < 3; j++)
      printf ("m(%d,%d) = %g\n", i, j,
              gsl_matrix_get (m, i, j));

  gsl_matrix_free (m);

  return 0;
}
