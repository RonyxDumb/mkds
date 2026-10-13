/* Decompiled C draft; module arm9; ROM address 02056208. No matching claim. */
#include "types.h"
#include "deps/02056208_GetWorstStarRank_from_thumb.h"

undefined4 GetWorstStarRank_from_thumb(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 7;
  bVar2 = 0;
  do {
    bVar1 = 0;
    do {
      iVar3 = GetCupEntryRank(bVar2,bVar1);
      if ((iVar3 == 9) || (iVar3 < iVar4)) {
        iVar4 = iVar3;
      }
      if ((iVar4 == 9) || (iVar4 < 5)) {
        return 0;
      }
      bVar1 = bVar1 + 1;
    } while (bVar1 < 4);
    bVar2 = bVar2 + 1;
  } while (bVar2 < 8);
  if (iVar4 == 5) {
    return 1;
  }
  if (iVar4 != 6) {
    if (iVar4 != 7) {
      return 0;
    }
    return 3;
  }
  return 2;
}

