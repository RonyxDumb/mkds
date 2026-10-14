/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define MI_CpuCopy8 SDK_data_0214d1fc
#define OS_GetMacAddress Os_GetMacAddress
#include "OS_ownerInfo.h"

#include "nitro/types.h"
#include "systemWork.h"
#include "MI_memory.h"
#include "code32.h"

void OS_GetMacAddress(u8 *macAddress)
{
    MI_CpuCopy8((void *)0x027FFCF4, macAddress, 0x6);
}
