/* Decompiled C draft; module arm9; ROM address 020ab660. No matching claim. */
#include "types.h"
#include "deps/020ab660_func_020ab660.h"

void func_020ab660(ushort param_1,int param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  ushort uVar4;
  bool bVar5;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar1 = piRam020ab710;
  uVar4 = param_1 ^ *(ushort *)((int)piRam020ab710 + 6);
  *(ushort *)(piRam020ab710 + 1) = param_1 & uVar4;
  *(ushort *)(piVar1 + 2) = ~param_1 & uVar4;
  *(ushort *)((int)piVar1 + 6) = param_1;
  if ((*(ushort *)((int)piVar1 + 6) & *(ushort *)((int)piVar1 + 10)) == 0) {
    *piVar1 = 0;
  }
  else {
    *piVar1 = *piVar1 + 1;
  }
  piVar1 = piRam020ab710;
  if (piRam020ab710[9] != 0) {
    MKDS_SLICE_2(local_8,2) = (short)(param_3 >> 0x10);
    bVar5 = MKDS_SLICE_2(local_8,2) != 0;
    local_c = param_2;
    local_8 = param_3;
    if (bVar5) {
      local_c = piRam020ab710[3];
      local_8 = (uint)*(ushort *)((int)piRam020ab710 + 0x12) << 0x10;
    }
    uVar2 = local_8 & 0xffff;
    if (uVar2 == *(ushort *)(piRam020ab710 + 4)) {
      if (uVar2 == 0) {
        piRam020ab710[7] = 0;
      }
      else {
        piRam020ab710[7] = 2;
        piVar1[6] = piVar1[6] + 1;
      }
    }
    else {
      if (uVar2 == 0) {
        iVar3 = 3;
      }
      else {
        iVar3 = 1;
      }
      piRam020ab710[7] = iVar3;
      piVar1[6] = 0;
    }
    piVar1 = piRam020ab710;
    if (uVar2 != 0) {
      *(undefined2 *)(piRam020ab710 + 5) = (undefined2)local_c;
      *(undefined2 *)((int)piVar1 + 0x16) = MKDS_SLICE_2(local_c,2);
    }
    piVar1 = piRam020ab710;
    *(undefined2 *)(piRam020ab710 + 8) = (undefined2)local_8;
    *(undefined2 *)(piVar1 + 3) = (undefined2)local_c;
    *(undefined2 *)((int)piVar1 + 0xe) = MKDS_SLICE_2(local_c,2);
    *(undefined2 *)(piVar1 + 4) = (undefined2)local_8;
    *(short *)((int)piVar1 + 0x12) = MKDS_SLICE_2(local_8,2);
  }
  return;
}

