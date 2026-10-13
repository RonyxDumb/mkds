/* Decompiled C draft; module arm9; ROM address 020d233c. No matching claim. */
#include "types.h"
#include "deps/020d233c_func_020d233c.h"

void func_020d233c(int param_1)

{
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfff0;
  *(ushort *)(param_1 + 2) =
       *(ushort *)(param_1 + 2) | (ushort)((int)(*(ushort *)(param_1 + 2) & 0xf000) >> 0xc);
  if ((*(ushort *)(param_1 + 2) & 2) == 0) {
    *(undefined2 *)(param_1 + 0x66) = 0x1f;
  }
  if (*(short *)(param_1 + 100) != -1) {
    func_020d50ec();
  }
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfeff;
  return;
}

