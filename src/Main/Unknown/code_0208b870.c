#include "Main/Unknown/code_02018000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_0208b870.h"

void func_0208b8c8(void) {
    if (data_0217b054 != 0) {
        data_0217b054();
    }
    func_0201873c(data_0217b044);
    func_0201873c(data_0217b04c);
    if (data_0217b03c != 0) {
        func_0201873c(data_0217b03c);
    }
}

void func_0208b870(Unk02012f58 *param_1) {
    func_02018674(data_0217b044, param_1);
    func_02018674(data_0217b04c, param_1);
    if (data_0217b03c != 0) {
        func_02018674(data_0217b03c, param_1);
    }
}
