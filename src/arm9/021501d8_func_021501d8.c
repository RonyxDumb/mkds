/* Decompiled C draft; module arm9; ROM address 021501d8. No matching claim. */
#include "types.h"
#include "deps/021501d8_func_021501d8.h"

undefined4 func_021501d8(void)

{
  Os_DisableIrq();
  if (*(uint *)((uint)puRam02150224 & 0xfffffffc) >> ((uint)puRam02150224 & 3) * 8 != 0 ||
      *(uint *)((uint)puRam02150224 & 0xfffffffc) << ((uint)puRam02150224 & 3) * -8 + 0x20 != 0) {
    Os_RestoreIrq();
    return 0;
  }
  *puRam02150224 = 1;
  Os_RestoreIrq();
  return 1;
}

