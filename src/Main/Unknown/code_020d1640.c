#include "Main/Unknown/code_020d1640.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b33d8.h"
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

void CreateSearchIconMBChildAndMultiDownload(void *heap) {
    gDownloadScreenFiles = HeapAlloc(heap, 0x2c);
    gDownloadScreenFiles->mSearchIconCellLayout = FindFileInLoadedArchives("search_icon_00.bncl");
    gDownloadScreenFiles->mSearchIconLayoutCellLayout = FindFileInLoadedArchives("search_icon_layout_00.bncl");
    LoadNcgrData2(&gDownloadScreenFiles->mSearchIconChars, FindFileInLoadedArchives("search_icon_00.nce.ncgr"));
    LoadNcerData(&gDownloadScreenFiles->mSearchIconCells, FindFileInLoadedArchives("search_icon_00.nce.ncer"));
    LoadNclrData(&gDownloadScreenFiles->mSearchIconPalette, FindFileInLoadedArchives("search_icon_00_o.nclr"));
    switch (data_021759d0->mLanguageIndex) {
        default:
            InitFontIfLoaded(&gDownloadScreenFiles->mMBChildFont, FindFileInLoadedArchives("MBChild_us.NFTR"));
            break;
        case 2:
            InitFontIfLoaded(&gDownloadScreenFiles->mMBChildFont, FindFileInLoadedArchives("MBChild_fr.NFTR"));
            break;
        case 3:
            InitFontIfLoaded(&gDownloadScreenFiles->mMBChildFont, FindFileInLoadedArchives("MBChild_ge.NFTR"));
            break;
        case 4:
            InitFontIfLoaded(&gDownloadScreenFiles->mMBChildFont, FindFileInLoadedArchives("MBChild_it.NFTR"));
            break;
        case 5:
            InitFontIfLoaded(&gDownloadScreenFiles->mMBChildFont, FindFileInLoadedArchives("MBChild_es.NFTR"));
            break;
    }
    switch (data_021759d0->mLanguageIndex) {
        default:
            gDownloadScreenFiles->mUnk_20 = FindFileInLoadedArchives("MBChild_us.bmg");
            break;
        case 2:
            gDownloadScreenFiles->mUnk_20 = FindFileInLoadedArchives("MBChild_fr.bmg");
            break;
        case 3:
            gDownloadScreenFiles->mUnk_20 = FindFileInLoadedArchives("MBChild_ge.bmg");
            break;
        case 4:
            gDownloadScreenFiles->mUnk_20 = FindFileInLoadedArchives("MBChild_it.bmg");
            break;
        case 5:
            gDownloadScreenFiles->mUnk_20 = FindFileInLoadedArchives("MBChild_es.bmg");
            break;
    }
    LoadNcgrData(&gDownloadScreenFiles->mMultiDownloadChars, FindFileInLoadedArchives("multi_download_00_b.NCGR"));
    LoadNclrData(&gDownloadScreenFiles->mMultiDownloadPalette, FindFileInLoadedArchives("multi_download_00_b.NCLR"));
}
