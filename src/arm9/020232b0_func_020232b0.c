/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_G2dMapScrToChar256x16Pltt func_02023244
#define NNS_G2dMapScrToCharText func_020232b0
#include <nitro.h>

#include <nnsys/g2d/g2d_CharCanvas.h>
#include <nnsys/g2d/fmt/g2d_Oam_data.h>
#include <nnsys/g2d/g2d_config.h>

#include "g2di_BitReader.h"
extern void NNS_G2dMapScrToChar256x16Pltt (void * areaBase, int areaWidth, int areaHeight, NNSG2d256x16PlttBGWidth scnWidth, int charNo, int cplt);
#pragma thumb off
void NNS_G2dMapScrToCharText (void * scnBase, int areaWidth, int areaHeight, int areaLeft, int areaTop, NNSG2dTextBGWidth scnWidth, int charNo, int cplt)
{
    NNS_G2D_POINTER_ASSERT(scnBase);
    NNS_G2D_ALIGN_ASSERT(scnBase, 2);
    NNS_G2D_ASSERT(0 < areaWidth);
    NNS_G2D_ASSERT(0 < areaHeight);
    NNS_G2D_ASSERT(0 <= areaLeft);
    NNS_G2D_ASSERT(0 <= areaTop);
    NNS_G2D_ASSERT(areaLeft + areaWidth <= scnWidth);
    NNS_G2D_ASSERT(areaTop + areaHeight <= MAX_TEXT_BG_CHEIGHT);
    NNS_G2D_TEXT_BG_WIDTH_ASSERT(scnWidth);
    NNS_G2D_ASSERT(0 <= charNo);
    NNS_G2D_ASSERT(charNo + (areaHeight * areaWidth) <= MAX_TEXT_BG_CHARACTER);
    NNS_G2D_MINMAX_ASSERT(cplt, 0, 15);

    if ( scnWidth <= 32 ) {
        void * areaBase = (u16 *)scnBase + (scnWidth * areaTop + areaLeft);
        NNS_G2dMapScrToChar256x16Pltt(areaBase, areaWidth, areaHeight,
                                      (NNSG2d256x16PlttBGWidth)scnWidth, charNo, cplt);
    } else {
        const int areaRight = areaLeft + areaWidth;
        const int areaBottom = areaTop + areaHeight;
        const u16 cplt_sft = (u16)(cplt << 12);
        u16 * const pScrBase = (u16 *)scnBase;
        int x, y;

        for (y = areaTop; y < areaBottom; ++y) {
            const int py = (y < 32) ? y: y + 32;
            u16 * pScr = pScrBase + py * 32;

            for (x = areaLeft; x < areaRight; ++x) {
                const int px = (x < 32) ? x: x + 32 * 31;
                *(pScr + px) = (u16)(cplt_sft | charNo++);
            }
        }
    }
}
