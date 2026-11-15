#include "Main/Net/scan_game_info.h"
#include "arena_cache_init.h"
#include "cpu_copy_fill.h"
#include "os_thread.h"

s32 IsScanBlockGameInfoMatch(WMBssDesc *bssDesc) {
    // volatile only so that userGameInfo[0] is read again for the second compare
    volatile u16 userGameInfo[4];

    if (bssDesc == 0) {
        return 0;
    }
    if (bssDesc->mGameInfoLength == 0) {
        return 0;
    }
    MI_CpuCopy8(&bssDesc->mGameInfo.mUserGameInfo, userGameInfo, 8);
    DC_StoreRange(userGameInfo, 8);
    if (bssDesc->mGameInfo.mGgid == 0) {
        if (userGameInfo[0] == 0x2348 || userGameInfo[0] == 0xbd8a) {
            if (userGameInfo[3] == 4) {
                return 1;
            }
        }
    }
    return 0;
}
