/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FX_AtanTable_ SDK_data_021614b4
#define FX_Atan2 func_02148538
#include <nitro/fx/fx_trig.h>
#include <nitro/fx/fx_cp.h>
#include <nitro/fx/fx_const.h>
extern const fx16 FX_AtanTable_[128 + 1];
#pragma thumb off
fx16 FX_Atan2 (fx32 y, fx32 x)
{
	fx32 a, b, c;
	int sgn;

	if (y > 0) {
		if (x > 0) {
			if (x > y) {
				a = y;
				b = x;
				c = 0;
				sgn = 1;
			} else if (x < y)   {
				a = x;
				b = y;
				c = 6434;
				sgn = 0;
			} else {
				return (fx16)3217;
			}
		} else if (x < 0)   {
			x = -x;
			if (x < y) {
				a = x;
				b = y;
				c = 6434;
				sgn = 1;
			} else if (x > y)   {
				a = y;
				b = x;
				c = 12868;
				sgn = 0;
			} else {
				return (fx16)9651;
			}
		} else {
			return (fx16)6434;
		}
	} else if (y < 0)   {
		y = -y;
		if (x < 0) {
			x = -x;
			if (x > y) {
				a = y;
				b = x;
				c = -12868;
				sgn = 1;
			} else if (x < y)   {
				a = x;
				b = y;
				c = -6434;
				sgn = 0;
			} else {
				return (fx16) - 9651;
			}
		} else if (x > 0)   {
			if (x < y) {
				a = x;
				b = y;
				c = -6434;
				sgn = 1;
			} else if (x > y)   {
				a = y;
				b = x;
				c = 0;
				sgn = 0;
			} else {
				return (fx16) - 3217;
			}
		} else {
			return (fx16) - 6434;
		}
	} else {
		if (x >= 0) {
			return 0;
		} else {
			return (fx16)12868;
		}
	}

	if (b == 0)
		return 0;
	if (sgn)
		return (fx16)(c + FX_AtanTable_[FX_Div(a, b) >> 5]);
	else
		return (fx16)(c - FX_AtanTable_[FX_Div(a, b) >> 5]);
}
