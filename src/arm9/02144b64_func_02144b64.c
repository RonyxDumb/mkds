/* Decompiled C draft; module arm9; ROM address 02144b64. No matching claim. */
#include "types.h"
#include "deps/02144b64_func_02144b64.h"

void func_02144b64(int param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  uint uVar5;
  uint uVar4;
  uint uVar6;
  
  iVar2 = Wm_GetGlobal();
  uVar3 = iVar2 + 4U & 3;
  uVar5 = *(uint *)(iVar2 + 4U & 0xfffffffc);
  uVar6 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  iVar2 = iVar2 + (uint)*(ushort *)(param_1 + 10) * 4;
  uVar3 = iVar2 + 0xc4;
  uVar5 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar4 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  uVar3 = iVar2 + 0x104;
  uVar5 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  if ((uVar4 != uRam02144c64) && (uVar4 != uRam02144c68)) {
    return;
  }
  if (uVar3 == 0) {
    return;
  }
  uVar5 = param_1 + 0x20U & 3;
  uVar4 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  if (uVar3 == (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20)) {
    DC_InvalidateRangeNoClean(uVar6 + 0x184,2);
    sVar1 = *(short *)(uVar6 + 0x184);
    if (*(short *)(param_1 + 2) != 0) {
      if (*(short *)(param_1 + 2) != 10) {
        *(undefined2 *)(uVar3 + 0x81c) = 5;
        return;
      }
      if (sVar1 != 0) {
        *(ushort *)(uVar3 + 0x80a) = *(short *)(uVar3 + 0x80a) + 3U & 3;
      }
      *(undefined2 *)(uVar3 + 0x81c) = 4;
      return;
    }
    if (sVar1 == 0) {
      *(short *)(uVar3 + (uint)*(ushort *)(uVar3 + 0x80a) * 2 + 0x800) =
           (short)((int)(uint)*(ushort *)(param_1 + 0x1a) >> 1);
      *(ushort *)(uVar3 + 0x80a) = *(short *)(uVar3 + 0x80a) + 1U & 3;
      return;
    }
    return;
  }
  return;
}

