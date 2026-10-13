/* Decompiled C draft; module arm9; ROM address 02015274. No matching claim. */
#include "types.h"
#include "deps/02015274_Anim_UnkFnPtr_BCA.h"

void Anim_UnkFnPtr_BCA(undefined4 param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar4;
  uint uVar3;
  
  uVar3 = param_2 + 8 & 3;
  uVar2 = *(uint *)(param_2 + 8 & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar4 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  uVar2 = (uint)*(ushort *)(uVar3 + 4);
  iVar1 = uVar2 * 0x1000;
  if ((int)(uVar4 + uVar2 * -0x1000) < 0 == SBORROW4(uVar4,iVar1)) {
    uVar4 = iVar1 - 1;
  }
  else if ((int)uVar4 < 0) {
    uVar4 = 0;
  }
  func_02014c5c(uVar3,param_3,uVar4,(uint *)(uintptr_t)(param_1));
  return;
}

