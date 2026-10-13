/* Decompiled C draft; module arm9; ROM address 0204db6c. No matching claim. */
#include "types.h"
#include "deps/0204db6c_func_0204db6c.h"

undefined4 func_0204db6c(void)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  iVar3 = *(int *)(*DAT_0204dc80 + 4);
  if (iVar3 == 2) {
    *(undefined4 *)(*DAT_0204dc80 + 4) = 5;
  }
  else if (iVar3 != 5) {
    if (iVar3 != 10) {
      return 3;
    }
    return 1;
  }
  iVar3 = *DAT_0204dc80;
  if (*(int *)(iVar3 + 0x10) != 0) {
    return 0;
  }
  iVar4 = *(int *)(iVar3 + 0xc);
  if (iVar4 < 0x19) {
    if (iVar4 < 0x18) {
      if (iVar4 < 0x10) {
        switch(iVar4) {
        case 3:
          func_0204fb40(1);
          func_02052bf8();
          break;
        case 4:
          func_0204f814();
          func_0204fb40(1);
          func_02052bf8();
          break;
        case 5:
          func_02052b60(0);
          break;
        case 6:
          uVar2 = func_0204dcf0(*(undefined1 *)(iVar3 + DAT_0204dc84));
          piVar1 = DAT_0204dc80;
          *(undefined1 *)(*DAT_0204dc80 + DAT_0204dc84) = uVar2;
          *(undefined2 *)(*piVar1 + DAT_0204dc88) = 0;
          func_02051a24();
          break;
        case 0xb:
        case 0xf:
          iVar3 = func_0204dc8c();
          if (iVar3 != 0) {
            func_02059878();
            uVar5 = 1;
          }
        }
      }
      else if (iVar4 == 0x16) {
        func_0204e128();
      }
    }
    else {
      func_0204e0bc();
    }
  }
  else if (iVar4 < 0x1c) {
    if (iVar4 < 0x1b) {
      if (iVar4 == 0x19) {
        StructZE_StateFn22_23_24_25_from_thumb();
      }
    }
    else {
      func_02052ecc();
    }
  }
  else if (iVar4 == 0x24) {
    func_020532dc(0x14);
  }
  return uVar5;
}

