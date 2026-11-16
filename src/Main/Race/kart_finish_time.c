#include "Main/Race/kart_finish_time.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/System/init_after_startup.h"

u32 GetKartFinishTimeMs(u32 kart) {
    return g_GlobalMV->mKarts[kart].mFinishTimeMs;
}
