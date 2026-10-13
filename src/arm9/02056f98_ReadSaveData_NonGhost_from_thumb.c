/* Decompiled C draft; module arm9; ROM address 02056f98. No matching claim. */
#include "types.h"
#include "deps/02056f98_ReadSaveData_NonGhost_from_thumb.h"

void ReadSaveData_NonGhost_from_thumb(void)

{
  int *piVar1;
  
  piVar1 = piRam02056fd0;
  *(uint *)(*piRam02056fd0 + 0x44) = *(uint *)(*piRam02056fd0 + 0x44) & 0xfffffffe | 1;
  *(undefined1 *)(*piVar1 + 0x3c) = 0;
  *(undefined2 *)(*piVar1 + 0x2a) = 0;
  EnableMKDSSVSomeFlag_from_thumb();
  WorkerInsertTask(uRam02056fd4);
  *(undefined4 *)(*piRam02056fd8 + 0xf8) = 1;
  return;
}

