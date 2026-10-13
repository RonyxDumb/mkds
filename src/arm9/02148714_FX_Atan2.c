/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define FX_AtanTable_ SDK_data_021615b8
#include "nitro/types.h"
#include "fx.h"
#include "code32.h"
extern const fx16 FX_AtanTable_[];
#pragma thumb off
u16 FX_Atan2(fx32 x, fx32 y){
    u32 positive, bias, denominator, numerator;
    if (x > 0)
    {
        if (y > 0)
        {
            if (y > x)
            {
                numerator = (u32)x;
                denominator = (u32)y;
                bias = 0;
                positive = TRUE;
            }
            else if (y < x)
            {
                numerator = (u32)y;
                denominator = (u32)x;
                bias = 0x4000;
                positive = FALSE;
            }
            else
            {
                return 0x2000;
            }
        }
        else if (y < 0)
        {
            y = -y;
            if (y < x)
            {
                numerator = (u32)y;
                denominator = (u32)x;
                bias = 0x4000;
                positive = TRUE;
            }
            else if (y > x)
            {
                numerator = (u32)x;
                denominator = (u32)y;
                bias = 0x8000;
                positive = FALSE;
            }
            else
            {
                return 0x6000;
            }
        }
        else
        {
            return 0x4000;
        }
    }
    else if (x < 0)
    {
        x = -x;
        if (y < 0)
        {
            y = -y;
            if (y > x)
            {
                numerator = (u32)x;
                denominator = (u32)y;
                bias = (u32)(-0x8000);
                positive = TRUE;
            }
            else if (y < x)
            {
                numerator = (u32)y;
                denominator = (u32)x;
                bias = (u32)(-0x4000);
                positive = FALSE;
            }
            else
            {
                return 0xA000;
            }
        }
        else if (y > 0)
        {
            if (y < x)
            {
                numerator = (u32)y;
                denominator = (u32)x;
                bias = (u32)(-0x4000);
                positive = TRUE;
            }
            else if (y > x)
            {
                numerator = (u32)x;
                denominator = (u32)y;
                bias = 0x0;
                positive = FALSE;
            }
            else
            {
                return 0xE000;
            }
        }
        else
        {
            return 0xC000;
        }
    }
    else
    {
        if (y >= 0)
            return 0x0;
        else
            return 0x8000;
    }
    if (denominator == 0x0)
        return 0x0;
    if (positive)
        return (u16)(bias + FX_AtanTable_[FX_Div((fx32)numerator, (fx32)denominator) >> 5]);
    else
        return (u16)(bias - FX_AtanTable_[FX_Div((fx32)numerator, (fx32)denominator) >> 5]);
}
