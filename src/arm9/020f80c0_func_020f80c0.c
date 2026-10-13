/* Decompiled C draft; module arm9; ROM address 020f80c0. No matching claim. */
#include "types.h"
#include "deps/020f80c0_func_020f80c0.h"

void func_020f80c0(int param_1,int param_2)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  ushort *puVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  
  puVar4 = (ushort *)(iRam020f8138 + (param_2 + -1) * 0xe);
  puVar7 = *(undefined2 **)(param_1 + 4);
  if (param_2 != 8) {
    iVar6 = 0;
    puVar3 = puVar7;
    if (0 < param_2) {
      do {
        iVar5 = 0;
        puVar2 = puVar7 + (*puVar4 - 1 & 0xffff) * 0x12;
        puVar1 = puVar3;
        do {
          *puVar1 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar1 = puVar1 + 1;
          iVar5 = iVar5 + 1;
        } while (iVar5 < 0x12);
        puVar4 = puVar4 + 1;
        iVar6 = iVar6 + 1;
        puVar3 = puVar3 + 0x12;
      } while (iVar6 < param_2);
    }
    if (iVar6 < 8) {
      puVar7 = puVar7 + iVar6 * 0x12;
      do {
        iVar5 = 0;
        puVar3 = puVar7;
        do {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
          iVar5 = iVar5 + 1;
        } while (iVar5 < 0x12);
        puVar7 = puVar7 + 0x12;
        iVar6 = iVar6 + 1;
      } while (iVar6 < 8);
    }
  }
  return;
}

