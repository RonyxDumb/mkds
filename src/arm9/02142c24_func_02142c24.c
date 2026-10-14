/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define func_0206152c Wm_CheckInitialized
#define WM_CheckStateEx func_02142988
#define func_0206116c Wm_DisableCallbackControl
#define func_0205ba64 Fifo_RegisterHandler
#define data_020a89ac SDK_data_0217eed4
#define data_020a89a8 SDK_data_0217eed0
#define func_02061674 func_02142c24
#include "../../vendor/sm64ds/include/types.h"
extern int func_0206152c(void);
extern int WM_CheckStateEx(int a, int b);
extern void func_0206116c(void);
extern void func_0205ba64(int idx, void *handler);

extern int data_020a89ac;
extern u16 data_020a89a8;

int func_02061674(void)
{
    int r;
    if (func_0206152c() != 0)
        return 3;
    r = WM_CheckStateEx(1, 0);
    if (r != 0)
        return r;
    func_0206116c();
    func_0205ba64(0xa, 0);
    data_020a89ac = 0;
    data_020a89a8 = 0;
    return 0;
}
