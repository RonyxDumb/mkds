/* Decompiled C draft; module arm9; ROM address 020422c4. No matching claim. */
#include "types.h"
#include "deps/020422c4_CountAreaType2_from_thumb.h"

void CountAreaType2_from_thumb(void)

{
  int *piVar1;
  char cVar2;
  ushort uVar3;
  int iVar4;
  
  piVar1 = piRam02042318;
  cVar2 = '\0';
  if (*(int *)(*piRam02042314 + 8) == 4) {
    uVar3 = 0;
    if (*(short *)(*piRam02042318 + 0x78) != 0) {
      do {
        iVar4 = GetGlobalPENkmAREAByIndex_from_thumb(uVar3);
        if (*(char *)(iVar4 + 0x44) == '\x02') {
          cVar2 = cVar2 + '\x01';
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(ushort *)(*piVar1 + 0x78));
    }
  }
  *(char *)(*piRam02042318 + iRam0204231c) = cVar2;
  return;
}

