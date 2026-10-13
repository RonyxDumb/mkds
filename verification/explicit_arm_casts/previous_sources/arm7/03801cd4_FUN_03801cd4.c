/* Decompiled C draft; module arm7; ROM address 03801cd4. No matching claim. */
#include "types.h"
#include "deps/03801cd4_FUN_03801cd4.h"

void FUN_03801cd4(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = DAT_03801dc8;
  iVar3 = 0;
  *(undefined4 *)(DAT_03801dc8 + 0x20) = 0;
  *(undefined4 *)(iVar2 + 0x24) = 0x14;
  *(undefined4 *)(iVar2 + 0x28) = 0x14;
  do {
    *(undefined2 *)(iVar2 + iVar3 * 2) = 0;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x10);
  iVar2 = FUN_037faee4();
  if (iVar2 == 0) {
    FUN_037faef4();
  }
  uVar1 = DAT_03801dd0;
  iVar2 = DAT_03801dcc;
  iVar3 = 0;
  do {
    iVar4 = iVar3 * 0x28 + iVar2;
    FUN_037fadcc(iVar4);
    FUN_037fac14(iVar4,uVar1);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  do {
  } while ((*DAT_03801dd4 & 0x80) != 0);
  *DAT_03801dd4 = (ushort)DAT_03801dd8;
  *DAT_03801ddc = 0x84;
  do {
  } while ((*DAT_03801dd4 & 0x80) != 0);
  *DAT_03801ddc = 0;
  do {
  } while ((*DAT_03801dd4 & 0x80) != 0);
  *DAT_03801dd4 = (ushort)DAT_03801de0;
  *DAT_03801ddc = 0;
  do {
  } while ((*DAT_03801dd4 & 0x80) != 0);
  return;
}

