/* Decompiled C draft; module arm9_ov000; ROM address 0219c67c. No matching claim. */
#include "types.h"
#include "deps/0219c67c_FUN_0219c67c.h"

void FUN_0219c67c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined1 auStack_38 [21];
  undefined1 auStack_23 [15];
  undefined4 local_14;
  undefined4 local_10;
  
  func_0x0214d168(auStack_38,0,0x2c);
  *DAT_0219c770 = param_1;
  *DAT_0219c774 = param_2;
  iVar1 = func_0x021526bc(*(undefined4 *)(*DAT_0219c778 + 0x20));
  if (iVar1 == 0) {
    iVar1 = func_0x021526c8(*DAT_0219c778 + 0x40);
    if (iVar1 == 0) {
      iVar1 = func_0x021526e4(*(int *)(*DAT_0219c778 + 0x20) + 4);
      if (iVar1 == 0) {
        func_0x02152744(*DAT_0219c778 + 0x40);
      }
      else {
        iVar3 = *DAT_0219c778;
        iVar1 = *(int *)(iVar3 + 0x20);
        uVar2 = *(undefined4 *)(iVar1 + 8);
        *(undefined4 *)(iVar3 + 0x40) = *(undefined4 *)(iVar1 + 4);
        *(undefined4 *)(iVar3 + 0x44) = uVar2;
        *(undefined4 *)(iVar3 + 0x48) = *(undefined4 *)(iVar1 + 0xc);
      }
    }
    else {
      uVar5 = func_0x0200f5ac();
      lVar4 = func_0x02133048((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),DAT_0219c780,DAT_0219c784);
      func_0x02152a88(*DAT_0219c778 + 0x40,(int)(lVar4 + (ulonglong)DAT_0219c788 >> 0x20),
                      (int)(lVar4 + (ulonglong)DAT_0219c788));
    }
    iVar1 = *DAT_0219c778;
    func_0x02152808(iVar1 + 0x40,*(undefined4 *)(iVar1 + 0xc),iVar1 + DAT_0219c77c);
  }
  else {
    iVar1 = *(int *)(*DAT_0219c778 + 0x20);
    func_0x02152808(iVar1 + 0x10,*(undefined4 *)(iVar1 + 0x24),*DAT_0219c778 + DAT_0219c77c);
  }
  func_0x0213a2d0(auStack_23,*DAT_0219c778 + DAT_0219c78c);
  local_14 = DAT_0219c790;
  local_10 = DAT_0219c794;
  uVar2 = FUN_021a3718(0,DAT_0219c798,4);
  *(undefined4 *)(*DAT_0219c778 + 0x28) = uVar2;
  uVar5 = func_0x0200f5ac();
  *(undefined8 *)(*DAT_0219c778 + 0x2c) = uVar5;
  FUN_02186560(auStack_38,uVar2);
  return;
}

