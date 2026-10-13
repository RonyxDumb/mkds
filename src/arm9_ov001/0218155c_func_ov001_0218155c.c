/* Decompiled C draft; module arm9_ov001; ROM address 0218155c. No matching claim. */
#include "types.h"
#include "deps/0218155c_func_ov001_0218155c.h"

void func_ov001_0218155c(uint param_1)

{
  int *piVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = piRam021815cc;
  if (*(ushort *)(*piRam021815cc + 6) <= param_1) {
    param_1 = (uint)*(ushort *)(*piRam021815cc + 6);
  }
  iVar5 = 0;
  if (0 < (int)param_1) {
    do {
      *(short *)(*piVar1 + 6) = *(short *)(*piVar1 + 6) + -1;
      uVar3 = func_ov001_0218180c();
      *(short *)(*piVar1 + 8) = *(short *)(*piVar1 + 8) + 1;
      iVar4 = *piVar1;
      if (uVar3 < *(ushort *)(iVar4 + 8)) {
        uVar2 = func_ov001_0218180c();
        *(undefined2 *)(*piRam021815cc + 8) = uVar2;
        return;
      }
      if (*(short *)(iVar4 + 0xe) == 0) {
        *(undefined2 *)(iVar4 + 0xe) = *(undefined2 *)(iVar4 + 0x10);
      }
      else {
        *(short *)(iVar4 + 0xe) = *(short *)(iVar4 + 0xe) + *(short *)(iVar4 + 0x16);
        iVar4 = *piVar1;
        if (*(ushort *)(iVar4 + 0x12) < *(ushort *)(iVar4 + 0xe)) {
          *(ushort *)(iVar4 + 0xe) = *(ushort *)(iVar4 + 0x12);
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)param_1);
  }
  return;
}

