// Compiler probe (docs/compiler.md): Thumb switch dispatch in ov001. 0x02194c7c matches on 1.2 b56 and base only,
// 0x02194ce4 on every 1.2 build; -inline auto inlines 0x02194ce4 into 0x02194c7c, which the game keeps out of line.
// python3 tools/probe_compilers.py docs/probes/thumb_switch_ov001.c --flags="-O4,p -inline on,noauto"

extern int data_ov001_021a6740[][3];
extern int data_ov001_021a66e0[];
int func_02056dec(int arg);
int func_ov001_02194ce4(int idx);

// PROBE: func_ov001_02194c7c ov001 0x02194c7c
int func_ov001_02194c7c(int idx) {
    int result = 0;
    int i;
    switch (idx) {
        case 0:
        case 1:
        case 4:
        case 5:
            return 1;
        case 2:
        case 3:
        case 6:
        case 7:
            for (i = 0; i < 3; i++) {
                result |= func_02056dec(data_ov001_021a6740[idx][i]);
            }
            result |= func_ov001_02194ce4(idx);
            break;
    }
    return result;
}

// PROBE: func_ov001_02194ce4 ov001 0x02194ce4
int func_ov001_02194ce4(int idx) {
    return func_02056dec(data_ov001_021a66e0[idx]);
}
