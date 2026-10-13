/* Decompiled C draft; module arm9; ROM address 02045874. No matching claim. */
#include "types.h"
#include "deps/02045874_func_02045874.h"

bool func_02045874(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = uRam020458c4;
  uVar2 = *(uint *)(uRam020458c4 & 0xfffffffc) >> (uRam020458c4 & 3) * 8 |
          *(uint *)(uRam020458c4 & 0xfffffffc) << (uRam020458c4 & 3) * -8 + 0x20;
  *(uint *)((*(uint *)(uRam020458c8 & 0xfffffffc) >> (uRam020458c8 & 3) * 8 |
            *(uint *)(uRam020458c8 & 0xfffffffc) << (uRam020458c8 & 3) * -8 + 0x20) +
            (uint)*(ushort *)(uVar2 + 0x60) * 4 + 0x5c) =
       *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
       *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
  uVar2 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
  *(short *)(uVar2 + 0x248) = *(short *)(uVar2 + 0x248) + 1;
  return *(ushort *)
          ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
           *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x248) < 5;
}

