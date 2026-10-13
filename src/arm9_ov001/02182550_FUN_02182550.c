/* Decompiled C draft; module arm9_ov001; ROM address 02182550. No matching claim. */
#include "types.h"
#include "deps/02182550_FUN_02182550.h"

void FUN_02182550(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined8 uVar8;
  
  if (param_1 != (int *)0x0) {
    iVar5 = 0;
    for (iVar7 = 0;
        (iVar5 < (int)(uint)*(ushort *)(param_1 + 1) &&
        (iVar4 = *(int *)(*param_1 + iVar7), iVar4 != 0)); iVar7 = iVar7 + 4) {
      puVar6 = *(undefined4 **)(iVar4 + 0x9c);
      uVar2 = puVar6[1];
      *(undefined4 *)(iVar4 + 0xd8) = *puVar6;
      *(undefined4 *)(iVar4 + 0xdc) = uVar2;
      *(undefined4 *)(iVar4 + 0xe0) = puVar6[2];
      *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar4 + 0xd8);
      *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar4 + 0xdc);
      *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar4 + 0xe0);
      *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + DAT_02182630;
      if (*(short *)(*(int *)(iVar4 + 0x9c) + 0x26) < 0) {
        *(short *)(iVar4 + 0xbc) = (short)DAT_02182634;
      }
      else {
        func_0x020d7da8(iVar4 + 0xb4,*(int *)(iVar4 + 0x9c),0);
        iVar1 = func_0x02133068((int)*(short *)(*(int *)(iVar4 + 0x9c) + 0x28) << 0xc,100);
        *(int *)(iVar4 + 0xb8) = iVar1;
        iVar3 = *(int *)(**(int **)(iVar4 + 0xb4) + *(int *)(iVar4 + 0xc0) * 0x54 + 0x34);
        uVar8 = func_0x02133048(iVar1,iVar1 >> 0x1f,iVar3,iVar3 >> 0x1f);
        *(uint *)(iVar4 + 0xc4) = (uint)uVar8 >> 0xc | (int)((ulonglong)uVar8 >> 0x20) << 0x14;
      }
      *(undefined4 *)(iVar4 + 0xb0) = DAT_02182638;
      if (*(short *)(*(int *)(iVar4 + 0x9c) + 0x2a) == 0) {
        *(undefined2 *)(iVar4 + 0xa0) = 0x1f;
      }
      else {
        *(undefined2 *)(iVar4 + 0xa0) = 0;
      }
      iVar5 = iVar5 + 1;
    }
  }
  return;
}

