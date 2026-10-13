/* Decompiled C draft; module arm9_ov003; ROM address 021b8bf0. No matching claim. */
#include "types.h"
#include "deps/021b8bf0_func_ov003_021b8bf0.h"

undefined4 func_ov003_021b8bf0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  uVar1 = func_ov003_021b7c30((char *)(uintptr_t)(uRam021b8c40));
  func_ov003_021b7f48(param_2,8,uRam021b8c40,uVar1);
  iVar2 = func_ov003_021b7da0((byte *)(uintptr_t)(param_1),(byte *)(uintptr_t)(param_2),6);
  if (iVar2 == 0) {
    iVar2 = func_ov003_021b7c44(*(undefined2 *)(param_1 + 6));
    iVar3 = func_ov003_021b7c44(*(undefined2 *)(param_2 + 6));
    if (iVar2 + 1 != iVar3) {
      uVar4 = 0xfffffffe;
    }
  }
  else {
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

