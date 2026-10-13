/* Decompiled C draft; module arm9; ROM address 02007e38. No matching claim. */
#include "types.h"
#include "deps/02007e38_func_02007e38.h"

int func_02007e38(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = Os_DisableIrq();
  if ((*piRam02007e94 != 0) && (iVar2 = func_02007138(param_1), iVar2 != 0)) {
    Mem_CpuCopy8(*piRam02007e94 + iRam02007e98 + (param_1 + -1) * 0x16,*piRam02007e94 + iRam02007e9c
                );
    Os_RestoreIrq(uVar1);
    return *piRam02007e94 + iRam02007e9c;
  }
  Os_RestoreIrq(uVar1);
  return 0;
}

