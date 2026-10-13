/* Decompiled C draft; module arm9_ov003; ROM address 021c39a4. No matching claim. */
#include "types.h"
#include "deps/021c39a4_FUN_021c39a4.h"

void FUN_021c39a4(void)

{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_021d1f70(1);
  if (((iVar2 == 0) && (iVar2 = FUN_021d1f70(0), iVar2 == 0)) &&
     (iVar2 = FUN_021bf2f0(), iVar2 != 0)) {
    FUN_021d2f00(*DAT_021c3a5c);
    FUN_021bf698();
    FUN_021bf410();
    FUN_021d1490(*DAT_021c3a60);
    FUN_021d272c(1,1);
    FUN_021d272c(0,0x14);
    if (*DAT_021c3a64 == '\0') {
      FUN_021c2120(0,0);
      FUN_021c212c(DAT_021c3a68);
      return;
    }
    cVar1 = *DAT_021c3a6c;
    if (cVar1 == '\0') {
      FUN_021c2120(0,1);
      FUN_021c212c(DAT_021c3a70);
      return;
    }
    if (cVar1 == '\x01') {
      FUN_021c2120(0,1);
      FUN_021c212c(DAT_021c3a74);
      return;
    }
    if (cVar1 != '\x02') {
      return;
    }
    FUN_021c2120(0,1);
    FUN_021c212c(DAT_021c3a78);
  }
  return;
}

