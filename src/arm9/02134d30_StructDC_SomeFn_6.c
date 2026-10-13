/* Decompiled C draft; module arm9; ROM address 02134d30. No matching claim. */
#include "types.h"
#include "deps/02134d30_StructDC_SomeFn_6.h"

undefined4 StructDC_SomeFn_6(uint param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 != 0) {
    do {
      if (((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) & 0xff) !=
          ((*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
           *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) & 0xff)) {
        if (((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
             *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) & 0xff) <
            ((*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
             *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) & 0xff)) {
          uVar1 = 0xffffffff;
        }
        else {
          uVar1 = 1;
        }
        return uVar1;
      }
      param_3 = param_3 + -1;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    } while (param_3 != 0);
  }
  return 0;
}

