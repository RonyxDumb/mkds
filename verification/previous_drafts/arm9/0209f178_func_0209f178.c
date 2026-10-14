/* Decompiled C draft; module arm9; ROM address 0209f178. No matching claim. */
#include "types.h"
#include "deps/0209f178_func_0209f178.h"

void func_0209f178(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = StructMapObject_SomeFn_2
                    (*(uint *)(uRam0209f1c0 & 0xfffffffc) >> (uRam0209f1c0 & 3) * 8 |
                     *(uint *)(uRam0209f1c0 & 0xfffffffc) << (uRam0209f1c0 & 3) * -8 + 0x20);
  *(short *)(param_2 + 0xa0) = *(short *)(param_2 + 0xa0) + 1;
  if (uVar1 <= *(ushort *)(param_2 + 0xa0)) {
    *(undefined2 *)(param_2 + 0xa0) = 0;
  }
  *(short *)(param_2 + 0x7e) = *(short *)(param_2 + 0x7e) + (short)uRam0209f1c4;
  return;
}

