/* Decompiled C draft; module arm9; ROM address 021138e4. No matching claim. */
#include "types.h"
#include "deps/021138e4_func_021138e4.h"

void func_021138e4(void)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_r1;
  int iVar3;
  
  iVar3 = (*(short *)(*piRam02113938 + 0x68) + -1) * 0x10000 >> 0x10;
  if (iVar3 < 0) {
    iVar3 = 4;
    iVar1 = func_02113ef0(4);
    if (iVar1 == 0) {
      uVar2 = func_021143b4();
      _s32_div_f(uVar2,5);
      iVar3 = (extraout_r1 + -1) * 0x10000 >> 0x10;
    }
  }
  if (*(short *)(*piRam02113938 + 0x68) != iVar3) {
    NNSi_MaybeSndPlayerStartSeq(uRam0211393c,0,0);
  }
  *(short *)(*piRam02113938 + 0x68) = (short)iVar3;
  return;
}

