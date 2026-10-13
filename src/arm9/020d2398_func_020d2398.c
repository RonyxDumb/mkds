/* Decompiled C draft; module arm9; ROM address 020d2398. No matching claim. */
#include "types.h"
#include "deps/020d2398_func_020d2398.h"

void func_020d2398(int param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort *puVar4;
  
  puVar2 = puRam020d2440;
  puVar1 = puRam020d243c;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfff;
  puVar4 = puRam020d2448;
  puVar3 = puRam020d2444;
  *(ushort *)(param_1 + 2) =
       *(ushort *)(param_1 + 2) | (ushort)((*(ushort *)(param_1 + 2) & 0xf) << 0xc);
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puVar1;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puVar2;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puVar3;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puVar4;
  if (*(short *)(param_1 + 100) != -1) {
    func_020d5114();
  }
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020d244c;
  return;
}

