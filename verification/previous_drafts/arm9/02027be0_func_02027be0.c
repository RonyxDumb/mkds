/* Decompiled C draft; module arm9; ROM address 02027be0. No matching claim. */
#include "types.h"
#include "deps/02027be0_func_02027be0.h"

void func_02027be0(void)

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
  undefined2 *puVar10;
  undefined2 *puVar11;
  undefined2 *puVar12;
  int iVar13;
  
  puVar12 = DAT_02027df4;
  puVar11 = DAT_02027df0;
  puVar10 = DAT_02027dec;
  puVar9 = DAT_02027de8;
  puVar8 = DAT_02027de4;
  puVar7 = DAT_02027de0;
  puVar6 = DAT_02027ddc;
  puVar5 = DAT_02027dd8;
  puVar4 = DAT_02027dd4;
  puVar3 = DAT_02027dd0;
  puVar2 = DAT_02027dcc;
  puVar1 = DAT_02027dc8;
  iVar13 = *DAT_02027dc4;
  switch(*(undefined4 *)(iVar13 + 0x60)) {
  case 0:
    *(undefined2 *)(iVar13 + 0x84) = *DAT_02027dc8;
    *(undefined2 *)(iVar13 + 0x86) = puVar1[1];
    *(undefined2 *)(iVar13 + 0x88) = puVar1[2];
    *(undefined2 *)(iVar13 + 0x8a) = puVar1[3];
    return;
  case 1:
    if (*(int *)(iVar13 + 100) != 4) {
      *(undefined2 *)(iVar13 + 0x84) = *DAT_02027dd0;
      *(undefined2 *)(iVar13 + 0x86) = puVar3[1];
      *(undefined2 *)(iVar13 + 0x88) = puVar3[2];
      *(undefined2 *)(iVar13 + 0x8a) = puVar3[3];
      return;
    }
    *(undefined2 *)(iVar13 + 0x84) = *DAT_02027dcc;
    *(undefined2 *)(iVar13 + 0x86) = puVar2[1];
    *(undefined2 *)(iVar13 + 0x88) = puVar2[2];
    *(undefined2 *)(iVar13 + 0x8a) = puVar2[3];
    return;
  case 2:
    *(undefined2 *)(iVar13 + 0x84) = *DAT_02027dd4;
    *(undefined2 *)(iVar13 + 0x86) = puVar4[1];
    *(undefined2 *)(iVar13 + 0x88) = puVar4[2];
    *(undefined2 *)(iVar13 + 0x8a) = puVar4[3];
    return;
  case 3:
    break;
  case 4:
    if ((*(int *)(iVar13 + 100) != 2) && (*(int *)(iVar13 + 100) != 7)) {
      *(undefined2 *)(iVar13 + 0x84) = *DAT_02027de4;
      *(undefined2 *)(iVar13 + 0x86) = puVar8[1];
      *(undefined2 *)(iVar13 + 0x88) = puVar8[2];
      *(undefined2 *)(iVar13 + 0x8a) = puVar8[3];
      return;
    }
    *(undefined2 *)(iVar13 + 0x84) = *DAT_02027de0;
    *(undefined2 *)(iVar13 + 0x86) = puVar7[1];
    *(undefined2 *)(iVar13 + 0x88) = puVar7[2];
    *(undefined2 *)(iVar13 + 0x8a) = puVar7[3];
    return;
  case 5:
    *(undefined2 *)(iVar13 + 0x84) = *DAT_02027de8;
    *(undefined2 *)(iVar13 + 0x86) = puVar9[1];
    *(undefined2 *)(iVar13 + 0x88) = puVar9[2];
    *(undefined2 *)(iVar13 + 0x8a) = puVar9[3];
    return;
  case 6:
    if (*(int *)(iVar13 + 100) != 4) {
      *(undefined2 *)(iVar13 + 0x84) = *DAT_02027df0;
      *(undefined2 *)(iVar13 + 0x86) = puVar11[1];
      *(undefined2 *)(iVar13 + 0x88) = puVar11[2];
      *(undefined2 *)(iVar13 + 0x8a) = puVar11[3];
      return;
    }
    *(undefined2 *)(iVar13 + 0x84) = *DAT_02027dec;
    *(undefined2 *)(iVar13 + 0x86) = puVar10[1];
    *(undefined2 *)(iVar13 + 0x88) = puVar10[2];
    *(undefined2 *)(iVar13 + 0x8a) = puVar10[3];
    return;
  case 7:
    *(undefined2 *)(iVar13 + 0x84) = *DAT_02027df4;
    *(undefined2 *)(iVar13 + 0x86) = puVar12[1];
    *(undefined2 *)(iVar13 + 0x88) = puVar12[2];
    *(undefined2 *)(iVar13 + 0x8a) = puVar12[3];
  default:
    return;
  }
  if ((*(int *)(iVar13 + 100) != 1) && (*(int *)(iVar13 + 100) != 6)) {
    *(undefined2 *)(iVar13 + 0x84) = *DAT_02027ddc;
    *(undefined2 *)(iVar13 + 0x86) = puVar6[1];
    *(undefined2 *)(iVar13 + 0x88) = puVar6[2];
    *(undefined2 *)(iVar13 + 0x8a) = puVar6[3];
    return;
  }
  *(undefined2 *)(iVar13 + 0x84) = *DAT_02027dd8;
  *(undefined2 *)(iVar13 + 0x86) = puVar5[1];
  *(undefined2 *)(iVar13 + 0x88) = puVar5[2];
  *(undefined2 *)(iVar13 + 0x8a) = puVar5[3];
  return;
}

