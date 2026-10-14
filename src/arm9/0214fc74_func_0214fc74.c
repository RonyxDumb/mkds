/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define func_0205f5fc func_0214fcb0
#define func_0205ff08 func_021501c0
#define func_0205ff00 SDK_data_021501b8
#define func_0205f5c0 func_0214fc74
extern int func_0205f5fc(int a, void *b, int *c);
extern void func_0205ff08(void);
extern void func_0205ff00(void);

int func_0205f5c0(int a) {
    int local;
    int r = func_0205f5fc(a, (void *)func_0205ff00, &local);
    if (r != 0) return r;
    func_0205ff08();
    return local;
}
