/* Decompiled C draft; module arm9_ov001; ROM address 021935f8. No matching claim. */
#include "types.h"
#include "deps/021935f8_FUN_021935f8.h"

void FUN_021935f8(void)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined *puVar7;
  int iVar8;
  
  iVar2 = FUN_02192e84();
  if ((iVar2 == -1) && (*(int *)(*(int *)PTR_data_ov001_02193724 + 0x10) == 4)) {
    FUN_02192e78(0);
  }
  puVar7 = PTR_data_ov001_02193724;
  *(int *)(*(int *)PTR_data_ov001_02193724 + 0xc) =
       *(int *)(*(int *)PTR_data_ov001_02193724 + 0xc) + 1;
  if (*(int *)(*(int *)puVar7 + 0xc) < 0xb) {
    sVar1 = func_0x020ae4c0(1,0,0xfa,*(int *)(*(int *)puVar7 + 0xc),10);
  }
  else {
    sVar1 = 0xfa;
  }
  iVar2 = 0;
  piVar6 = (int *)PTR_data_ov001_0219372c;
  puVar7 = PTR_data_ov001_02193728;
  do {
    iVar8 = 0;
    if (0 < *piVar6) {
      do {
        if (iVar2 == 1) {
          *(short *)(*(int *)(*(int *)PTR_data_ov001_02193724 + 0x20) +
                     (uint)(byte)puVar7[iVar8] * 0x40 + 4) = sVar1;
        }
        else {
          *(short *)(*(int *)(*(int *)PTR_data_ov001_02193724 + 0x20) +
                     (uint)(byte)puVar7[iVar8] * 0x40 + 4) = -sVar1;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < *piVar6);
    }
    puVar7 = puVar7 + 4;
    piVar6 = piVar6 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  if (*(int *)(*(int *)PTR_data_ov001_02193724 + 0x10) == 1) {
    uVar3 = func_0x020ae4c0(1,0,0x32,*(undefined4 *)(*(int *)PTR_data_ov001_02193724 + 0xc),10);
    *(undefined4 *)(*(int *)PTR_data_ov001_02193724 + 0x18) = uVar3;
  }
  if ((9 < *(int *)(*(int *)PTR_data_ov001_02193724 + 0xc)) &&
     (((*(int *)(*(int *)PTR_data_ov001_02193724 + 8) != 2 ||
       (iVar2 = func_0x02128274(), iVar2 != 0)) &&
      (iVar2 = FUN_02192e84(), puVar7 = PTR_data_ov001_02193724, iVar2 == -1)))) {
    iVar2 = *(int *)PTR_data_ov001_02193724;
    if (*(int *)(iVar2 + 8) == 2) {
      *(undefined4 *)(iVar2 + 4) = 6;
      *(undefined4 *)(*(int *)puVar7 + 0xc) = 0;
      uVar3 = func_0x020b3f7c(*(undefined4 *)(*(int *)puVar7 + 0x38),3);
      uVar4 = func_0x020b3f7c(*(undefined4 *)(*(int *)PTR_data_ov001_02193724 + 0x3c),0);
      uVar5 = func_0x020b3f7c(*(undefined4 *)(*(int *)PTR_data_ov001_02193724 + 0x3c),1);
      func_0x0212611c(uVar3,uVar4,uVar5,1);
      return;
    }
    FUN_02192ea0(*(undefined4 *)(iVar2 + 0x10));
  }
  return;
}

