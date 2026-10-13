/* Decompiled C draft; module arm9; ROM address 0203e4c4. No matching claim. */
#include "types.h"
#include "deps/0203e4c4_func_0203e4c4.h"

void func_0203e4c4(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = uRam0203e548;
  iVar4 = param_1 * 0x8c +
          (*(uint *)(uRam0203e548 & 0xfffffffc) >> (uRam0203e548 & 3) * 8 |
          *(uint *)(uRam0203e548 & 0xfffffffc) << (uRam0203e548 & 3) * -8 + 0x20) + 0x14;
  if (param_2 == 0) {
    iVar2 = 2;
  }
  else {
    iVar2 = 1;
  }
  *(ushort *)(iVar4 + 0x3c) = *(ushort *)(iVar4 + 0x3c) & 0xfcff | (ushort)(iVar2 << 8);
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  if ((uint)*(byte *)((*(uint *)(uRam0203e54c & 0xfffffffc) >> (uRam0203e54c & 3) * 8 |
                      *(uint *)(uRam0203e54c & 0xfffffffc) << (uRam0203e54c & 3) * -8 + 0x20) +
                     0x3d0) <= (uint)*(ushort *)(uVar3 + 0xe) + (uint)*(ushort *)(uVar3 + 0x10)) {
    func_0203d21c();
    return;
  }
  return;
}

