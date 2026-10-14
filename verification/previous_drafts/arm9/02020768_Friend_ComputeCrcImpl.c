/* Decompiled C draft; module arm9; ROM address 02020768. No matching claim. */
#include "types.h"
#include "deps/02020768_Friend_ComputeCrcImpl.h"

void Friend_ComputeCrcImpl(int param_1,byte *param_2,byte *param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  
  bVar2 = *param_2;
  uVar3 = 0;
  if (param_4 != 0) {
    do {
      bVar1 = *param_3;
      uVar3 = uVar3 + 1;
      param_3 = param_3 + 1;
      bVar2 = *(byte *)(param_1 + (uint)(bVar2 ^ bVar1));
    } while (uVar3 < param_4);
  }
  *param_2 = bVar2;
  return;
}

