/* Decompiled C draft; module arm9_ov000; ROM address 0218134c. No matching claim. */
#include "types.h"
#include "deps/0218134c_FUN_0218134c.h"

void FUN_0218134c(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined2 local_14 [2];
  
  iVar2 = func_0x02125f54();
  if (iVar2 != 0) {
    func_0x02125fc0();
    return;
  }
  iVar2 = func_0x02125f88();
  piVar1 = DAT_02181454;
  if (iVar2 != 0) {
    local_14[0] = *DAT_02181450;
    local_14[1] = DAT_02181450[1];
    iVar6 = *DAT_02181454;
    iVar2 = *(int *)(iVar6 + 0x10);
    if (iVar2 < 0) {
      *(int *)(iVar6 + 0x10) = iVar2 + 1;
      iVar2 = *piVar1;
      uVar3 = func_0x020b3f7c(*(undefined4 *)(iVar2 + 0x38),local_14[*(int *)(iVar2 + 0x10)]);
      uVar4 = func_0x020b3f7c(*(undefined4 *)(iVar2 + 0x3c),6);
      func_0x02126570(uVar3,uVar4);
      return;
    }
    if (iVar2 == 0) {
      *(undefined4 *)(iVar6 + 0x10) = 1;
      iVar2 = *piVar1;
      uVar3 = func_0x020b3f7c(*(undefined4 *)(iVar2 + 0x38),local_14[*(int *)(iVar2 + 0x10)]);
      uVar4 = func_0x020b3f7c(*(undefined4 *)(*DAT_02181454 + 0x3c),0);
      uVar5 = func_0x020b3f7c(*(undefined4 *)(iVar2 + 0x3c),1);
      func_0x02126454(uVar3,uVar4,uVar5,0);
      return;
    }
    iVar2 = func_0x02125f60();
    piVar1 = DAT_02181454;
    if (iVar2 == 0) {
      *(undefined4 *)(*DAT_02181454 + 4) = 7;
      uVar3 = func_0x020b3f7c(*(undefined4 *)(*piVar1 + 0x38),0x14);
      func_0x02126638(uVar3,1,1,1,0,1,0);
      func_0x0211fe24();
      *(undefined4 *)(*DAT_02181454 + 0x14) = 1;
      func_0x02108bb4();
      return;
    }
    *(undefined4 *)(*DAT_02181454 + 0xc) = 1;
    func_ov000_021806e0(*(undefined4 *)(*piVar1 + 0xc));
  }
  return;
}

