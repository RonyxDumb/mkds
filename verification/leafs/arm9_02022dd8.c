/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define GetGlyphIndex NFTR_CharacterMap_GetTileIndexForCharacter
#include <nitro.h>

#include <nnsys/g2d/g2d_Font.h>
#include <nnsys/g2d/load/g2d_NFT_load.h>
#include <nnsys/g2d/fmt/g2d_Font_data.h>
#include <nnsys/g2d/g2d_config.h>

#pragma thumb off
u16 GetGlyphIndex (const NNSG2dFontCodeMap * pMap, u16 c)
{
    u16 index = NNS_G2D_GLYPH_INDEX_NOT_FOUND;

    NNS_G2D_POINTER_ASSERT(pMap);
    NNS_G2D_ASSERT(pMap->ccodeBegin <= c && c <= pMap->ccodeEnd);

    switch (pMap->mappingMethod) {
    case NNS_G2D_MAPMETHOD_DIRECT:
    {
        u16 offset = pMap->mapInfo[0];
        index = (u16)(c - pMap->ccodeBegin + offset);
    }
    break;
    case NNS_G2D_MAPMETHOD_TABLE:
    {
        const int table_index = c - pMap->ccodeBegin;

        index = pMap->mapInfo[table_index];
    }
    break;
    case NNS_G2D_MAPMETHOD_SCAN:
    {
        const NNSG2dCMapInfoScan * const ws = (NNSG2dCMapInfoScan *)(pMap->mapInfo);
        const NNSG2dCMapScanEntry * st = &(ws->entries[0]);
        const NNSG2dCMapScanEntry * ed = &(ws->entries[ws->num - 1]);

        while (st <= ed) {
            const NNSG2dCMapScanEntry * md = st + (ed - st) / 2;

            if (md->ccode < c) {
                st = md + 1;
            } else if (c < md->ccode) {
                ed = md - 1;
            } else {
                index = md->index;
                break;
            }
        }
    }
    break;
    default:
        NNS_G2D_ASSERTMSG(FALSE, "unknwon MAPMETHOD");
    }

    return index;
}
