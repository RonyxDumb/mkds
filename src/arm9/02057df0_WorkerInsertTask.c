/* Decompiled C draft; module arm9; ROM address 02057df0. No matching claim. */
#include "types.h"
#include "deps/02057df0_WorkerInsertTask.h"

bool WorkerInsertTask(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  uVar9 = *(uint *)(uRam02057e80 & 0xfffffffc) >> (uRam02057e80 & 3) * 8 |
          *(uint *)(uRam02057e80 & 0xfffffffc) << (uRam02057e80 & 3) * -8 + 0x20;
  uVar7 = uVar9 + 0xf8 & 3;
  uVar3 = *(uint *)(uVar9 + 0xf8 & 0xfffffffc);
  if (uVar3 >> uVar7 * 8 != 0 || uVar3 << uVar7 * -8 + 0x20 != 0) {
    return false;
  }
  uVar7 = (uint)*(byte *)(uVar9 + 0x28);
  iVar8 = 0;
  do {
    uVar5 = uVar7 - iRam02057e88 *
                    ((int)((longlong)iRam02057e84 * (longlong)(int)uVar7 >> 0x22) -
                    ((int)uVar7 >> 0x1f));
    uVar6 = uVar5 & 0xff;
    uVar3 = uVar9 + uVar6 * 4;
    uVar1 = uVar3 & 3;
    uVar4 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = uVar4 >> uVar1 * 8;
    iVar2 = uVar4 << uVar1 * -8 + 0x20;
    if (uVar3 == 0 && iVar2 == 0) break;
    iVar8 = iVar8 + 1;
    uVar7 = uVar7 + 1;
  } while (iVar8 < 10);
  if (uVar3 == 0 && iVar2 == 0) {
    *(undefined4 *)(uVar9 + uVar6 * 4) = param_1;
    *(char *)(uVar9 + 0x28) = (char)uVar5;
  }
  return uVar3 == 0 && iVar2 == 0;
}

