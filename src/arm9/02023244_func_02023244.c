/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_G2dMapScrToChar256x16Pltt func_02023244
#include <nitro.h>

#include <nnsys/g2d/g2d_CharCanvas.h>
#include <nnsys/g2d/fmt/g2d_Oam_data.h>
#include <nnsys/g2d/g2d_config.h>

#include "g2di_BitReader.h"

#pragma thumb off
void NNS_G2dMapScrToChar256x16Pltt (void * areaBase, int areaWidth, int areaHeight, NNSG2d256x16PlttBGWidth scnWidth, int charNo, int cplt)
{
    u16 * pScrBase;
    int x, y;
    const u16 cplt_sft = (u16)(cplt << 12);

    NNS_G2D_POINTER_ASSERT(areaBase);
    NNS_G2D_ALIGN_ASSERT(areaBase, 2);
    NNS_G2D_ASSERT(0 < areaWidth);
    NNS_G2D_ASSERT(0 < areaHeight);
    NNS_G2D_ASSERT(areaHeight <= MAX_256x16PLTT_BG_CHEIGHT);
    NNS_G2D_256x16PLTT_BG_WIDTH_ASSERT(scnWidth);
    NNS_G2D_ASSERT(areaWidth <= scnWidth);
    NNS_G2D_ASSERT(0 <= charNo);
    NNS_G2D_ASSERT(charNo + (areaHeight * areaWidth) <= MAX_256x16PLTT_BG_CHARACTER);
    NNS_G2D_MINMAX_ASSERT(cplt, 0, 15);

    pScrBase = areaBase;

    for (y = 0; y < areaHeight; ++y) {
        u16 * pScr = pScrBase;
        for (x = 0; x < areaWidth; ++x) {
            *pScr++ = (u16)(cplt_sft | charNo++);
        }
        pScrBase += scnWidth;
    }
}
