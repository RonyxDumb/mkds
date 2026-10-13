/* Decompiled C draft; module arm9; ROM address 020d6910. No matching claim. */
#include "types.h"
#include "deps/020d6910_func_020d6910.h"

undefined1 func_020d6910(int param_1,ushort *param_2)

{
  uint uVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = (uint)*param_2;
  iVar4 = 0;
  if (99 < uVar5) {
    do {
      uVar5 = uVar5 - 100;
      iVar4 = iVar4 + 1;
    } while (99 < (int)uVar5);
  }
  uVar3 = iVar4 * 0x38 + iRam020d6964 + param_1 * 4;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar2 = *(undefined1 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + uVar5);
  if ((param_2[1] & 0x800) != 0) {
    uVar2 = 0;
  }
  return uVar2;
}

