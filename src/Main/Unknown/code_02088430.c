#include "Main/Unknown/code_02088430.h"
#include "code_02135014.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"

char *func_020887d8(s32 a, s32 b) {
    const char *e = "nsbmd";
    const char *p;
    if (b != 0) {
        p = data_02155cec[a].mUnk_00;
    } else {
        p = data_02155cf0[a].mUnk_00;
    }
    func_02135048(data_0217af28, 0x100, "%s%s%s", data_0217af24, data_02165ac4, data_02165e80[a]);
    func_02135048(data_0217af28, 0x100, "%s%s.%s", data_0217af28, p, e);
    return data_0217af28;
}

char *func_02088728(s32 a, s32 b) {
    const char *e = "nsbtx";
    const char *p;
    if (b != 0) {
        p = data_02155cec[a].mUnk_00;
    } else {
        p = data_02155cf0[a].mUnk_00;
    }
    func_02135048(data_0217af28, 0x100, "%s%s%s", data_0217af24, data_02165ac4, data_02165e80[a]);
    func_02135048(data_0217af28, 0x100, "%s%s.%s", data_0217af28, p, e);
    return data_0217af28;
}

char *func_0208867c(s32 a) {
    const char *e = "nsbmd";
    func_02135048(data_0217af28, 0x100, "%s%s%skart_%s.%s", data_0217af24, data_02165ac8,
                  a % 3 == 0 ? "mario/" : data_02165e80[a / 3], data_02155d88[a].mUnk_00, e);
    return data_0217af28;
}

char *func_020885d0(s32 a) {
    const char *e = "nsbtx";
    func_02135048(data_0217af28, 0x100, "%s%s%skart_%s.%s", data_0217af24, data_02165ac8,
                  a % 3 == 0 ? "mario/" : data_02165e80[a / 3], data_02155d88[a].mUnk_00, e);
    return data_0217af28;
}

char *func_02088574(s32 a, const char *b) {
    const char *p = "nsbmd";
    func_02135048(data_0217af28, 0x100, "%s%stire/%s.%s", data_0217af24, data_02165ac8, b, p);
    return data_0217af28;
}

char *func_02088518(s32 a, const char *b) {
    const char *p = "nsbtx";
    func_02135048(data_0217af28, 0x100, "%s%stire/%s.%s", data_0217af24, data_02165ac8, b, p);
    return data_0217af28;
}

char *func_020884bc(s32 a) {
    func_02135048(data_0217af28, 0x100, "%s%sshadow/sh_%s.nsbmd", data_0217af24, data_02165ac8,
                  data_02155d8c[a].mUnk_00);
    return data_0217af28;
}

const char *func_0208848c(s32 a, s32 b) {
    if (b != 0) {
        return data_02155cec[a].mUnk_00;
    } else {
        return data_02155cf0[a].mUnk_00;
    }
}

char *func_02088430(s32 a) {
    func_02135048(data_0217af28, 0x100, "%s%s%s", data_0217af24, data_02165ac4, data_02165e80[a]);
    return data_0217af28;
}
