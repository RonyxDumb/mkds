/* Decompiled C draft; module arm9_ov000; ROM address 0218dd8c. No matching claim. */
#include "types.h"
#include "deps/0218dd8c_FUN_0218dd8c.h"

int FUN_0218dd8c(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == 0) {
    func_0x0213442c(DAT_0218ddd4,DAT_0218ddd8,0,0xd3);
  }
  iVar3 = 0;
  if (0 < param_1[1]) {
    iVar2 = 0;
    do {
      iVar1 = FUN_0218d8dc(*(undefined4 *)(*param_1 + iVar2),param_2,param_3);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar2 = iVar2 + 4;
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1[1]);
  }
  return 0;
}

