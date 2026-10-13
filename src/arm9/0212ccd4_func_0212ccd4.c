/* Decompiled C draft; module arm9; ROM address 0212ccd4. No matching claim. */
#include "types.h"
#include "deps/0212ccd4_func_0212ccd4.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 func_0212ccd4(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int unaff_r5;
  int iVar6;
  int iVar7;
  bool bVar8;
  undefined4 in_stack_00000010;
  int in_stack_00000014;
  undefined4 in_stack_00000020;
  int in_stack_00000024;
  undefined4 in_stack_00000028;
  undefined4 local_34;
  int local_30;
  
  puVar1 = puRam0212d030;
  local_34 = 0;
  iVar7 = -1;
  Arm_FlushRange(param_2,param_4);
  Arm_FlushRange(param_3,param_4);
  bVar8 = param_5 == 1;
  iVar2 = _s32_div_f(uRam0212d034,in_stack_00000010);
  if (in_stack_00000024 != 0) {
    iVar2 = iVar2 + 0x10 >> 5;
    uVar3 = param_4;
    if (!bVar8) {
      uVar3 = param_4 >> 1;
    }
    iVar4 = MaybeBoundsCheck(uVar3,in_stack_00000020);
    iVar6 = 0x20;
    local_30 = iVar2 * iVar4;
    if (!bVar8) {
      iVar6 = 0x10;
    }
    unaff_r5 = iVar6 * iVar2;
  }
  if (param_1 != 2) {
    local_34 = 10;
  }
  if ((in_stack_00000024 != 0) && (iVar7 = func_0212bb9c(), iVar7 < 0)) {
    return 0;
  }
  iVar2 = func_0212bbfc(3);
  if (iVar2 == 0) {
    if (-1 < iVar7) {
      func_0212bb7c(iVar7);
    }
    return 0;
  }
  iVar2 = func_0212bc58(10);
  if (iVar2 != 0) {
    func_02020a14(1,!bVar8,param_2);
    func_02020b70(0,bVar8,param_2,param_4 >> 2);
    func_02020a14(3,!bVar8,param_3);
    func_02020b70(1,bVar8,param_3,param_4 >> 2);
    if (-1 < iVar7) {
      func_02020b2c(iVar7,local_30 + unaff_r5,local_30,uRam0212d038);
    }
    if (param_1 == 1) {
      func_02020930(1,2,1,1);
    }
    SND_StartTimer(local_34,3);
    *puVar1 = 1;
    puVar1[1] = param_1;
    puVar1[8] = 10;
    puVar1[9] = local_34;
    puVar1[10] = 3;
    puVar1[0xb] = iVar7;
    puVar1[2] = param_5;
    puVar1[3] = param_2;
    puVar1[4] = param_3;
    puVar1[5] = param_4;
    uVar5 = MaybeBoundsCheck(param_4,in_stack_00000020);
    puVar1[6] = uVar5;
    puVar1[7] = 0;
    puVar1[0xc] = in_stack_00000020;
    puVar1[0xd] = in_stack_00000024;
    puVar1[0xe] = in_stack_00000028;
    puVar1[0x14] = in_stack_00000014;
    func_0212f864(puVar1 + 0xf);
    func_0212f834(puVar1 + 0xf,in_stack_00000014 << 8,1);
    puVar1[0x13] = 0;
    return 1;
  }
  if (-1 < iVar7) {
    func_0212bb7c(iVar7);
  }
  func_0212bbe0(3);
  return 0;
}

