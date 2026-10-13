/* Decompiled C draft; module arm9_ov003; ROM address 021c7e20. No matching claim. */
#include "types.h"
#include "deps/021c7e20_FUN_021c7e20.h"

void FUN_021c7e20(void)

{
  int *piVar1;
  char *pcVar2;
  uint uVar3;
  char local_8 [8];
  
  piVar1 = DAT_021c7e88;
  pcVar2 = local_8;
  local_8[0] = *DAT_021c7e80;
  local_8[1] = DAT_021c7e80[1];
  local_8[2] = DAT_021c7e80[2];
  local_8[3] = DAT_021c7e80[3];
  uVar3 = 0;
  while (*DAT_021c7e84 != *pcVar2) {
    pcVar2 = pcVar2 + 1;
    uVar3 = uVar3 + 1;
    if (3 < (int)uVar3) {
      return;
    }
  }
  *(undefined1 *)(*DAT_021c7e88 + uVar3 + 4) = 0x14;
  if ((uVar3 & 1) != 0) {
    *(undefined1 *)(*piVar1 + uVar3 + 3) = 0;
    return;
  }
  *(undefined1 *)(*piVar1 + uVar3 + 5) = 0;
  return;
}

