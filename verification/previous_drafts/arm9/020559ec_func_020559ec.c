/* Decompiled C draft; module arm9; ROM address 020559ec. No matching claim. */
#include "types.h"
#include "deps/020559ec_func_020559ec.h"

void func_020559ec(undefined4 param_1,uint param_2,byte param_3)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam02055a44 & 0xfffffffc) >> (uRam02055a44 & 3) * 8 |
          *(uint *)(uRam02055a44 & 0xfffffffc) << (uRam02055a44 & 3) * -8 + 0x20;
  bVar1 = *(byte *)(uVar2 + 0x43d);
  Mem_CpuCopy8((ushort *)(uintptr_t)(param_1),(uint *)(uintptr_t)(param_2 * 0x22c + uVar2 + iRam02055a48),0x14);
  *(byte *)((*(uint *)(uRam02055a44 & 0xfffffffc) >> (uRam02055a44 & 3) * 8 |
            *(uint *)(uRam02055a44 & 0xfffffffc) << (uRam02055a44 & 3) * -8 + 0x20) + 0x43d) =
       bVar1 & param_3 | (byte)(1 << (param_2 & 0xff));
  return;
}

