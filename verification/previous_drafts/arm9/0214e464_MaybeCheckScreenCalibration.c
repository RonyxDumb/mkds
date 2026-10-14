/* Decompiled C draft; module arm9; ROM address 0214e464. No matching claim. */
#include "types.h"
#include "deps/0214e464_MaybeCheckScreenCalibration.h"

undefined4
MaybeCheckScreenCalibration
          (undefined2 *param_1,uint param_2,uint param_3,uint param_4,ushort param_5,ushort param_6,
          ushort param_7,ushort param_8,ushort param_9)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  int *piVar4;
  uint uVar5;
  
  if ((((0xfff < param_2) || (0xfff < param_3)) || (0xfff < param_6)) || (0xfff < param_7)) {
    return 1;
  }
  if (((0xff < param_4) || (0xff < param_8)) || ((0xbf < param_5 || (0xbf < param_9)))) {
    return 1;
  }
  if (((param_4 == param_8) || (param_5 == param_9)) ||
     ((param_2 == param_6 || (param_3 == param_7)))) {
    return 1;
  }
  Os_DisableIrq();
  piVar4 = piRam0214e6c8;
  puVar3 = puRam0214e6c4;
  *puRam0214e6c4 = 0;
  *piVar4 = (param_2 - param_6) * 0x100;
  piVar4 = piRam0214e6cc;
  *piRam0214e6cc = param_4 - param_8;
  piVar4[1] = 0;
  do {
  } while ((*puVar3 & 0x8000) != 0);
  uVar5 = *(uint *)(uRam0214e6d0 & 0xfffffffc) >> (uRam0214e6d0 & 3) * 8 |
          *(uint *)(uRam0214e6d0 & 0xfffffffc) << (uRam0214e6d0 & 3) * -8 + 0x20;
  *puVar3 = 0;
  *piRam0214e6c8 = (param_3 - param_7) * 0x100;
  piVar4 = piRam0214e6cc;
  *piRam0214e6cc = (uint)param_5 - (uint)param_9;
  piVar4[1] = 0;
  if (((int)uVar5 < 0x8000) && (-0x8001 < (int)uVar5)) {
    param_1[2] = (short)uVar5;
    puVar3 = puRam0214e6c4;
    iVar1 = ((param_2 + param_6) * 0x100 - (int)(short)param_1[2] * (param_4 + param_8)) * 0x200;
    iVar2 = iVar1 >> 0x10;
    if ((0x7fff < iVar2) || (iVar2 < -0x8000)) {
      Os_RestoreIrq();
      return 1;
    }
    *param_1 = (short)((uint)iVar1 >> 0x10);
    do {
    } while ((*puVar3 & 0x8000) != 0);
    uVar5 = *(uint *)(uRam0214e6d0 & 0xfffffffc) >> (uRam0214e6d0 & 3) * 8 |
            *(uint *)(uRam0214e6d0 & 0xfffffffc) << (uRam0214e6d0 & 3) * -8 + 0x20;
    Os_RestoreIrq();
    if (((int)uVar5 < 0x8000) && (-0x8001 < (int)uVar5)) {
      param_1[3] = (short)uVar5;
      iVar1 = ((param_3 + param_7) * 0x100 -
              (int)(short)param_1[3] * ((uint)param_5 + (uint)param_9)) * 0x200;
      iVar2 = iVar1 >> 0x10;
      if ((iVar2 < 0x8000) && (-0x8001 < iVar2)) {
        param_1[1] = (short)((uint)iVar1 >> 0x10);
        return 0;
      }
      return 1;
    }
    return 1;
  }
  Os_RestoreIrq();
  return 1;
}

