/**
 * This file is part of gsl-examples.
 */

/**
 * gsl_vector_view gsl_vector_subvector (gsl_vector * v, size_t offset, size_t n)
 * gls_vector_const_view gsl_vector_const_subvector (const gsl_vector * v, size_t offset, size_t n)
 *   Theses functions return a vector view of a subvector of another vector v. The start of
 *   the new vector is offset by offset elements from the start of the original vector. The
 *   new vector has n elements. Mathematically, the i-th element of the new vector v' is
 *   given by,
 *
 *       v'(i) = v->data[(offset + i)*v->stride]
 *
 *   where the index i runs from 0 to n-1.
 *
 *   The data pointer of the returned vector struct is set to null if the combined parameters
 *   (offset, n) overrun the end of the original vector.
 *
 *   The new vector is only a view of the block underlying the original vector, v. The block
 *   containing the elements of v is not owned by the new vector. When the view goes
 *   out of scope the original vector v and its block will continue to exist, The original
 *   memory can only be deallocated by freeing the original vector. Of course, the original
 *   vector should not be deallocated while the view is still in use.
 *
 *   The function gsl_vector_const_subvector is equivalent to gsl_vector_subvector
 *   but can be used for vectors which are declared const.
 */

/**
 * gsl_vector_view gsl_vector_subvector_with_stride (gsl_vector * v, size_t offset, size_t stride, size_t n)
 * gsl_vector_const_view gsl_vector_const_subvector_with_stride (const gsl_vector * v, size_t offset, size_t stride, size_t n)
 *   These functions return a vector view of a subvector of another vector v with an
 *   additional stride argument. The subvector is formed in the same way as for gsl_
 *   vector_subvector but the new vector has n elements with a step-size of stride from
 *   one element to the next in the original vector. Mathematically, the i-th element of
 *   the new vector v' is given by,
 *
 *       v'(i) = v->data[(offset + i*stride)*v->stride]
 *
 *   where the index i runs from 0 to n-1.
 *
 *   Note that subvector view give direct acces to the underlying elements of the original
 *   vector. For example, the following code will zero the even elements of the vector v of
 *   length n, while leaving the odd elements untouched,
 *
 *       gsl_vector_view v_even = gsl_vector_subvector_with_stride (v, 0, 2, n/2);
 *       gsl_vector_set_zero (&v_even.vector);
 *
 *   A vector view can be passes to any subroutine which takes a vector argument just as
 *   a directly allocated vector would be, using &view.vector. For example, the following
 *   code computes the norm of the odd elements of v using the BLAS routine DNRM2,
 *
 *       gsl_vector_view v_odd = gsl_vector_subvector_with_stride (v, 1, 2, n/2);
 *       double r = gsl_blas_dnrm2 (&v_odd.vector);
 *
 *   The function gsl_vector_const_subvector_with_stride is equivalent to
 *   gsl_vector_subvector_with_stride but can be used for vectors which are
 *   declared const.
 */

/**
 * void gsl_vector_set_zero (gsl_vector * v)
 *   This function sets all the elements of the vector v to zero.
 */

/**
 * float gsl_blas_snrm2 (const gsl_vector_float * x)
 * double gsl_blas_dnrm2 (const gsl_vector * x)
 *   These functions compute the Euclidean norm of ||x|| = root(sigma x_i^2) of the vector x.
 */

#include <math.h>
#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_blas.h>

int
main (void)
{
  int i = 0;
  size_t n = 100;
  gsl_vector * v = gsl_vector_alloc (100);

  for (i = 0; i < n; i++)
    {
      gsl_vector_set (v, i, 1.23 + i);
    }

  gsl_vector_view v_sub = gsl_vector_subvector (v, 0, 10);

  // If i lies outside the allowed range of 0 to 10 - 1 then the error handler is invoked.
  for (i = 0; i < 10; i++)
    {
      printf ("v_%d = %g\n", i, gsl_vector_get (&v_sub.vector, i));
    }

  gsl_vector_view v_even = gsl_vector_subvector_with_stride (v, 0, 2, n/2);
  gsl_vector_set_zero (&v_even.vector);

  double r_v = gsl_blas_dnrm2 (v);

  gsl_vector_view v_odd = gsl_vector_subvector_with_stride (v, 1, 2, n/2);
  double r_v_odd = gsl_blas_dnrm2 (&v_odd.vector);

  // If the even elements of the vector v are zero,
  // the norm of the vector v is equivalent to the norm of the odd elements of v.
  double k = r_v - r_v_odd;

  gsl_vector_free (v);

  printf ("\ndifferences = %g (should be zero)\n", k);
  return 0;
}
