/* Decompiled C draft; module arm9; ROM address 0204684c. No matching claim. */
#include "types.h"
#include "deps/0204684c_GetCourseIdFromInternalId.h"

int GetCourseIdFromInternalId(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  iVar6 = 0;
  iVar3 = -1;
  do {
    iVar4 = 0;
    do {
      uVar2 = iRam020468ac + iVar5 * 0x10 + iVar4 * 4;
      uVar1 = uVar2 & 3;
      uVar2 = *(uint *)(uVar2 & 0xfffffffc);
      if (param_1 == (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) {
        iVar3 = (iVar4 + iVar6) * 0x1000000 >> 0x18;
        break;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 4);
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + 4;
    if (7 < iVar5) {
      return iVar3;
    }
  } while( true );
}

