#include "00/Lib/CPS/https_enable_flag.h"
#include "00/Lib/CPS/https_protocol.h"
#include "startup_entry.h"
#include "build_info_layout.h"
#include "Main/Net/wbt_os_thread_globals.h"
#include "thread_scheduler.h"
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
