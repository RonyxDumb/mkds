#include "00/code_021acef8.h"
#include "00/code_021a8878.h"
#include "00/code_021acfd8.h"
#include "00/code_021ad018.h"
#include "00/unk_021b6380.h"

u32 CPS_Resolve(const char *name) {
    u32 address;
    u8 askServer[2];
    u16 queryIds[2];
    s32 retry;
    s32 serverIndex;

    CPSiRand32ctx[0] = (s64) CPSiRand32ctx[1] * (s64) CPSiRand32ctx[0] + CPSiRand32ctx[2];
    queryIds[0] = ((CPSiRand32ctx[0] >> 32) * 0x10000) >> 32;
    CPSiRand32ctx[0] = (s64) CPSiRand32ctx[1] * (s64) CPSiRand32ctx[0] + CPSiRand32ctx[2];
    queryIds[1] = ((CPSiRand32ctx[0] >> 32) * 0x10000) >> 32;
    if (rawip(name, &address) != FALSE) {
        return address;
    }
    askServer[0] = 1;
    askServer[1] = 1;
    for (retry = 0; retry < 3; retry++) {
        for (serverIndex = 0; serverIndex < 2; serverIndex++) {
            if (askServer[serverIndex] != 0) {
                address = resolve_sub(name, CPSDnsIp[serverIndex], queryIds[serverIndex]);
                if (address != 0 && address != 0xffffffff) {
                    goto done;
                }
                if (address == 0xffffffff) {
                    askServer[serverIndex] = 0;
                }
            }
        }
    }
done:
    if (address == 0xffffffff) {
        address = 0;
    }
    return address;
}
