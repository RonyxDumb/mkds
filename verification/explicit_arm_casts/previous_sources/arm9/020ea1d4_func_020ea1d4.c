/* Decompiled C draft; module arm9; ROM address 020ea1d4. No matching claim. */
#include "types.h"
#include "deps/020ea1d4_func_020ea1d4.h"

void func_020ea1d4(undefined4 param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  ushort *puVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint local_40;
  uint local_3c;
  undefined4 local_38;
  int local_34;
  uint uStack_30;
  undefined4 uStack_2c;
  
  iVar9 = func_020d849c(uRam020ea358);
  uVar2 = uRam020ea364;
  iVar7 = iRam020ea360;
  uVar6 = uRam020ea35c;
  uVar5 = uRam020ea358;
  while (iVar9 != 0) {
    iVar9 = 0;
    do {
      uVar10 = iVar7 + iVar9 * 4;
      uVar11 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      iVar1 = iVar9 * 4;
      *(uint *)(iVar7 + iVar9 * 4) = (uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20) + 0xc;
      uVar10 = iVar7 + iVar9 * 4;
      uVar11 = uVar10 & 3;
      uVar10 = *(uint *)(uVar10 & 0xfffffffc);
      iVar9 = iVar9 + 1;
      if (uVar2 < (uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20)) {
        *(undefined4 *)(iVar7 + iVar1) = uVar6;
      }
    } while (iVar9 < 4);
    iVar9 = func_020d7c84(uVar5,0,iVar7);
  }
  func_020d8488(uRam020ea358,&local_40);
  iVar7 = iRam020ea36c;
  puVar8 = puRam020ea368;
  *puRam020ea368 = *puRam020ea368 + 100;
  uVar2 = param_2 + 4 & 3;
  uVar13 = *(uint *)(param_2 + 4 & 0xfffffffc);
  uVar12 = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
           *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20;
  uVar10 = param_3 + 4 & 3;
  uVar11 = *(uint *)(param_3 + 4 & 0xfffffffc);
  uVar10 = uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20;
  lVar3 = (longlong)(int)((uVar13 >> uVar2 * 8 | uVar13 << uVar2 * -8 + 0x20) - uVar10) *
          (longlong)(*(short *)(iVar7 + ((int)(uint)*puVar8 >> 4) * 4) + 0x1000 >> 2);
  lVar4 = (longlong)
          (int)((*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) - uVar12) *
          (longlong)(*(short *)(iVar7 + (((int)(uint)*puVar8 >> 4) * 2 + 1) * 2) + 0x1000 >> 2);
  lVar4 = (longlong)(int)local_40 *
          (longlong)(int)(uVar12 + ((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14));
  local_40 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
  lVar3 = (longlong)(int)local_3c *
          (longlong)(int)(uVar10 + ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14));
  local_3c = (uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14;
  local_38 = 0;
  VecFx32_Add(&local_40,param_1,&local_40);
  uStack_30 = local_3c;
  uStack_2c = local_38;
  local_34 = local_40 +
             (*(uint *)(uRam020ea370 & 0xfffffffc) >> (uRam020ea370 & 3) * 8 |
             *(uint *)(uRam020ea370 & 0xfffffffc) << (uRam020ea370 & 3) * -8 + 0x20);
  func_02147288(&local_34,uRam020ea374,uRam020ea378);
  return;
}

