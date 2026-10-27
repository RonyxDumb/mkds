#include "Main/Unknown/code_021115b0.h"

#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0211130c.h"
#include "Main/Unknown/code_02111684.h"
#include "Main/Unknown/code_021114cc.h"
#include "Main/Unknown/code_02111a98.h"
#include "Main/Unknown/code_02114158.h"
#include "Main/Unknown/code_021144c0.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "01/code_02198854.h"
#include "01/code_0219a050.h"

#pragma thumb on

void func_021115b0(void *a, s16 b) {
    Unk02125de0Arg v;
    data_0217d344 = func_02036bec(a, 0x34);
    data_0217d344->mUnk_00 = a;
    data_0217d344->mUnk_30 = 0;
    data_0217d344->mUnk_32 = 0;
    func_021250b0(a);
    func_0212abdc(a, func_02111318());
    v.mUnk_00 = 1;
    v.mUnk_04 = func_020b403c(1);
    v.mUnk_08 = 0;
    v.mUnk_0c = 1;
    v.mUnk_10 = 0;
    v.mUnk_14 = 0;
    v.mUnk_1c = 1;
    v.mUnk_20 = 1;
    v.mUnk_24 = 0;
    func_02125c2c();
    func_02125de0(a, &v);
    func_021144c0(data_0217d344->mUnk_00);
    func_021143f4();
    data_0217d344->mUnk_04 = func_020369fc(data_0217d344->mUnk_00);
    func_02111684();
    func_02111a98();
    data_0217d344->mUnk_14 = b;
    data_0217d344->mUnk_16 = -1;
    data_0217d344->mUnk_0c = -1;
    data_0217d344->mUnk_2c = 2;
    if (data_0217d344->mUnk_14 == 12) {
        data_0217d344->mUnk_10 = 6;
        data_0217d344->mUnk_08 = 3;
        func_02111ab4();
    } else {
        data_0217d344->mUnk_10 = 5;
        data_0217d344->mUnk_08 = 0;
        func_ov001_0219a050();
    }
    data_0217d344->mUnk_18.mUnk_00(data_0217d344->mUnk_04);
}

#pragma thumb off
