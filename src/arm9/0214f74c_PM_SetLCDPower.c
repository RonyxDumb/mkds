/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define func_0205fa78 func_0214fc74
#define func_0205fab4 func_0214fcb0
#define data_020a8110 SDK_data_02180440
#define func_0205f68c PM_SetLCDPower
extern int func_0205fa78(int a);
extern int func_0205fab4(int x, int y, int z);
extern int data_020a8110;

int func_0205f68c(int mode, int arg1, int arg2, int arg3) {
    if (mode == 0) goto block0;
    if (mode != 1) goto done;
    if (arg2 == 0) {
        if ((unsigned int)(*(int*)0x27ffc3c - data_020a8110) <= 7) return 0;
    }
    if (arg1 != 0) {
        if (arg3 != 0) func_0205fa78(arg1);
        else func_0205fab4(arg1, 0, 0);
    }
    *(volatile unsigned short*)0x4000304 |= 1;
    goto done;
block0:
    *(volatile unsigned short*)0x4000304 &= ~1;
    data_020a8110 = *(int*)0x27ffc3c;
    if (arg1 != 0) {
        if (arg3 != 0) func_0205fa78(arg1);
        else func_0205fab4(arg1, 0, 0);
    }
done:
    return 1;
}
