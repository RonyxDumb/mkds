/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define func_0206116c Wm_DisableCallbackControl
#include "../../vendor/sm64ds/include/types.h"
void func_0206116c(void)
{
    u16 *p = (u16*)0x027fff96;
    if (*p & 1)
        *p &= ~1;
}
