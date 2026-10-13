/* Decompiled C draft; module arm9; ROM address 02145030. No matching claim. */
#include "types.h"
#include "deps/02145030_func_02145030.h"

int func_02145030(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = Wm_GetGlobal();
  iVar3 = func_02142988(2,9,10);
  if (iVar3 != 0) {
    return iVar3;
  }
  if (param_1 != 0) {
    if (*(short *)(param_1 + 0x80e) != 0) {
      uVar4 = iVar2 + (uint)*(ushort *)(param_1 + 0x816) * 4 + 0xc4;
      uVar1 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      uVar4 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
      if ((uVar4 == uRam021450e4) || (uVar4 == uRam021450e8)) {
        func_0214358c((uint)*(ushort *)(param_1 + 0x816),0,0);
        *(undefined2 *)(param_1 + 0x80e) = 0;
        *(undefined2 *)(param_1 + 0x81c) = 0;
        return 0;
      }
    }
    return 3;
  }
  return 6;
}

