/**
 * This file is part of gsl-examples.
 */

/**
 * size_t gsl_vector_min_index (const gsl_vector * v)
 *   This function returns the index of the minimum value in the vector v. When there
 *   are several equal minimum elements then the lowest index is returned.
 */

/**
 * size_t gsl_vector_max_index (const gsl_vector * v)
 *   This function returns the index of the maximum value in the vector v. When there
 *   are several equal maximum elements then the lowest index is returned.
 */

/**
 * void gsl_vector_minmax_index (const gsl_vector * v, size_t * imin)
 *   This function returns the indices of the minimum and maximum values in the vector v,
 *   storing them in imin and imax. when there are several equal minimum or maximum
 *   elements then the lowest indices a returned.
 */

#include <stdio.h>
#include <gsl/gsl_vector.h>

int
main (void)
{
  int i = 0;
  double min_v_1, max_v_1, min_v_2, max_v_2, k = 0.0;
  size_t min_i_1, max_i_1, min_i_2, max_i_2 = 0;
  size_t n = 100;

  gsl_vector * v = gsl_vector_alloc (n);

  for (i = 0; i < n; i++)
    {
      gsl_vector_set (v, i, 1.23 + i);
    }

  min_i_1 = gsl_vector_min_index (v);
  max_i_1 = gsl_vector_max_index (v);

  min_v_1 = gsl_vector_get (v, min_i_1);
  max_v_1 = gsl_vector_get (v, max_i_1);

  gsl_vector_minmax_index (v, &min_i_2, &max_i_2);

  min_v_2 = gsl_vector_get (v, min_i_2);
  max_v_2 = gsl_vector_get (v, max_i_2);

  k += (min_v_1 - min_v_2);
  k += (max_v_1 - max_v_2);

  gsl_vector_free(v);

  printf("difference = %g (should be zero)\n", k);

  return 0;
}
