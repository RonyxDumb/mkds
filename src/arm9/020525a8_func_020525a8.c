/* Decompiled C draft; module arm9; ROM address 020525a8. No matching claim. */
#include "types.h"
#include "deps/020525a8_func_020525a8.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_020525a8(int param_1,undefined4 param_2,undefined1 *param_3,int param_4,byte param_5)

{
  uint uVar1;
  byte bVar2;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  
  if (3 < param_5) {
    return;
  }
  uVar5 = -((int)((uint)*(byte *)(param_4 + 0x15) << 0x1f) >> 0x1f);
  if (uVar5 != 0) {
    uVar4 = (*(uint *)(uRam020527bc & 0xfffffffc) >> (uRam020527bc & 3) * 8 |
            *(uint *)(uRam020527bc & 0xfffffffc) << (uRam020527bc & 3) * -8 + 0x20) + 0x1d00;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) == 2) {
      bVar2 = *(byte *)(param_4 + 0x14);
      Mem_CpuCopy8((ushort *)(uintptr_t)(param_2),(uint *)(uintptr_t)(param_1),0xc0);
      uVar3 = param_3[1];
      *(undefined1 *)(param_1 + 0xc0) = *param_3;
      *(undefined1 *)(param_1 + 0xc1) = uVar3;
      uVar3 = param_3[3];
      *(undefined1 *)(param_1 + 0xc2) = param_3[2];
      *(undefined1 *)(param_1 + 0xc3) = uVar3;
      uVar3 = param_3[5];
      *(undefined1 *)(param_1 + 0xc4) = param_3[4];
      *(undefined1 *)(param_1 + 0xc5) = uVar3;
      *(byte *)(param_1 + 0xdc) = *(byte *)(param_1 + 0xdc) & 0xfe | 1;
      *(undefined1 *)(param_1 + 0xdb) = 0;
      *(byte *)(param_1 + 0xda) = (byte)(((uint)bVar2 << 0x1c) >> 0x1c);
      *(byte *)(param_1 + 0xdc) =
           *(byte *)(param_1 + 0xdc) & 0xe1 | (byte)((((uint)bVar2 << 0x18) >> 0x1c) << 1);
      *(byte *)(param_1 + 0xdc) = *(byte *)(param_1 + 0xdc) & 0xdf;
      *(byte *)(param_1 + 0xdc) = *(byte *)(param_1 + 0xdc) & 0xbf | (byte)((uVar5 & 1) << 6);
      Mem_CpuCopy8((ushort *)(uintptr_t)(param_4),(uint *)(uintptr_t)(param_1 + 0xc6),0x14);
      func_0204ec28(param_5,param_4);
      return;
    }
    return;
  }
  uVar5 = (*(uint *)(uRam020527bc & 0xfffffffc) >> (uRam020527bc & 3) * 8 |
          *(uint *)(uRam020527bc & 0xfffffffc) << (uRam020527bc & 3) * -8 + 0x20) + 0x1d00;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if ((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) != 2) {
    bVar2 = *(byte *)(param_4 + 0x14);
    Mem_CpuCopy8((ushort *)(uintptr_t)(param_2),(uint *)(uintptr_t)(param_1),0xc0);
    uVar3 = param_3[1];
    *(undefined1 *)(param_1 + 0xc0) = *param_3;
    *(undefined1 *)(param_1 + 0xc1) = uVar3;
    uVar3 = param_3[3];
    *(undefined1 *)(param_1 + 0xc2) = param_3[2];
    *(undefined1 *)(param_1 + 0xc3) = uVar3;
    uVar3 = param_3[5];
    *(undefined1 *)(param_1 + 0xc4) = param_3[4];
    *(undefined1 *)(param_1 + 0xc5) = uVar3;
    *(byte *)(param_1 + 0xdc) = *(byte *)(param_1 + 0xdc) & 0xfe | 1;
    *(undefined1 *)(param_1 + 0xdb) = 0;
    *(byte *)(param_1 + 0xda) = (byte)(((uint)bVar2 << 0x1c) >> 0x1c);
    *(byte *)(param_1 + 0xdc) =
         *(byte *)(param_1 + 0xdc) & 0xe1 | (byte)((((uint)bVar2 << 0x18) >> 0x1c) << 1);
    *(byte *)(param_1 + 0xdc) = *(byte *)(param_1 + 0xdc) & 0xdf;
    *(byte *)(param_1 + 0xdc) = *(byte *)(param_1 + 0xdc) & 0xbf;
    Mem_CpuCopy8((ushort *)(uintptr_t)(param_4),(uint *)(uintptr_t)(param_1 + 0xc6),0x14);
    return;
  }
  return;
}

