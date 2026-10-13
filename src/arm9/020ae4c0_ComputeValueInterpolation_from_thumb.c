/* Decompiled C draft; module arm9; ROM address 020ae4c0. No matching claim. */
#include "types.h"
#include "deps/020ae4c0_ComputeValueInterpolation_from_thumb.h"

int ComputeValueInterpolation_from_thumb
              (int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_2;
  if ((0 < param_4) && (iVar1 = param_3, param_4 < param_5)) {
    if (param_1 == 0) {
      iVar1 = _s32_div_f((param_3 - param_2) * param_4);
      iVar1 = (param_2 + iVar1) * 0x10000 >> 0x10;
    }
    else {
      iVar1 = param_1;
      if (param_1 == 1) {
        _s32_div_f(param_4 << 0xf);
        iVar1 = Maybe_helper_0ae564();
        param_3 = param_3 - param_2;
        if (param_3 < 1) {
          uVar2 = FUN_02132440(param_3 * 0x1000);
          func_021329f8(uVar2,uRam020ae544);
        }
        else {
          uVar2 = FUN_02132440(param_3 * 0x1000);
          func_02131234(uRam020ae544,uVar2);
        }
        uVar2 = func_021322c8();
        func_020ae554(uVar2,iRam020ae548 - iVar1);
        uVar2 = func_020ae54c();
        iVar1 = _s32_div_f(uVar2,2);
        iVar1 = (param_2 + iVar1) * 0x10000 >> 0x10;
      }
    }
  }
  return iVar1;
}

