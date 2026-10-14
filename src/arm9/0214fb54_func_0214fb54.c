/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define func_0205f994 func_0214fb90
#define func_0205ff08 func_021501c0
#define func_0205ff00 SDK_data_021501b8
#define func_0205f958 func_0214fb54
extern int func_0205f994(void *a, int *b);
extern void func_0205ff08(void);
extern void func_0205ff00(void);

int func_0205f958(void) {
    int local;
    int r = func_0205f994((void *)func_0205ff00, &local);
    if (r != 0) return r;
    func_0205ff08();
    return local;
}
