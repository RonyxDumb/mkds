/* Decompiled C draft; module arm9; ROM address 02042320. No matching claim. */
#include "types.h"
#include "deps/02042320_CountAreaType4_from_thumb.h"

void CountAreaType4_from_thumb(void)

{
  int *piVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  
  piVar1 = piRam02042364;
  sVar2 = 0;
  uVar3 = 0;
  iVar4 = *piRam02042364;
  if (*(short *)(iVar4 + 0x78) != 0) {
    do {
      iVar4 = GetGlobalPENkmAREAByIndex_from_thumb(uVar3);
      if (*(char *)(iVar4 + 0x44) == '\x04') {
        sVar2 = sVar2 + 1;
      }
      uVar3 = uVar3 + 1;
      iVar4 = *piVar1;
    } while (uVar3 < *(ushort *)(iVar4 + 0x78));
  }
  *(short *)(iVar4 + iRam02042368) = sVar2;
  return;
}

