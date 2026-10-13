/* Decompiled C draft; module arm9; ROM address 020050c0. No matching claim. */
#include "types.h"
#include "deps/020050c0_func_020050c0.h"

void func_020050c0(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  if ((param_2 != 0) && (param_1 == 0)) {
    uVar1 = func_02150dc8(1);
    iVar2 = Fs_ComputeCompareDigest(uRam02005138,param_2,param_3);
    if (iVar2 == 0) {
      Os_Terminate();
    }
    func_02150dc8(uVar1);
  }
  piVar3 = piRam0200513c;
  if (param_1 != 0) {
    piVar3 = piRam02005140;
  }
  Os_DisableIrq();
  *piVar3 = param_2;
  piVar3[1] = param_3;
  Os_RestoreIrq();
  return;
}

