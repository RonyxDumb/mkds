#include "00/Lib/DWC/dwc_connectinet.h"
#include "00/Lib/DWC/code_02188720.h"
#include "00/code_02188000.h"
#include "00/code_021a6fa8.h"
#include "00/code_021a86bc.h"
#include "00/unk_021b5000.h"
#include "03/Net/essid_packet_steps.h"
#include "00/code_021a3000.h"
#include "00/Lib/DWC/code_0219c384.h"
#include "00/code_021a5000.h"
#include "00/unk_021b1000.h"
#include "00/Lib/DWC/code_02185954.h"
#include "00/Lib/DWC/dwc_memfunc.h"
#include "00/unk_021b4000.h"
#include "code_0214d018.h"
#include "00/Lib/GameSpy/code_0218e2dc.h"
#include "00/Lib/GameSpy/code_021a3a18.h"
#include "00/code_021a4000.h"
#include "00/code_021a88a8.h"
#include "00/code_021a8aa8.h"
#include "string.h"
#include "code_02134398.h"
#include "00/Lib/NitroWiFi/util.h"

DWCInetControl *gInetControl;

void DWC_InitInetEx(DWCInetControl *inetCntl, u16 dmaNo, u32 powerMode, u32 sslThreadPriority) {
    if (gInetControl == NULL) {
        MI_CpuFill8(inetCntl, 0, 12);
        inetCntl->mDmaNo = dmaNo;
        inetCntl->mPowerMode = 1;
        inetCntl->mState = INET_STATUS_INITIALIZED;
        inetCntl->mOnline = 0;
        gInetControl = inetCntl;
        DWC_SetAuthServer(0);
        gSslLowThreadPriority = sslThreadPriority;
    }
}

void DWC_InitInet(void *inetCntl) {
    DWC_InitInetEx((inetCntl), 3, 1, 0x14);
}

void DWC_SetAuthServer(s32 type) {
    switch (type) {
        case 0:
            DWC_Auth_SetCustomNas("https://nas.test.nintendowifi.net/ac");
            break;
        case 1:
            DWC_Auth_SetCustomNas("https://nas.dev.nintendowifi.net/ac");
            break;
        case 2:
            DWC_Auth_SetCustomNas("https://nas.nintendowifi.net/ac");
            break;
    }
}

void DWC_ConnectInetAsync(void) {
    DWCACConfig config;
    if (gInetControl != NULL) {
        if (gInetControl->mState != INET_STATUS_INITIALIZED) {
            return;
        }
        MI_CpuFill8(&config, 0, 12);
        config.mDmaNo = gInetControl->mDmaNo;
        config.mPowerMode = gInetControl->mPowerMode;
        config.mAlloc = DWC_Alloc;
        config.mFree = DWC_Free;
        gInetControl->mState = INET_STATUS_CONNECTING;
        if (DWC_AC_Create(&config) != 0) {
            return;
        }
        DWCi_SetError(0xb, -6);
        return;
    }
    DWCi_SetError(0xb, -4);
}

u32 DWC_CheckInet(void) {
    DWCInetControl *inetCntl;
    inetCntl = gInetControl;
    if (inetCntl == NULL) {
        return 0;
    }
    if (inetCntl->mAcState != 0) {
        inetCntl->mState = INET_STATUS_CONNECT_FINISHED;
        DWC_GetInetStatus();
        return 1;
    }
    return 0;
}

void DWC_ProcessInet(void) {
    DWCInetControl *inetCntl = gInetControl;
    if (inetCntl != NULL && inetCntl->mState == INET_STATUS_CONNECTING) {
        gInetControl->mAcState = DWC_AC_Process();
    } else if (inetCntl != NULL && inetCntl->mState == INET_STATUS_ONLINE && inetCntl->mOnline != 0 &&
               WCM_GetPhase() != 9) {
        gInetControl->mOnline = 0;
        gInetControl->mState = INET_STATUS_LINK_LOST;
    }
}

u32 DWC_GetInetStatus(void) {
    u32 result = 0;
    s32 state;
    if (gInetControl != NULL) {
        state = DWC_AC_GetStatus();
        if (state == 5) {
            gInetControl->mState = INET_STATUS_ONLINE;
            gInetControl->mOnline = 1;
            return INET_STATUS_ONLINE;
        }
        if (state < 0) {
            if (state >= -10) {
                DWCi_SetError(0xb, state - 0x2bc);
                gInetControl->mState = INET_STATUS_FAILED_SMALL_CODE;
                return INET_STATUS_FAILED_SMALL_CODE;
            }
            DWCi_SetError(5, state);
            gInetControl->mState = INET_STATUS_FAILED_LARGE_CODE;
            return INET_STATUS_FAILED_LARGE_CODE;
        }
        result = INET_STATUS_CONNECTING;
    }
    return result;
}

void DWC_CleanupInet(void) {
    int destroyResult;
    if (gInetControl != NULL) {
        destroyResult = DWC_AC_Destroy();
        while (destroyResult == 0) {
            OS_Sleep(10);
            destroyResult = DWC_AC_Destroy();
        }
        *(s32 *) &gInetControl = 0;
    }
}

BOOL DWC_CleanupInetAsync(void) {
    DWCInetControl *inetCntl = gInetControl;
    if (inetCntl == NULL) {
        return TRUE;
    }
    if (inetCntl->mState == INET_STATUS_ONLINE) {
        inetCntl->mState = INET_STATUS_CLEANING_UP;
    } else if (inetCntl->mState != INET_STATUS_CLEANING_UP) {
        return TRUE;
    }
    if (SOCL_CalmDown() != 0) {
        return FALSE;
    }
    if (DWC_AC_Destroy() != 0) {
        gInetControl = NULL;
        return TRUE;
    }
    return FALSE;
}

u32 DWCi_CheckDisconnected(void) {
    if ((gInetControl != NULL) && (gInetControl->mState == INET_STATUS_LINK_LOST)) {
        return 1;
    }
    return 0;
}

u32 DWC_GetLinkLevel(void) {
    return WCM_GetLinkLevel();
}
