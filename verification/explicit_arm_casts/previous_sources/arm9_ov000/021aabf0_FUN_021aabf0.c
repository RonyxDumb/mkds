/* Decompiled C draft; module arm9_ov000; ROM address 021aabf0. No matching claim. */
#include "types.h"
#include "deps/021aabf0_FUN_021aabf0.h"

void FUN_021aabf0(int param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  byte *local_3c;
  int local_38;
  int local_34;
  int local_30;
  byte *local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar7 = (uint)param_2[2] + ((uint)*param_2 * 0x100 + (uint)param_2[1]) * 0x100;
  local_c = param_2 + 3;
  *(undefined4 *)(param_1 + DAT_021aad80) = 0xffffffff;
  uStack_8 = param_3;
  uStack_4 = param_4;
  func_0x0214e038(&local_38);
  *(int *)(param_1 + DAT_021aad88) =
       local_30 + (local_38 + DAT_021aad84) * 0x10000 + local_34 * 0x100;
  uVar6 = 0;
  *(undefined1 *)(param_1 + DAT_021aad8c) = 0;
  puVar1 = (undefined4 *)(param_1 + DAT_021aad90);
  *puVar1 = 0;
  *(undefined4 *)(param_1 + DAT_021aad94) = *puVar1;
  iVar8 = 0;
  while( true ) {
    iVar2 = (uint)local_c[2] + ((uint)*local_c * 0x100 + (uint)local_c[1]) * 0x100;
    local_c = local_c + 3;
    iVar7 = iVar7 - (iVar2 + 3);
    *(undefined4 *)(param_1 + DAT_021aad98) = 0xffffffff;
    *(undefined1 *)(param_1 + DAT_021aad9c) = 0;
    *(undefined1 *)(param_1 + DAT_021aada0) = 0;
    *(undefined1 *)(param_1 + DAT_021aada4) = 0;
    *(undefined1 *)(param_1 + DAT_021aad8c) = 0;
    *(undefined1 *)(param_1 + DAT_021aada8) = 0;
    *(undefined1 *)(param_1 + DAT_021aadac) = 0;
    *(byte **)(param_1 + DAT_021aadb0) = local_c;
    *(int *)(param_1 + DAT_021aadb4) = iVar2;
    iVar2 = FUN_021ab09c(param_1,&local_c,0,0,uVar6);
    if (((iVar2 != 0) || (*(uint *)(param_1 + DAT_021aad94) < 0x33)) ||
       (*(int *)(param_1 + DAT_021aad90) == 0)) {
      *(undefined1 *)(param_1 + DAT_021aadb8) = 9;
      return;
    }
    uVar3 = FUN_021aae44(param_1);
    if (((iVar8 == 0) && (*(int *)(param_1 + DAT_021aadbc) != 0)) &&
       (iVar2 = FUN_021aadcc(*(int *)(param_1 + DAT_021aadbc),param_1 + DAT_021aadac), iVar2 != 0))
    {
      uVar3 = uVar3 | DAT_021aadc0;
    }
    uVar5 = uVar3 & 0xff;
    if ((uVar5 == 1) && (iVar7 != 0)) {
      local_3c = local_c + 3;
      *(undefined1 *)(param_1 + DAT_021aad9c) = 0;
      iVar2 = FUN_021ab09c(param_1,&local_3c,0,0,2);
      if (iVar2 != 0) {
        *(undefined1 *)(param_1 + DAT_021aadb8) = 9;
        return;
      }
      uVar4 = FUN_021aaf38(param_1,param_1 + DAT_021aadc4);
      uVar3 = uVar3 & 0xffffff00 | uVar4;
    }
    if (*(code **)(param_1 + DAT_021aadc8) != (code *)0x0) {
      uVar3 = (**(code **)(param_1 + DAT_021aadc8))(uVar3,param_1,iVar8);
    }
    iVar8 = iVar8 + 1;
    if (((uVar5 == 0) || (uVar3 != 0)) || (iVar7 == 0)) break;
    uVar6 = 1;
  }
  if (uVar3 == 0) {
    *(undefined1 *)(param_1 + DAT_021aadb8) = 3;
    return;
  }
  *(undefined1 *)(param_1 + DAT_021aadb8) = 9;
  return;
}

