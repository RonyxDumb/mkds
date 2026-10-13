/* Decompiled C draft; module arm9; ROM address 02052b60. No matching claim. */
#include "types.h"
#include "deps/02052b60_func_02052b60.h"

void func_02052b60(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = uRam02052bb0;
  *(undefined4 *)
   ((*(uint *)(uRam02052bb0 & 0xfffffffc) >> (uRam02052bb0 & 3) * 8 |
    *(uint *)(uRam02052bb0 & 0xfffffffc) << (uRam02052bb0 & 3) * -8 + 0x20) + 0xc) = 6;
  if (param_1 == 0) {
    param_1 = iRam02052bb4;
  }
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(undefined4 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x10) = 1;
  iVar2 = func_02143bc4(param_1);
  if (iVar2 != 2) {
    func_020533a0();
    return;
  }
  return;
}

