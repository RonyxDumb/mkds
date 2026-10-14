/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNSi_G2dCalcRequiredOBJ func_020231e4
#include <nitro.h>

#include <nnsys/g2d/g2d_CharCanvas.h>
#include <nnsys/g2d/fmt/g2d_Oam_data.h>
#include <nnsys/g2d/g2d_config.h>

#include "g2di_BitReader.h"

#pragma thumb off
int NNSi_G2dCalcRequiredOBJ (int areaWidth, int areaHeight)
{
    const u32 w = (unsigned int)areaWidth;
    const u32 h = (unsigned int)areaHeight;
    const u32 w8 = w / 8;
    const u32 h8 = h / 8;
    const u32 w4 = (w & 4) >> 2;
    const u32 h4 = (h & 4) >> 2;
    const u32 wcp = ((w & 2) >> 1) + (w & 1);
    const u32 hcp = ((h & 2) >> 1) + (h & 1);
    int ret = 0;

    NNS_G2D_ASSERT(0 < areaWidth);
    NNS_G2D_ASSERT(0 < areaHeight);

    ret += w8 * h8;
    ret += (wcp * 2 + w4) * h8;
    ret += (hcp * 2 + h4) * w8;
    ret += (wcp + w4) * (hcp + h4);

    return ret;
}
