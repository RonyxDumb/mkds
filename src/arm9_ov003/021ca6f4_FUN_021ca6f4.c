/* Decompiled C draft; module arm9_ov003; ROM address 021ca6f4. No matching claim. */
#include "types.h"
#include "deps/021ca6f4_FUN_021ca6f4.h"

void FUN_021ca6f4(void)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  int local_c [3];
  
  puVar1 = DAT_021ca7a4;
  *DAT_021ca7a4 = *DAT_021ca7a4 + 1;
  if (DAT_021ca7a8 <= *puVar1) {
    FUN_021cdbd0();
    iVar2 = FUN_021cd0d0(local_c);
    if (iVar2 == 0) {
      *DAT_021ca7ac = 2;
      FUN_021cefc0(0x43,1,1,0xffffffff,0);
      FUN_021cdc10(0x12);
      FUN_021bf2d0();
      FUN_021c212c(DAT_021ca7b0);
      return;
    }
    iVar3 = 0;
    if (0 < iVar2) {
      do {
        if (*(char *)(local_c[0] + 0x28) != '\x02') break;
        local_c[0] = local_c[0] + 0x2a;
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar2);
    }
    if (iVar3 == iVar2) {
      *DAT_021ca7ac = 3;
      FUN_021cefc0(0x42,1,1,0xffffffff,0);
      FUN_021cdc10(0x12);
      FUN_021bf2d0();
      FUN_021c212c(DAT_021ca7b0);
      return;
    }
    *DAT_021ca7ac = 1;
    FUN_021cdc10(0xf);
    FUN_021c212c(DAT_021ca7b4);
  }
  return;
}

