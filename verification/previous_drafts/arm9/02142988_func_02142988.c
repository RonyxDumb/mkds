/* Decompiled C draft; module arm9; ROM address 02142988. No matching claim. */
#include "types.h"
#include "deps/02142988_func_02142988.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

int func_02142988(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  uint uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  puVar7 = auStack_18;
  uStack_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  iVar3 = Wm_CheckInitialized();
  if (iVar3 != 0) {
    return iVar3;
  }
  uVar4 = (*(uint *)(uRam02142a2c & 0xfffffffc) >> (uRam02142a2c & 3) * 8 |
          *(uint *)(uRam02142a2c & 0xfffffffc) << (uRam02142a2c & 3) * -8 + 0x20) + 4;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  DC_InvalidateRangeNoClean(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,2);
  puVar5 = &uStack_10;
  uVar4 = (*(uint *)(uRam02142a2c & 0xfffffffc) >> (uRam02142a2c & 3) * 8 |
          *(uint *)(uRam02142a2c & 0xfffffffc) << (uRam02142a2c & 3) * -8 + 0x20) + 4;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if (uStack_10 == 0) {
    puVar7 = auStack_14;
  }
  uVar2 = *(ushort *)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  iVar3 = 3;
  if (uStack_10 == 0) {
    return iVar3;
  }
  do {
    puVar5 = puVar5 + 1;
    iVar6 = *(int *)(puVar7 + 8);
    if (*puVar5 == (uint)uVar2) {
      iVar3 = 0;
    }
    *(int *)(puVar7 + 8) = iVar6 + -1;
  } while (iVar6 + -1 != 0);
  return iVar3;
}

