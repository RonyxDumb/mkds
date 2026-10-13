/* Decompiled C draft; module arm9; ROM address 0214f1f4. No matching claim. */
#include "types.h"
#include "deps/0214f1f4_func_0214f1f4.h"

undefined4 func_0214f1f4(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  Os_DisableIrq();
  if (*(uint *)((uint)puRam0214f260 & 0xfffffffc) >> ((uint)puRam0214f260 & 3) * 8 == 0 &&
      *(uint *)((uint)puRam0214f260 & 0xfffffffc) << ((uint)puRam0214f260 & 3) * -8 + 0x20 == 0) {
    *puRam0214f260 = 1;
    Os_RestoreIrq();
    puVar1 = puRam0214f260;
    puRam0214f260[1] = param_1;
    puVar1[2] = param_2;
    iVar2 = func_0214ef00();
    if (iVar2 == 0) {
      uVar3 = 3;
    }
    else {
      uVar3 = 0;
    }
    return uVar3;
  }
  Os_RestoreIrq();
  return 1;
}

