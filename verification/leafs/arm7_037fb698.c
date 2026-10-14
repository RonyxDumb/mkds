/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define PXI_IsCallbackReady FUN_037fb698
#include  <nitro.h>

#pragma thumb off
BOOL PXI_IsCallbackReady (int fifotag, PXIProc proc)
{
    OSSystemWork * p = OS_GetSystemWork();
    return (p->pxiHandleChecker[proc] & (1UL << fifotag)) ? TRUE : FALSE;
}
