/* Decompiled C draft; module arm9_ov000; ROM address 021af550. No matching claim. */
#include "types.h"
#include "deps/021af550_FUN_021af550.h"

void FUN_021af550(undefined4 param_1,int param_2,int param_3,byte param_4,ushort param_5)

{
  uint *puVar1;
  ushort *puVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  uint uVar8;
  
  puVar1 = DAT_021af6fc;
  if (*(char *)(param_3 + 8) != '\0') {
    puVar7 = DAT_021af6f8;
    if (*(int *)(DAT_021af6f0 + 4) != DAT_021af6f4) {
      puVar7 = (ushort *)(*(int *)(param_3 + 0x4c) + 0x22);
    }
    if ((param_4 & 2) == 0) {
      uVar8 = 0x14;
    }
    else {
      uVar8 = 0x18;
    }
    puVar7[-6] = (ushort)(byte)(*DAT_021af6fc >> 0x18) | (ushort)((*DAT_021af6fc >> 0x10) << 8);
    puVar7[-5] = (ushort)((*puVar1 & 0xffff) >> 8) | (ushort)((*puVar1 & 0xffff) << 8);
    puVar7[-4] = (ushort)(byte)(*(uint *)(param_3 + 0x1c) >> 0x18) |
                 (ushort)((*(uint *)(param_3 + 0x1c) >> 0x10) << 8);
    uVar6 = *(uint *)(param_3 + 0x1c) & 0xffff;
    puVar7[-3] = (ushort)(uVar6 >> 8) | (ushort)(uVar6 << 8);
    puVar7[-2] = (ushort)DAT_021af700;
    uVar6 = uVar8 + param_2 & 0xffff;
    puVar7[-1] = (ushort)(uVar6 >> 8) | (ushort)(uVar6 << 8);
    *puVar7 = *(ushort *)(param_3 + 10) >> 8 | *(ushort *)(param_3 + 10) << 8;
    puVar7[1] = *(ushort *)(param_3 + 0x18) >> 8 | *(ushort *)(param_3 + 0x18) << 8;
    puVar7[2] = (ushort)(byte)(*(uint *)(param_3 + 0x28) >> 0x18) |
                (ushort)((*(uint *)(param_3 + 0x28) >> 0x10) << 8);
    uVar6 = *(uint *)(param_3 + 0x28) & 0xffff;
    puVar7[3] = (ushort)(uVar6 >> 8) | (ushort)(uVar6 << 8);
    puVar7[4] = (ushort)(byte)(*(uint *)(param_3 + 0x24) >> 0x18) |
                (ushort)((*(uint *)(param_3 + 0x24) >> 0x10) << 8);
    uVar6 = *(uint *)(param_3 + 0x24) & 0xffff;
    puVar7[5] = (ushort)(uVar6 >> 8) | (ushort)(uVar6 << 8);
    *(char *)(puVar7 + 6) = (char)((uVar8 >> 2) << 4);
    *(byte *)((int)puVar7 + 0xd) = param_4;
    uVar6 = *(int *)(param_3 + 0x3c) - *(int *)(param_3 + 0x44) & 0xffff;
    puVar7[7] = (ushort)(uVar6 >> 8) | (ushort)(uVar6 << 8);
    puVar7[8] = 0;
    puVar7[9] = param_5 >> 8 | param_5 << 8;
    iVar5 = DAT_021af708;
    puVar2 = DAT_021af704;
    if ((param_4 & 2) != 0) {
      puVar7[10] = (ushort)(byte)((uint)*DAT_021af704 + DAT_021af708 >> 0x18) |
                   (ushort)(((uint)*DAT_021af704 + DAT_021af708 >> 0x10) << 8);
      uVar6 = (uint)*puVar2 + iVar5 & 0xffff;
      puVar7[0xb] = (ushort)(uVar6 >> 8) | (ushort)(uVar6 << 8);
    }
    uVar4 = FUN_021b01b4(puVar7 + -6,uVar8 + 0xc,0);
    uVar3 = FUN_021b01b4((ushort *)(uintptr_t)(param_1),param_2,uVar4);
    iVar5 = FUN_021b01a0(uVar3);
    puVar7[8] = (ushort)((uint)iVar5 >> 8) | (ushort)(iVar5 << 8);
    FUN_021af858((int)(uintptr_t)(puVar7),uVar8,param_1,param_2,*(undefined4 *)(param_3 + 0x1c),6);
    *(int *)(param_3 + 0x28) = *(int *)(param_3 + 0x28) + param_2;
    if ((param_4 & 3) != 0) {
      *(int *)(param_3 + 0x28) = *(int *)(param_3 + 0x28) + 1;
    }
  }
  return;
}

