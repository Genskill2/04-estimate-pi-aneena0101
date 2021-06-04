#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


float wallis_pi(int l)
{ int k=1;

    if(l>=1)
    {     k*=((4*l*l)/((4*l*l)-1);
              wallis_pi(l-1);
              }
              return (2*k);
              }







float mc_pi(int m)
  { float c=0.0;
  float s=0.0;
  c=sqrt(m)/2;
  c=M_PI*c*c;
  s=(4*c)/m;
  return s;

  }

float frandom() {
  long int q = random();
  float ret = (float)q/(float)RAND_MAX;
  return ret;
}

int main(void) {

float pi;
  for (int i=1; i<5; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) > 0.15)) {
      printf("Estimate with just %d iterations is %f which is too accurate.\n", i, pi);
      abort();
    }
  }

  for (int i=500; i<3000; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) < 0.01)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi);
      abort();
    }
  }

  float pi0;
  float pi1;

  pi0 = mc_pi(frandom());
  pi1 = mc_pi(25000);
  printf("%f %f\n", pi0, pi1);

  if (pi0 == pi1) {
      printf("Two separate estimates of pi are exactly the same. This is unlikely.\n");
      abort();
    }

  if (fabs(pi0 - pi1) > 0.05) {
      printf("Two separate estimates %f and %f are too different.\n", pi0, pi1);
      abort();
  }


  for (int i=2000; i<5000; i++) {
    pi0 = mc_pi(i);
    if (!(fabs(pi0 - M_PI) < 0.4)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi0);
      abort();
    }
  }
}
