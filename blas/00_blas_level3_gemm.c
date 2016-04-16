/**
 * This file is part of gsl-examples.
 */

/**
 * int gsl_blas_sgemm (CBLAS_TRANSPOSE_t TransA,
 *         CBLAS_TRANSPOSE_t TransB, float alpha, const gsl_matrix_float * A, const
 *         gsl_matrix_float * B, float beta, gsl_matrix_float * C)
 *
 * int gsl_blas_dgemm (CBLAS_TRANSPOSE_t TransA,
 *         CBLAS_TRANSPOSE_t TransB, double alpha, const gsl_matrix * A, const
 *         gsl_matrix * B, double beta gsl_matrix * C)
 *
 * int gsl_blas_cgem (CBLAS_TRANSPOSE_t TransA,
 *         CBLAS_TRANSPOSE_t TransB, const gsl_complex_float alpha, const
 *         gsl_matrix_complex_float * A, const gsl_matrix_complex_float * B, const
 *         gsl_complex_float beta, gsl_matrix_complex_float * C)
 *
 * int gsl_blas_zgemm (CBLAS_TRANSPOSE_t TransA,
 *         CBLAS_TRANSPOSE_t TransB, const gsl_complex alpha, const
 *         gsl_matrix_complex * A, const gsl_matrix_complex * B, const gsl_complex beta,
 *         gsl_matrix_complex * C)
 *
 *     These functions compute the matrix-matrix product and sum C = alpha op(A) op(B) + beta C
 *     where op(A) = A, A^T, A^H for TransA = CblasNoTrans, CblasTrans,
 *     CblasConjTrans and similarly for the parameter TransB.
 */

/**
 * gsl_matrix_view gsl_matrix_view_array (double * base, size_t n1, size_t n2)
 * gsl_matrix_const_view gsl_matrix_const_view_array (const double * base, size_t n1, size_t n2)
 *
 *     These functions return a matrix view of the array base. The matrix has n1 rows
 *     and n2 columns. The physical number of columns in memory is also given by n2.
 *     Mathematically, the (i,j)-th element of the new matrix is given by,
 *
 *         m'(i,j) = base[i*n2 + j]
 *
 *     where the index i runs from 0 to n1-1 and the index j runs from 0 to n2-1.
 *     The new matrix is only a view of the array base. When the view goes out of scope
 *     the original array base will continue to exist. The original memory can only be
 *     deallocated by freeing the original array. Of course, the original array should not be
 *     deallocated while the view is still in use.
 *
 *     The function gsl_matrix_const_view_array is equivalent to gsl_matrix_view_array
 *     but can be used for matrices which are declared const.
 */

#include <stdio.h>
#include <gsl/gsl_blas.h>

int
main (void)
{
  double a[] = { 0.11, 0.12, 0.13,
                 0.21, 0.22, 0.23 };

  double b[] = { 1011, 1012,
                 1021, 1022,
                 1031, 1032 };

  double c[] = { 0.00, 0.00,
                 0.00, 0.00 };

  gsl_matrix_view A = gsl_matrix_view_array(a, 2, 3);
  gsl_matrix_view B = gsl_matrix_view_array(b, 3, 2);
  gsl_matrix_view C = gsl_matrix_view_array(c, 2, 2);

  /* Compute C = A B */

  gsl_blas_dgemm (CblasNoTrans, CblasNoTrans,
                  1.0, &A.matrix, &B.matrix,
                  0.0, &C.matrix);

  printf ("[ %g, %g\n", c[0], c[1]);
  printf ("  %g, %g ]\n", c[2], c[3]);

  return 0;
}
