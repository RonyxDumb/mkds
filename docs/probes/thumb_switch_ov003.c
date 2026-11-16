// Compiler probe (docs/compiler.md): Thumb switch dispatch in ov003. Matches on 1.2 b56 and base only;
// 0x021c88c4 also breaks at -O3, -O2 and -O3,p.
// python3 tools/probe_compilers.py docs/probes/thumb_switch_ov003.c --flags="-O4,p -inline on,noauto"

typedef struct {
    char pad0[0x10];
    unsigned short field10;
    unsigned short field12;
    char pad14[0x19 - 0x14];
    unsigned char field19;
    unsigned char field1A;
    unsigned char field1B;
} Obj021da228;

typedef struct {
    unsigned short field0;
    unsigned short field2;
    unsigned short field4;
    unsigned short field6;
} Rect021cca5c;

typedef struct {
    char pad0[0xe7];
    unsigned char fieldE7;
    char pade8[0xf5 - 0xe8];
    unsigned char fieldF5;
    unsigned char fieldF6;
} Obj021cdb2c;

extern Obj021da228 *data_ov003_021da228;
extern unsigned char data_ov003_021d65f0[];
Obj021cdb2c *func_ov003_021cdb2c(void);

// PROBE: func_ov003_021cca5c ov003 0x021cca5c
void func_ov003_021cca5c(int kind, Rect021cca5c *rect) {
    rect->field0 = data_ov003_021da228->field10;
    rect->field4 = rect->field0 + 12;
    switch (kind) {
        case 1:
            rect->field2 = data_ov003_021da228->field12 + data_ov003_021da228->field1A;
            rect->field6 = rect->field2 + data_ov003_021d65f0[data_ov003_021da228->field1B];
            break;
        case 2:
            rect->field2 = data_ov003_021da228->field12 - 13;
            rect->field6 = data_ov003_021da228->field12;
            break;
        case 3:
            rect->field2 = data_ov003_021da228->field12 + data_ov003_021da228->field19;
            rect->field6 = rect->field2 + 13;
            break;
        case 4:
            rect->field2 = data_ov003_021da228->field12;
            rect->field6 = rect->field2 + data_ov003_021da228->field19;
            break;
    }
}

// PROBE: func_ov003_021c88c4 ov003 0x021c88c4
int func_ov003_021c88c4(int kind) {
    Obj021cdb2c *obj = func_ov003_021cdb2c();
    int result = 1;
    switch (kind) {
        case 7:
            if (obj->fieldF5 == 0) {
                result = 0;
            }
            break;
        case 0:
        case 1:
            if (obj->fieldE7 == 1 || obj->fieldE7 == 2) {
                result = 0;
            }
            break;
        case 4:
        case 5:
        case 6:
            if (obj->fieldF5 != 0) {
                result = 0;
            }
            break;
        case 9:
        case 10:
            if (obj->fieldF6 != 0) {
                result = 0;
            }
            break;
    }
    return result;
}
