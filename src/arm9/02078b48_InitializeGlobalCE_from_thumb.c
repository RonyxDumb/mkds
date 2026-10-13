/* Decompiled C draft; module arm9; ROM address 02078b48. No matching claim. */
#include "types.h"
#include "deps/02078b48_InitializeGlobalCE_from_thumb.h"

void InitializeGlobalCE_from_thumb(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  *puRam02078c14 = 0;
  iVar2 = Mem_AllocateHeap(param_1,uRam02078c18);
  piVar1 = piRam02078c1c;
  *piRam02078c1c = iVar2;
  *(undefined2 *)(iVar2 + iRam02078c20) = 0xffff;
  iVar2 = iRam02078c24;
  *(undefined2 *)(*piVar1 + iRam02078c24) = 0;
  iVar3 = *piVar1;
  *(int *)(iVar3 + 0x20) = iVar3 + 0x58 + *(short *)(iVar3 + iVar2) * 0xb8;
  *(undefined4 *)(*piVar1 + iRam02078c28) = 0;
  *(undefined4 *)(*piVar1 + iRam02078c2c) = 0;
  *(undefined4 *)(*piVar1 + iRam02078c30) = 0;
  *(undefined4 *)(*piVar1 + iRam02078c34) = 0;
  *(undefined4 *)(*piVar1 + 0x18) = 0;
  *(undefined4 *)(*piVar1 + 0x1c) = 0;
  *(undefined4 *)(*piVar1 + iRam02078c38) = 0;
  *(undefined4 *)(*piVar1 + iRam02078c3c) = 0;
  *(undefined4 *)(*piVar1 + iRam02078c40) = 0;
  *(undefined2 *)(*piVar1 + iRam02078c44) = 0;
  iVar2 = iRam02078c48;
  *(undefined4 *)(*piVar1 + iRam02078c48) = 0;
  *(undefined4 *)(*piVar1 + iRam02078c4c) = *(undefined4 *)(*piVar1 + iVar2);
  ReadEmblemPalette_from_thumb(param_1);
  ReadKartModelMenuFile_from_thumb(param_1,uRam02078c50,*piRam02078c1c + iRam02078c54);
  piVar1 = piRam02078c1c;
  uVar4 = 0;
  do {
    StructCESub_Initialize_from_thumb(param_1,*piVar1 + 0x58 + uVar4 * 0xb8);
    uVar4 = uVar4 + 1 & 0xffff;
  } while (uVar4 < 2);
  StructCE0_SomeFn_from_thumb((undefined4 *)(uintptr_t)(*piRam02078c1c + 0x24),1);
  SetActiveExecutionContextHeapGroupId_from_thumb(9);
  return;
}

