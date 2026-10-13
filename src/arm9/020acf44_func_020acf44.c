/* Decompiled C draft; module arm9; ROM address 020acf44. No matching claim. */
#include "types.h"
#include "deps/020acf44_func_020acf44.h"

void func_020acf44(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = *(int *)(*piRam020acfe8 + 0x68);
  iVar2 = func_020acbe8(*(undefined4 *)(*piRam020acfe8 + 0x6c));
  iVar3 = func_020adaf8();
  if (iVar3 < 10) {
    iVar3 = 0;
    do {
      uVar4 = func_020adaf8();
      uVar1 = ComputeValueInterpolation_from_thumb(1,0xf8,0,uVar4,10);
      *(undefined2 *)(iVar6 + iVar3 * 0x40 + 4) = uVar1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0xf);
    iVar3 = 0;
    do {
      uVar4 = func_020adaf8();
      uVar1 = ComputeValueInterpolation_from_thumb(1,0xe4,0,uVar4,10);
      *(undefined2 *)(iVar6 + (iVar3 + iVar2) * 0x40 + 4) = uVar1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 2);
  }
  else {
    iVar5 = 0;
    iVar3 = 0;
    do {
      *(undefined2 *)(iVar6 + iVar5 * 0x40 + 4) = 0;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0xf);
    do {
      *(undefined2 *)(iVar6 + (iVar3 + iVar2) * 0x40 + 4) = 0;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 2);
    func_020adad0(2,8);
    *(undefined4 *)(*piRam020acfe8 + 0x58) = 0;
  }
  func_020acff4();
  return;
}

