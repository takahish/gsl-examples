/**
 * This file is part of gsl-examples.
 */

/**
 * int gsl_matrix_fprintf (FILE * stream, const gsl_matrix * m, const char * format)
 *   This function writes the elements of the matrix m line-by-lien to the stream stream
 *   using the format specifier format, which should be one of the %g, %e or %f formats for
 *   floating point numbers and %d for integers. The function return 0 for success and
 *   GSL_EFAILED if there was a problem writing to the file.
 */

/**
 * int gsl_matrix_fscanf (FILE * stream, gsl_matrix * m)
 *  This function reads formatted data from the stream stream into the matrix m. The
 *  matrix m must be preallocated with the correct dimensions since the function uses
 *  the size of m to determine how many numbers to read. The function returns 0 for
 *  success and GSL_EFAILED if there was a problem reading from the file.
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
    FILE * f = fopen ("test.dat", "w");
    gsl_matrix_fprintf (f, m, "%e");
    fclose(f);
  }

  {
    FILE * f = fopen("test.dat", "r");
    gsl_matrix_fscanf (f, a);
    fclose (f);
  }

  for (i = 0; i < 100; i++)
    for (j = 0; j < 100; j++)
      {
        float mij = gsl_matrix_get (m, i, j);
        float aij = gsl_matrix_get (a, i, j);
        if (mij != aij) k++;
      }

  gsl_matrix_free (m);
  gsl_matrix_free (a);

  printf ("differences = %d (should be zero)\n", k);
  return (k > 0);
}
