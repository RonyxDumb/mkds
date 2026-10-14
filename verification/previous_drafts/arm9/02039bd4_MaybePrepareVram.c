/* Decompiled C draft; module arm9; ROM address 02039bd4. No matching claim. */
#include "types.h"
#include "deps/02039bd4_MaybePrepareVram.h"

void MaybePrepareVram(void)

{
  switch(*(uint *)(DAT_02039c6c & 0xfffffffc) >> (DAT_02039c6c & 3) * 8 |
         *(uint *)(DAT_02039c6c & 0xfffffffc) << (DAT_02039c6c & 3) * -8 + 0x20) {
  case 0:
    GX_SetBankForLCDC(DAT_02039c70);
    Mem_CpuFastMemorySet(0,(undefined4 *)(uintptr_t)(0x6800000),0x60000);
    Mem_CpuFastMemorySet(0,(undefined4 *)(uintptr_t)(DAT_02039c74),0x24000);
    break;
  case 1:
    goto LAB_02039c3c;
  case 2:
    break;
  case 3:
LAB_02039c3c:
    GX_SetBankForLCDC(DAT_02039c78);
    Mem_CpuFastMemorySet(0,(undefined4 *)(uintptr_t)(0x6800000),0xa4000);
  }
  GX_DisableBankForLCDC();
  return;
}

