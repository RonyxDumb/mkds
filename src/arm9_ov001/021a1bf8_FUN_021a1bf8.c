/* Decompiled C draft; module arm9_ov001; ROM address 021a1bf8. No matching claim. */
#include "types.h"
#include "deps/021a1bf8_FUN_021a1bf8.h"

void FUN_021a1bf8(void)

{
  int *piVar1;
  ushort *puVar2;
  int iVar3;
  
  piVar1 = DAT_021a1c30;
  iVar3 = 0;
  puVar2 = DAT_021a1c2c;
  do {
    *(undefined4 *)(*(int *)(*piVar1 + 0x14) + (uint)*puVar2 * 0x40) = 0;
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  iVar3 = *piVar1;
  *(undefined4 *)(*(int *)(iVar3 + 0x14) + (uint)DAT_021a1c2c[*(int *)(iVar3 + 0x34)] * 0x40) = 1;
  return;
}

