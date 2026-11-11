#include "00/code_0218a064.h"
#include "00/code_021884d8.h"
#include "00/code_021898dc.h"
#include "00/code_0218a018.h"
#include "00/unk_021b0000.h"
#include "code_0214d018.h"

void MakeSOCConfig(const u32 *hold, ACWORK *work, SOCConfig *config) {
    DWCMemPage *info;

    MI_CpuCopy8(gAcSocConfig, config, 0x58);
    config->mAlloc = hold[0];
    config->mFree = hold[1];
    if (work->mConnectApType < 6) {
        info = &work->mUserInfo[DWCi_ConvConnectAPType(work->mConnectApType)];
        if (info->mUnk_c0[0] != 0) {
            config->mFlag = 0;
            config->mAddr = ConvAddress(info->mUnk_c0);
            config->mNetmask = ConvNetMask(info->mUnk_d0);
            config->mRouter = ConvAddress(info->mUnk_c4);
            config->mDns1 = ConvAddress(info->mUnk_c8);
            config->mDns2 = ConvAddress(info->mUnk_cc);
        } else {
            config->mFlag = 1;
            config->mAddr = 0;
            config->mNetmask = 0;
            config->mRouter = 0;
            config->mDns1 = 0;
            config->mDns2 = 0;
        }
    }
}
