/* Decompiled C draft; module arm9; ROM address 020aab70. No matching claim. */
#include "types.h"
#include "deps/020aab70_func_020aab70.h"

void func_020aab70(int param_1)

{
  ushort uVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  int *piVar7;
  
  piVar7 = *(int **)(param_1 + 0x2c);
  MIi_CpuCopyFast((undefined4 *)(uintptr_t)(*(undefined4 *)(iRam020aad90 + 4)),(undefined4 *)(uintptr_t)(*(undefined4 *)(iRam020aad90 + 8)),
                  *(undefined4 *)(piVar7[1] + 0x10));
  Mem_CpuFastMemorySet(0,(undefined4 *)(uintptr_t)(*(int *)(iRam020aad90 + 8) + *(int *)(piVar7[1] + 0x10) * 0x20),0x20);
  iVar3 = iRam020aad90;
  if (*(ushort *)(param_1 + 0x40) != 0) {
    pbVar6 = (byte *)(*piVar7 + (*(ushort *)(param_1 + 0x40) - 1) * 8);
    pbVar5 = pbVar6;
    do {
      func_020aa3a0(*(undefined4 *)(iVar3 + 8),
                    (uint)*(ushort *)(*(int *)(*(int *)(iRam020aad94 + 0x2c) + 4) + 2) << 3,8,
                    (uint)*pbVar5,(uint)pbVar5[1],(uint)*pbVar5 + (uint)pbVar5[2],
                    (uint)pbVar5[1] + (uint)pbVar5[3]);
      pbVar5 = pbVar5 + *(short *)(pbVar5 + 4) * 8;
    } while (pbVar5 != pbVar6);
  }
  iVar4 = iRam020aad94;
  iVar3 = iRam020aad90;
  if (*(ushort *)(param_1 + 0x42) != 0) {
    pbVar6 = (byte *)(*piVar7 + (*(ushort *)(param_1 + 0x42) - 1) * 8);
    pbVar5 = pbVar6;
    do {
      func_020aa3a0(*(undefined4 *)(iVar3 + 8),
                    (uint)*(ushort *)(*(int *)(*(int *)(iVar4 + 0x2c) + 4) + 2) << 3,8,(uint)*pbVar5
                    ,(uint)pbVar5[1],(uint)*pbVar5 + (uint)pbVar5[2],
                    (uint)pbVar5[1] + (uint)pbVar5[3]);
      pbVar5 = pbVar5 + *(short *)(pbVar5 + 4) * 8;
    } while (pbVar5 != pbVar6);
  }
  iVar4 = iRam020aad94;
  iVar3 = iRam020aad90;
  pbVar5 = *(byte **)(param_1 + 0x44);
  if (((((pbVar5 != (byte *)0x0) && (uVar1 = *(ushort *)(pbVar5 + 6), uVar1 != 0)) &&
       (uVar1 < 0x100)) && ((uVar1 != puRam020aad98[1] && (uVar1 != *puRam020aad98)))) &&
     (pbVar5 != *(byte **)(param_1 + 0x10))) {
    pbVar6 = pbVar5;
    pbVar2 = *(byte **)(param_1 + 0x18);
    while (pbVar5 != pbVar2) {
      func_020aa47c(*(undefined4 *)(iVar3 + 8),
                    (uint)*(ushort *)(*(int *)(*(int *)(iVar4 + 0x2c) + 4) + 2) << 3,8,(uint)*pbVar6
                    ,(uint)pbVar6[1],(uint)*pbVar6 + (uint)pbVar6[2],
                    (uint)pbVar6[1] + (uint)pbVar6[3]);
      pbVar6 = pbVar6 + *(short *)(pbVar6 + 4) * 8;
      pbVar2 = pbVar6;
    }
  }
  iVar4 = iRam020aad94;
  iVar3 = iRam020aad90;
  pbVar5 = *(byte **)(param_1 + 0x18);
  if (((pbVar5 != (byte *)0x0) && (uVar1 = *(ushort *)(pbVar5 + 6), uVar1 != 0)) &&
     ((uVar1 < 0x100 && ((uVar1 != puRam020aad98[1] && (pbVar6 = pbVar5, uVar1 != *puRam020aad98))))
     )) {
    do {
      func_020aa3a0(*(undefined4 *)(iVar3 + 8),
                    (uint)*(ushort *)(*(int *)(*(int *)(iVar4 + 0x2c) + 4) + 2) << 3,8,(uint)*pbVar6
                    ,(uint)pbVar6[1],(uint)*pbVar6 + (uint)pbVar6[2],
                    (uint)pbVar6[1] + (uint)pbVar6[3]);
      pbVar6 = pbVar6 + *(short *)(pbVar6 + 4) * 8;
    } while (pbVar6 != pbVar5);
  }
  iVar4 = iRam020aad94;
  iVar3 = iRam020aad90;
  pbVar5 = *(byte **)(param_1 + 0x10);
  if (((((pbVar5 != (byte *)0x0) && (uVar1 = *(ushort *)(pbVar5 + 6), uVar1 != 0)) &&
       (uVar1 < 0x100)) && ((uVar1 != puRam020aad98[1] && (uVar1 != *puRam020aad98)))) &&
     (pbVar5 != *(byte **)(param_1 + 0x18))) {
    pbVar6 = pbVar5;
    if ((*(int *)(param_1 + 0x14) != 0) && (uVar1 == *(ushort *)(*(int *)(param_1 + 0x14) + 6))) {
      do {
        func_020aa3a0(*(undefined4 *)(iVar3 + 8),
                      (uint)*(ushort *)(*(int *)(*(int *)(iVar4 + 0x2c) + 4) + 2) << 3,8,
                      (uint)*pbVar6,(uint)pbVar6[1],(uint)*pbVar6 + (uint)pbVar6[2],
                      (uint)pbVar6[1] + (uint)pbVar6[3]);
        pbVar6 = pbVar6 + *(short *)(pbVar6 + 4) * 8;
      } while (pbVar6 != pbVar5);
      return;
    }
    do {
      func_020aa47c(*(undefined4 *)(iVar3 + 8),
                    (uint)*(ushort *)(*(int *)(*(int *)(iVar4 + 0x2c) + 4) + 2) << 3,8,(uint)*pbVar6
                    ,(uint)pbVar6[1],(uint)*pbVar6 + (uint)pbVar6[2],
                    (uint)pbVar6[1] + (uint)pbVar6[3]);
      pbVar6 = pbVar6 + *(short *)(pbVar6 + 4) * 8;
    } while (pbVar6 != pbVar5);
  }
  return;
}

