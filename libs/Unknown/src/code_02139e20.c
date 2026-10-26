#pragma avoid_byte all

#include "code_02139e20.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_0217e000.h"

int func_02139e20(int a) {
    Unk02139e20Func f;

    if (a < 1 || a > 7) {
        return -1;
    }
    if (func_0200ec08(data_0217eb68) == 0) {
        data_0217ea94[7] = *(u32 *) (*(u32 *) (data_0216ff5c + 8) + 0x6c);
        data_0217eab8[7] = 1;
    } else if (data_0217ea94[7] == *(u32 *) (*(u32 *) (data_0216ff5c + 8) + 0x6c)) {
        data_0217eab8[7]++;
    } else {
        func_0200ed34(data_0217eb68);
        data_0217ea94[7] = *(u32 *) (*(u32 *) (data_0216ff5c + 8) + 0x6c);
        data_0217eab8[7] = 1;
    }
    f = data_0217ee94[a - 1];
    if (f != (Unk02139e20Func) 1) {
        data_0217ee94[a - 1] = 0;
    }
    data_0217eab8[7]--;
    if (data_0217eab8[7] == 0) {
        func_0200ecc4(data_0217eb68);
    }
    if (f == (Unk02139e20Func) 1 || (f == 0 && a == 1)) {
        return 0;
    }
    if (f == 0) {
        func_02133f84(0);
    }
    f(a);
    return 0;
}
