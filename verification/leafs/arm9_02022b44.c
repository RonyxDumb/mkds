/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNSi_G2dFontGetTextHeight NFTR_SomeFn_0
#include <nitro.h>

#include <nnsys/g2d/g2d_Font.h>
#include <nnsys/g2d/load/g2d_NFT_load.h>
#include <nnsys/g2d/fmt/g2d_Font_data.h>
#include <nnsys/g2d/g2d_config.h>

#pragma thumb off
int NNSi_G2dFontGetTextHeight (const NNSG2dFont * pFont, int vSpace, const void * txt)
{
    const void * pos = txt;
    int lines = 1;
    NNSG2dTextRect rect = {0, 0};
    u16 c;
    NNSiG2dSplitCharCallback getNextChar;

    NNS_G2D_FONT_ASSERT(pFont);
    NNS_G2D_POINTER_ASSERT(txt);

    getNextChar = NNSi_G2dFontGetSpliter(pFont);

    while ((c = getNextChar((const void **)&pos)) != 0) {
        if (c == '\n') {
            lines++;
        }
    }

    return lines * (NNS_G2dFontGetLineFeed(pFont) + vSpace) - vSpace;
}
