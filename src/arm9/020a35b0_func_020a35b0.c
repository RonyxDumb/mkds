/* Decompiled C draft; module arm9; ROM address 020a35b0. No matching claim. */
#include "types.h"
#include "deps/020a35b0_func_020a35b0.h"

void func_020a35b0(int param_1)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  int iVar7;
  undefined2 uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int local_28;
  int local_24;
  int local_20;
  
  iVar9 = GetGlobalHD4();
  uVar1 = iVar9 + 0x15cU & 3;
  uVar10 = *(uint *)(iVar9 + 0x15cU & 0xfffffffc);
  uVar2 = iVar9 + 0x164U & 3;
  uVar12 = *(uint *)(iVar9 + 0x164U & 0xfffffffc);
  iVar11 = FX_Atan2(uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20,
                    uVar12 >> uVar2 * 8 | uVar12 << uVar2 * -8 + 0x20);
  VecFx32_Subtract(param_1 + 4,iVar9 + 0x24,&local_28);
  iVar7 = local_24;
  iVar11 = (int)(iVar11 - 0x4000U & 0xffff) >> 4;
  iVar13 = (int)*(short *)(iRam020a368c + iVar11 * 4);
  iVar11 = (int)*(short *)(iRam020a368c + (iVar11 * 2 + 1) * 2);
  lVar3 = (longlong)local_20 * (longlong)iVar11;
  lVar4 = (longlong)local_28 * (longlong)iVar13;
  VecFx32_Subtract(param_1 + 0xb0,iVar9 + 0x24,&local_28);
  lVar5 = (longlong)local_28 * (longlong)iVar13;
  lVar6 = (longlong)local_20 * (longlong)iVar11;
  uVar8 = FX_Atan2(iVar7 - local_24,
                   -((((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14) +
                     ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14)) -
                    (((uint)lVar5 >> 0xc | (int)((ulonglong)lVar5 >> 0x20) << 0x14) +
                    ((uint)lVar6 >> 0xc | (int)((ulonglong)lVar6 >> 0x20) << 0x14))));
  *(undefined2 *)(param_1 + 0x7e) = uVar8;
  return;
}

