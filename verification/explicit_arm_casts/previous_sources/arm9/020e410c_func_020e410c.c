/* Decompiled C draft; module arm9; ROM address 020e410c. No matching claim. */
#include "types.h"
#include "deps/020e410c_func_020e410c.h"

void func_020e410c(undefined4 *param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined1 auStack_20 [4];
  undefined4 local_1c;
  
  puVar8 = (undefined4 *)*param_1;
  iVar5 = 0;
  iVar4 = -1;
  uVar1 = *(ushort *)(param_1 + 1);
  puVar7 = puVar8;
  if (uVar1 != 0) {
    do {
      psVar6 = (short *)*puVar7;
      if (*psVar6 == 0xcb) {
        if (iVar4 < 0) {
          *(undefined4 *)((int)psVar6 + iRam020e417c) = 0;
          iVar4 = iVar5;
        }
        else {
          VecFx32_Subtract(puVar8[iVar4] + 4,psVar6 + 2,auStack_20);
          local_1c = 0;
          uVar3 = VecFx32_Norm(auStack_20);
          iVar2 = iRam020e4180;
          *(undefined4 *)((int)psVar6 + iRam020e4180) = uVar3;
          *(int *)((int)psVar6 + iRam020e4180) =
               *(int *)((int)psVar6 + iVar2) - *(int *)(puVar8[iVar4] + 0x58);
          iVar4 = iVar5;
        }
      }
      iVar5 = iVar5 + 1;
      puVar7 = puVar7 + 1;
    } while (iVar5 < (int)(uint)uVar1);
  }
  return;
}

