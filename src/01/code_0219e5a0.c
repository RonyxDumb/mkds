#include "01/code_0219e5a0.h"

void func_ov001_0219e5d4(int i) {
    func_02016468(4, 0, data_ov001_021ca400->mUnk_038[i]->mUnk_14, data_ov001_021ca400->mUnk_038[i]->mUnk_10);
    func_02016468(8, 0, data_ov001_021ca400->mUnk_040[i]->mUnk_0c, data_ov001_021ca400->mUnk_040[i]->mUnk_08);
    func_02016468(0xf, 0, data_ov001_021ca400->mUnk_048[i]->mUnk_0c, data_ov001_021ca400->mUnk_048[i]->mUnk_08);
    func_02016468(0x14, 0, data_ov001_021ca400->mUnk_050[i]->mUnk_14, data_ov001_021ca400->mUnk_050[i]->mUnk_10);
    func_02016468(0x18, 0, data_ov001_021ca400->mUnk_058[i]->mUnk_0c, data_ov001_021ca400->mUnk_058[i]->mUnk_08);
    func_02016468(0x1f, 0, data_ov001_021ca400->mUnk_060[i]->mUnk_0c, data_ov001_021ca400->mUnk_060[i]->mUnk_08);
}

void func_ov001_0219e5a0(void) {
    *((u16 *) 0x04000008u) = *((u16 *) 0x04000008u) & 0x43 | (u16) ((u32) 0x00001f80u);
    func_ov001_0219e5d4((int) (1));
    *(u32 *) (*((int *) ((u32) (&data_ov001_021ca400))) + 0x18) = 1;
    return;
}
