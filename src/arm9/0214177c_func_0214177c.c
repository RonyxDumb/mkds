/* Public C reconstruction; complete local function bytes verified. Full ROM remains unverified. */
#define func_020712a0 func_02141b5c
#define func_02070ec0 func_0214177c
#define func_02071364 func_02141c98
#define data_0209a628 SDK_data_0216ef98
#define data_0209a658 SDK_data_0216efc8
#define data_0209a680 SDK_data_0216eff0
#define data_0209a698 SDK_data_0216f008
#define data_0209a6a8 SDK_data_0216f018
#define data_0209a6b0 SDK_data_0216f020
#define data_0209a6b8 SDK_data_0216f028
#define data_0209a6c0 SDK_data_0216f030
#define data_0209a6c8 SDK_data_0216f038
#define data_0209a6cc SDK_data_0216f03c
#define data_0209a6d0 SDK_data_0216f040
#define data_0209a6d4 SDK_data_0216f044
#define data_0209a6d8 SDK_data_0216f048
#define data_0209a6dc SDK_data_0216f04c
#define data_0209a6e0 SDK_data_0216f050
#define data_0209a6e4 SDK_data_0216f054
#define data_0209a6e8 SDK_data_0216f058
#define data_0209a6ec SDK_data_0216f05c
#define data_0209a6f0 SDK_data_0216f060
#define data_0209a6f4 SDK_data_0216f064
#define data_0209a6f8 SDK_data_0216f068
typedef struct Big {
    short v[19];
} Big;

extern unsigned char data_0209a628[];
extern unsigned char data_0209a658[];
extern unsigned char data_0209a680[];
extern unsigned char data_0209a698[];
extern unsigned char data_0209a6a8[];
extern unsigned char data_0209a6b0[];
extern unsigned char data_0209a6b8[];
extern unsigned char data_0209a6c0[];
extern unsigned char data_0209a6c8[];
extern unsigned char data_0209a6cc[];
extern unsigned char data_0209a6d0[];
extern unsigned char data_0209a6d4[];
extern unsigned char data_0209a6d8[];
extern unsigned char data_0209a6dc[];
extern unsigned char data_0209a6e0[];
extern unsigned char data_0209a6e4[];
extern unsigned char data_0209a6e8[];
extern unsigned char data_0209a6ec[];
extern unsigned char data_0209a6f0[];
extern unsigned char data_0209a6f4[];
extern unsigned char data_0209a6f8[];

void func_020712a0(Big *out, unsigned char *str, short val);
void func_02071364(Big *dst, Big *a, Big *b);
void func_02070ec0(Big *out, int n);

void func_02070ec0(Big *out, int n)
{
    Big half;
    Big copy;

    switch (n) {
    case -64: func_020712a0(out, data_0209a628, -20); return;
    case -53: func_020712a0(out, data_0209a658, -16); return;
    case -32: func_020712a0(out, data_0209a680, -10); return;
    case -16: func_020712a0(out, data_0209a698, -5); return;
    case -8:  func_020712a0(out, data_0209a6a8, -3); return;
    case -7:  func_020712a0(out, data_0209a6b0, -3); return;
    case -6:  func_020712a0(out, data_0209a6b8, -2); return;
    case -5:  func_020712a0(out, data_0209a6c0, -2); return;
    case -4:  func_020712a0(out, data_0209a6c8, -2); return;
    case -3:  func_020712a0(out, data_0209a6cc, -1); return;
    case -2:  func_020712a0(out, data_0209a6d0, -1); return;
    case -1:  func_020712a0(out, data_0209a6d4, -1); return;
    case 0:   func_020712a0(out, data_0209a6d8, 0); return;
    case 1:   func_020712a0(out, data_0209a6dc, 0); return;
    case 2:   func_020712a0(out, data_0209a6e0, 0); return;
    case 3:   func_020712a0(out, data_0209a6e4, 0); return;
    case 4:   func_020712a0(out, data_0209a6e8, 1); return;
    case 5:   func_020712a0(out, data_0209a6ec, 1); return;
    case 6:   func_020712a0(out, data_0209a6f0, 1); return;
    case 7:   func_020712a0(out, data_0209a6f4, 2); return;
    case 8:   func_020712a0(out, data_0209a6f8, 2); return;
    default:
        func_02070ec0(&half, (int)(n + ((n & 0x80000000u) >> 31)) >> 1);
        func_02071364(out, &half, &half);
        if (n & 1) {
            copy = *out;
            if (n > 0)
                func_020712a0(&half, data_0209a6dc, 0);
            else
                func_020712a0(&half, data_0209a6d4, -1);
            func_02071364(out, &copy, &half);
        }
        return;
    }
}
