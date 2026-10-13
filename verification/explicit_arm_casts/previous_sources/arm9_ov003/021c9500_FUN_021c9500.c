/* Decompiled C draft; module arm9_ov003; ROM address 021c9500. No matching claim. */
#include "types.h"
#include "deps/021c9500_FUN_021c9500.h"

void FUN_021c9500(void)

{
  undefined1 uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 local_48 [23];
  undefined1 local_31 [21];
  undefined1 local_1c [28];
  
  puVar5 = local_48;
  iVar4 = 0x17;
  puVar6 = DAT_021c960c;
  do {
    uVar1 = *puVar6;
    puVar6 = puVar6 + 1;
    *puVar5 = uVar1;
    puVar5 = puVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  puVar5 = local_31;
  iVar4 = 0x15;
  puVar6 = DAT_021c9610;
  do {
    uVar1 = *puVar6;
    puVar6 = puVar6 + 1;
    *puVar5 = uVar1;
    puVar5 = puVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  puVar6 = local_1c;
  iVar4 = 0x16;
  puVar5 = DAT_021c9614;
  do {
    uVar1 = *puVar5;
    puVar5 = puVar5 + 1;
    *puVar6 = uVar1;
    puVar6 = puVar6 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *DAT_021c9618 = *DAT_021c9618 & 0x43 | (ushort)DAT_021c961c;
  FUN_021bf620(DAT_021c9620,DAT_021c9624);
  FUN_021bf620(DAT_021c9628,DAT_021c962c);
  FUN_021bf620(DAT_021c9630,DAT_021c9634);
  FUN_021bf620(local_31,DAT_021c9638);
  FUN_021bf620(DAT_021c963c,DAT_021c9640);
  uVar3 = FUN_021bf650(local_48);
  uVar3 = FUN_021d14b8(uVar3,0,4);
  piVar2 = DAT_021c9644;
  *(undefined4 *)(*DAT_021c9644 + 8) = uVar3;
  FUN_021cca30(*(undefined4 *)(*piVar2 + 8));
  FUN_021cc9fc();
  uVar3 = FUN_021bf650(local_31);
  uVar3 = FUN_021d14b8(uVar3,0,4);
  *(undefined4 *)(*DAT_021c9644 + 0xc) = uVar3;
  uVar3 = FUN_021bf650(local_1c);
  uVar3 = FUN_021d14b8(uVar3,0,4);
  *(undefined4 *)(*DAT_021c9644 + 0x10) = uVar3;
  *DAT_021c9648 = *DAT_021c9648 & 0xfffc | 3;
  *DAT_021c964c = *DAT_021c964c & 0xfffc | 3;
  *DAT_021c9650 = *DAT_021c9650 & 0xfffc | 3;
  *DAT_021c9654 = *DAT_021c9654 & 0xfffc | 2;
  *DAT_021c9618 = *DAT_021c9618 & 0xfffc | 3;
  *DAT_021c9658 = *DAT_021c9658 & 0xfffc | 2;
  return;
}

