/* Decompiled C draft; module arm9; ROM address 0202e530. No matching claim. */
#include "types.h"
#include "deps/0202e530_func_0202e530.h"

void func_0202e530(undefined4 param_1,int param_2,undefined4 param_3,undefined2 param_4,
                  undefined2 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                  undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
                  undefined4 param_13,undefined4 param_14)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = Mem_AllocateHeap(param_1,uRam0202e670);
  *piRam0202e674 = iVar2;
  CARD_func_0054__mkds_2e68c(iVar2,uRam0202e670);
  *(int *)*piRam0202e674 = param_2;
  uVar3 = Mem_AllocateHeapAligned(param_1,param_2 * 2,0x20);
  piVar1 = piRam0202e674;
  *(undefined4 *)(*piRam0202e674 + 4) = uVar3;
  func_0202e680(param_3,*(undefined4 *)(*piVar1 + 4),param_2 * 2);
  func_0202e680(param_9,*piRam0202e674 + 0x58,uRam0202e678);
  piVar1 = piRam0202e674;
  *(undefined2 *)(*piRam0202e674 + 0x2c) = param_4;
  *(undefined2 *)(*piVar1 + 0x2e) = param_5;
  *(undefined4 *)(*piVar1 + 0x30) = param_6;
  *(undefined4 *)(*piVar1 + 8) = param_7;
  *(undefined4 *)(*piVar1 + 0x34) = param_13;
  *(undefined4 *)(*piVar1 + 0x28) = param_14;
  *(undefined4 *)(*piVar1 + 0xc) = param_8;
  *(undefined4 *)(*piVar1 + 0x10) = param_10;
  *(undefined4 *)(*piVar1 + 0x14) = param_11;
  *(undefined4 *)(*piVar1 + 0x18) = param_12;
  *(undefined4 *)(*piVar1 + iRam0202e67c) = 1;
  *(undefined4 *)(*piVar1 + 0x1c) = 0xffffffff;
  *(undefined4 *)(*piVar1 + 0x20) = *(undefined4 *)(*piVar1 + 0x1c);
  func_0202edd0();
  uVar3 = func_0202edfc();
  func_0202f120(0,0xffffffff,0xffffffff,uVar3);
  piVar1 = piRam0202e674;
  for (iVar2 = 0; (iVar2 < 6 && (iVar2 < *(int *)(*piVar1 + 0x34))); iVar2 = iVar2 + 1) {
    func_0202f120(1,iVar2 + 1,iVar2,0xffffffff);
  }
  func_0202ee3c(0,0);
  func_0202ee3c(6,0);
  for (iVar2 = *(int *)(*piRam0202e674 + 0x34); iVar2 < 5; iVar2 = iVar2 + 1) {
    func_0202ee3c(iVar2 + 1,0);
  }
  iVar2 = *piRam0202e674;
  *(uint *)(*(int *)(iVar2 + 8) + (uint)*(ushort *)(iVar2 + 0x2e) * 0x40) =
       (uint)(5 < *(int *)(iVar2 + 0x34));
  iVar2 = *piRam0202e674;
  if (*(int *)(iVar2 + 0x34) == 0) {
    *(undefined4 *)(*(int *)(iVar2 + 8) + (uint)*(ushort *)(iVar2 + 0x2c) * 0x40) = 0;
  }
  *(undefined4 *)(*piRam0202e674 + 0x48) = 0xf;
  return;
}

