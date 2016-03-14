/**
 * This file is part of gsl-examples.
 */

/**
 * gsl_vector * gsl_vector_alloc (size_t n)
 *   This function create a vector of length n, returning a pointer to a newly initialized
 *   vector struct. A new block is allocated for the elements of the vector, and stored int
 *   the block component of the vector struct. The block is "owned" by the vector, and
 *   will be deallocated when the vector is deallocated.
 */

/**
 * void gsl_vector_free (gsl_vector * v)
 *   This function frees a previously allocated vector v. If the vector was created using
 *   gsl_vector_alloc then the block underlying the vector will also be deallocated. If
 *   the vector has been created from another object then the memory is still owned by
 *   that object and will not be deallocated.
 */

/**
 * double gsl_vector_get (const gsl_vector * v, const size_t i)
 *   This function returns the i-th element of a vector v. If i lies outside the allowed range
 *   of 0 to n - 1 then the error handler is invoked and 0 is returned. An inline version of
 *   this function is used when HAVE_INLINE is defined.
 */

/**
 * void gsl_vector_set (gsl_vector * v, const size_t i, double x)
 *   This function sets the value of the i-th element of a vector v to x. If i lies outside
 *   the allowed range of 0 to n - 1 then the error handler is invoked. An inline version of
 *   this function is used when HAVE_INLINE is defined.
 */

#include <stdio.h>
#include <gsl/gsl_vector.h>

int
main (void)
{
  int i;
  gsl_vector * v = gsl_vector_alloc (3);

  for (i = 0; i < 3; i++)
    {
      gsl_vector_set (v, i, 1.23 + i);
    }

  for (i = 0; i < 100; i++) /* OUT OF RANGE ERROR */
    {
      printf ("v_%d = %g\n", i, gsl_vector_get (v, i));
    }

  gsl_vector_free (v);
  return 0;
}
