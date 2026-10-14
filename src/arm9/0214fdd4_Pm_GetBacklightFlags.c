/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define func_0205f9e8 Pm_GetBacklightFlagsImpl
#define func_0205ff08 func_021501c0
#define func_0205ff00 SDK_data_021501b8
#define func_0205f9ac Pm_GetBacklightFlags
extern int func_0205f9e8(int a, int b, void *c, int *d);
extern void func_0205ff08(void);
extern void func_0205ff00(void);

int func_0205f9ac(int a, int b) {
    int local;
    int r = func_0205f9e8(a, b, (void *)func_0205ff00, &local);
    if (r != 0) return r;
    func_0205ff08();
    return local;
}
