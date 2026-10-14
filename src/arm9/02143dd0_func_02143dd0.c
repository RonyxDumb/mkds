/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define func_020614d0 func_02142a30
#define WM_SetCallbackTable SetSomeFunctionPtr
#define WM_SendCommand WM_SomeFn
#define func_02062200 func_02143dd0
#include "../../vendor/sm64ds/include/types.h"
extern int func_020614d0(int x);
extern void WM_SetCallbackTable(int i, int val);
extern int WM_SendCommand(int a, int b);

int func_02062200(int x) {
    int r = func_020614d0(x);
    if (r != 0) return r;
    WM_SetCallbackTable(1, x);
    r = WM_SendCommand(1, 0);
    if (r == 0) return 2;
    return r;
}
