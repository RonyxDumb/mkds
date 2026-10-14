/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define InitializeCmdIf FUN_0600f118

#include "WlSys.h"
#include "DbgChar.h"

#include "WlLib.h"
#include "WlCmdIf.h"

#include "MLME.h"
#include "MA.h"
#include "ParamCmd.h"
#include "DevCmd.h"

#pragma thumb off
void InitializeCmdIf(void)
{

    wlMan->CmdIf.Busy = 0;
}
