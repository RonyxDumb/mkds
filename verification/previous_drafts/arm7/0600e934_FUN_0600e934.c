/* Decompiled C draft; module arm7; ROM address 0600e934. No matching claim. */
#include "types.h"
#include "deps/0600e934_FUN_0600e934.h"

void FUN_0600e934(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(DAT_0600e9a4 & 0xfffffffc) >> (DAT_0600e9a4 & 3) * 8 |
          *(uint *)(DAT_0600e9a4 & 0xfffffffc) << (DAT_0600e9a4 & 3) * -8 + 0x20;
  FUN_0600e69c();
  uVar1 = FUN_0600e840(param_1);
  if (uVar1 != 0) {
    iVar2 = FUN_0600e808(param_1);
    *(undefined2 *)(iVar2 + 2) = 0;
    *(ushort *)(uVar3 + 0x53a) = *(ushort *)(uVar3 + 0x53a) & ~(ushort)(1 << (uVar1 & 0xff));
    *(short *)(uVar3 + 0x538) = *(short *)(uVar3 + 0x538) + -1;
    if (*(short *)(uVar3 + 0x538) == 0) {
      FUN_0600ac28();
    }
  }
  return;
}

