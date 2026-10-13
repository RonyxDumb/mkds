/* Decompiled C draft; module arm9_ov000; ROM address 021ae724. No matching claim. */
#include "types.h"
#include "deps/021ae724_FUN_021ae724.h"

void FUN_021ae724(int param_1,ushort *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  
  if ((param_2[3] == 0) || (iVar1 = FUN_021b0138(param_2,param_3,param_1,0x11), iVar1 == 0)) {
    for (iVar1 = *(int *)(DAT_021ae878 + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x68)) {
      piVar4 = *(int **)(iVar1 + 0xa4);
      if (((((piVar4 != (int *)0x0) && (*piVar4 != 0)) && ((char)piVar4[2] == '\n')) &&
          ((uint)*(ushort *)((int)piVar4 + 10) ==
           ((int)(uint)param_2[1] >> 8 | (param_2[1] & 0xff) << 8))) &&
         (((*(ushort *)(piVar4 + 6) == 0 ||
           ((uint)*(ushort *)(piVar4 + 6) == ((int)(uint)*param_2 >> 8 | (*param_2 & 0xff) << 8)))
          && ((uVar3 = piVar4[7], uVar3 == 0 ||
              ((uVar3 == 0xffffffff ||
               (uVar3 == (((int)(uint)*(ushort *)(param_1 + 0xc) >> 8 |
                          (*(ushort *)(param_1 + 0xc) & 0xff) << 8) << 0x10 |
                         (int)(uint)*(ushort *)(param_1 + 0xe) >> 8 |
                         (*(ushort *)(param_1 + 0xe) & 0xff) << 8))))))))) {
        piVar4[5] = ((int)(uint)*(ushort *)(param_1 + 0x10) >> 8 |
                    (*(ushort *)(param_1 + 0x10) & 0xff) << 8) << 0x10 |
                    (int)(uint)*(ushort *)(param_1 + 0x12) >> 8 |
                    (*(ushort *)(param_1 + 0x12) & 0xff) << 8;
        if (piVar4[7] == 0) {
          piVar4[7] = ((int)(uint)*(ushort *)(param_1 + 0xc) >> 8 |
                      (*(ushort *)(param_1 + 0xc) & 0xff) << 8) << 0x10 |
                      (int)(uint)*(ushort *)(param_1 + 0xe) >> 8 |
                      (*(ushort *)(param_1 + 0xe) & 0xff) << 8;
          *(ushort *)(piVar4 + 6) = *param_2 >> 8 | *param_2 << 8;
        }
        if (piVar4[0x11] != 0) {
          return;
        }
        uVar2 = param_3 - 8;
        if ((uint)piVar4[0xf] < uVar2) {
          piVar4[0x11] = piVar4[0xf];
        }
        else {
          piVar4[0x11] = uVar2;
        }
        func_0x0214d1fc(param_2 + 4,piVar4[0x10],piVar4[0x11],uVar3,uVar2);
        if (piVar4[1] != 3) {
          if ((code *)piVar4[0xe] == (code *)0x0) {
            return;
          }
          iVar1 = (*(code *)piVar4[0xe])(piVar4[0x10],piVar4[0x11],piVar4);
          if (iVar1 == 0) {
            return;
          }
          piVar4[0x11] = 0;
          return;
        }
        piVar4[1] = 0;
        func_0x0200df68(*piVar4);
        return;
      }
    }
  }
  return;
}

