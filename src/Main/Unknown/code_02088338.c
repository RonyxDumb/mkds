#include "Main/Unknown/code_02088338.h"
#include "code_02135014.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"

char *func_02088390(u32 a) {
    func_02135048(data_0217af28, 0x100, data_02165ed4, data_0217af24, data_02155cf4[a].mUnk_00);
    return data_0217af28;
}

char *func_02088338(s32 a) {
    func_02135048(data_0217af28, 0x100, data_02165eb4, data_0217af24, data_02165e4c[a == 0]);
    return data_0217af28;
}
