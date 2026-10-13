/* Decompiled C draft; module arm9; ROM address 020ab7a4. No matching claim. */
#include "types.h"
#include "deps/020ab7a4_func_020ab7a4.h"

void func_020ab7a4(short *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  int iVar6;
  
  piVar1 = piRam020ab844;
  iVar6 = 0;
  iVar3 = *piRam020ab844;
  if (*(short *)(iVar3 + 0x44) != 0) {
    iVar4 = 0;
    do {
      *(undefined2 *)(*(int *)(iVar3 + 0x40) + iVar4) = 0;
      iVar4 = iVar4 + 2;
      iVar6 = iVar6 + 1;
      iVar3 = *piVar1;
    } while (iVar6 < (int)(uint)*(ushort *)(iVar3 + 0x44));
  }
  piVar1 = piRam020ab844;
  iVar6 = 0;
  uVar5 = *(ushort *)(iVar3 + 0x4a);
  if (uVar5 != 0) {
    iVar4 = 0;
    do {
      *(short *)(*(int *)(iVar3 + 0x40) + iVar4) = *param_1;
      piVar2 = piRam020ab844;
      if (*param_1 == 0) {
        *(short *)(*piRam020ab844 + 0x46) = (short)iVar6;
        *(undefined2 *)(*piVar2 + 0x48) = *(undefined2 *)(*piVar2 + 0x46);
        return;
      }
      param_1 = param_1 + 1;
      iVar4 = iVar4 + 2;
      iVar6 = iVar6 + 1;
      iVar3 = *piVar1;
      uVar5 = *(ushort *)(iVar3 + 0x4a);
    } while (iVar6 < (int)(uint)uVar5);
  }
  *(ushort *)(iVar3 + 0x46) = uVar5 - 1;
  piVar1 = piRam020ab844;
  *(undefined2 *)(*piRam020ab844 + 0x48) = *(undefined2 *)(*piRam020ab844 + 0x46);
  *(undefined2 *)(*(int *)(*piVar1 + 0x40) + (uint)*(ushort *)(*piVar1 + 0x4a) * 2) = 0;
  return;
}

