/* Decompiled C draft; module arm9_ov000; ROM address 021840c8. No matching claim. */
#include "types.h"
#include "deps/021840c8_FUN_021840c8.h"

void FUN_021840c8(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar4 = 0;
  puVar3 = DAT_02184118;
  do {
    iVar2 = *DAT_0218411c;
    if (*(int *)(iVar2 + iVar4 + 0x24) == 0) {
      uVar1 = func_0x020b3f7c(*(undefined4 *)(iVar2 + DAT_02184120),10);
      func_0x0212426c(1,*puVar3,*(undefined4 *)(*DAT_0218411c + DAT_0218412c),uVar1,
                      *(undefined4 *)(iVar2 + DAT_02184124),*(undefined4 *)(iVar2 + DAT_02184128));
    }
    iVar4 = iVar4 + 4;
    puVar3 = puVar3 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  return;
}

