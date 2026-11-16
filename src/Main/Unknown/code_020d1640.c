#include "Main/Unknown/code_020d1640.h"
#include "Main/System/Heap.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Race/RaceStartSequence.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b85dc.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_020b3000.h"
#include "Main/Unknown/code_020b4000.h"

void s2d_init(void *heap) {
    sStatic2dData = heap_alloc(heap, 0x2c);
    sStatic2dData->mUnk_00 = arc_get2dArcFile("search_icon_00.bncl");
    sStatic2dData->mUnk_04 = arc_get2dArcFile("search_icon_layout_00.bncl");
    g2du_unpackCharacterData(&sStatic2dData->mUnk_08, arc_get2dArcFile("search_icon_00.nce.ncgr"));
    g2du_unpackCellBankData(&sStatic2dData->mUnk_0c, arc_get2dArcFile("search_icon_00.nce.ncer"));
    g2du_unpackPaletteData(&sStatic2dData->mUnk_10, arc_get2dArcFile("search_icon_00_o.nclr"));
    switch (gSystemData->mLanguageIndex) {
        default:
            m2d_initFont(&sStatic2dData->mUnk_14, arc_get2dArcFile("MBChild_us.NFTR"));
            break;
        case 2:
            m2d_initFont(&sStatic2dData->mUnk_14, arc_get2dArcFile("MBChild_fr.NFTR"));
            break;
        case 3:
            m2d_initFont(&sStatic2dData->mUnk_14, arc_get2dArcFile("MBChild_ge.NFTR"));
            break;
        case 4:
            m2d_initFont(&sStatic2dData->mUnk_14, arc_get2dArcFile("MBChild_it.NFTR"));
            break;
        case 5:
            m2d_initFont(&sStatic2dData->mUnk_14, arc_get2dArcFile("MBChild_es.NFTR"));
            break;
    }
    switch (gSystemData->mLanguageIndex) {
        default:
            sStatic2dData->mUnk_20 = arc_get2dArcFile("MBChild_us.bmg");
            break;
        case 2:
            sStatic2dData->mUnk_20 = arc_get2dArcFile("MBChild_fr.bmg");
            break;
        case 3:
            sStatic2dData->mUnk_20 = arc_get2dArcFile("MBChild_ge.bmg");
            break;
        case 4:
            sStatic2dData->mUnk_20 = arc_get2dArcFile("MBChild_it.bmg");
            break;
        case 5:
            sStatic2dData->mUnk_20 = arc_get2dArcFile("MBChild_es.bmg");
            break;
    }
    g2du_unpackCharacterDataBG(&sStatic2dData->mUnk_24, arc_get2dArcFile("multi_download_00_b.NCGR"));
    g2du_unpackPaletteData(&sStatic2dData->mUnk_28, arc_get2dArcFile("multi_download_00_b.NCLR"));
}
