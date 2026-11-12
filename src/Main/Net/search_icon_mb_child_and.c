#include "Main/Net/search_icon_mb_child_and.h"
#include "Main/System/heap.h"
#include "Main/Graphics/oam.h"
#include "Main/Race/race_start_sequence.h"
#include "Main/System/result_archive_path.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "tp.h"
#include "code_020222ec.h"
#include "Main/Graphics/font_and_player_character.h"

struct DownloadScreenFiles *gDownloadScreenFiles;

void CreateSearchIconMBChildAndMultiDownload(void *heap) {
    gDownloadScreenFiles = HeapAlloc(heap, 0x2c);
    gDownloadScreenFiles->mSearchIconCellLayout = FindFileInLoadedArchives("search_icon_00.bncl");
    gDownloadScreenFiles->mSearchIconLayoutCellLayout = FindFileInLoadedArchives("search_icon_layout_00.bncl");
    LoadNcgrData2(&gDownloadScreenFiles->mSearchIconChars, FindFileInLoadedArchives("search_icon_00.nce.ncgr"));
    LoadNcerData(&gDownloadScreenFiles->mSearchIconCells, FindFileInLoadedArchives("search_icon_00.nce.ncer"));
    LoadNclrData(&gDownloadScreenFiles->mSearchIconPalette, FindFileInLoadedArchives("search_icon_00_o.nclr"));
    switch (gStartupWork->mLanguageIndex) {
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
    switch (gStartupWork->mLanguageIndex) {
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
