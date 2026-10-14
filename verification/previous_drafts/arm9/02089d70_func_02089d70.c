/* Decompiled C draft; module arm9; ROM address 02089d70. No matching claim. */
#include "types.h"
#include "deps/02089d70_func_02089d70.h"

void func_02089d70(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = puRam02089e00;
  *puRam02089dfc = uRam02089df8 | (int)*(short *)(param_1 + 2) << 0x10;
  *puVar1 = 0x8c000;
  *puVar1 = 0x6e000;
  puVar2 = puRam02089e04;
  *puVar1 = 0xa000;
  *puVar2 = 1;
  *puRam02089e08 = (uint)*(ushort *)(param_1 + 4);
  func_02089e10(0);
  func_02089e10(1);
  func_02089e10(2);
  func_02089e10(3);
  *puRam02089e0c = 0;
  return;
}

