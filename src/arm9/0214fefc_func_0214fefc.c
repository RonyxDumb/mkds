/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define func_0205ff20 func_021501d8
#define func_0205f8b0 func_0214fa7c
#define func_0205f68c PM_SetLCDPower
#define data_020a8108 SDK_data_02180434
#define data_020a810c SDK_data_02180438
#define func_0205fc44 func_0214fefc
extern int func_0205ff20(void);
extern void func_0205f8b0(int param);
extern void func_0205f68c(int a, int b, int c, int d);
extern volatile int data_020a8108;
extern int data_020a810c;

int func_0205fc44(unsigned int a, unsigned int b)
{
    volatile int *p;

    if (!func_0205ff20()) return 1;
    data_020a8108 = 0;
    func_0205f8b0(0x3006000);
    p = &data_020a8108;
    while (!*p) { }
    *p = 0;
    data_020a810c = 0;
    func_0205f68c(0, 2, 0, 0);
    func_0205f8b0((a & 0xff) | 0x2006100);
    func_0205f8b0((b & 0xffff) | 0x1010000);
    return 0;
}
