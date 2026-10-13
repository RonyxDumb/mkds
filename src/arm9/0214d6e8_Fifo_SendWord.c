/* Decompiled C draft; module arm9; ROM address 0214d6e8. No matching claim. */
#include "types.h"
#include "deps/0214d6e8_Fifo_SendWord.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 Fifo_SendWord(uint param_1,int param_2,uint param_3)

{
  if ((*puRam0214d794 & 0x4000) != 0) {
    *puRam0214d794 = *puRam0214d794 | 0xc000;
    return 0xffffffff;
  }
  Os_DisableIrq(*puRam0214d794 & 0x4000);
  if ((*puRam0214d794 & 2) == 0) {
    *puRam0214d798 = param_1 & 0x1f | (param_3 & 1) << 5 | param_2 << 6;
    Os_RestoreIrq();
    return 0;
  }
  Os_RestoreIrq();
  return 0xfffffffe;
}

