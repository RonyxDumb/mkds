/* Decompiled C draft; module arm9_ov000; ROM address 0219c524. No matching claim. */
#include "types.h"
#include "deps/0219c524_FUN_0219c524.h"

void FUN_0219c524(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined1 auStack_3b8 [21];
  undefined1 auStack_3a3 [15];
  undefined4 local_394;
  undefined4 local_390;
  undefined1 auStack_38c [74];
  undefined1 auStack_342 [301];
  undefined1 auStack_215 [77];
  undefined4 local_1c8 [114];
  
  iVar2 = FUN_021863cc();
  if (iVar2 != 0x14) {
    iVar2 = FUN_021863cc();
    if (iVar2 != 0) {
      lVar4 = func_0x0200f5ac();
      lVar4 = lVar4 - *(longlong *)(*DAT_0219c654 + 0x2c);
      uVar3 = (uint)lVar4;
      uVar5 = func_0x02132e40(uVar3 * 0x40,(int)((ulonglong)lVar4 >> 0x20) * 0x40 | uVar3 >> 0x1a,
                              DAT_0219c668,0);
      iVar2 = (int)((ulonglong)uVar5 >> 0x20);
      uVar3 = (uint)uVar5;
      if ((uint)(uVar3 <= DAT_0219c66c) <= (uint)-iVar2) {
        FUN_0218635c(local_1c8);
        FUN_02186430();
        FUN_021a3704(0,*(undefined4 *)(*DAT_0219c654 + 0x28),0);
        *(undefined4 *)(*DAT_0219c654 + 0x28) = 0;
        FUN_0219c990(2,local_1c8[0]);
        return;
      }
      FUN_02186430(DAT_0219c66c - uVar3,iVar2,DAT_0219c66c,-(uint)(uVar3 > DAT_0219c66c) - iVar2);
      func_0x0214d168(auStack_3b8,0,0x2c);
      func_0x0213a2d0(auStack_3a3,*DAT_0219c654 + DAT_0219c670);
      local_394 = DAT_0219c674;
      local_390 = DAT_0219c678;
      FUN_02186560(auStack_3b8,*(undefined4 *)(*DAT_0219c654 + 0x28));
    }
    return;
  }
  FUN_0218635c(auStack_38c);
  func_0x0213a2d0(*DAT_0219c654 + 0x4c,auStack_342);
  func_0x0213a2d0(*DAT_0219c654 + DAT_0219c658,auStack_215);
  FUN_02186430();
  FUN_021a3704(0,*(undefined4 *)(*DAT_0219c654 + 0x28),0);
  piVar1 = DAT_0219c654;
  *(undefined4 *)(*DAT_0219c654 + 0x28) = 0;
  iVar2 = func_0x021526bc(*(undefined4 *)(*piVar1 + 0x20));
  if (iVar2 != 0) {
    (*(code *)*DAT_0219c660)(*DAT_0219c654 + 0x4c,*DAT_0219c654 + DAT_0219c658,*DAT_0219c65c);
    return;
  }
  FUN_0219c79c(*DAT_0219c654 + 0x4c,*DAT_0219c654 + DAT_0219c658,DAT_0219c664,3);
  return;
}

