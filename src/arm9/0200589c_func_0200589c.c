/* Decompiled C draft; module arm9; ROM address 0200589c. No matching claim. */
#include "types.h"
#include "deps/0200589c_func_0200589c.h"

undefined4 func_0200589c(int *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  
  uVar5 = 0;
  piVar2 = param_1 + 0x27;
  if (*param_1 != 0) {
    return 0;
  }
  if (*piVar2 == 0) {
    return 0;
  }
  func_020070fc();
  uVar1 = func_02007114();
  switch(*piVar2) {
  case 2:
    Mem_CpuCopy32(piVar2,param_1,0x9c);
    *(undefined1 *)(param_1 + 3) = uVar1;
    uVar5 = func_020070d8();
    uVar3 = func_020070e4();
    uVar5 = func_02006858(param_2,(short)param_1[2],(char)param_1[3],uVar5,uVar3);
    break;
  case 4:
    Mem_CpuCopy32(piVar2,param_1,0x9c);
    *(undefined1 *)(param_1 + 3) = uVar1;
    uVar4 = 0;
    iVar7 = (int)param_1 + DAT_02005a2c;
    piVar6 = param_1;
    do {
      if (((int)(uint)*(ushort *)(param_1 + 2) >> (uVar4 & 0xff) & 1U) != 0) {
        func_0200639c((undefined4 *)(uintptr_t)(iVar7),param_1[6],piVar6[0x17],piVar6[7]);
      }
      iVar7 = iVar7 + 0x68;
      piVar6 = piVar6 + 1;
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < 0x10);
    if (*piVar2 == 4) {
      uVar5 = func_02006794(param_2,(short)param_1[2],(char)param_1[3],param_1[5],0);
    }
    else {
      uVar5 = func_020066c0(param_2,(short)param_1[2],(char)param_1[3],param_1[5],0);
    }
    break;
  case 6:
    Mem_CpuCopy32(piVar2,param_1,0x9c);
    *(undefined1 *)(param_1 + 3) = uVar1;
    uVar4 = 0;
    iVar7 = (int)param_1 + DAT_02005a2c;
    piVar6 = param_1;
    do {
      if (((int)(uint)*(ushort *)(param_1 + 2) >> (uVar4 & 0xff) & 1U) != 0) {
        func_0200639c((undefined4 *)(uintptr_t)(iVar7),param_1[6],iVar7 + 0x1c,piVar6[7]);
      }
      iVar7 = iVar7 + 0x68;
      piVar6 = piVar6 + 1;
      uVar4 = uVar4 + 1;
    } while ((int)uVar4 < 0x10);
    if (*piVar2 == 4) {
      uVar5 = func_02006794(param_2,(short)param_1[2],(char)param_1[3],param_1[5],0);
    }
    else {
      uVar5 = func_020066c0(param_2,(short)param_1[2],(char)param_1[3],param_1[5],0);
    }
    break;
  case 10:
    Mem_CpuCopy32(piVar2,param_1,0x9c);
    *(undefined1 *)(param_1 + 3) = uVar1;
    uVar5 = func_0200654c(param_2,(short)param_1[2],(char)param_1[3],param_1 + 5,
                          *(undefined1 *)((int)param_1 + 0x1d));
  }
  *piVar2 = 0;
  return uVar5;
}

