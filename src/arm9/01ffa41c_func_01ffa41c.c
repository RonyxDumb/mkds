/* Decompiled C draft; module arm9; ROM address 01ffa41c. No matching claim. */
#include "types.h"
#include "deps/01ffa41c_func_01ffa41c.h"

undefined1 func_01ffa41c(int param_1,uint param_2,uint param_3)

{
  longlong lVar1;
  bool bVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  bool bVar7;
  
  uVar3 = 1;
  bVar2 = false;
  if (((param_2 & 0x2000000) != 0) &&
     (uVar4 = param_3 + 8 & 3, uVar6 = *(uint *)(param_3 + 8 & 0xfffffffc),
     uVar6 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20,
     uVar4 = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
             *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20,
     lVar1 = (longlong)(int)uVar4 * (longlong)(int)uVar4 +
             (longlong)(int)uVar6 * (longlong)(int)uVar6, iVar5 = (int)((ulonglong)lVar1 >> 0x20),
     bVar7 = 0x1000000 < (uint)lVar1, 0 < (int)(iVar5 + (uint)bVar7) != SBORROW4(-iVar5,(uint)bVar7)
     )) {
    bVar2 = true;
  }
  if ((!bVar2) &&
     (uVar4 = param_1 + 0x44U & 3, uVar6 = *(uint *)(param_1 + 0x44U & 0xfffffffc),
     ((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) & 0x4000000) == 0)) {
    uVar3 = 0;
  }
  return uVar3;
}

