/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OS_DisableInterrupts FUN_037faf70
#define OSi_ExitThread_ArgSpecified FUN_037f923c
#define OSi_ThreadInfo SDK_data_038076fc
#define OS_ExitThread FUN_037f92a4
#include <nitro/os.h>
#include <nitro/mi.h>
#include <nitro/utest.h>

#include <nitro/code32.h>

#include  <nitro/codereset.h>
extern void OSi_ExitThread_ArgSpecified (OSThread * thread, void * arg);
extern OSThreadInfo OSi_ThreadInfo;
#pragma thumb off
void OS_ExitThread (void)
{
    (void)OS_DisableInterrupts();

#ifdef SDK_THREAD_INFINITY
    OSi_ExitThread_ArgSpecified(OS_GetCurrentThread(), 0);
#else
    OSi_ExitThread_Destroy();
#endif
}
