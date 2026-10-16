/* Decompiled C draft; module arm9; ROM address 02027a58. No matching claim. */
#include "types.h"
#include "deps/02027a58_func_02027a58.h"

void func_02027a58(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  int iVar10;
  
  puVar9 = DAT_02027bdc;
  puVar8 = DAT_02027bd8;
  puVar7 = DAT_02027bd4;
  puVar6 = DAT_02027bd0;
  puVar5 = DAT_02027bcc;
  puVar4 = DAT_02027bc8;
  puVar3 = DAT_02027bc4;
  puVar2 = DAT_02027bc0;
  puVar1 = DAT_02027bbc;
  iVar10 = *DAT_02027bb8;
  switch(*(undefined4 *)(iVar10 + 0x60)) {
  case 0:
    *(undefined2 *)(iVar10 + 0x84) = *DAT_02027bbc;
    *(undefined2 *)(iVar10 + 0x86) = puVar1[1];
    *(undefined2 *)(iVar10 + 0x88) = puVar1[2];
    *(undefined2 *)(iVar10 + 0x8a) = puVar1[3];
    return;
  case 1:
    *(undefined2 *)(iVar10 + 0x84) = *DAT_02027bc0;
    *(undefined2 *)(iVar10 + 0x86) = puVar2[1];
    *(undefined2 *)(iVar10 + 0x88) = puVar2[2];
    *(undefined2 *)(iVar10 + 0x8a) = puVar2[3];
    return;
  case 2:
    *(undefined2 *)(iVar10 + 0x84) = *DAT_02027bc4;
    *(undefined2 *)(iVar10 + 0x86) = puVar3[1];
    *(undefined2 *)(iVar10 + 0x88) = puVar3[2];
    *(undefined2 *)(iVar10 + 0x8a) = puVar3[3];
    return;
  case 3:
    *(undefined2 *)(iVar10 + 0x84) = *DAT_02027bc8;
    *(undefined2 *)(iVar10 + 0x86) = puVar4[1];
    *(undefined2 *)(iVar10 + 0x88) = puVar4[2];
    *(undefined2 *)(iVar10 + 0x8a) = puVar4[3];
    return;
  case 4:
    *(undefined2 *)(iVar10 + 0x84) = *DAT_02027bcc;
    *(undefined2 *)(iVar10 + 0x86) = puVar5[1];
    *(undefined2 *)(iVar10 + 0x88) = puVar5[2];
    *(undefined2 *)(iVar10 + 0x8a) = puVar5[3];
    return;
  case 5:
    *(undefined2 *)(iVar10 + 0x84) = *DAT_02027bd0;
    *(undefined2 *)(iVar10 + 0x86) = puVar6[1];
    *(undefined2 *)(iVar10 + 0x88) = puVar6[2];
    *(undefined2 *)(iVar10 + 0x8a) = puVar6[3];
    return;
  case 6:
    *(undefined2 *)(iVar10 + 0x84) = *DAT_02027bd4;
    *(undefined2 *)(iVar10 + 0x86) = puVar7[1];
    *(undefined2 *)(iVar10 + 0x88) = puVar7[2];
    *(undefined2 *)(iVar10 + 0x8a) = puVar7[3];
    return;
  case 7:
    *(undefined2 *)(iVar10 + 0x84) = *DAT_02027bd8;
    *(undefined2 *)(iVar10 + 0x86) = puVar8[1];
    *(undefined2 *)(iVar10 + 0x88) = puVar8[2];
    *(undefined2 *)(iVar10 + 0x8a) = puVar8[3];
    return;
  case 8:
    *(undefined2 *)(iVar10 + 0x84) = *DAT_02027bdc;
    *(undefined2 *)(iVar10 + 0x86) = puVar9[1];
    *(undefined2 *)(iVar10 + 0x88) = puVar9[2];
    *(undefined2 *)(iVar10 + 0x8a) = puVar9[3];
  }
  return;
}

