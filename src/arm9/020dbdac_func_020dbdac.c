/* Decompiled C draft; module arm9; ROM address 020dbdac. No matching claim. */
#include "types.h"
#include "deps/020dbdac_func_020dbdac.h"

void func_020dbdac(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar2 = iRam020dbe68;
  uVar1 = param_2 + 0xb4U & 3;
  uVar3 = *(uint *)(param_2 + 0xb4U & 0xfffffffc);
  iVar5 = param_2 + 0x28;
  if (uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) {
    iVar5 = (int)(uint)*(ushort *)(param_2 + 0xba) >> 4;
    MTX_RotY33__from_thumb
              ((undefined4 *)(uintptr_t)(iRam020dbe68),(int)*(short *)(iRam020dbe64 + iVar5 * 4),
               (int)*(short *)(iRam020dbe64 + (iVar5 * 2 + 1) * 2));
    MTX_Concat33(iVar2,(uint *)(uintptr_t)(param_2 + 0x28),(uint *)(uintptr_t)(iVar2));
    iVar5 = iVar2;
  }
  uVar3 = uRam020dbe6c;
  uVar1 = param_2 + 4U & 3;
  uVar4 = *(uint *)(param_2 + 4U & 0xfffffffc);
  *(int *)(iVar5 + 0x24) = (int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 8U & 3;
  uVar4 = *(uint *)(param_2 + 8U & 0xfffffffc);
  *(int *)(iVar5 + 0x28) = (int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = param_2 + 0xcU & 3;
  uVar4 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  *(int *)(iVar5 + 0x2c) = (int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) >> 4;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  func_020ea8a8(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,iVar5,param_2 + 0x1c,param_4);
  func_020ea868(*(uint *)(uRam020dbe70 & 0xfffffffc) >> (uRam020dbe70 & 3) * 8 |
                *(uint *)(uRam020dbe70 & 0xfffffffc) << (uRam020dbe70 & 3) * -8 + 0x20,iVar5,
                param_2 + 0x1c,param_4);
  return;
}

