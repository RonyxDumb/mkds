/* Decompiled C draft; module arm9; ROM address 02046828. No matching claim. */
#include "types.h"
#include "deps/02046828_GetSomeInternalCourseId.h"

uint GetSomeInternalCourseId(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = (int)param_1 >> 0x1f;
  uVar3 = iRam02046848 + (param_1 >> 2) * 0x10 +
          ((param_1 * 0x40000000 + iVar2 >> 0x1e | iVar2 << 2) - iVar2) * 4;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  return uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
}

