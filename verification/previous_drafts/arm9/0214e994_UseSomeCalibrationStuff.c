/* Decompiled C draft; module arm9; ROM address 0214e994. No matching claim. */
#include "types.h"
#include "deps/0214e994_UseSomeCalibrationStuff.h"

void UseSomeCalibrationStuff(short *param_1)

{
  short sVar1;
  int iVar2;
  ushort *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  
  if (param_1 != (short *)0x0) {
    Os_DisableIrq();
    puVar4 = puRam0214ead0;
    puVar3 = puRam0214eacc;
    iVar2 = iRam0214eac8;
    sVar1 = param_1[2];
    if (sVar1 == 0) {
      *(undefined4 *)(iRam0214eac8 + 0x18) = 0;
      *(undefined4 *)(iVar2 + 0x1c) = 0;
      *(undefined4 *)(iVar2 + 0x20) = 0;
    }
    else {
      *puRam0214eacc = 0;
      piVar5 = piRam0214ead4;
      *puVar4 = 0x10000000;
      *piVar5 = (int)sVar1;
      piVar5[1] = 0;
      iVar2 = iRam0214eac8;
      *(int *)(iRam0214eac8 + 0x18) = (int)*param_1;
      *(int *)(iVar2 + 0x1c) = (int)param_1[2];
      do {
      } while ((*puVar3 & 0x8000) != 0);
      *(uint *)(iRam0214eac8 + 0x20) =
           *(uint *)(uRam0214ead8 & 0xfffffffc) >> (uRam0214ead8 & 3) * 8 |
           *(uint *)(uRam0214ead8 & 0xfffffffc) << (uRam0214ead8 & 3) * -8 + 0x20;
    }
    puVar4 = puRam0214ead0;
    puVar3 = puRam0214eacc;
    iVar2 = iRam0214eac8;
    sVar1 = param_1[3];
    if (sVar1 == 0) {
      *(undefined4 *)(iRam0214eac8 + 0x24) = 0;
      *(undefined4 *)(iVar2 + 0x28) = 0;
      *(undefined4 *)(iVar2 + 0x2c) = 0;
    }
    else {
      *puRam0214eacc = 0;
      piVar5 = piRam0214ead4;
      *puVar4 = 0x10000000;
      *piVar5 = (int)sVar1;
      piVar5[1] = 0;
      iVar2 = iRam0214eac8;
      *(int *)(iRam0214eac8 + 0x24) = (int)param_1[1];
      *(int *)(iVar2 + 0x28) = (int)param_1[3];
      do {
      } while ((*puVar3 & 0x8000) != 0);
      *(uint *)(iRam0214eac8 + 0x2c) =
           *(uint *)(uRam0214ead8 & 0xfffffffc) >> (uRam0214ead8 & 3) * 8 |
           *(uint *)(uRam0214ead8 & 0xfffffffc) << (uRam0214ead8 & 3) * -8 + 0x20;
    }
    Os_RestoreIrq();
    *(undefined2 *)(iRam0214eac8 + 0x30) = 1;
    return;
  }
  *(undefined2 *)(iRam0214eac8 + 0x30) = 0;
  return;
}

