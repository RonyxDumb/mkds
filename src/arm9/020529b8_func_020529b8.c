/* Decompiled C draft; module arm9; ROM address 020529b8. No matching claim. */
#include "types.h"
#include "deps/020529b8_func_020529b8.h"

void func_020529b8(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  if (*(short *)(param_1 + 2) != 0) {
    func_020533a0();
    return;
  }
  sVar1 = *(short *)(param_1 + 8);
  if (sVar1 == 0) {
    uVar3 = *(uint *)(uRam02052b44 & 0xfffffffc) >> (uRam02052b44 & 3) * 8 |
            *(uint *)(uRam02052b44 & 0xfffffffc) << (uRam02052b44 & 3) * -8 + 0x20;
    uVar5 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    Mem_CpuCopy8((ushort *)(uintptr_t)((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 0xc),
                 (uint *)(uintptr_t)((*(uint *)(uRam02052b48 & 0xfffffffc) >> (uRam02052b48 & 3) * 8 |
                 *(uint *)(uRam02052b48 & 0xfffffffc) << (uRam02052b48 & 3) * -8 + 0x20) +
                 iRam02052b4c),0x14);
    uVar3 = *(uint *)(uRam02052b44 & 0xfffffffc) >> (uRam02052b44 & 3) * 8 |
            *(uint *)(uRam02052b44 & 0xfffffffc) << (uRam02052b44 & 3) * -8 + 0x20;
    uVar5 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    Mem_CpuCopy8((ushort *)(uintptr_t)((uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20) + 0x20),
                 (uint *)(uintptr_t)((*(uint *)(uRam02052b48 & 0xfffffffc) >> (uRam02052b48 & 3) * 8 |
                 *(uint *)(uRam02052b48 & 0xfffffffc) << (uRam02052b48 & 3) * -8 + 0x20) + 0x680),4);
    iVar6 = iRam02052b50;
    uVar3 = 0;
    uVar5 = *(uint *)(uRam02052b48 & 0xfffffffc) >> (uRam02052b48 & 3) * 8 |
            *(uint *)(uRam02052b48 & 0xfffffffc) << (uRam02052b48 & 3) * -8 + 0x20;
    if (uVar5 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
              *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
    }
    if (uVar4 == 1) {
      uVar3 = uVar5 + 0x18 & 3;
      uVar5 = *(uint *)(uVar5 + 0x18 & 0xfffffffc);
      uVar3 = (uint)*(ushort *)((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + 0xc);
    }
    else if (uVar4 == 2) {
      uVar3 = uVar5 + 0x24 & 3;
      uVar5 = *(uint *)(uVar5 + 0x24 & 0xfffffffc);
      uVar3 = (uint)*(ushort *)((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + 0x48);
    }
    uVar5 = *(uint *)(uRam02052b48 & 0xfffffffc) >> (uRam02052b48 & 3) * 8 |
            *(uint *)(uRam02052b48 & 0xfffffffc) << (uRam02052b48 & 3) * -8 + 0x20;
    *(uint *)(uVar5 + 0x1ee8) = uVar3 * 3 | uVar3 << 0x10;
    uVar2 = uRam02052b54;
    iVar6 = uVar5 + iVar6;
    *(undefined4 *)(iVar6 + 4) = 0;
    *(undefined4 *)(iVar6 + 8) = uVar2;
    uVar2 = uRam02052b5c;
    *(undefined4 *)(iVar6 + 0xc) = uRam02052b58;
    *(undefined4 *)(iVar6 + 0x10) = uVar2;
    *(undefined4 *)(iVar6 + 0x14) = 0;
    *(undefined4 *)(uVar5 + 0x10) = 0;
    return;
  }
  if (sVar1 == 7) {
    func_02050d80(*(undefined2 *)(param_1 + 0x10),(undefined1 *)(uintptr_t)(param_1 + 10),param_1 + 0x14);
    return;
  }
  if (sVar1 != 9) {
    return;
  }
  func_02050b88(*(undefined2 *)(param_1 + 0x10));
  uVar5 = *(uint *)(uRam02052b48 & 0xfffffffc) >> (uRam02052b48 & 3) * 8 |
          *(uint *)(uRam02052b48 & 0xfffffffc) << (uRam02052b48 & 3) * -8 + 0x20;
  if (uVar5 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
  }
  if (uVar3 != 1) {
    return;
  }
  uVar3 = uVar5 + 4 & 3;
  uVar4 = *(uint *)(uVar5 + 4 & 0xfffffffc);
  if ((uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) != 9) {
    return;
  }
  *(byte *)(uVar5 + 0x1eac) =
       *(byte *)(uVar5 + 0x1eac) | (byte)(1 << (*(ushort *)(param_1 + 0x10) & 0xff));
  return;
}

