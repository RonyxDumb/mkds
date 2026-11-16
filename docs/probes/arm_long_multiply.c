// Compiler probe (docs/compiler.md): an ARM 64-bit multiply in main. Matches on 1.2 b56 to sp2p3, no 2.0 build.
// python3 tools/probe_compilers.py docs/probes/arm_long_multiply.c --flags="-O4,p -inline on,noauto"

typedef struct {
    char pad0[0x90];
    short field90;
    short field92;
    char pad94[0xc4 - 0x94];
    int fieldC4;
} Obj020dac00;

// PROBE: UpdateKuriboState2 main 0x020dac00
void UpdateKuriboState2(Obj020dac00 *obj) {
    obj->fieldC4 = (int) (((long long) obj->fieldC4 * 0x1266) >> 12);
    if (obj->fieldC4 > 0x1800) {
        obj->field90 = 3;
        obj->field92 = 1;
    }
}
