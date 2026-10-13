/* Decompiled C draft; module arm9_ov000; ROM address 02184c74. No matching claim. */
#include "types.h"
#include "deps/02184c74_FUN_02184c74.h"

void FUN_02184c74(void)

{
  int *piVar1;
  int iVar2;
  undefined1 *puVar3;
  byte *pbVar4;
  int iVar5;
  
  piVar1 = DAT_02184cdc;
  iVar5 = 0;
  puVar3 = DAT_02184cd8;
  pbVar4 = DAT_02184cd4;
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

