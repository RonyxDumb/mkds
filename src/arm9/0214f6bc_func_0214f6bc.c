/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define func_0205ff20 func_021501d8
#define func_0205f8b0 func_0214fa7c
#define data_020a8114 SDK_data_02180448
#define func_0205f5fc func_0214f6bc
int func_0205ff20(int a, int b, int c);
void func_0205f8b0(int param);

struct D020a8114 { int w0; int w1; int w2; };
extern struct D020a8114 data_020a8114;

int func_0205f5fc(int a, int b, int c) {
    if (!func_0205ff20(a, b, c)) return 1;
    data_020a8114.w1 = b;
    data_020a8114.w2 = c;
    func_0205f8b0((a & 0xff) | 0x3006600);
    return 0;
}
