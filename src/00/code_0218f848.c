#include "00/code_0218f848.h"
#include "00/GameSpy/nonport.h"
#include "00/GameSpy/gp.h"
#include "00/GameSpy/gpi.h"
#include "00/code_0218f808.h"
#include "00/GameSpy/gpiProfile.h"
#include "00/GameSpy/gpiUtility.h"
#include "00/code_021a3668.h"
#include "00/code_021a3690.h"
#include "00/unk_021b23b0.h"
#include "code_021384cc.h"
#include "string.h"
#include "code_02134398.h"

char data_ov000_021b2718[36] = {10, 10, 10, 10, 10, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 10, 103, 112, 105, 73, 110, 105, 116, 105, 97, 108, 105, 122, 101, 10};

u32 GpiInitialize(GpConnection *a, s32 b, s32 c) {
    GpConnection p;
    u32 r;
    s32 i;
    a->mGpiConnection = NULL;
    p.mGpiConnection = func_ov000_021a3690(0x490);
    if (p.mGpiConnection == NULL) {
        return 1;
    }
    memset(p.mGpiConnection, 0, 0x490);
    p.mGpiConnection->mErrorMessage[0] = 0;
    p.mGpiConnection->mErrorNumber = 0;
    p.mGpiConnection->mUnk_100 = 1;
    p.mGpiConnection->mUnk_104 = FALSE;
    p.mGpiConnection->mUnk_108 = 0;
    p.mGpiConnection->mFirewall = FALSE;
    p.mGpiConnection->mProductId = b;
    p.mGpiConnection->mNamespaceId = c;
    if (GpiInitProfileList(&p) == FALSE) {
        func_ov000_021a3668(p.mGpiConnection);
        p.mGpiConnection = NULL;
        return 1;
    }
    p.mGpiConnection->mUnk_420 = 0;
    for (i = 0; i < 6; i++) {
        p.mGpiConnection->mCallbacks[i].mCallback = NULL;
        p.mGpiConnection->mCallbacks[i].mUnk_04 = 0;
    }
    p.mGpiConnection->mUnk_460 = NULL;
    func_ov000_0219690c(&p, data_ov000_021b2718);
    r = GpiResetConnection(&p);
    if (r != 0) {
        func_ov000_0218f808(&p);
        return r;
    }
    func_ov000_0218e8b8();
    srand(func_ov000_0218e8c4());
    a->mGpiConnection = p.mGpiConnection;
    return 0;
}
