#include "Main/Race/kart_highest_lap.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/System/init_after_startup.h"

u16 GetKartHighestLap(u16 kart) {
    return g_GlobalMV->mKarts[kart].mHighestLap;
}
