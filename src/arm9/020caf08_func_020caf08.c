/* Decompiled C draft; module arm9; ROM address 020caf08. No matching claim. */
#include "types.h"
#include "deps/020caf08_func_020caf08.h"

void func_020caf08(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = func_020ccccc();
  iVar5 = *(int *)(*piRam020caf84 + iRam020caf88);
  iVar4 = *(int *)(*piRam020caf84 + iRam020caf8c);
  if (iVar2 < 10) {
    uVar1 = ComputeValueInterpolation_from_thumb(1,0,0xffffffd8,iVar2,10);
    *(undefined2 *)(iVar5 + 6) = uVar1;
    uVar1 = ComputeValueInterpolation_from_thumb(1,0,0xf0,iVar2,10);
    iVar2 = 0;
    do {
      *(undefined2 *)(iVar4 + iVar2 * 0x40 + 4) = uVar1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0xf);
  }
  else {
    *(undefined2 *)(iVar5 + 6) = 0xffd8;
    iVar2 = 0;
    do {
      *(undefined2 *)(iVar4 + iVar2 * 0x40 + 4) = 0xf0;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0xf);
    uVar3 = func_020ccc9c();
    func_020ccc74(uVar3,0x1f);
  }
  func_020cb2d4();
  return;
}

