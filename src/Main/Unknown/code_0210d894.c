#include "Main/Unknown/code_0210d894.h"
#include "Main/Unknown/code_0210d890.h"
#include "Main/Unknown/code_0210dc60.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_0212c6a0.h"
#include "code_0212ba68.h"
#include "code_0212da38.h"
#include "code_0212d5e0.h"
#include "code_0212df7c.h"

void func_0210d894(void *a, u32 b, const u8 *c) {
    func_0212baa8();
    data_0217d130 = func_0212dcc8(a, b);
    data_0217d06c = func_0212db7c(data_0217d130, 0x1020, func_0210d890, 0, 0);
    if (c != 0) {
        func_0212d8e0(&data_0217d0a0, c, data_0217d130, 0);
        data_0217d064 = 1;
        func_0212edac(data_0217d130);
    }
    func_0212c6a0(&data_0217d068);
    func_0210dc60(&data_0217d084, &data_0217d070, 0);
}
