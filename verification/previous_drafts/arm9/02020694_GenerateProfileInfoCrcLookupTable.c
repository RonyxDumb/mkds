/* Decompiled C draft; module arm9; ROM address 02020694. No matching claim. */
#include "types.h"
#include "deps/02020694_GenerateProfileInfoCrcLookupTable.h"

void GenerateProfileInfoCrcLookupTable(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  uVar3 = 0;
  do {
    uVar2 = 0;
    uVar1 = uVar3;
    do {
      bVar4 = (uVar1 & 1) != 0;
      if (bVar4) {
        uVar1 = param_2 ^ uVar1 >> 1;
      }
      uVar2 = uVar2 + 1;
      if (!bVar4) {
        uVar1 = uVar1 >> 1;
      }
    } while (uVar2 < 8);
    *(uint *)(param_1 + uVar3 * 4) = uVar1;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x100);
  return;
}

