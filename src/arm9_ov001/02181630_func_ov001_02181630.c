/* Decompiled C draft; module arm9_ov001; ROM address 02181630. No matching claim. */
#include "types.h"
#include "deps/02181630_func_ov001_02181630.h"

void func_ov001_02181630(short param_1)

{
  undefined2 uVar1;
  uint uVar2;
  
  *(short *)(*piRam0218165c + 6) = *(short *)(*piRam0218165c + 6) + param_1;
  uVar2 = func_ov001_0218180c();
  if (uVar2 < *(ushort *)(*piRam0218165c + 6)) {
    uVar1 = func_ov001_0218180c();
    *(undefined2 *)(*piRam0218165c + 6) = uVar1;
  }
  return;
}

