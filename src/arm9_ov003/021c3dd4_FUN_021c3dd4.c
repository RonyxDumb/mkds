/* Decompiled C draft; module arm9_ov003; ROM address 021c3dd4. No matching claim. */
#include "types.h"
#include "deps/021c3dd4_FUN_021c3dd4.h"

void FUN_021c3dd4(void)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  
  *DAT_021c3e58 = 0;
  FUN_021c3cc4();
  FUN_021bf86c(0x10);
  FUN_021cdcf0(3);
  FUN_021bf43c(0x88,0xffffffff);
  puVar2 = (uint *)FUN_021d1c18(0,0x5b);
  piVar1 = DAT_021c3e5c;
  *DAT_021c3e5c = (int)puVar2;
  *puVar2 = (*DAT_021c3e60 & DAT_021c3e64) << 0x10 | *puVar2 & DAT_021c3e68 | DAT_021c3e60[1] & 0xff
  ;
  *(ushort *)(*piVar1 + 4) = *(ushort *)(*piVar1 + 4) & (ushort)DAT_021c3e6c | (ushort)DAT_021c3e70;
  iVar3 = (uint)*DAT_021c3e74 * 8;
  FUN_021bf6c8(*(undefined2 *)(DAT_021c3e78 + iVar3),*(undefined2 *)(DAT_021c3e7c + iVar3),
               *(undefined2 *)(DAT_021c3e80 + iVar3),*(undefined2 *)(DAT_021c3e84 + iVar3));
  FUN_021c212c(DAT_021c3e88);
  return;
}

