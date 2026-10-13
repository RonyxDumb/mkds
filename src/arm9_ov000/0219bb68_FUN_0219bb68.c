/* Decompiled C draft; module arm9_ov000; ROM address 0219bb68. No matching claim. */
#include "types.h"
#include "deps/0219bb68_FUN_0219bb68.h"

int FUN_0219bb68(void)

{
  char *pcVar1;
  int iVar2;
  
  if (*DAT_0219bba4 == 0) {
    return 0;
  }
  pcVar1 = (char *)(*DAT_0219bba4 + DAT_0219bba8);
  if ((*pcVar1 != '\x02') && (*pcVar1 != '\x03')) {
    iVar2 = FUN_021a160c();
    return iVar2 + 1;
  }
  iVar2 = FUN_021a15f8();
  return iVar2 + 1;
}

