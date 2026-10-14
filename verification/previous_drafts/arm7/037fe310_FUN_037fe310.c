/* Decompiled C draft; module arm7; ROM address 037fe310. No matching claim. */
#include "types.h"
#include "deps/037fe310_FUN_037fe310.h"

void FUN_037fe310(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  while (0xef < *(ushort *)(param_1 + 0x1c)) {
    *(short *)(param_1 + 0x1c) = *(short *)(param_1 + 0x1c) + -0xf0;
    iVar5 = iVar5 + 1;
  }
  iVar4 = 0;
  do {
    if (iVar5 <= iVar4) {
LAB_037fe37c:
      uVar2 = *(uint *)(DAT_037fe3cc & 0xfffffffc) >> (DAT_037fe3cc & 3) * 8 |
              *(uint *)(DAT_037fe3cc & 0xfffffffc) << (DAT_037fe3cc & 3) * -8 + 0x20;
      if (uVar2 != 0) {
        iVar3 = uVar2 + 0x40;
        iVar5 = (uint)*(byte *)(param_1 + 1) * 0x24;
        uVar2 = iVar3 + iVar5;
        uVar1 = uVar2 & 3;
        uVar2 = *(uint *)(uVar2 & 0xfffffffc);
        *(uint *)(iVar3 + iVar5) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + iVar4;
      }
      *(short *)(param_1 + 0x1c) =
           *(short *)(param_1 + 0x1c) +
           (short)((uint)*(ushort *)(param_1 + 0x18) * (uint)*(ushort *)(param_1 + 0x1a) >> 8);
      return;
    }
    iVar3 = FUN_037fd404(param_1,1);
    if (iVar3 != 0) {
      FUN_037fe230((byte *)(uintptr_t)(param_1));
      goto LAB_037fe37c;
    }
    iVar4 = iVar4 + 1;
  } while( true );
}

