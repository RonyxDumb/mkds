// Compiler probe (docs/compiler.md): a Thumb function walking a char path and formatting it with four copies
// each of two format strings. Breaks with -char signed (0x144 bytes) and with -str reuse (0x124).
// python3 tools/probe_compilers.py docs/probes/thumb_char_strings.c --only 1.2/base --flags="-O4,p -inline on,noauto" \
//     --flags="-O4,p -inline on,noauto -char signed" --flags="-O4,p -inline on,noauto -str reuse"

typedef struct {
    char pad0[0x18];
    const char *field18;
    const char *field1C;
    const char *field20;
    const char *field24;
    const char *field28;
} Names02164e04;

typedef struct {
    char pad0[0x308];
    int field308;
    char pad30c[0x378 - 0x30c];
    int field378;
    char pad37c[0x3e8 - 0x37c];
    int field3E8;
} Obj021759a8;

extern Names02164e04 gArchiveNames;
extern Obj021759a8 *data_021759a8;
int GetCurrentSceneNumber(void);
int OS_SNPrintf(char *dst, int len, const char *fmt, ...);
int func_02048504(const char *path, int arg);

// PROBE: LoadKartModelFile main 0x02047780
int LoadKartModelFile(const char *path) {
    char buf[0x80];
    const char *name;
    int result = 0;
    int mode = GetCurrentSceneNumber();
    if (mode == 1 || mode == 3 || mode == 12) {
        name = gArchiveNames.field28;
        if (path[0] == '/') {
            OS_SNPrintf(buf, 0x80, "%s:%s", name, path);
        } else {
            OS_SNPrintf(buf, 0x80, "%s:/%s", name, path);
        }
        result = func_02048504(buf, 8);
    } else {
        if (data_021759a8->field308 != 0) {
            name = gArchiveNames.field18;
            if (path[0] == '/') {
                OS_SNPrintf(buf, 0x80, "%s:%s", name, path);
            } else {
                OS_SNPrintf(buf, 0x80, "%s:/%s", name, path);
            }
            result = func_02048504(buf, 8);
        }
        if (result == 0 && data_021759a8->field378 != 0) {
            name = gArchiveNames.field1C;
            if (path[0] == '/') {
                OS_SNPrintf(buf, 0x80, "%s:%s", name, path);
            } else {
                OS_SNPrintf(buf, 0x80, "%s:/%s", name, path);
            }
            result = func_02048504(buf, 8);
        }
        if (result == 0 && data_021759a8->field3E8 != 0) {
            name = gArchiveNames.field20;
            if (path[0] == '/') {
                OS_SNPrintf(buf, 0x80, "%s:%s", name, path);
            } else {
                OS_SNPrintf(buf, 0x80, "%s:/%s", name, path);
            }
            result = func_02048504(buf, 8);
        }
    }
    return result;
}
