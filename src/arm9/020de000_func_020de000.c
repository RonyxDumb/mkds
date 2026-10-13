/* Decompiled C draft; module arm9; ROM address 020de000. No matching claim. */
#include "types.h"
#include "deps/020de000_func_020de000.h"

void func_020de000(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = *(undefined4 *)(param_3 + 0xa4);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_3 + 0xa0);
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_3 + 0xa8);
  *(uint *)(param_1 + 0xf4) = (uint)(*(int *)(param_3 + 0xfc) == 0);
  iVar2 = iRam020de118;
  if (*(int *)(param_1 + 0xf4) != 0) {
    iVar2 = *(int *)(param_3 + iRam020de114);
  }
  if (*(int *)(param_3 + 0xfc) == 0) {
    uVar1 = 7;
  }
  else {
    uVar1 = 4;
  }
  func_020dd950((int *)(uintptr_t)(param_1 + 0xa4),param_1 + 4,param_1 + 4,iVar2 - *(int *)(param_3 + 0xf0),uVar1,
                uRam020de11c,(int *)(uintptr_t)(param_1 + 0x1c));
  if (*(int *)(param_1 + 0xf4) == 0) {
    func_020dda2c(param_1 + 0xa4);
    *(int *)(param_1 + 0xa8) = *(int *)(param_1 + 0xa8) + -0xcd;
    *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + -0x3d;
    *(int *)(param_1 + 0xb8) = *(int *)(param_1 + 0xb8) + 0x52;
    *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) + iRam020de120;
    *(int *)(param_1 + 0xc0) = *(int *)(param_1 + 0xc0) + 0x52;
    *(undefined4 *)(param_1 + 0xb0) = 0;
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020de124;
  }
  *(int *)(param_1 + 0xa0) = param_3;
  iVar2 = iRam020de128;
  if (*(int *)(param_1 + 0xf4) != 0) {
    iVar2 = *(int *)(param_3 + 0xf8);
  }
  uVar1 = FUN_02132440(iVar2 + *(int *)(param_3 + 0xf0));
  func_0213250c(uRam020de12c,uVar1);
  uVar1 = func_021322c8();
  *(undefined4 *)(param_1 + 0x68) = uVar1;
  return;
}

