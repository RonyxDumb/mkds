#include "code_0200f6f4.h"
#include "code_0200c914.h"
#include "code_0200f580.h"
#include "code_0200f5ac.h"
#include "Main/Unknown/unk_02170000.h"

void func_0200f6f4(void) {
    if (data_0217024c != 0) {
        return;
    }
    data_0217024c = 1;
    func_0200f580(0);
    data_02170254 = 0;
    *(vu16 *) 0x4000102 = 0;
    *(vu16 *) 0x4000100 = 0;
    *(vu16 *) 0x4000102 = 0xc1;
    func_0200cc74(8, func_0200f65c);
    func_0200cae4(8);
    data_02170250 = 0;
}
