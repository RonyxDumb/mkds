/* Decompiled C draft; module arm9; ROM address 0214ca38. No matching claim. */
#include "types.h"
#include "deps/0214ca38_MI_DmaFill32Async.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void MI_DmaFill32Async(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,code *param_5,
                      undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_4 != 0) {
    MI_WaitDma();
    if (param_5 == (code *)0x0) {
      uVar1 = Os_DisableIrq();
      iVar2 = iRam0214cb0c + param_1 * 4;
      *(undefined4 *)(param_1 * 4 + 0x40000e0) = param_3;
      func_01fffe8c(param_1,iVar2,param_2,param_4 >> 2 | 0x85000000);
      Os_RestoreIrq(uVar1);
      return;
    }
    OSi_EnterDmaCallback(param_1,param_5,param_6);
    uVar1 = Os_DisableIrq();
    iVar2 = iRam0214cb0c;
    *(undefined4 *)(param_1 * 4 + 0x40000e0) = param_3;
    func_01fffe8c(param_1,iVar2 + param_1 * 4,param_2,param_4 >> 2 | 0xc5000000);
    Os_RestoreIrq(uVar1);
    return;
  }
  if (param_5 != (code *)0x0) {
    (*param_5)(param_6);
    return;
  }
  return;
}

