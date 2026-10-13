/* Decompiled C draft; module arm9; ROM address 0202ba14. No matching claim. */
#include "types.h"
#include "deps/0202ba14_func_0202ba14.h"

void func_0202ba14(void)

{
  uint uVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  uVar4 = 0x19;
  uVar3 = func_02025ebc(*piRam0202bb04 + iRam0202bb08);
  uVar1 = uRam0202bb10;
  bVar5 = *(int *)(*piRam0202bb04 + iRam0202bb0c) != 2;
  if (!bVar5) {
    uVar4 = 0x1b;
    *puRam0202bb14 = uVar3 & uRam0202bb10;
    *puRam0202bb18 = -uVar3 & uVar1;
    *puRam0202bb1c = *puRam0202bb1c & 0xfffc | 3;
    *puRam0202bb20 = *puRam0202bb20 & 0xfffc | 3;
  }
  if (*(int *)(*piRam0202bb04 + iRam0202bb24) == 2) {
    uVar4 = uVar4 | 2;
  }
  *puRam0202bb28 = *puRam0202bb28 & uRam0202bb2c | uVar4 << 8;
  ConfigureDispcntDisplay(1,0,bVar5);
  if (*(int *)(*piRam0202bb04 + iRam0202bb0c) != 2) {
    *puRam0202bb28 = *puRam0202bb28 & uRam0202bb30;
    return;
  }
  *puRam0202bb28 = *puRam0202bb28 & uRam0202bb30 | uRam0202bb34;
  puVar2 = puRam0202bb38;
  *puRam0202bb38 = *puRam0202bb38 & 0xffc0 | 0x3d;
  *puVar2 = *puVar2 & (ushort)uRam0202bb3c | (ushort)uRam0202bb40 | (ushort)uRam0202bb44;
  *puRam0202bb48 = *puRam0202bb48 & 0xffc0 | 0x3c;
  *puRam0202bb4c = 0x80;
  *puRam0202bb50 = 0xc0;
  *puRam0202bb58 = (short)uRam0202bb54;
  *puRam0202bb5c = 0xc0;
  return;
}

