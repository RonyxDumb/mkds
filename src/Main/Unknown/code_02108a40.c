#include "Main/Unknown/code_02108a40.h"

#include "code_0212c6ac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d068.h"

void func_02108b2c(void) {
    func_0212c6f0(&data_0217c788, 1);
    if (data_0217c788 != 0) {
        func_0212c6f0(&data_0217c788, 0);
    }
    func_0212ecc0(&data_0217c788, 0, 0x204);
}

void func_02108adc(void) {
    func_0212c6f0((Unk0212c400 **) data_0217c778, 1);
    if (((Unk0212c400 **) data_0217c778)[0] != 0) {
        func_0212c6f0((Unk0212c400 **) data_0217c778, 0);
    }
    func_0212ecc0(data_0217c778, 0, 0x205);
}

void func_02108a8c(void) {
    func_0212c6f0((Unk0212c400 **) data_0217c778, 1);
    if (((Unk0212c400 **) data_0217c778)[0] != 0) {
        func_0212c6f0((Unk0212c400 **) data_0217c778, 0);
    }
    func_0212ecc0(data_0217c778, 0, 0x206);
}

void func_02108a40(void) {
    func_0212c6f0(&data_0217c788, 1);
    func_0212c6f0((Unk0212c400 **) data_0217c778, 1);
    func_0212ecc0(&data_0217d068, 0, 0x207);
}
