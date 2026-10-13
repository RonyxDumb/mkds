/* Decompiled C draft; module arm9; ROM address 020df7d8. No matching claim. */
#include "types.h"
#include "deps/020df7d8_func_020df7d8.h"

undefined1 func_020df7d8(int param_1,int param_2,undefined4 param_3,undefined1 *param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = 1 << (*(ushort *)(param_2 + 0x74) & 0xff);
  if ((((uint)*(byte *)(param_1 + 0xe4) & uVar1 & 0xff) == 0) &&
     (iVar3 = func_020d26f8(), iVar3 != 0)) {
    uVar2 = param_1 + 0x78U & 3;
    uVar4 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
    *(uint *)(param_1 + 0x78) =
         uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20 |
         *(uint *)(uRam020df838 & 0xfffffffc) >> (uRam020df838 & 3) * 8 |
         *(uint *)(uRam020df838 & 0xfffffffc) << (uRam020df838 & 3) * -8 + 0x20;
    *(byte *)(param_1 + 0xe4) = *(byte *)(param_1 + 0xe4) | (byte)uVar1;
  }
  return *param_4;
}

