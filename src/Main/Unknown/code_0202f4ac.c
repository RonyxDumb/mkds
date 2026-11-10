#include "Main/Unknown/code_0202f4ac.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"

void func_0202f530(void *dest, u32 fillValue, u32 size) {
    volatile u32 value = fillValue;

    MIi_CpuClearFast(value, dest, size);
}

void func_0202f51c(void *dest, u32 size) {
    func_0202f530(dest, 0, size);
}

void WLMenuSetMainBg1Record(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 cntVal7,
                            u32 cntVal8, u32 cntVal2, u32 cntVal13) {
    SetBg1Record(&displaySettings->mMainBgRecords, cntLow2, cntBit6, cntVal14, cntVal7, cntVal8, cntVal2, cntVal13);
}

void WLMenuSetSubBg3RecordParams(DisplaySettings *displaySettings, u32 cntLow2, u32 cntBit6, u32 cntVal14, u32 e,
                                 u32 cntVal8, u32 cntVal2) {
    SetBg3RecordParams(&displaySettings->mSubBgRecords, cntLow2, cntBit6, cntVal14, e, cntVal8, cntVal2);
}
