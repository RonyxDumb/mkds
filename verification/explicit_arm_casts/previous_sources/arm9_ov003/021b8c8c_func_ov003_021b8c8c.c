/* Decompiled C draft; module arm9_ov003; ROM address 021b8c8c. No matching claim. */
#include "types.h"
#include "deps/021b8c8c_func_ov003_021b8c8c.h"

int func_ov003_021b8c8c(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined1 auStack_1c [8];
  
  func_ov003_021b7d90(auStack_1c,param_1 + 0x10,8);
  uVar2 = func_ov003_021b7c30(uRam021b8d90);
  iVar3 = func_ov003_021b7f48(auStack_1c,8,uRam021b8d90,uVar2);
  if (iVar3 == -1) {
    func_ov003_021b94b8(2);
    return -100;
  }
  uVar2 = func_ov003_021b7c44(*(undefined2 *)(param_1 + 6));
  iVar3 = func_ov003_021b8c44(uVar2,auStack_1c);
  if (iVar3 == 0) {
    iVar3 = func_ov003_021b7c44(*(undefined2 *)(param_1 + 6));
    if (iVar3 == iRam021b8d94) {
      func_ov003_021b7d90(uRam021b8d98,auStack_1c,8);
    }
    uVar4 = func_ov003_021b7c44(*(undefined2 *)(param_1 + 0xc));
    if ((uVar4 & 0xf) == 0) {
      return 0;
    }
    uVar4 = func_ov003_021b7c44(*(undefined2 *)(param_1 + 0x18));
    iVar3 = func_ov003_021ba178();
    if (iVar3 == 0) {
      func_ov003_021b94b8(2);
      return 100;
    }
    iVar5 = func_ov003_021b8160(param_1 + 0x1c,iVar3,uVar4,*(undefined1 *)(param_1 + 0xe),
                                param_1 + 0x1a,uRam021b8d98,8);
    if (iVar5 < 0) {
      func_ov003_021ba164(iVar3);
      iVar3 = func_ov003_021b94ac();
      if (iVar3 == 2) {
        return 100;
      }
      return 200;
    }
    func_ov003_021b7d90((undefined2 *)(param_1 + 0x18),iVar3,uVar4);
    uVar1 = func_ov003_021b7c94(uVar4 & 0xffff);
    *(undefined2 *)(param_1 + 10) = uVar1;
    func_ov003_021ba164(iVar3);
    iVar3 = 0;
  }
  return iVar3;
}

