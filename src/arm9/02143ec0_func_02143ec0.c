/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define WM_CheckStateEx func_02142988
#define WM_SetCallbackTable SetSomeFunctionPtr
#define WM_SendCommand WM_SomeFn
#define func_020622f0 func_02143ec0
extern int WM_CheckStateEx(int a, int b);
extern void WM_SetCallbackTable(int i, int val);
extern int WM_SendCommand(int a, int b);

int func_020622f0(int this)
{
    int r;
    r = WM_CheckStateEx(1, 1);
    if (r != 0) return r;
    WM_SetCallbackTable(5, this);
    r = WM_SendCommand(5, 0);
    if (r == 0) return 2;
    return r;
}
