/**
 * This file is part of gsl-examples.
 */

/**
 * int gsl_vector_fprintf (FILE * stream, const gsl_vector * v, const char * format)
 *   This function writes the elements of the vector v line-by-line to the stream stream
 *   using the format specifier format, which should be one of the %g, %e or %f formats for
 *   floating point numbers and %d for integers. The function returns 0 for success and
 *   GSL_EFAILED if there was a problem writing to the file.
 */

/**
 * int gsl_vector_fscanf (FILE * stream, gsl_vector * v)
 *   This function reads formatted data from the stream stream into the vector v. The
 *   vector v must be preallocated with the correct length sice the function uses the size
 *   of v to determine how many numbers to read. The function returns 0 for success and
 *   GSL_EFAILED if there was a problem reading from the file.
 */

#include <stdio.h>
#include <gsl/gsl_vector.h>

int
main (void)
{
  int i, k = 0;
  gsl_vector * v = gsl_vector_alloc (100);
  gsl_vector * a = gsl_vector_alloc (100);

  for (i = 0; i < 100; i++)
    gsl_vector_set (v, i, 1.23 + i);

  {
    FILE * f = fopen ("test.dat", "w");
    gsl_vector_fprintf (f, v, "%e");
    fclose (f);
  }

  {
    FILE * f = fopen ("test.dat", "r");
    gsl_vector_fscanf (f, a);
    fclose (f);
  }

  for (i = 0; i < 100; i++)
    {
      double vi = gsl_vector_get (v, i);
      double ai = gsl_vector_get (a, i);
      if (vi != ai) k++;
    }

  gsl_vector_free (v);
  gsl_vector_free (a);

  printf("difference = %d (should be zero)\n", k);
  return (k > 0);
}
