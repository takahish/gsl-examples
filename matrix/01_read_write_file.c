/**
 * This file is part of gsl-examples.
 */

/**
 * int gsl_matrix_fwrite (FILE * stream, const gsl_matrix * m)
 *   This function writes the elements of the matrix m to the stream stream in binary
 *   format. The retrun value is 0 for success and GSL_EFAILED if there was a problem
 *   writing to the file. Since the data is written in the native binary format it may not
 *   be portable between different architectures.
 */

/**
 * int gsl_matrix_fread (FILE * stream, gsl_matrix * m)
 *   This function reads into the matrix m from the open stream stream in binary format.
 *   The matrix m must be preallocated with the correct dimensions since the function
 *   uses the size of m to determine how many bytes to read. The return value is 0 for
 *   success and GSL_EFAILED if there was a problem reading from the file. The data is
 *   assumend to have been written in the native binary format on the same architecture.
 */

#include <stdio.h>
#include <gsl/gsl_matrix.h>

int
main (void)
{
  int i, j, k = 0;
  gsl_matrix * m = gsl_matrix_alloc (100, 100);
  gsl_matrix * a = gsl_matrix_alloc (100, 100);

  for (i = 0; i < 100; i++)
    for (j = 0; j < 100; j++)
      gsl_matrix_set (m, i, j, 0.23 + i + j);

  {
    FILE * f = fopen ("test.dat", "wb");
    gsl_matrix_fwrite (f, m);
    fclose(f);
  }

  {
    FILE * f = fopen("test.dat", "rb");
    gsl_matrix_fread (f, a);
    fclose (f);
  }

  for (i = 0; i < 100; i++)
    for (j = 0; j < 100; j++)
      {
        double mij = gsl_matrix_get (m, i, j);
        double aij = gsl_matrix_get (a, i, j);
        if (mij != aij) k++;
      }

  gsl_matrix_free (m);
  gsl_matrix_free (a);

  printf ("differences = %d (should be zero)\n", k);
  return (k > 0);
}
