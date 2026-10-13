/* Decompiled C draft; module arm9; ROM address 02139ffc. No matching claim. */
#include "types.h"
#include "deps/02139ffc_func_02139ffc.h"

int func_02139ffc(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar1 = param_1 + 1;
  while( true ) {
    if ((uVar2 & 0xff) == 0) {
      if ((param_2 & 0xff) == 0) {
        iVar3 = uVar1 - 1;
      }
      else {
        iVar3 = 0;
      }
      return iVar3;
    }
    if ((uVar2 & 0xff) == (param_2 & 0xff)) break;
    uVar2 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
    uVar1 = uVar1 + 1;
  }
  return uVar1 - 1;
}

