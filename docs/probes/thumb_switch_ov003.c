// Compiler probe (docs/compiler.md): Thumb switch dispatch in ov003. Matches on 1.2 b56 and base only;
// 0x021c88c4 also breaks at -O3, -O2 and -O3,p.
// python3 tools/probe_compilers.py docs/probes/thumb_switch_ov003.c --flags="-O4,p -inline on,noauto"

typedef struct {
    char pad0[0x10];
    unsigned short mUnk_10;
    unsigned short mUnk_12;
    char pad14[0x19 - 0x14];
    unsigned char mUnk_19;
    unsigned char mUnk_1a;
    unsigned char mUnk_1b;
} Obj021da228;

typedef struct {
    unsigned short mUnk_00;
    unsigned short mUnk_02;
    unsigned short mUnk_04;
    unsigned short mUnk_06;
} Rect021cca5c;

typedef struct {
    char pad0[0xe7];
    unsigned char mUnk_e7;
    char pade8[0xf5 - 0xe8];
    unsigned char mUnk_f5;
    unsigned char mUnk_f6;
} Obj021cdb2c;

extern Obj021da228 *data_ov003_021da228;
extern unsigned char data_ov003_021d65f0[];
Obj021cdb2c *func_ov003_021cdb2c(void);

// PROBE: func_ov003_021cca5c ov003 0x021cca5c
void func_ov003_021cca5c(int kind, Rect021cca5c *rect) {
    rect->mUnk_00 = data_ov003_021da228->mUnk_10;
    rect->mUnk_04 = rect->mUnk_00 + 12;
    switch (kind) {
        case 1:
            rect->mUnk_02 = data_ov003_021da228->mUnk_12 + data_ov003_021da228->mUnk_1a;
            rect->mUnk_06 = rect->mUnk_02 + data_ov003_021d65f0[data_ov003_021da228->mUnk_1b];
            break;
        case 2:
            rect->mUnk_02 = data_ov003_021da228->mUnk_12 - 13;
            rect->mUnk_06 = data_ov003_021da228->mUnk_12;
            break;
        case 3:
            rect->mUnk_02 = data_ov003_021da228->mUnk_12 + data_ov003_021da228->mUnk_19;
            rect->mUnk_06 = rect->mUnk_02 + 13;
            break;
        case 4:
            rect->mUnk_02 = data_ov003_021da228->mUnk_12;
            rect->mUnk_06 = rect->mUnk_02 + data_ov003_021da228->mUnk_19;
            break;
    }
}

// PROBE: func_ov003_021c88c4 ov003 0x021c88c4
int func_ov003_021c88c4(int kind) {
    Obj021cdb2c *obj = func_ov003_021cdb2c();
    int result = 1;
    switch (kind) {
        case 7:
            if (obj->mUnk_f5 == 0) {
                result = 0;
            }
            break;
        case 0:
        case 1:
            if (obj->mUnk_e7 == 1 || obj->mUnk_e7 == 2) {
                result = 0;
            }
            break;
        case 4:
        case 5:
        case 6:
            if (obj->mUnk_f5 != 0) {
                result = 0;
            }
            break;
        case 9:
        case 10:
            if (obj->mUnk_f6 != 0) {
                result = 0;
            }
            break;
    }
    return result;
}
