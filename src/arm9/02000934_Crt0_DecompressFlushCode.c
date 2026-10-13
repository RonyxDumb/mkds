/* Decompiled C draft; module arm9; ROM address 02000934. No matching claim. */
#include "types.h"
#include "deps/02000934_Crt0_DecompressFlushCode.h"

int Crt0_DecompressFlushCode(int param_1)

{
  bool bVar1;
  ushort uVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  ushort *puVar6;
  byte *pbVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  
  if (param_1 != 0) {
    pbVar4 = (byte *)(param_1 + *(int *)(param_1 + -4));
    puVar6 = (ushort *)(param_1 - (*(uint *)(param_1 + -8) >> 0x18));
    uVar3 = param_1 - (*(uint *)(param_1 + -8) & 0xffffff);
    pbVar5 = pbVar4;
    while ((int)uVar3 < (int)puVar6) {
      puVar6 = (ushort *)((int)puVar6 + -1);
      uVar8 = (uint)*(byte *)puVar6;
      iVar9 = 8;
      while (0 < iVar9) {
        if ((uVar8 & 0x80) == 0) {
          puVar6 = (ushort *)((int)puVar6 + -1);
          pbVar5 = pbVar5 + -1;
          *pbVar5 = *(byte *)puVar6;
        }
        else {
          pbVar7 = (byte *)((int)puVar6 + -1);
          puVar6 = puVar6 + -1;
          uVar2 = *puVar6;
          iVar10 = *pbVar7 + 0x20;
          do {
            pbVar7 = pbVar5 + (uVar2 & 0xffff0fff) + 2;
            pbVar5 = pbVar5 + -1;
            *pbVar5 = *pbVar7;
            bVar1 = 0xf < iVar10;
            iVar10 = iVar10 + -0x10;
          } while (bVar1);
        }
        uVar8 = uVar8 << 1;
        iVar9 = iVar9 + -1;
        if ((int)puVar6 <= (int)uVar3) goto LAB_020009b8;
      }
    }
LAB_020009b8:
    param_1 = 0;
    uVar3 = uVar3 & 0xffffffe0;
    do {
      coproc_moveto_Data_Synchronization(0);
      coproc_moveto_Invalidate_Instruction_Cache_by_MVA(uVar3);
      coproc_moveto_Invalidate_Data_Cache_by_MVA(uVar3);
      uVar3 = uVar3 + 0x20;
    } while ((int)uVar3 < (int)pbVar4);
  }
  return param_1;
}

