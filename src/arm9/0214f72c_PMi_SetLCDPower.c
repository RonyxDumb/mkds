/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define func_0205f68c SDK_data_0214f74c
#define func_0205f66c PMi_SetLCDPower
extern int func_0205f68c(int mode, int arg1, int arg2, int arg3);

int func_0205f66c(int a) {
    int mode = a;
    if (a != 1) mode = 0;
    return func_0205f68c(mode, 0, 0, 1);
}
