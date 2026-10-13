/* Decompiled C draft; module arm9; ROM address 02145e8c. No matching claim. */
#include "types.h"
#include "deps/02145e8c_Card_RequestStreamCommand.h"

bool Card_RequestStreamCommand
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,int param_6,undefined4 param_7,undefined4 param_8,
               undefined4 param_9)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = uRam02145f70;
  Os_ReferSymbol(uRam02145f74);
  uVar2 = Os_DisableIrq();
  uVar1 = uVar3 + 0x114 & 3;
  uVar4 = *(uint *)(uVar3 + 0x114 & 0xfffffffc);
  if (((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 4) != 0) {
    do {
      Os_Thread_Sleep(uVar3 + 0x10c);
      uVar1 = uVar3 + 0x114 & 3;
      uVar4 = *(uint *)(uVar3 + 0x114 & 0xfffffffc);
    } while (((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 4) != 0);
  }
  uVar1 = uVar3 + 0x114 & 3;
  uVar4 = *(uint *)(uVar3 + 0x114 & 0xfffffffc);
  *(uint *)(uVar3 + 0x114) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20 | 4;
  *(undefined4 *)(uVar3 + 0x38) = param_4;
  *(undefined4 *)(uVar3 + 0x3c) = param_5;
  Os_RestoreIrq(uVar2);
  *(undefined4 *)(uVar3 + 0x1c) = param_1;
  *(undefined4 *)(uVar3 + 0x20) = param_2;
  *(undefined4 *)(uVar3 + 0x24) = param_3;
  *(undefined4 *)(uVar3 + 0x2c) = param_7;
  *(undefined4 *)(uVar3 + 0x30) = param_8;
  *(undefined4 *)(uVar3 + 0x34) = param_9;
  if (param_6 == 0) {
    uVar1 = iRam02145f7c + 4U & 3;
    uVar4 = *(uint *)(iRam02145f7c + 4U & 0xfffffffc);
    *(uint *)(uRam02145f70 + 0x104) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    Card_BackupCommandTask(uVar3);
    uVar3 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    return uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0;
  }
  Card_SetTask(uRam02145f78);
  return true;
}

