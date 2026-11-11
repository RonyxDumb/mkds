#include "00/code_021a9200.h"
#include "00/code_021a9228.h"
#include "code_02000b44.h"
#include "unk_02000000.h"
#include "Main/Unknown/unk_0216f000.h"

#pragma opt_unpromotetypes on

void CPS_SetSsl(u8 useHttps) {
    CPSSoc *connection;
    OSi_ReferSymbol((u32) ((u8 *) &BuildInfo + 0x98));
    connection = OSi_ThreadInfo.mCurrentThread->mSpecific[0];
    if (connection != NULL) {
        connection->mUseHttps = useHttps;
    }
}
