#include "01/code_021932c8.h"
#include "01/code_02195000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02126000.h"

void func_ov001_021932e4(void) {
    Unk021a9bd0_18 callbacks = data_ov001_021a8170;

    func_ov001_02192eac((UnkFunc **) &callbacks);
}

void func_ov001_021932c8(void) {
    data_ov001_021a9bd0->mUnk_18.mUnk_00 = 0;
    data_ov001_021a9bd0->mUnk_18.mUnk_04 = 0;
    data_ov001_021a9bd0->mUnk_18.mUnk_08 = 0;
    data_ov001_021a9bd0->mUnk_18.mUnk_0c = 0;
}
