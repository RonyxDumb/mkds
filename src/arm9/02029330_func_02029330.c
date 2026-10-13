/* Decompiled C draft; module arm9; ROM address 02029330. No matching claim. */
#include "types.h"
#include "deps/02029330_func_02029330.h"

void func_02029330(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  int extraout_r1_03;
  int iVar4;
  
  iVar1 = func_020280dc();
  if (iVar1 == 0) {
    iVar1 = *piRam0202940c;
    iVar1 = func_02025da4(*(undefined4 *)(iVar1 + 0x98),*(undefined4 *)(iVar1 + 0xa4),
                          *(undefined4 *)(iVar1 + 0xa8));
    iVar2 = func_02025df4(*(undefined4 *)(*piRam0202940c + 0x98),
                          *(undefined4 *)(*piRam0202940c + 0xa4));
    iVar4 = *piRam0202940c;
    if (*(int *)(iVar4 + iRam02029410) == 0) {
      *(uint *)(*(int *)(iVar4 + 0x60) + iRam02029414) = (uint)(9 < iVar1);
      uVar3 = _s32_div_f(iVar1,10);
      _s32_div_f(uVar3,10);
      func_02025c48(5,extraout_r1 + 10,*(undefined4 *)(iVar4 + 0x54));
      _s32_div_f(iVar1,10);
      func_02025c48(6,extraout_r1_00 + 10,*(undefined4 *)(iVar4 + 0x54));
      if (iVar2 < 10) {
        *(undefined4 *)(*(int *)(iVar4 + 0x60) + iRam02029418) = 0;
        _s32_div_f(iVar2,10);
        func_02025c48(8,extraout_r1_03 + 0x14,*(undefined4 *)(iVar4 + 0x54));
      }
      else {
        uVar3 = _s32_div_f(iVar2,10);
        _s32_div_f(uVar3,10);
        func_02025c48(8,extraout_r1_01 + 0x14,*(undefined4 *)(iVar4 + 0x54));
        _s32_div_f(iVar2,10);
        func_02025c48(9,extraout_r1_02 + 0x14,*(undefined4 *)(iVar4 + 0x54));
      }
    }
    else {
      func_0202b554(iVar1,iVar2);
    }
  }
  return;
}

