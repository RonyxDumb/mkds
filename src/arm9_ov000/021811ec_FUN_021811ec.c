/* Decompiled C draft; module arm9_ov000; ROM address 021811ec. No matching claim. */
#include "types.h"
#include "deps/021811ec_FUN_021811ec.h"

void FUN_021811ec(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined2 local_18 [4];
  
  iVar2 = func_0x02125f54();
  if (iVar2 != 0) {
    func_0x02125fc0();
    return;
  }
  iVar2 = func_0x02125f88();
  piVar1 = DAT_021812f0;
  if (iVar2 != 0) {
    local_18[0] = *DAT_021812ec;
    local_18[1] = DAT_021812ec[1];
    iVar6 = *DAT_021812f0;
    iVar2 = *(int *)(iVar6 + 0x10);
    if (iVar2 < 0) {
      *(int *)(iVar6 + 0x10) = iVar2 + 1;
      iVar2 = *piVar1;
      uVar3 = func_0x020b3f7c(*(undefined4 *)(iVar2 + 0x38),local_18[*(int *)(iVar2 + 0x10)]);
      uVar4 = func_0x020b3f7c(*(undefined4 *)(iVar2 + 0x3c),6);
      func_0x02126570(uVar3,uVar4);
      return;
    }
    if (iVar2 == 0) {
      *(undefined4 *)(iVar6 + 0x10) = 1;
      iVar2 = *piVar1;
      uVar3 = func_0x020b3f7c(*(undefined4 *)(iVar2 + 0x38),local_18[*(int *)(iVar2 + 0x10)]);
      uVar4 = func_0x020b3f7c(*(undefined4 *)(*DAT_021812f0 + 0x3c),0);
      uVar5 = func_0x020b3f7c(*(undefined4 *)(iVar2 + 0x3c),1);
      func_0x02126454(uVar3,uVar4,uVar5,1);
      return;
    }
    iVar2 = func_0x02125f60();
    piVar1 = DAT_021812f0;
    if (iVar2 == 0) {
      *(undefined4 *)(*DAT_021812f0 + 4) = 4;
      uVar3 = func_0x020b3f7c(*(undefined4 *)(*piVar1 + 0x38),0x23);
      uVar4 = func_0x020b3f7c(*(undefined4 *)(*DAT_021812f0 + 0x3c),6);
      func_0x02126570(uVar3,uVar4);
      *(undefined4 *)(*DAT_021812f0 + 0x10) = 0;
      return;
    }
    *(undefined4 *)(*DAT_021812f0 + 0xc) = 1;
    func_ov000_021806e0(*(undefined4 *)(*piVar1 + 0xc));
  }
  return;
}

