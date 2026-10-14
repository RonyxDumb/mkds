/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MATH_CountPopulation FUN_038068e0
#include <nitro/math.h>

#pragma thumb off
u8 MATH_CountPopulation (u32 x)
{
	x -= ((x >> 1) & 0x55555555);
	x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
	x += (x >> 4);

	x &= 0x0f0f0f0f;

	x += (x >> 8);
	x += (x >> 16);

	return (u8)x;
}
