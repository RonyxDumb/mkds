/* Decompiled C draft; module arm9; ROM address 02050d80. No matching claim. */
#include "types.h"
#include "deps/02050d80_func_02050d80.h"

void func_02050d80(uint param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = uRam02050e58;
  uVar2 = *(uint *)(uRam02050e58 & 0xfffffffc) >> (uRam02050e58 & 3) * 8 |
          *(uint *)(uRam02050e58 & 0xfffffffc) << (uRam02050e58 & 3) * -8 + 0x20;
  if (6 < *(byte *)(uVar2 + 0x84)) {
    return;
  }
  *(short *)((undefined1 *)(uVar2 + 0x44) + (param_1 - 1) * 8 + 6) = (short)param_1;
  iVar1 = iRam02050e5c;
  *(char *)(uVar2 + 0x84) = *(char *)(uVar2 + 0x84) + '\x01';
  *(byte *)(uVar2 + 0x87) = *(byte *)(uVar2 + 0x87) | (byte)(1 << (param_1 & 0xff));
  *(undefined1 *)(uVar2 + 0x44) = *param_2;
  *(undefined1 *)(uVar2 + 0x45) = param_2[1];
  *(undefined1 *)(uVar2 + 0x46) = param_2[2];
  *(undefined1 *)(uVar2 + 0x47) = param_2[3];
  *(undefined1 *)(uVar2 + 0x48) = param_2[4];
  *(undefined1 *)(uVar2 + 0x49) = param_2[5];
  Mem_CpuCopy8(param_3,param_1 * 0x22c +
                       (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                       *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + iVar1,0x14);
  uVar2 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
  *(byte *)(uVar2 + 0x8b) = *(byte *)(uVar2 + 0x8b) | 8;
  if ((*(byte *)(param_3 + 0x14) & 1) != 0) {
    uVar3 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    *(byte *)(uVar3 + 0x457) = *(byte *)(uVar3 + 0x457) | (byte)(1 << (param_1 & 0xff));
  }
  return;
}

