/* Decompiled C draft; module arm9; ROM address 02003a6c. No matching claim. */
#include "types.h"
#include "deps/02003a6c_Fs_File_DefaultOperation_ReadFile.h"

void Fs_File_DefaultOperation_ReadFile(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar5 = param_1 + 0x2cU & 3;
  uVar3 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
  uVar1 = param_1 + 0x38U & 3;
  uVar4 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
  uVar2 = param_1 + 8U & 3;
  uVar6 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar7 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
  uVar2 = param_1 + 0x30U & 3;
  uVar6 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
  *(uint *)(param_1 + 0x2c) =
       (uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) +
       (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  uVar5 = uVar7 + 0x48;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  (*(code *)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20))
            (uVar7,uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20);
  return;
}

