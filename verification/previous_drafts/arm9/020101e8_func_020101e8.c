/* Decompiled C draft; module arm9; ROM address 020101e8. No matching claim. */
#include "types.h"
#include "deps/020101e8_func_020101e8.h"

undefined4 func_020101e8(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = param_1 + 8U & 3;
  uVar3 = *(uint *)(param_1 + 8U & 0xfffffffc);
  param_1 = param_1 + (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  iVar2 = NNS_G3dGetResDataByName(param_1 + (uint)*(ushort *)(param_1 + 2));
  if ((iVar2 != 0) && ((*(byte *)(iVar2 + 3) & 1) != 0)) {
    *(byte *)(iVar2 + 3) = *(byte *)(iVar2 + 3) & 0xfe;
    return 1;
  }
  return 0;
}

