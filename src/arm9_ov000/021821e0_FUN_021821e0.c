/* Decompiled C draft; module arm9_ov000; ROM address 021821e0. No matching claim. */
#include "types.h"
#include "deps/021821e0_FUN_021821e0.h"

void FUN_021821e0(void)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = DAT_02182260;
  iVar5 = 0;
  puVar3 = DAT_0218225c;
  iVar4 = DAT_02182258;
  do {
    iVar2 = *DAT_02182264;
    if ((iVar5 == *(int *)(iVar2 + 8)) && (*(int *)(iVar2 + 0x24) != 0)) {
      *(undefined4 *)(*(int *)(iVar2 + iVar1) + (uint)*(byte *)(iVar4 + 1) * 0x40) = 1;
      iVar2 = *DAT_02182264;
      func_0x02124100(*puVar3,0xe,*(undefined4 *)(iVar2 + DAT_0218226c),
                      *(undefined4 *)(iVar2 + iVar1),*(undefined4 *)(iVar2 + DAT_02182268));
    }
    else {
      *(undefined4 *)(*(int *)(iVar2 + iVar1) + (uint)*(byte *)(iVar4 + 1) * 0x40) = 0;
      iVar2 = *DAT_02182264;
      func_0x02124100(*puVar3,0xf,*(undefined4 *)(iVar2 + DAT_0218226c),
                      *(undefined4 *)(iVar2 + iVar1),*(undefined4 *)(iVar2 + DAT_02182268));
    }
    iVar4 = iVar4 + 9;
    puVar3 = puVar3 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  return;
}

