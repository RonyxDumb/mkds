/* Decompiled C draft; module arm9; ROM address 02090940. No matching claim. */
#include "types.h"
#include "deps/02090940_IsTitleTrue.h"

undefined4 IsTitleTrue(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = 0;
  while( true ) {
    iVar2 = CupHasRecord(iVar4,iVar3);
    bVar1 = false;
    if ((iVar2 != 0) && (iVar2 = CupGetResult(iVar4,iVar3), iVar2 == 0)) {
      bVar1 = true;
    }
    if (!bVar1) break;
    iVar3 = iVar3 + 1;
    if ((3 < iVar3) && (iVar4 = iVar4 + 1, iVar3 = 0, 7 < iVar4)) {
      return 1;
    }
  }
  return 0;
}

