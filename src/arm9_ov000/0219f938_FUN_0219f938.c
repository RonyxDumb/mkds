/* Decompiled C draft; module arm9_ov000; ROM address 0219f938. No matching claim. */
#include "types.h"
#include "deps/0219f938_FUN_0219f938.h"

undefined4 FUN_0219f938(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = DAT_0219f9a8;
  uVar3 = 1;
  iVar2 = *DAT_0219f9a8;
  if (*(char *)(iVar2 + 0x15) == '\x03') {
    if (*(char *)(iVar2 + 0xd) != '\0') {
      FUN_0219f0f4();
    }
    FUN_021a1a38(6,DAT_0219f9ac);
    return 0;
  }
  *(undefined1 *)(iVar2 + 0x14) = *(undefined1 *)(iVar2 + 0xd);
  *(undefined4 *)(*piVar1 + DAT_0219f9b0) = 0;
  if (*(int *)(*piVar1 + DAT_0219f9b4) != 0) {
    FUN_0219ac50();
    *(undefined4 *)(*DAT_0219f9a8 + DAT_0219f9b4) = 0;
  }
  if (*(char *)(*DAT_0219f9a8 + 0xd) == '\0') {
    *(undefined4 *)(*DAT_0219f9a8 + DAT_0219f9b8) = 4;
    uVar3 = FUN_0219fb48();
  }
  else {
    FUN_0219f214();
  }
  return uVar3;
}

