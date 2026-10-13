/* Decompiled C draft; module arm9; ROM address 021053e4. No matching claim. */
#include "types.h"
#include "deps/021053e4_func_021053e4.h"

void func_021053e4(int param_1)

{
  func_020d233c();
  *(undefined2 *)(param_1 + 0x66) = 0x1f;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfffd;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfff7;
  *(undefined2 *)(param_1 + 0x66) = 0x1f;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined2 *)(param_1 + 0xa0) = 0;
  *(undefined2 *)(param_1 + 0xa2) = 0;
  *(undefined2 *)(param_1 + 0xa4) = 0x80;
  return;
}

