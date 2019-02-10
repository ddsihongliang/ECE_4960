//*****************************************
//	ECE4960
//	in class hacker: denormals
//	2/1/2019
//	Hongliang Si (hs983@cornell.edu)
//*****************************************

#include <stdio.h>
#include <cmath>
#include <cfenv>
using namespace std;

#pragma STDC FENV_ACCESS ON

volatile double zero = 0.0;
volatile double one = 1.0;

int main() {
  feclearexcept(FE_ALL_EXCEPT);
  // Observe overflow handling in integres
  //
  long i, intFactorial = 1, iLimit = 36;
  for (i = 2; i < iLimit; i++) {
    intFactorial *=i;
    printf("%d  %d\n", i,intFactorial);
  }

  // Observe NaN and INF hadling in integers
  //
  long m = 0, n = 0, intResult1, intResult2;
  intResult1 = 1/m;
  printf("1/0 as %d\n", intResult1);
  if(fetestexcept(FE_DIVBYZERO))
    printf("Divide by zero reported");
  feclearexcept(FE_ALL_EXCEPT);

  intResult2 = n/m;
  printf("0/0 as %d\n", intResult2);
  feclearexcept(FE_ALL_EXCEPT);

  return 0;
}
