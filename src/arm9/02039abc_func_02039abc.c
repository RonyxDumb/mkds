/* Decompiled C draft; module arm9; ROM address 02039abc. No matching claim. */
#include "types.h"
#include "deps/02039abc_func_02039abc.h"

void func_02039abc(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  
  if (param_2 != 0) {
    Os_Terminate();
  }
  uVar1 = (uint)(piRam02039b20 + 1) & 3;
  uVar2 = *(uint *)((uint)(piRam02039b20 + 1) & 0xfffffffc);
  pcVar3 = (code *)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  *piRam02039b20 = param_1;
  if (pcVar3 == (code *)0x0) {
    return;
  }
  if (param_1 == 0) {
    (*pcVar3)(0);
    return;
  }
  if (param_1 == 1) {
    (*pcVar3)(1);
    return;
  }
  return;
}

