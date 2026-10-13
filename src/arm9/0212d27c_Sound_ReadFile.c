/* Decompiled C draft; module arm9; ROM address 0212d27c. No matching claim. */
#include "types.h"
#include "deps/0212d27c_Sound_ReadFile.h"

undefined4 Sound_ReadFile(uint param_1,undefined4 param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar6;
  uint uVar5;
  
  uVar6 = *(uint *)(uRam0212d2fc & 0xfffffffc) >> (uRam0212d2fc & 3) * 8 |
          *(uint *)(uRam0212d2fc & 0xfffffffc) << (uRam0212d2fc & 3) * -8 + 0x20;
  uVar3 = uVar6 + 0x84 & 3;
  uVar4 = *(uint *)(uVar6 + 0x84 & 0xfffffffc);
  uVar5 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  uVar3 = uVar5 + 8;
  uVar4 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) <= param_1) {
    return 0xffffffff;
  }
  uVar5 = uVar5 + 0xc + param_1 * 0x10;
  uVar3 = uVar5 + 4 & 3;
  uVar4 = *(uint *)(uVar5 + 4 & 0xfffffffc);
  uVar3 = (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) - param_4;
  if (uVar3 < param_3) {
    param_3 = uVar3;
  }
  iVar1 = Fs_File_Seek(uVar6 + 0x34,
                       (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                       *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + param_4,0);
  if (iVar1 != 0) {
    uVar2 = Fs_File_Read(uVar6 + 0x34,param_2,param_3);
    return uVar2;
  }
  return 0xffffffff;
}

