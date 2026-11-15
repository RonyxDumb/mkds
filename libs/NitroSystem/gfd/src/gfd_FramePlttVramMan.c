#include "gfd_FramePlttVramMan.h"
#include "Main/Graphics/g3d_anm_function_pointers.h"
#include "data_02173000.h"
#include "gfd_LinkedListPlttVramMan.h"
#include "mic.h"
#include "gfd_LinkedListTexVramMan.h"
#include "gfd_FrameTexVramMan.h"

NNSGfdFrmPlttVramManager s_managerState_;

void NNS_GfdInitFrmPlttVramManager(u32 szByte, s32 useAsDefault) {
    s_managerState_.mSzTotal = szByte;
    NNS_GfdResetFrmPlttVramState();
    if (useAsDefault != 0) {
        NNS_GfdDefaultFuncAllocPlttVram = (u32(*)(s32, s32, s32)) NNS_GfdAllocFrmPlttVram;
        NNS_GfdDefaultFuncFreePlttVram = NNS_GfdFreeFrmPlttVram;
    }
}

u32 NNS_GfdAllocFrmPlttVram(u32 szByte, s32 bPltt4, s32 allocFrom) {
    u32 addr = 0;
    u32 increase;
    u32 current;
    u32 alignment;
    u32 found;
    if (szByte == 0) {
        szByte = 8;
    } else {
        szByte = (szByte + 7) & ~7;
    }
    if (szByte >= 0x7fff8) {
        return 0;
    }
    if (allocFrom == 1) {
        current = s_managerState_.mLoAddr;
        if (bPltt4 != 0) {
            alignment = (8 - (current & 7)) & 7;
        } else {
            alignment = (16 - (current & 0xf)) & 0xf;
        }
        increase = szByte + alignment;
        if (s_managerState_.mHiAddr - current >= increase) {
            found = current + increase;
            if (bPltt4 != 0 && found > 0x10000) {
                found = 0;
            } else {
                addr = current + alignment;
                found = 1;
                s_managerState_.mLoAddr += increase;
            }
        } else {
            found = 0;
        }
    } else {
        current = s_managerState_.mHiAddr;
        if (current >= szByte) {
            increase = current - szByte;
            if (bPltt4 != 0) {
                alignment = increase & 7;
            } else {
                alignment = increase & 0xf;
            }
            increase = szByte + alignment;
            if (current - s_managerState_.mLoAddr >= increase) {
                if (bPltt4 != 0 && current > 0x10000) {
                    found = 0;
                } else {
                    found = 1;
                    s_managerState_.mHiAddr -= increase;
                    addr = s_managerState_.mHiAddr;
                }
                goto done;
            }
        }
        found = 0;
    }
done:
    if (found != 0) {
        return ((szByte >> 3) << 16) | ((addr >> 3) & 0xffff);
    }
    return 0;
}

// Frame managers do not free single blocks.
s32 NNS_GfdFreeFrmPlttVram(u32 plttKey) {
    return 0;
}

void NNS_GfdResetFrmPlttVramState(void) {
    s_managerState_.mLoAddr = 0;
    s_managerState_.mHiAddr = s_managerState_.mSzTotal;
}
