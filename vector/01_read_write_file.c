/**
 * This file is part of gsl-examples.
 */

/**
 * int gsl_vector_fwrite (FILE * stream, const gsl_vector * v)
 *   This function writes the elements of the vector v to the stream stream in binary
 *   format. The return value is 0 for success and GSL_EFAILED if there was a problem
 *   writing to the file. Since the data is written in the native binary format it may not
 *   be portable between different architectures.
 */

/**
 * int gsl_vector_fread (FILE * stream, gsl_vector * v)
 *   This function reads into the vector v from the open stream stream in binary format.
 *   The vector v must be preallocated with the correct length since the function uses the
 *   size of v to determine how many bytes to read. The return value is 0 for success and
 *   GSL_EFAILED if there was a problem reading from the file. The data is assumed to
 *   have been written in the native binary format on the same architecture.
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
    FILE * f = fopen ("test.dat", "wb");
    gsl_vector_fwrite (f, v);
    fclose (f);
  }

  {
    FILE * f = fopen ("test.dat", "rb");
    gsl_vector_fread (f, a);
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
