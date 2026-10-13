/* Decompiled C draft; module arm9; ROM address 0202993c. No matching claim. */
#include "types.h"
#include "deps/0202993c_DoInitializeGlobalCA_from_thumb.h"

void DoInitializeGlobalCA_from_thumb(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  CpuFastMemoryZero(*piRam020299d8,uRam020299dc);
  piVar1 = piRam020299d8;
  iVar4 = 0;
  do {
    iVar3 = iVar4 * 0x18;
    *(undefined4 *)(*piVar1 + iVar3) = 0xffffffff;
    *(undefined4 *)(*piVar1 + iVar3 + 4) = 0xffffffff;
    *(undefined4 *)(*piVar1 + iVar3 + 8) = 4;
    *(undefined4 *)(*piVar1 + iVar3 + 0xc) = 0xffffffff;
    *(undefined4 *)(*piVar1 + iVar3 + 0x10) = 3;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 8);
  *(undefined1 *)(*piVar1 + 0xfc) = 1;
  *(undefined1 *)(*piVar1 + 0xfd) = 1;
  iVar4 = GetPMaybeState();
  if (iVar4 == 0) {
    iVar4 = func_020299e4();
    if (iVar4 == 0) {
      uVar2 = find_buf_fn_from_thumb(uRam020299e0);
      *(undefined4 *)(*piRam020299d8 + 0xf4) = uVar2;
    }
    else {
      *(undefined4 *)(*piRam020299d8 + 0xf4) = 0;
    }
    iVar4 = *piRam020299d8;
    if (*(int *)(iVar4 + 0xf4) == 0) {
      *(undefined4 *)(iVar4 + 0xf8) = 0;
    }
    else {
      *(int *)(iVar4 + 0xf8) = *(int *)(iVar4 + 0xf4) + 8;
    }
  }
  return;
}

