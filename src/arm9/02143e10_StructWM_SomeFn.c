/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define func_020616e8 Wm_Initialize
#define WM_SetCallbackTable SetSomeFunctionPtr
#define WM_GetSystemWork Wm_GetGlobal
#define WM_SendCommand WM_SomeFn
#define func_02062240 StructWM_SomeFn
extern int func_020616e8(int a, int b);
extern void WM_SetCallbackTable(int i, int val);
extern int *WM_GetSystemWork(void);
extern int WM_SendCommand(int a, int b, int c, int d, int e);

int func_02062240(int arg0, int arg1, int arg2)
{
    int *p;
    int r;
    r = func_020616e8(arg0, arg2);
    if (r) return r;
    WM_SetCallbackTable(0, arg1);
    p = WM_GetSystemWork();
    r = WM_SendCommand(0, 3, p[0], p[1], p[4]);
    if (r == 0) return 2;
    return r;
}
