/* Decompiled C draft; module arm9; ROM address 02077b3c. No matching claim. */
#include "types.h"
#include "deps/02077b3c_func_02077b3c.h"

void func_02077b3c(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = piRam02077ba0;
  if ((*(int *)(*piRam02077ba0 + iRam02077ba4) != 0) ||
     (*(int *)(*piRam02077ba0 + iRam02077ba8) != 0)) {
    *(undefined4 *)
     (*piRam02077ba0 + *(short *)(*piRam02077ba0 + iRam02077bac) * 0x34 + iRam02077bb0) = 1;
    **(undefined4 **)(*piVar1 + 0x20) = *(undefined4 *)(*piVar1 + 0x24);
    *(undefined4 *)(*(int *)(*piVar1 + 0x20) + 4) = *(undefined4 *)(*piVar1 + 0x28);
    iVar2 = *piVar1;
    *(int *)(*(int *)(iVar2 + 0x20) + 0x20) =
         *(int *)(iVar2 + iRam02077bb4) + *(int *)(iVar2 + 0x28) * 0xe0;
    WorkerInsertTask(uRam02077bb8);
    *(undefined4 *)(*piRam02077bbc + 0xf8) = 1;
  }
  return;
}

