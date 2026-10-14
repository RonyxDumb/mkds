/* Decompiled C draft; module arm9; ROM address 02144920. No matching claim. */
#include "types.h"
#include "deps/02144920_func_02144920.h"

void func_02144920(int param_1)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  ushort *puVar5;
  uint uVar9;
  
  iVar3 = Wm_GetGlobal();
  uVar9 = param_1 + 0x1cU & 3;
  uVar7 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  uVar7 = uVar7 >> uVar9 * 8 | uVar7 << uVar9 * -8 + 0x20;
  uVar9 = iVar3 + 4U & 3;
  uVar8 = *(uint *)(iVar3 + 4U & 0xfffffffc);
  uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
  if (uVar7 == 0) {
    return;
  }
  if (*(short *)(param_1 + 2) != 0) {
    *(undefined2 *)(uVar7 + 0x81c) = 5;
    return;
  }
  sVar1 = *(short *)(param_1 + 4);
  if (sVar1 == 7) {
    return;
  }
  if (sVar1 != 9) {
    if (sVar1 != 0x15) {
      return;
    }
    uVar8 = param_1 + 0xcU & 3;
    uVar4 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    puVar5 = (ushort *)(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20);
    uVar2 = *puVar5;
    uVar6 = *(ushort *)(param_1 + 0x10);
    DC_InvalidateRangeNoClean(uVar9 + 0x184,2);
    if ((uVar6 != *(ushort *)(uVar7 + 0x814)) && (0x200 < uVar6)) {
      uVar6 = 0x200;
    }
    if (3 < uVar6) {
      if (((uint)uVar2 & 1 << (*(ushort *)(uVar9 + 0x184) & 0xff)) != 0) {
        CopyMemory16((int)(uintptr_t)(puVar5),uVar7 + (uint)*(ushort *)(uVar7 + 0x808) * 0x200,uVar6);
        *(short *)(uVar7 + (uint)*(ushort *)(uVar7 + 0x808) * 2 + 0x800) =
             (short)((int)(uint)*(ushort *)(param_1 + 0x1a) >> 1);
        *(ushort *)(uVar7 + 0x808) = *(short *)(uVar7 + 0x808) + 1U & 3;
        return;
      }
      return;
    }
    return;
  }
  return;
}

