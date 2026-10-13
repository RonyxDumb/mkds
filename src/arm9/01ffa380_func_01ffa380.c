/* Decompiled C draft; module arm9; ROM address 01ffa380. No matching claim. */
#include "types.h"
#include "deps/01ffa380_func_01ffa380.h"

undefined1 func_01ffa380(int param_1,uint param_2,uint param_3)

{
  longlong lVar1;
  bool bVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  uVar3 = 1;
  bVar2 = false;
  if (((param_2 & 0x2000000) != 0) &&
     (uVar4 = param_3 + 8 & 3, uVar8 = *(uint *)(param_3 + 8 & 0xfffffffc),
     uVar8 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20,
     uVar4 = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
             *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20,
     lVar1 = (longlong)(int)uVar4 * (longlong)(int)uVar4 +
             (longlong)(int)uVar8 * (longlong)(int)uVar8, iVar5 = (int)((ulonglong)lVar1 >> 0x20),
     bVar9 = 0x1000000 < (uint)lVar1, 0 < (int)(iVar5 + (uint)bVar9) != SBORROW4(-iVar5,(uint)bVar9)
     )) {
    bVar2 = true;
  }
  if ((!bVar2) &&
     (uVar4 = param_1 + 0x1d0U & 3, uVar8 = *(uint *)(param_1 + 0x1d0U & 0xfffffffc),
     uVar7 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20,
     uVar6 = (uint)((ulonglong)uRam01ffa418 * (ulonglong)uVar7), uVar4 = param_3 + 4 & 3,
     uVar8 = *(uint *)(param_3 + 4 & 0xfffffffc),
     (int)(uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) <=
     (int)(uVar6 + 0x800 >> 0xc |
          (((int)uVar7 >> 0x1f) * uRam01ffa418 +
           ((int)((ulonglong)uRam01ffa418 * (ulonglong)uVar7 >> 0x20) - uVar7) +
          (uint)(0xfffff7ff < uVar6)) * 0x100000))) {
    uVar3 = 0;
  }
  return uVar3;
}

