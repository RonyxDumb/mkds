/* Decompiled C draft; module arm9; ROM address 0204f33c. No matching claim. */
#include "types.h"
#include "deps/0204f33c_func_0204f33c.h"

void func_0204f33c(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = iRam0204f3e0;
  piVar1 = piRam0204f3dc;
  *(undefined4 *)(*piRam0204f3dc + iRam0204f3e0) = uRam0204f3d8;
  uVar2 = Mem_AllocateHeapAligned(param_1,*(undefined4 *)(*piVar1 + iVar3),0x20);
  piVar1 = piRam0204f3dc;
  *(undefined4 *)(*piRam0204f3dc + iRam0204f3e4) = uVar2;
  iVar3 = iRam0204f3ec;
  *(undefined4 *)(*piVar1 + iRam0204f3ec) = uRam0204f3e8;
  uVar2 = Mem_AllocateHeapAligned(param_1,*(undefined4 *)(*piVar1 + iVar3),0x20);
  piVar1 = piRam0204f3dc;
  *(undefined4 *)(*piRam0204f3dc + iRam0204f3f0) = uVar2;
  iVar4 = 0;
  iVar3 = 0;
  do {
    uVar2 = Mem_AllocateHeapAligned(param_1,0x28,0x20);
    *(undefined4 *)(*piVar1 + iVar3 + iRam0204f3f4) = uVar2;
    uVar2 = Mem_AllocateHeapAligned(param_1,4,0x20);
    *(undefined4 *)(*piVar1 + iVar3 + iRam0204f3f8) = uVar2;
    iVar3 = iVar3 + 4;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 8);
  uVar2 = Mem_AllocateHeapAligned(param_1,uRam0204f3fc,0x20);
  *(undefined4 *)(*piRam0204f3dc + iRam0204f400) = uVar2;
  uVar2 = Mem_AllocateHeapAligned(param_1,0x20,0x20);
  *(undefined4 *)(*piRam0204f3dc + iRam0204f404) = uVar2;
  return;
}

