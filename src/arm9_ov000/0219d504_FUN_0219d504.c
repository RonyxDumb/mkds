/* Decompiled C draft; module arm9_ov000; ROM address 0219d504. No matching claim. */
#include "types.h"
#include "deps/0219d504_FUN_0219d504.h"

void FUN_0219d504(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  undefined1 auStack_118 [268];
  
  piVar2 = (int *)*DAT_0219d554;
  if (((code *)piVar2[0x11] != (code *)0x0) && (*piVar2 != 1)) {
    (*(code *)piVar2[0x11])(param_1,piVar2[0x12]);
  }
  if (*(int *)(*DAT_0219d554 + 0x34) != 0) {
    uVar1 = FUN_0219daa8(*(int *)(*DAT_0219d554 + 0x18) + param_1 * 0xc,(undefined4)(uintptr_t)(auStack_118));
    (**(code **)(*DAT_0219d554 + 0x34))
              (param_1,uVar1,auStack_118,*(undefined4 *)(*DAT_0219d554 + 0x38));
  }
  return;
}

