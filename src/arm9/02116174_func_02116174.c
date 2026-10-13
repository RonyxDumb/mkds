/* Decompiled C draft; module arm9; ROM address 02116174. No matching claim. */
#include "types.h"
#include "deps/02116174_func_02116174.h"

void func_02116174(void)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_r1;
  int iVar3;
  
  iVar3 = (*(short *)(*piRam021161c8 + 0x74) + -1) * 0x10000 >> 0x10;
  if (iVar3 < 0) {
    iVar3 = 4;
    iVar1 = func_02116844(4);
    if (iVar1 == 0) {
      uVar2 = func_021143b4();
      _s32_div_f(uVar2,5);
      iVar3 = (extraout_r1 + -1) * 0x10000 >> 0x10;
    }
  }
  if (*(short *)(*piRam021161c8 + 0x74) != iVar3) {
    NNSi_MaybeSndPlayerStartSeq(uRam021161cc,0,0);
  }
  *(short *)(*piRam021161c8 + 0x74) = (short)iVar3;
  return;
}

