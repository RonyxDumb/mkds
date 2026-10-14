/* Decompiled C draft; module arm9; ROM address 02095d1c. No matching claim. */
#include "types.h"
#include "deps/02095d1c_func_02095d1c.h"

void func_02095d1c(uint param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  iVar4 = iRam02095db4;
  uVar3 = uRam02095db0;
  if (param_1 == 0) {
    return;
  }
  iVar6 = 0;
  while( true ) {
    if ((int)(uint)*(ushort *)(param_1 + 4) <= iVar6) {
      return;
    }
    uVar7 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + iVar6 * 4;
    uVar2 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar7 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
    if (uVar7 == 0) break;
    uVar2 = uVar7 + 0x9c & 3;
    uVar5 = *(uint *)(uVar7 + 0x9c & 0xfffffffc);
    iVar1 = (int)*(short *)((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + 0x28) << 0xc;
    *(int *)(uVar7 + 0xa8) = (int)((longlong)iVar4 * (longlong)iVar1 >> 0x25) - (iVar1 >> 0x1f);
    func_020e516c((uint *)(uintptr_t)(uVar7 + 0xdc),(int *)(uintptr_t)(uVar7 + 4),uVar3,0xe);
    iVar6 = iVar6 + 1;
  }
  return;
}

