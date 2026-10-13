/* Decompiled C draft; module arm9; ROM address 02087d0c. No matching claim. */
#include "types.h"
#include "deps/02087d0c_Animation_GetCurrentLength.h"

int Animation_GetCurrentLength(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar1 = param_1 + 0x28U & 3;
  uVar6 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
  uVar5 = param_1 + 0x1cU & 3;
  uVar2 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  uVar5 = (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) + (uint)*(ushort *)(param_1 + 0x1a) * 4;
  uVar2 = uVar5 & 3;
  uVar3 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = iRam02087d40 + (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) * 4;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  iVar4 = (*(code *)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20))
                    (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  return iVar4 << 0xc;
}

