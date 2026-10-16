/* Decompiled C draft; module arm9; ROM address 02009974. No matching claim. */
#include "types.h"
#include "deps/02009974_func_02009974.h"

byte func_02009974(void)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  
  iVar2 = *piRam020099bc;
  if (*(short *)(iVar2 + 0x12) == 0) {
    bVar3 = 0;
  }
  else {
    bVar3 = 2;
  }
  if (*(short *)(iVar2 + 0x14) == 0) {
    bVar4 = 0;
  }
  else {
    bVar4 = 4;
  }
  if (*(short *)(iVar2 + 0x16) == 0) {
    bVar1 = 0;
  }
  else {
    bVar1 = 8;
  }
  return bVar1 | bVar4 | *(short *)(iVar2 + 0xe) != 0 | bVar3;
}

