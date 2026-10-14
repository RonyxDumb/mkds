/* Decompiled C draft; module arm9; ROM address 0200cf30. No matching claim. */
#include "types.h"
#include "deps/0200cf30_Os_Lock_UnlockImpl.h"

undefined4 Os_Lock_UnlockImpl(uint param_1,undefined4 *param_2,code *param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_1 == *(ushort *)(param_2 + 1)) {
    if (param_4 == 0) {
      uVar1 = Os_DisableIrq(param_1);
    }
    else {
      uVar1 = Os_DisableIrqFiq();
    }
    *(undefined2 *)(param_2 + 1) = 0;
    if (param_3 != (code *)0x0) {
      (*param_3)();
    }
    *param_2 = 0;
    if (param_4 == 0) {
      Os_RestoreIrq(uVar1);
    }
    else {
      Os_RestoreIrqFiq(uVar1);
    }
    return 0;
  }
  return 0xfffffffe;
}

