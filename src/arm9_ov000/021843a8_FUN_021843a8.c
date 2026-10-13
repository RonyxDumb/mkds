/* Decompiled C draft; module arm9_ov000; ROM address 021843a8. No matching claim. */
#include "types.h"
#include "deps/021843a8_FUN_021843a8.h"

void FUN_021843a8(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  byte *local_2c;
  byte *local_28;
  byte *local_24;
  int local_20;
  int local_18;
  
  func_0x02029930();
  iVar2 = func_0x02036bec(param_1,DAT_02184570);
  piVar1 = DAT_02184574;
  *DAT_02184574 = iVar2;
  *(undefined4 *)(iVar2 + 0xd0) = param_1;
  iVar2 = 0;
  *(undefined4 *)*piVar1 = 0;
  *(undefined4 *)(*piVar1 + 4) = 0;
  *(undefined4 *)(*piVar1 + 0x20) = 0xffffffff;
  *(undefined4 *)(*piVar1 + 8) = 0;
  *(undefined4 *)(*piVar1 + 0xc) = 0;
  *(undefined4 *)(*piVar1 + 0x38) = 0;
  iVar6 = 0;
  do {
    *(undefined4 *)(*piVar1 + iVar6 + 0x24) = 0;
    iVar6 = iVar6 + 4;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  *(undefined4 *)(*piVar1 + 0x40) = 0;
  FUN_02184130();
  uVar3 = func_ov000_021804f4();
  uVar4 = func_ov000_021804e0();
  func_0x020ae6d4(uVar3,uVar4);
  iVar2 = *DAT_02184574;
  func_0x02124ed0(param_1,*(undefined4 *)(iVar2 + DAT_02184578),
                  *(undefined4 *)(iVar2 + DAT_0218457c),(undefined4 *)(uintptr_t)(iVar2 + DAT_02184580));
  uVar3 = func_0x0204799c(DAT_02184584);
  *(undefined4 *)(*DAT_02184574 + DAT_02184588) = uVar3;
  uVar3 = func_0x02047a28(DAT_0218458c);
  *(undefined4 *)(*DAT_02184574 + DAT_02184590) = uVar3;
  FUN_02184670();
  local_20 = 0;
  local_2c = DAT_02184598;
  local_28 = DAT_0218459c;
  local_18 = DAT_021845a0;
  local_24 = DAT_021845a4;
  iVar6 = 0;
  iVar2 = DAT_02184594;
  do {
    iVar5 = 0;
    do {
      *(undefined4 *)
       (*(int *)(*DAT_02184574 + DAT_02184580) + (uint)*(byte *)(iVar2 + iVar5) * 0x40) = 0;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 5);
    *(undefined4 *)(*(int *)(*DAT_02184574 + DAT_02184580) + (uint)*local_2c * 0x40) = 1;
    *(undefined4 *)
     (*(int *)(*DAT_02184574 + DAT_02184580) +
     ((uint)*local_28 + (uint)*(ushort *)(*(int *)(*DAT_02184574 + DAT_02184578) + 6)) * 0x40) = 0;
    iVar5 = iVar6;
    do {
      *(undefined4 *)
       (*(int *)(*DAT_02184574 + DAT_02184580) +
       ((uint)*(byte *)(local_18 + iVar5) +
       (uint)*(ushort *)(*(int *)(*DAT_02184574 + DAT_02184578) + 6)) * 0x40) = 0;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 2);
    *(undefined4 *)(*(int *)(*DAT_02184574 + DAT_02184580) + (uint)*local_24 * 0x40) = 1;
    iVar2 = iVar2 + 5;
    local_2c = local_2c + 1;
    local_28 = local_28 + 1;
    local_18 = local_18 + 2;
    local_24 = local_24 + 1;
    local_20 = local_20 + 1;
  } while (local_20 < 3);
  *(short *)(*DAT_02184574 + 0x10) = (short)DAT_021845a8;
  piVar1 = DAT_02184574;
  iVar2 = iVar6;
  do {
    *(undefined2 *)(*piVar1 + iVar6 + 0x12) = 0;
    *(undefined2 *)(*piVar1 + iVar6 + 0x18) = 0;
    iVar6 = iVar6 + 2;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  FUN_021845ac();
  iVar2 = func_ov000_02180644();
  if (iVar2 == 0) {
    uVar3 = func_0x020b3f7c(*(undefined4 *)(*DAT_02184574 + DAT_02184588),8);
    func_0x02126638(uVar3,0,0,1,0,1,0);
  }
  else {
    uVar3 = func_0x020b3f7c(*(undefined4 *)(*DAT_02184574 + DAT_02184588),0xc);
    func_0x02126638(uVar3,0,0,1,0,1,0);
  }
  *(undefined4 *)(*DAT_02184574 + 0x48) = 0;
  return;
}

