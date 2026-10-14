/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts FUN_037faf70
#define OS_RestoreInterrupts FUN_037faf84
#define OSi_ThreadInfo SDK_data_038076fc
#define OS_SetSwitchThreadCallback FUN_037f8db0
#include <nitro/os.h>
#include <nitro/mi.h>
#include <nitro/utest.h>

#include <nitro/code32.h>

#include  <nitro/codereset.h>
extern OSThreadInfo OSi_ThreadInfo;
#pragma thumb off
OSSwitchThreadCallback OS_SetSwitchThreadCallback (OSSwitchThreadCallback callback)
{
    OSSwitchThreadCallback prev;
    OSIntrMode enabled;

    enabled = OS_DisableInterrupts();
    prev = OSi_ThreadInfo.switchCallback;
    OSi_ThreadInfo.switchCallback = callback;

    (void)OS_RestoreInterrupts(enabled);
    return prev;
}
