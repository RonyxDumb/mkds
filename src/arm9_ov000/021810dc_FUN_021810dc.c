/* Decompiled C draft; module arm9_ov000; ROM address 021810dc. No matching claim. */
#include "types.h"
#include "deps/021810dc_FUN_021810dc.h"

void FUN_021810dc(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined2 local_1c [6];
  
  iVar2 = func_0x02125f54();
  if (iVar2 != 0) {
    func_0x02125fc0();
    return;
  }
  iVar2 = func_0x02125f88();
  piVar1 = DAT_021811e8;
  if (iVar2 != 0) {
    local_1c[0] = *DAT_021811e4;
    local_1c[1] = DAT_021811e4[1];
    local_1c[2] = DAT_021811e4[2];
    iVar6 = *DAT_021811e8;
    iVar2 = *(int *)(iVar6 + 0x10);
    if (iVar2 < 1) {
      *(int *)(iVar6 + 0x10) = iVar2 + 1;
      iVar2 = *piVar1;
      uVar3 = func_0x020b3f7c(*(undefined4 *)(iVar2 + 0x38),local_1c[*(int *)(iVar2 + 0x10)]);
      uVar4 = func_0x020b3f7c(*(undefined4 *)(iVar2 + 0x3c),6);
      func_0x02126570(uVar3,uVar4);
      return;
    }
    if (iVar2 == 1) {
      *(undefined4 *)(iVar6 + 0x10) = 2;
      iVar2 = *piVar1;
      uVar3 = func_0x020b3f7c(*(undefined4 *)(iVar2 + 0x38),local_1c[*(int *)(iVar2 + 0x10)]);
      uVar4 = func_0x020b3f7c(*(undefined4 *)(*DAT_021811e8 + 0x3c),0);
      uVar5 = func_0x020b3f7c(*(undefined4 *)(iVar2 + 0x3c),1);
      func_0x02126454(uVar3,uVar4,uVar5,1);
      return;
    }
    iVar2 = func_0x02125f60();
    piVar1 = DAT_021811e8;
    if (iVar2 == 0) {
      *(undefined4 *)(*DAT_021811e8 + 4) = 7;
      uVar3 = func_0x020b3f7c(*(undefined4 *)(*piVar1 + 0x38),0x14);
      func_0x02126638(uVar3,1,1,1,0,1,0);
      func_0x0211fe24();
      *(undefined4 *)(*DAT_021811e8 + 0x14) = 1;
      func_0x02108bb4();
      return;
    }
    *(undefined4 *)(*DAT_021811e8 + 0xc) = 1;
    func_ov000_021806e0(*(undefined4 *)(*piVar1 + 0xc));
  }
  return;
}

