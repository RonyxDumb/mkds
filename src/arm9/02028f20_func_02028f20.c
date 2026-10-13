/* Decompiled C draft; module arm9; ROM address 02028f20. No matching claim. */
#include "types.h"
#include "deps/02028f20_func_02028f20.h"

void func_02028f20(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = func_020280dc();
  if (iVar1 == 0) {
    uVar2 = func_02025d98(*(undefined4 *)(*piRam02028f7c + 0xa8));
    uVar2 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piRam02028f7c + 0x88),uVar2);
    iVar1 = iRam02028f80;
    iVar3 = *piRam02028f7c;
    iVar4 = 8;
    do {
      func_0212426c(1,(int)*(short *)(iVar1 + iVar4 * 0xc),*(undefined4 *)(iVar3 + 0x78),uVar2,
                    *(undefined4 *)(iVar3 + 0x70),*(undefined4 *)(iVar3 + 0x7c));
      iVar4 = iVar4 + -1;
    } while (6 < iVar4);
  }
  return;
}

