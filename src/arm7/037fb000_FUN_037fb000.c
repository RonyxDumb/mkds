/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts FUN_037faf70
#define OS_Halt thunk_FUN_038011be
#define OS_Terminate FUN_037fb000
#include <nitro/os/common/system.h>

#include <nitro/code32.h>

#include <nitro/codereset.h>

#pragma thumb off
SDK_WEAK_SYMBOL void OS_Terminate(void)
{
    while (TRUE) {
        OS_DisableInterrupts();
        OS_Halt();
    }
}
