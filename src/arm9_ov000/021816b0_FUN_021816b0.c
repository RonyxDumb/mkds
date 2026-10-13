/* Decompiled C draft; module arm9_ov000; ROM address 021816b0. No matching claim. */
#include "types.h"
#include "deps/021816b0_FUN_021816b0.h"

void FUN_021816b0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = func_0x02036bec(param_1,0x40);
  piVar1 = DAT_02181708;
  *DAT_02181708 = iVar2;
  *(undefined4 *)(iVar2 + 0x1c) = param_1;
  *(undefined4 *)*piVar1 = 0;
  *(undefined4 *)(*piVar1 + 4) = 0;
  *(undefined4 *)(*piVar1 + 0xc) = 0xffffffff;
  *(undefined4 *)(*piVar1 + 8) = 0;
  uVar3 = func_0x0204799c(DAT_0218170c);
  *(undefined4 *)(*DAT_02181708 + 0x38) = uVar3;
  uVar3 = func_0x02047a28(DAT_02181710);
  *(undefined4 *)(*DAT_02181708 + 0x3c) = uVar3;
  FUN_021816a0();
  func_0x0212a910(1,1);
  func_0x021281c8(0xe);
  func_0x0204f804();
  return;
}

