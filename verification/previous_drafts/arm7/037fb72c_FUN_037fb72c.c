/* Decompiled C draft; module arm7; ROM address 037fb72c. No matching claim. */
#include "types.h"
#include "deps/037fb72c_FUN_037fb72c.h"

void FUN_037fb72c(void)

{
  int iVar1;
  ushort *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  uVar3 = FUN_037faf70();
  if (*DAT_037fb7ec == 0) {
    *DAT_037fb7ec = 1;
    iVar4 = 0;
    *(undefined4 *)(DAT_037fb7f0 + 0x38c) = 0;
    iVar1 = DAT_037fb7f4;
    do {
      *(undefined4 *)(iVar1 + iVar4 * 4) = 0;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x20);
    *DAT_037fb7fc = (short)DAT_037fb7f8;
    FUN_037f881c(0x40000);
    FUN_037f8944(0x40000,DAT_037fb800);
    FUN_037f888c(0x40000);
    puVar2 = DAT_037fb804;
    for (uVar5 = 8; -1 < (int)uVar5; uVar5 = uVar5 - 1) {
      *puVar2 = (ushort)(uVar5 << 8);
      FUN_037fafd4(1000);
      if ((*puVar2 & 0xf) != uVar5) {
        uVar5 = 8;
      }
    }
  }
  FUN_037faf84(uVar3);
  return;
}

