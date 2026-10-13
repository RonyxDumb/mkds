/* Decompiled C draft; module arm9; ROM address 02150a10. No matching claim. */
#include "types.h"
#include "deps/02150a10_func_02150a10.h"

void func_02150a10(uint param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar5;
  uint local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  uint uVar4;
  
  uVar4 = param_1 + 0x1c & 3;
  uVar3 = *(uint *)(param_1 + 0x1c & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  iVar5 = param_1 + 0x20;
  iVar1 = (int)uVar4 >> 2;
  if ((uVar4 & 3) == 0) {
    *(undefined4 *)(iVar5 + iVar1 * 4) = 0;
  }
  *(undefined1 *)(param_1 + 0x20 + uVar4) = 0x80;
  while (uVar4 = uVar4 + 1, (uVar4 & 3) != 0) {
    *(undefined1 *)(param_1 + 0x20 + uVar4) = 0;
  }
  iVar1 = iVar1 + 1;
  uVar4 = param_1 + 0x1c & 3;
  uVar2 = *(uint *)(param_1 + 0x1c & 0xfffffffc);
  uVar3 = uRam02150c18;
  uStack_4 = param_4;
  uStack_8 = param_3;
  puStack_c = param_2;
  local_10 = param_1;
  if (0x37 < (int)(uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20)) {
    for (; iVar1 < 0x10; iVar1 = iVar1 + 1) {
      *(undefined4 *)(iVar5 + iVar1 * 4) = 0;
    }
    (*(code *)(*(uint *)(uRam02150c18 & 0xfffffffc) >> (uRam02150c18 & 3) * 8 |
              *(uint *)(uRam02150c18 & 0xfffffffc) << (uRam02150c18 & 3) * -8 + 0x20))
              (param_1,iVar5,0x40);
    iVar1 = 0;
    uVar3 = uRam02150c18;
  }
  for (; uRam02150c18 = uVar3, iVar1 < 0xe; iVar1 = iVar1 + 1) {
    *(undefined4 *)(iVar5 + iVar1 * 4) = 0;
    uVar3 = uRam02150c18;
  }
  uVar4 = local_10 + 0x14 & 3;
  uVar2 = *(uint *)(local_10 + 0x14 & 0xfffffffc);
  uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  *(char *)(param_1 + 0x5f) = (char)uVar4;
  *(char *)(param_1 + 0x5e) = (char)(uVar4 >> 8);
  *(char *)(param_1 + 0x5d) = (char)(uVar4 >> 0x10);
  *(char *)(param_1 + 0x5c) = (char)(uVar4 >> 0x18);
  uVar4 = local_10 + 0x18 & 3;
  uVar2 = *(uint *)(local_10 + 0x18 & 0xfffffffc);
  uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  *(char *)(param_1 + 0x5b) = (char)uVar4;
  *(char *)(param_1 + 0x5a) = (char)(uVar4 >> 8);
  *(char *)(param_1 + 0x59) = (char)(uVar4 >> 0x10);
  *(char *)(param_1 + 0x58) = (char)(uVar4 >> 0x18);
  (*(code *)(*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20))(local_10,iVar5,0x40);
  uVar4 = *(uint *)(local_10 & 0xfffffffc) >> (local_10 & 3) * 8 |
          *(uint *)(local_10 & 0xfffffffc) << (local_10 & 3) * -8 + 0x20;
  *param_2 = (char)(uVar4 >> 0x18);
  param_2[1] = (char)(uVar4 >> 0x10);
  param_2[2] = (char)(uVar4 >> 8);
  param_2[3] = (char)uVar4;
  uVar4 = local_10 + 4 & 3;
  uVar3 = *(uint *)(local_10 + 4 & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  param_2[4] = (char)(uVar4 >> 0x18);
  param_2[5] = (char)(uVar4 >> 0x10);
  param_2[6] = (char)(uVar4 >> 8);
  param_2[7] = (char)uVar4;
  uVar4 = local_10 + 8 & 3;
  uVar3 = *(uint *)(local_10 + 8 & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  param_2[8] = (char)(uVar4 >> 0x18);
  param_2[9] = (char)(uVar4 >> 0x10);
  param_2[10] = (char)(uVar4 >> 8);
  param_2[0xb] = (char)uVar4;
  uVar4 = local_10 + 0xc & 3;
  uVar3 = *(uint *)(local_10 + 0xc & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  param_2[0xc] = (char)(uVar4 >> 0x18);
  param_2[0xd] = (char)(uVar4 >> 0x10);
  param_2[0xe] = (char)(uVar4 >> 8);
  param_2[0xf] = (char)uVar4;
  uVar4 = local_10 + 0x10 & 3;
  uVar3 = *(uint *)(local_10 + 0x10 & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  param_2[0x10] = (char)(uVar4 >> 0x18);
  param_2[0x11] = (char)(uVar4 >> 0x10);
  param_2[0x12] = (char)(uVar4 >> 8);
  param_2[0x13] = (char)uVar4;
  *(undefined4 *)(local_10 + 0x1c) = 0;
  MIi_CpuClear32(0,&local_10,4);
  return;
}

