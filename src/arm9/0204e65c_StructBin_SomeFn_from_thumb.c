/* Decompiled C draft; module arm9; ROM address 0204e65c. No matching claim. */
#include "types.h"
#include "deps/0204e65c_StructBin_SomeFn_from_thumb.h"

void StructBin_SomeFn_from_thumb(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*piRam0204e6d4 + iRam0204e6d8);
  if (iVar1 != 0) {
    Mem_CpuFill8((uint *)(uintptr_t)(iVar1),0,*(undefined4 *)(*piRam0204e6d4 + iRam0204e6dc));
  }
  if (*(int *)(*piRam0204e6d4 + iRam0204e6e0) != 0) {
    Mem_CpuFill8((uint *)(uintptr_t)(*(int *)(*piRam0204e6d4 + iRam0204e6e0)),0,uRam0204e6e4);
  }
  iVar2 = 0;
  iVar1 = param_1;
  do {
    *(undefined4 *)(iVar1 + 0x14) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  *(undefined1 *)(param_1 + 0x3c) = 0;
  *(undefined1 *)(param_1 + 0x3d) = 0;
  *(undefined1 *)(param_1 + 0x3e) = 0;
  *(undefined1 *)(param_1 + 0x3f) = 0;
  *(undefined1 *)(param_1 + 0x40) = 0;
  *(undefined1 *)(param_1 + 0x41) = 0;
  *(undefined2 *)(param_1 + 0x38) = 0;
  *(undefined2 *)(param_1 + 0x3a) = 0;
  *(undefined1 *)(param_1 + 0x42) = 0xff;
  *(undefined4 *)(param_1 + 0x44) = 0;
  return;
}

