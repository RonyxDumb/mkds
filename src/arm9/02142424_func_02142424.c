/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define func_02071974 func_021423e4
#define func_020719b4 func_02142424
void func_02071974(int arg);

int func_020719b4(int a, int base, int *pcount) {
    int count = *pcount;
    int i;
    for (i = 0; (unsigned)i < (unsigned)count; i++) {
        func_02071974(base + i);
    }
    return 0;
}
