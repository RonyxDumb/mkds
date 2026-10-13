/* Decompiled C draft; module arm9; ROM address 020d3bf8. No matching claim. */
#include "types.h"
#include "deps/020d3bf8_func_020d3bf8.h"

short func_020d3bf8(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  short sVar3;
  int iVar4;
  
  sVar3 = 0;
  iVar4 = 0;
  puVar1 = (undefined4 *)*puRam020d3c28;
  if (*(short *)(puVar1 + 1) != 0) {
    puVar2 = (undefined4 *)*puVar1;
    do {
      if (param_1 == *(ushort *)*puVar2) {
        sVar3 = sVar3 + 1;
      }
      puVar2 = puVar2 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)(uint)*(ushort *)(puVar1 + 1));
  }
  return sVar3;
}

