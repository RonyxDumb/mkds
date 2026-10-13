/* Decompiled C draft; module arm9_ov003; ROM address 021c70a4. No matching claim. */
#include "types.h"
#include "deps/021c70a4_FUN_021c70a4.h"

void FUN_021c70a4(void)

{
  int iVar1;
  uint *puVar2;
  int local_20;
  undefined4 local_1c [4];
  undefined4 local_c;
  
  local_1c[0] = *DAT_021c7104;
  local_1c[1] = DAT_021c7104[1];
  local_1c[2] = DAT_021c7104[2];
  local_1c[3] = DAT_021c7104[3];
  local_c = DAT_021c7104[4];
  iVar1 = FUN_021cef6c();
  if (iVar1 == 0) {
    if (*(char *)(*DAT_021c7108 + 0x15) == '\0') {
      puVar2 = *(uint **)(*DAT_021c7108 + 4);
      *puVar2 = *puVar2 & DAT_021c710c;
      FUN_021c212c(DAT_021c7110);
      return;
    }
    FUN_021c20dc(&local_20,0);
    (*(code *)local_1c[local_20])(*DAT_021c7108 + 8);
    FUN_021c212c(DAT_021c7114);
  }
  return;
}

