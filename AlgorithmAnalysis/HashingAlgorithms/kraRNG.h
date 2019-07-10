#pragma once
#include <time.h>

/*Period parameters */
#define CMATH_N 624
#define CMATH_M 397
#define CMATH_MATRIX_A 0x9908b0df   /*constant vector a */
#define CMATH_UPPER_MASK 0x80000000 /*most significant w-r bits */
#define CMATH_LOWER_MASK 0x7fffffff /*least significant r bits */

/*Tempering parameters */
#define CMATH_TEMPERING_MASK_B 0x9d2c5680
#define CMATH_TEMPERING_MASK_C 0xefc60000
#define CMATH_TEMPERING_SHIFT_U(y)  (y >> 11)
#define CMATH_TEMPERING_SHIFT_S(y)  (y << 7)
#define CMATH_TEMPERING_SHIFT_T(y)  (y << 15)
#define CMATH_TEMPERING_SHIFT_L(y)  (y >> 18)

class kraRandom
{

 public:
   kraRandom();

   //************************************
   // Method:    Random
   // FullName:  kraRandom::Random
   // Access:    public 
   // Returns:   unsigned int
   // Description: Function that returns a random number from 0 to n
   // excluding n.
   // Parameter: unsigned int n (the range for the number)
   //************************************
   unsigned int
   Random(unsigned int n);

   //************************************
   // Method:    Random
   // FullName:  kraRandom::Random
   // Access:    public 
   // Returns:   float
   // Qualifier:
   //************************************
   float
   Random();

   void
   setRandomSeed(unsigned int n);

   unsigned int
   GetRandomSeed();

   void
   Randomize();

 private:

   unsigned int m_rSeed;
   unsigned int m_rSeed_sp;
   unsigned long m_mt[CMATH_N];
   int m_mti;

};
