/* Decompiled C draft; module arm9; ROM address 01ffa478. No matching claim. */
#include "types.h"
#include "deps/01ffa478_func_01ffa478.h"

undefined1 func_01ffa478(undefined4 param_1,uint param_2,uint param_3)

{
  longlong lVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  
  uVar2 = 0;
  if (((param_2 & 0x2000000) != 0) &&
     (uVar3 = param_3 + 8 & 3, uVar5 = *(uint *)(param_3 + 8 & 0xfffffffc),
     uVar5 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20,
     uVar3 = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
             *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20,
     lVar1 = (longlong)(int)uVar3 * (longlong)(int)uVar3 +
             (longlong)(int)uVar5 * (longlong)(int)uVar5, iVar4 = (int)((ulonglong)lVar1 >> 0x20),
     bVar6 = 0x1000000 < (uint)lVar1, 0 < (int)(iVar4 + (uint)bVar6) != SBORROW4(-iVar4,(uint)bVar6)
     )) {
    uVar2 = 1;
  }
  return uVar2;
}

