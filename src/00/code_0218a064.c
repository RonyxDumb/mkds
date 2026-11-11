#include "00/code_0218a064.h"
#include "00/code_021884d8.h"
#include "00/code_021898dc.h"
#include "00/code_0218a018.h"
#include "00/unk_021b0000.h"
#include "code_0214d018.h"

void MakeSOCConfig(const SocketAllocPair *hold, ACWORK *work, SOCConfig *config) {
    DWCMemPage *info;

    MI_CpuCopy8(gAcSocConfig, config, 0x58);
    config->mAlloc = hold->mAlloc;
    config->mFree = hold->mFree;
    if (work->mConnectApType < 6) {
        info = &work->mUserInfo[DWCi_ConvConnectAPType(work->mConnectApType)];
        if (info->mIp[0] != 0) {
            config->mFlag = 0;
            config->mAddr = ConvAddress(info->mIp);
            config->mNetmask = ConvNetMask(info->mNetmaskCidr);
            config->mRouter = ConvAddress(info->mGateway);
            config->mDns1 = ConvAddress(info->mDns1);
            config->mDns2 = ConvAddress(info->mDns2);
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
