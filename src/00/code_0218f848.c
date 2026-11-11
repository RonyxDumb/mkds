#include "00/code_0218f848.h"
#include "00/code_0218e2dc.h"
#include "00/code_0218e8d4.h"
#include "00/code_0218f15c.h"
#include "00/code_0218f808.h"
#include "00/code_021948f8.h"
#include "00/code_02196594.h"
#include "00/code_021a3668.h"
#include "00/code_021a3690.h"
#include "00/unk_021b23b0.h"
#include "code_021384cc.h"
#include "string.h"
#include "code_02134398.h"

u32 GpiInitialize(GpConnection *a, s32 b, s32 c) {
    GpConnection p;
    u32 r;
    s32 i;
    a->mGpiConnection = NULL;
    p.mGpiConnection = DWCi_GsMalloc(0x490);
    if (p.mGpiConnection == NULL) {
        return 1;
    }
    memset(p.mGpiConnection, 0, 0x490);
    p.mGpiConnection->mErrorMessage[0] = 0;
    p.mGpiConnection->mErrorNumber = 0;
    p.mGpiConnection->mInfoCaching = 1;
    p.mGpiConnection->mInfoCachingBuddyOnly = FALSE;
    p.mGpiConnection->mSimulation = 0;
    p.mGpiConnection->mFirewall = FALSE;
    p.mGpiConnection->mProductId = b;
    p.mGpiConnection->mNamespaceId = c;
    if (GpiInitProfileList(&p) == FALSE) {
        DWCi_GsFree(p.mGpiConnection);
        p.mGpiConnection = NULL;
        return 1;
    }
    p.mGpiConnection->mUnk_420 = 0;
    for (i = 0; i < 6; i++) {
        p.mGpiConnection->mCallbacks[i].mCallback = NULL;
        p.mGpiConnection->mCallbacks[i].mParam = 0;
    }
    p.mGpiConnection->mDebugBuffer = NULL;
    gpiDebug(&p, gGpiInitializeDebugText);
    r = GpiResetConnection(&p);
    if (r != 0) {
        gpiDestroy(&p);
        return r;
    }
    SocketStartUp();
    srand(GetElapsedMilliseconds());
    a->mGpiConnection = p.mGpiConnection;
    return 0;
}
