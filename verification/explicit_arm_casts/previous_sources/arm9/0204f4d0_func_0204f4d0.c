/* Decompiled C draft; module arm9; ROM address 0204f4d0. No matching claim. */
#include "types.h"
#include "deps/0204f4d0_func_0204f4d0.h"

void func_0204f4d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5
                  )

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = 0;
  do {
    iVar4 = uVar2 * 0x88;
    if (*(char *)(*piRam0204f5b0 + iVar4 + iRam0204f5b4) == '\0') {
      Mem_CpuCopy8(param_1,*piRam0204f5b0 + iRam0204f5b4 + iVar4,0x40);
      piVar1 = piRam0204f5b0;
      if (param_5 == 0) {
        *(undefined4 *)(*piRam0204f5b0 + iVar4 + iRam0204f5bc) = 0;
        *(undefined4 *)(*piVar1 + iVar4 + iRam0204f5c0) = 0;
        iVar3 = iRam0204f5c4;
        *(uint *)(*piVar1 + iRam0204f5c4 + iVar4) =
             *(uint *)(*piVar1 + iRam0204f5c4 + iVar4) & uRam0204f5d4;
        *(uint *)(*piVar1 + iVar3 + iVar4) =
             *(uint *)(*piVar1 + iVar3 + iVar4) & uRam0204f5cc | param_4 & uRam0204f5d0;
      }
      else {
        *(undefined4 *)(*piRam0204f5b0 + iVar4 + iRam0204f5bc) =
             *(undefined4 *)(*piRam0204f5b0 + iRam0204f5b8);
        *(undefined4 *)(*piVar1 + iVar4 + iRam0204f5c0) = 0;
        iVar3 = iRam0204f5c4;
        *(uint *)(*piVar1 + iRam0204f5c4 + iVar4) =
             *(uint *)(*piVar1 + iRam0204f5c4 + iVar4) | uRam0204f5c8;
        *(uint *)(*piVar1 + iVar3 + iVar4) =
             *(uint *)(*piVar1 + iVar3 + iVar4) & uRam0204f5cc | param_4 & uRam0204f5d0;
      }
      piVar1 = piRam0204f5b0;
      *(undefined4 *)(*piRam0204f5b0 + iVar4 + iRam0204f5d8) = param_2;
      iVar3 = *piVar1 + iRam0204f5c4;
      *(uint *)(iVar3 + iVar4) = *(uint *)(iVar3 + iVar4) | uRam0204f5dc;
      *(undefined4 *)(*piVar1 + iVar4 + iRam0204f5e0) = param_3;
      return;
    }
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 0xc);
  return;
}

