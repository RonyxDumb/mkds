/* Decompiled C draft; module arm9_ov003; ROM address 021c3cc4. No matching claim. */
#include "types.h"
#include "deps/021c3cc4_FUN_021c3cc4.h"

void FUN_021c3cc4(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 local_5c [22];
  undefined1 local_46 [26];
  int local_2c;
  int local_28;
  
  puVar4 = local_5c;
  iVar3 = 0x16;
  puVar5 = DAT_021c3da4;
  do {
    uVar1 = *puVar5;
    puVar5 = puVar5 + 1;
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puVar5 = local_46;
  iVar3 = 0x17;
  puVar4 = DAT_021c3da8;
  do {
    uVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    *puVar5 = uVar1;
    puVar5 = puVar5 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  FUN_021bf620(DAT_021c3dac,DAT_021c3db0);
  FUN_021bf620(DAT_021c3db4,DAT_021c3db8);
  uVar2 = FUN_021bf650((int)(uintptr_t)(local_46));
  uVar2 = FUN_021d14b8(uVar2,0,4);
  *DAT_021c3dbc = uVar2;
  uVar2 = FUN_021bf650((int)(uintptr_t)(local_5c));
  iVar3 = FUN_021d14b8(uVar2,0,4);
  func_0x02151910(&local_2c);
  if (local_28 == 0 && local_2c == 0) {
    iVar7 = iVar3 + 0xc0;
    iVar6 = iVar3 + 0x40;
    iVar8 = 0;
    do {
      func_0x0214d1fc((ushort *)(uintptr_t)(iVar7),(uint *)(uintptr_t)(iVar6),0x20);
      iVar8 = iVar8 + 1;
      iVar7 = iVar7 + 0x20;
      iVar6 = iVar6 + 0x20;
    } while (iVar8 < 2);
  }
  func_0x0200ee74(iVar3,DAT_021c3dc0);
  func_0x0214c160(iVar3,0,DAT_021c3dc0);
  FUN_021d1490(iVar3);
  *DAT_021c3dc4 = *DAT_021c3dc4 & 0xfffc | 3;
  *DAT_021c3dc8 = *DAT_021c3dc8 & 0xfffc | 3;
  *DAT_021c3dcc = *DAT_021c3dcc & 0xfffc | 3;
  *DAT_021c3dd0 = *DAT_021c3dd0 & 0xfffc | 3;
  return;
}

