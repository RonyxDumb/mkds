/* Decompiled C draft; module arm9_ov001; ROM address 0218052c. No matching claim. */
#include "types.h"
#include "deps/0218052c_func_ov001_0218052c.h"

void func_ov001_0218052c(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 extraout_r1;
  
  func_ov001_021805ec();
  func_0x020ae718();
  if (param_1 != 0) {
    uVar2 = func_ov001_021805ec();
    iVar3 = func_ov001_021805bc(uVar2,1);
    if (iVar3 != 0) {
      *(undefined2 *)(param_1 + 4) = 0;
    }
    iVar3 = func_ov001_021805bc(uVar2,uRam021805b4);
    if (iVar3 != 0) {
      iVar3 = *piRam021805b8;
      func_0x02133068(*(int *)(iVar3 + 4) + 1,4);
      *(undefined4 *)(iVar3 + 4) = extraout_r1;
      piVar1 = piRam021805b8;
      *(undefined4 *)(*piRam021805b8 + 8) = 1;
      if (*(int *)(*piVar1 + 4) == 1) {
        func_0x020ca688(0);
      }
    }
  }
  if (*(uint *)(*piRam021805b8 + 4) < 4) {
                    /* WARNING: Could not recover jumptable at 0x0218059a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(*(short *)(*(uint *)(*piRam021805b8 + 4) * 2 + 0x218059c) + 0x218059c))();
    return;
  }
  return;
}

