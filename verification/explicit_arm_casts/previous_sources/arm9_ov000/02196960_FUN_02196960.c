/* Decompiled C draft; module arm9_ov000; ROM address 02196960. No matching claim. */
#include "types.h"
#include "deps/02196960_FUN_02196960.h"

void FUN_02196960(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 local_24 [16];
  
  if (*DAT_021969c8 != 0) {
    iVar4 = FUN_0218dc44();
    puVar3 = DAT_021969d0;
    uVar2 = DAT_021969cc;
    iVar4 = iVar4 + -1;
    if (-1 < iVar4) {
      do {
        puVar6 = local_24;
        iVar5 = 0x10;
        puVar7 = DAT_021969d4;
        do {
          uVar1 = *puVar7;
          puVar7 = puVar7 + 1;
          *puVar6 = uVar1;
          puVar6 = puVar6 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        *puVar3 = uVar2;
        FUN_021971ec(local_24,0xf);
        FUN_021969d8(iVar4,0,0,local_24,0);
        iVar4 = iVar4 + -1;
      } while (-1 < iVar4);
    }
    FUN_0218dc48(*DAT_021969c8);
    *DAT_021969c8 = 0;
  }
  return;
}

