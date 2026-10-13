/* Decompiled C draft; module arm9; ROM address 020161b4. No matching claim. */
#include "types.h"
#include "deps/020161b4_func_020161b4.h"

void func_020161b4(uint param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_1 < 3) {
    func_0201625c(4,3,2,0,1);
  }
  else {
    func_0201625c(4,3,0,2,1);
  }
  *puRam02016248 = (short)param_1;
  func_02016134();
  puVar2 = puRam02016258;
  uVar1 = uRam02016254;
  if (param_2 != 0) {
    *puRam02016250 = uRam0201624c;
    *puVar2 = uVar1;
    return;
  }
  return;
}

