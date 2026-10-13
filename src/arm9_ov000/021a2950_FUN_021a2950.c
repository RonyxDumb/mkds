/* Decompiled C draft; module arm9_ov000; ROM address 021a2950. No matching claim. */
#include "types.h"
#include "deps/021a2950_FUN_021a2950.h"

undefined8 FUN_021a2950(longlong *param_1,undefined4 param_2)

{
  uint uVar1;
  char *pcVar2;
  bool bVar3;
  longlong lVar4;
  
  pcVar2 = (char *)*DAT_021a2998;
  if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
    lVar4 = FUN_021a350c();
    lVar4 = lVar4 - *(longlong *)(pcVar2 + 0x10);
    uVar1 = (uint)((ulonglong)lVar4 >> 0x20);
    if (param_1 != (longlong *)0x0) {
      *param_1 = lVar4;
    }
    bVar3 = *(uint *)(pcVar2 + 4) <= (uint)lVar4;
    return CONCAT44(uVar1 - !bVar3,(uint)(uVar1 != 0 || uVar1 < bVar3));
  }
  return CONCAT44(param_2,0xffffffff);
}

