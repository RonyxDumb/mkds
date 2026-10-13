/* Decompiled C draft; module arm9; ROM address 02129c18. No matching claim. */
#include "types.h"
#include "deps/02129c18_func_02129c18.h"

void func_02129c18(void)

{
  ushort *puVar1;
  undefined4 uVar2;
  
  *puRam02129c98 = 0;
  *puRam02129c9c = *puRam02129c9c & uRam02129ca4 | ((*puRam02129c9c & uRam02129ca0) >> 8 | 0xc) << 8
  ;
  puVar1 = puRam02129ca8;
  *puRam02129ca8 = *puRam02129ca8 & 0x43 | (ushort)uRam02129cac;
  *puVar1 = *puVar1 & 0xfffc | 2;
  puVar1 = puRam02129cb0;
  *puRam02129cb0 = *puRam02129cb0 & 0x43 | (ushort)uRam02129cb4;
  *puVar1 = *puVar1 & 0xfffc | 2;
  uVar2 = func_0214a214();
  Mem_CpuFastMemorySet(0,(undefined4 *)(uintptr_t)(uVar2),uRam02129cb8);
  uVar2 = func_0214a108();
  Mem_CpuFastMemorySet(0,(undefined4 *)(uintptr_t)(uVar2),uRam02129cb8);
  return;
}

