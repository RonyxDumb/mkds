/* Decompiled C draft; module arm9; ROM address 0212030c. No matching claim. */
#include "types.h"
#include "deps/0212030c_GetTKByIndex.h"

int GetTKByIndex(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam0212033c & 0xfffffffc) >> (uRam0212033c & 3) * 8 |
          *(uint *)(uRam0212033c & 0xfffffffc) << (uRam0212033c & 3) * -8 + 0x20;
  if (((uint)*(byte *)(uVar2 + 0x1f55) & 1 << (param_1 & 0xff)) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1 * 0x244 + uVar2 + 0x228;
  }
  return iVar1;
}

