/* Decompiled C draft; module arm9_ov003; ROM address 021b88c0. No matching claim. */
#include "types.h"
#include "deps/021b88c0_func_ov003_021b88c0.h"

undefined4 func_ov003_021b88c0(int param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  
  pbVar4 = (byte *)(param_1 + 6);
  do {
    uVar2 = func_ov003_021b7c44(*(undefined2 *)(pbVar4 + 2));
    bVar1 = *pbVar4;
    if (bVar1 < 0x36) {
      if (bVar1 < 0x35) {
        if (bVar1 == 0x30) {
LAB_021b88f2:
          if (0x40 < uVar2) {
            return 0xffffffff;
          }
        }
      }
      else {
LAB_021b8902:
        if (0x21 < uVar2) {
          return 0xffffffff;
        }
      }
    }
    else if (bVar1 < 0x41) {
      if (bVar1 == 0x40) goto LAB_021b88f2;
    }
    else if (bVar1 == 0x45) goto LAB_021b8902;
    if (bVar1 < 0x36) {
      if (bVar1 < 0x35) {
        if (bVar1 != 0x30) {
          return 0xffffffff;
        }
        goto LAB_021b8930;
      }
LAB_021b8940:
      if ((uVar2 != 0) && (pbVar4[uVar2 + 5] != 0)) {
        return 0xffffffff;
      }
      func_ov003_021b7d90(param_2 + 8,pbVar4 + 6,uVar2);
    }
    else {
      if (0x40 < bVar1) {
        if (bVar1 != 0x45) {
          return 0xffffffff;
        }
        goto LAB_021b8940;
      }
      if (bVar1 != 0x40) {
        return 0xffffffff;
      }
LAB_021b8930:
      func_ov003_021b7d90(param_2 + 0x30,pbVar4 + 6,uVar2);
      *(uint *)(param_2 + 4) = uVar2;
    }
    if (*(short *)(pbVar4 + 4) == 0) {
      return 0;
    }
    iVar3 = func_ov003_021b7c44();
    pbVar4 = (byte *)(param_1 + 6 + iVar3);
  } while( true );
}

