/* Decompiled C draft; module arm9; ROM address 020ff178. No matching claim. */
#include "types.h"
#include "deps/020ff178_func_020ff178.h"

int func_020ff178(int param_1)

{
  return (int)(short)(*(ushort *)(param_1 + 0x4c) |
                     (ushort)((int)((*(ushort *)(param_1 + 0x78) & 0xffff00ff) << 0x10) >> 0xc));
}

