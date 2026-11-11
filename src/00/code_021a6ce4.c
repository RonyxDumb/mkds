#include "00/code_021a6ce4.h"

#include "00/unk_021b5000.h"
#include "00/code_021a574c.h"
#include "00/code_021a6c08.h"
#include "code_02133048.h"
#include "code_0200fc8c.h"

u32 WCM_GetLinkLevel(void) {
    u32 enabled;
    WCMWork *work;
    u32 level;

    enabled = OS_DisableInterrupts();
    work = WCMi_GetSystemWork();
    level = 0;
    if (work != NULL && work->mPhase == 9) {
        level = WcmGetLinkLevel();
    }
    OS_RestoreInterrupts(enabled);
    return level;
}
