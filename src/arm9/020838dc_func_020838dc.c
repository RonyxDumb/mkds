/* Decompiled C draft; module arm9; ROM address 020838dc. No matching claim. */
#include "types.h"
#include "deps/020838dc_func_020838dc.h"

void func_020838dc(int param_1)

{
  uint uVar1;
  int iVar3;
  uint uVar2;
  
  iVar3 = (uint)*(ushort *)(param_1 + 0x74) * 0x58 +
          (*(uint *)(uRam02083924 & 0xfffffffc) >> (uRam02083924 & 3) * 8 |
          *(uint *)(uRam02083924 & 0xfffffffc) << (uRam02083924 & 3) * -8 + 0x20);
  uVar2 = iVar3 + 0x20U & 3;
  uVar1 = *(uint *)(iVar3 + 0x20U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 0) {
    *(undefined1 *)(uVar2 + 0x99) = 1;
    *(undefined4 *)(iVar3 + 0x20) = 0;
  }
  uVar2 = iVar3 + 0x24U & 3;
  uVar1 = *(uint *)(iVar3 + 0x24U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 != 0) {
    *(undefined1 *)(uVar2 + 0x99) = 1;
    *(undefined4 *)(iVar3 + 0x24) = 0;
  }
  return;
}

