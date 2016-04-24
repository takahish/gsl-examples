/**
 * This file is part of gsl-examples.
 */

/**
 * int gsl_blas_ssymm (CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo,
 *         float alpha, const gsl_matrix_float * A, const gsl_matrix_float * B, float beta,
 *         gsl_matrix_float * C)
 *
 * int gsl_blas_dsymm (CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo,
 *         double alpha, const gsl_matrix * A, const gsl_matrix * B, double beta,
 *         gsl_matrix * C)
 *
 * int gsl_blas_csymm (CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo,
 *         const gsl_complex_float alpha, const gsl_matrix_complex_float * A, const
 *         gsl_matrix_complex_float * B, const gsl_complex_float beta,
 *         gsl_matrix_complex_float * C)
 *
 * int gsl_blas_zsymm (CBLAS_SIDE_t Side, CBLAS_UPLO_t Uplo,
 *         const gsl_complex alpha, const gsl_matrix_complex * A, const
 *         gsl_matrix_complex * B, const gsl_complex beta, gsl_matrix_complex * C)
 *
 *     These functions compute the matrix-matrix product and sum C = alpha AB + beta C for
 *     Side is CBlasLeft and C = alpha BA + beta C for Side is CblasRight, where the matrix A
 *     is symmetric. When Uplo is CblasUpper then the upper triangle and diagonal of A
 *     are used, and when Uplo is CblasLower then the lower triangle and diagonal of A are
 *     used.
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
  double a[] = { 0.11, 0.12,
                 0.21, 0.22 };

  double b[] = { 1011, 1012,
                 1021, 1022 };

  double c[] = { 0.00, 0.00,
                 0.00, 0.00 };

  gsl_matrix_view A = gsl_matrix_view_array(a, 2, 2);
  gsl_matrix_view B = gsl_matrix_view_array(b, 2, 2);
  gsl_matrix_view C = gsl_matrix_view_array(c, 2, 2);

  /* Compute C = A B */

  gsl_blas_dsymm (CblasLeft, CblasUpper,
                  1.0, &A.matrix, &B.matrix,
                  0.0, &C.matrix);

  printf ("[ %g, %g\n", c[0], c[1]);
  printf ("  %g, %g ]\n", c[2], c[3]);

  return 0;
}
