#include "00/code_02194874.h"

void gpiProfileMapCallback(u32 profile, u32 *mapData) {
    (*(UnkFunc *) mapData[1])(*mapData, profile, mapData[2]);
}
