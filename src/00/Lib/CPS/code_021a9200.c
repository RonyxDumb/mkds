#include "00/Lib/CPS/code_021a9200.h"
#include "00/Lib/CPS/code_021a9228.h"
#include "code_02000b44.h"
#include "unk_02000000.h"
#include "Main/Net/wbt_os_thread_globals.h"
#include "os_thread.h"
#include "mb_data.h"

#pragma opt_unpromotetypes on

void CPS_SetSsl(u8 useHttps) {
    CPSSoc *connection;
    OSi_ReferSymbol(BuildInfo.mSsl);
    connection = OSi_ThreadInfo.mCurrentThread->mSpecific[0];
    if (connection != NULL) {
        connection->mUseHttps = useHttps;
    }
}
