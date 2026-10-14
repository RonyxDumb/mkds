/* Decompiled C draft; module arm9; ROM address 02020720. No matching claim. */
#include "types.h"
#include "deps/02020720_SomeHashing.h"

void SomeHashing(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  
  uVar4 = 0;
  do {
    uVar3 = 0;
    uVar2 = uVar4;
    do {
      bVar5 = (uVar2 & 1) != 0;
      if (bVar5) {
        uVar2 = param_2 ^ uVar2 >> 1;
      }
      uVar3 = uVar3 + 1;
      if (!bVar5) {
        uVar2 = uVar2 >> 1;
      }
    } while (uVar3 < 8);
    iVar1 = uVar4 * 2;
    uVar4 = uVar4 + 1;
    *(short *)(param_1 + iVar1) = (short)uVar2;
  } while (uVar4 < 0x100);
  return;
}

