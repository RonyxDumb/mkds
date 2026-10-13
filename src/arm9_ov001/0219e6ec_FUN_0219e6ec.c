/* Decompiled C draft; module arm9_ov001; ROM address 0219e6ec. No matching claim. */
#include "types.h"
#include "deps/0219e6ec_FUN_0219e6ec.h"

void FUN_0219e6ec(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 local_18 [6];
  
  iVar2 = func_0x02036bec(param_1,DAT_0219e808);
  *DAT_0219e80c = iVar2;
  *(undefined4 *)(iVar2 + 0x10) = param_1;
  uVar3 = func_0x021250b0(param_1);
  piVar1 = DAT_0219e80c;
  *(undefined4 *)(*DAT_0219e80c + 0x1c) = uVar3;
  *(undefined2 *)(*piVar1 + 0x14) = 0xffff;
  *(undefined4 *)*piVar1 = 0;
  ((undefined4 *)*piVar1)[1] = *(undefined4 *)*piVar1;
  *(undefined4 *)(*piVar1 + 8) = 0;
  if (*(int *)*DAT_0219e810 == 0x36) {
    *(undefined4 *)(*piVar1 + 0xc) = 1;
  }
  else {
    *(undefined4 *)(*piVar1 + 0xc) = 0;
  }
  *(undefined4 *)(*DAT_0219e80c + 0x18) = 0;
  uVar3 = func_0x02047a28(DAT_0219e814);
  *(undefined4 *)(*DAT_0219e80c + DAT_0219e818) = uVar3;
  FUN_0219e660();
  FUN_0219e38c();
  func_0x020ae6d4(*DAT_0219e80c + 0x68,0);
  iVar2 = *DAT_0219e80c;
  func_0x02124ed0(*(undefined4 *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 0x30),
                  *(undefined4 *)(iVar2 + 0x34),(undefined4 *)(uintptr_t)(iVar2 + 0x20));
  piVar1 = DAT_0219e80c;
  uVar3 = 0;
  **(undefined4 **)(*DAT_0219e80c + 0x20) = 0;
  local_18[0] = *DAT_0219e81c;
  local_18[1] = DAT_0219e81c[1];
  local_18[2] = DAT_0219e81c[2];
  local_18[3] = DAT_0219e81c[3];
  iVar2 = *piVar1;
  if (*(int *)(iVar2 + 0xc) == 0) {
    uVar3 = func_0x020b3f7c(*(undefined4 *)(iVar2 + DAT_0219e818),0x77);
  }
  else if (*(int *)(iVar2 + 0xc) == 1) {
    uVar3 = func_0x020b3f7c(*(undefined4 *)(iVar2 + DAT_0219e818),0x78);
  }
  iVar2 = *DAT_0219e80c;
  func_0x021243ac(*(undefined4 *)(iVar2 + 0x10),0,*(undefined4 *)(iVar2 + 0x34),
                  local_18[*(int *)(iVar2 + 0xc) * 2],local_18[*(int *)(iVar2 + 0xc) * 2 + 1],0,
                  *(undefined4 *)(iVar2 + 0x24),*(undefined4 *)(iVar2 + 0x30),
                  *(undefined4 *)(iVar2 + 0x20),DAT_0219e820);
  iVar2 = *DAT_0219e80c;
  func_0x0212426c(0,0,*(undefined4 *)(iVar2 + 0x34),uVar3,*(undefined4 *)(iVar2 + 0x30),
                  *(undefined4 *)(iVar2 + 0x20));
  return;
}

