/* Decompiled C draft; module arm9_ov003; ROM address 021b7df4. No matching claim. */
#include "types.h"
#include "deps/021b7df4_func_ov003_021b7df4.h"

undefined4 func_ov003_021b7df4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = func_ov003_021b7cac();
  *(undefined4 *)(iRam021b7e50 + 0x10) = uVar2;
  uVar2 = func_ov003_021b7cac(param_2);
  *(undefined4 *)(iRam021b7e50 + 0x14) = uVar2;
  uVar2 = func_ov003_021b7cac(param_3);
  iVar3 = iRam021b7e50;
  *(undefined4 *)(iRam021b7e50 + 0x18) = uVar2;
  iVar3 = func_0x021a8c94(iVar3);
  piVar1 = piRam021b7e54;
  if (iVar3 < 0) {
    return 0xffffffff;
  }
  iVar3 = *piRam021b7e54;
  while (iVar3 == 0) {
    func_0x0200dc3c(100);
    iVar3 = *piVar1;
  }
  return 0;
}

