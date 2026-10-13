/* Decompiled C draft; module arm9_ov001; ROM address 0219e660. No matching claim. */
#include "types.h"
#include "deps/0219e660_FUN_0219e660.h"

void FUN_0219e660(void)

{
  uint uVar1;
  uint uVar2;
  ushort *puVar3;
  
  uVar2 = DAT_0219e6b8;
  uVar1 = DAT_0219e6b4;
  *DAT_0219e6b0 = *DAT_0219e6b0 & DAT_0219e6b4 | DAT_0219e6b8;
  *DAT_0219e6bc = *DAT_0219e6bc & uVar1 | uVar2;
  puVar3 = DAT_0219e6c0;
  *DAT_0219e6c0 = *DAT_0219e6c0 & 0xfffc | 3;
  *puVar3 = *puVar3 & 0x43 | (ushort)DAT_0219e6c4;
  *DAT_0219e6c8 = *DAT_0219e6c8 & 0x43 | (ushort)DAT_0219e6cc;
  *DAT_0219e6d0 = 0;
  *DAT_0219e6d4 = 0;
  *DAT_0219e6d8 = 0;
  *DAT_0219e6dc = 0;
  return;
}

