/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNSi_G2dFontGetStringWidth NFTR_GetStringWidth
#define NNSi_G2dFontGetTextRect G2d_ComputeMaxWidthHeight
#include <nitro.h>

#include <nnsys/g2d/g2d_Font.h>
#include <nnsys/g2d/load/g2d_NFT_load.h>
#include <nnsys/g2d/fmt/g2d_Font_data.h>
#include <nnsys/g2d/g2d_config.h>
extern int NNSi_G2dFontGetStringWidth (const NNSG2dFont * pFont, int hSpace, const void * str, const void ** pPos);
#pragma thumb off
NNSG2dTextRect NNSi_G2dFontGetTextRect (const NNSG2dFont * pFont, int hSpace, int vSpace, const void * txt)
{
    int lines = 1;
    NNSG2dTextRect rect = {0, 0};

    NNS_G2D_FONT_ASSERT(pFont);
    NNS_G2D_POINTER_ASSERT(txt);

    while (txt != NULL) {
        const int width = NNSi_G2dFontGetStringWidth(pFont, hSpace, txt, &txt);
        if (width > rect.width) {
            rect.width = width;
        }
        lines++;
    }

    rect.height = ((lines - 1) * (NNS_G2dFontGetLineFeed(pFont) + vSpace) - vSpace);

    return rect;
}
