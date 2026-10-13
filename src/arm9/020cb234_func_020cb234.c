/* Decompiled C draft; module arm9; ROM address 020cb234. No matching claim. */
#include "types.h"
#include "deps/020cb234_func_020cb234.h"

void func_020cb234(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = func_020ccccc();
  iVar4 = *(int *)(*piRam020cb2bc + iRam020cb2c0);
  iVar3 = *(int *)(*piRam020cb2bc + iRam020cb2c4);
  if (iVar2 < 10) {
    uVar1 = ComputeValueInterpolation_from_thumb(1,0xffffffd8,0,iVar2,10);
    *(undefined2 *)(iVar4 + 6) = uVar1;
    uVar1 = ComputeValueInterpolation_from_thumb(1,0xf0,0,iVar2,10);
    iVar2 = 0;
    do {
      *(undefined2 *)(iVar3 + iVar2 * 0x40 + 4) = uVar1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0xf);
    func_02128374();
  }
  else {
    iVar2 = 0;
    *(undefined2 *)(iVar4 + 6) = 0;
    do {
      *(undefined2 *)(iVar3 + iVar2 * 0x40 + 4) = 0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0xf);
    func_020ccc74(1,0x1f);
    func_021281c8(0xf);
    *(undefined4 *)(*piRam020cb2bc + iRam020cb2c8) = 0;
  }
  func_020cb2d4();
  return;
}

