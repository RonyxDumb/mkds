/* Decompiled C draft; module arm9_ov003; ROM address 021d1654. No matching claim. */
#include "types.h"
#include "deps/021d1654_FUN_021d1654.h"

void FUN_021d1654(void)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined1 auStack_d0 [36];
  undefined4 local_ac;
  undefined1 auStack_88 [128];
  
  iVar3 = FUN_021d283c(0xe8,4);
  *DAT_021d1750 = iVar3;
  func_0x02004d80(auStack_d0);
  iVar3 = func_0x02004a30(auStack_d0,DAT_021d1754);
  if (iVar3 == 0) {
    func_0x0200fd1c();
  }
  uVar2 = func_0x0200cd28();
  *(undefined2 *)(*DAT_021d1750 + 0xe4) = uVar2;
  func_0x020048ac(auStack_d0,&local_e0,8);
  func_0x020048ac(auStack_d0,&local_d8,8);
  func_0x020049e8(auStack_d0);
  func_0x02004238(*DAT_021d1750 + 0x88);
  iVar3 = func_0x02004128(*DAT_021d1750 + 0x88,DAT_021d1758,3);
  if (iVar3 == 0) {
    func_0x0200fd1c();
  }
  func_0x02003c60(*DAT_021d1750 + 0x88,DAT_021d175c,DAT_021d1760);
  iVar3 = func_0x02004018(*DAT_021d1750 + 0x88,local_ac,local_d8,local_d4,local_e0,local_dc,
                          DAT_021d1764,DAT_021d1768);
  if (iVar3 == 0) {
    func_0x0200fd1c();
  }
  uVar4 = func_0x02003e24(*DAT_021d1750 + 0x88,0,0);
  uVar5 = FUN_021d285c(uVar4,4);
  piVar1 = DAT_021d1750;
  *(undefined4 *)*DAT_021d1750 = uVar5;
  func_0x02003e24((undefined4 *)*piVar1 + 0x22,*(undefined4 *)*piVar1,uVar4);
  uVar4 = FUN_021d1d60(0x20,*DAT_021d1750 + 4,4);
  *(undefined4 *)(*DAT_021d1750 + 0x84) = uVar4;
  func_0x0200da28(auStack_88,DAT_021d176c,DAT_021d1758);
  func_0x020047ec(auStack_88);
  return;
}

