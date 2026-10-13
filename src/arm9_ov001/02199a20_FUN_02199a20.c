/* Decompiled C draft; module arm9_ov001; ROM address 02199a20. No matching claim. */
#include "types.h"
#include "deps/02199a20_FUN_02199a20.h"

void FUN_02199a20(void)

{
  int *piVar1;
  int iVar2;
  undefined1 *puVar3;
  byte *pbVar4;
  int iVar5;
  
  piVar1 = DAT_02199a88;
  iVar5 = 0;
  puVar3 = DAT_02199a84;
  pbVar4 = DAT_02199a80;
  do {
    iVar2 = *piVar1;
    if ((iVar5 == *(int *)(iVar2 + 8)) && (*(int *)(iVar2 + 0x14) != 0)) {
      *(undefined4 *)(*(int *)(iVar2 + 0x1c) + (uint)*pbVar4 * 0x40) = 1;
      func_0x02124a20(*puVar3,0xe,*(undefined4 *)(*piVar1 + 0x20),*(undefined4 *)(*piVar1 + 0x2c));
    }
    else {
      *(undefined4 *)(*(int *)(iVar2 + 0x1c) + (uint)*pbVar4 * 0x40) = 0;
      func_0x02124a20(*puVar3,0xf,*(undefined4 *)(*piVar1 + 0x20),*(undefined4 *)(*piVar1 + 0x2c));
    }
    pbVar4 = pbVar4 + 1;
    puVar3 = puVar3 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  return;
}

