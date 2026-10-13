/* Decompiled C draft; module arm9; ROM address 0211b23c. No matching claim. */
#include "types.h"
#include "deps/0211b23c_func_0211b23c.h"

void func_0211b23c(void)

{
  ushort *puVar1;
  int iVar2;
  
  iVar2 = *piRam0211b2b0;
  if ((*(int *)(iVar2 + 0xb8) == 1) &&
     ((*(int *)(iVar2 + 0x2c) == 3 || (*(int *)(iVar2 + 0x70) == 1)))) {
    *puRam0211b2b4 =
         *puRam0211b2b4 & uRam0211b2bc | ((*puRam0211b2b4 & uRam0211b2b8) >> 8 & 0xfffffffc) << 8;
  }
  puVar1 = puRam0211b2c0;
  *puRam0211b2c0 = *puRam0211b2c0 & 0xfffc;
  *puVar1 = *puVar1 & 0x43 | (ushort)uRam0211b2c4;
  func_02116dc8();
  if (*psRam0211b2c8 != 2) {
    func_0212b91c();
  }
  Mem_DestroyHeap(*(undefined4 *)(*piRam0211b2b0 + 0x28));
  *piRam0211b2b0 = 0;
  return;
}

