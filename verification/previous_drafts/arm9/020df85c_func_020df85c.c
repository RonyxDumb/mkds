/* Decompiled C draft; module arm9; ROM address 020df85c. No matching claim. */
#include "types.h"
#include "deps/020df85c_func_020df85c.h"

void func_020df85c(int param_1)

{
  ushort *puVar1;
  
  puVar1 = puRam020df88c;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020df888;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puVar1;
  return;
}

