/* Decompiled C draft; module arm9_ov001; ROM address 02193b28. No matching claim. */
#include "types.h"
#include "deps/02193b28_FUN_02193b28.h"

void FUN_02193b28(undefined4 param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined *puVar6;
  int iVar7;
  
  iVar2 = func_0x02036bec(param_1,0x40);
  puVar1 = PTR_data_ov001_02193c44;
  *(int *)PTR_data_ov001_02193c44 = iVar2;
  *(undefined4 *)(iVar2 + 0x1c) = param_1;
  **(undefined4 **)puVar1 = 0;
  *(undefined4 *)(*(int *)puVar1 + 4) = 0;
  iVar2 = FUN_02192e94();
  if (iVar2 != 1) {
    if (iVar2 == 2) {
      *(undefined4 *)(*(int *)PTR_data_ov001_02193c44 + 8) = 1;
      goto LAB_02193b68;
    }
    if (iVar2 != 4) goto LAB_02193b68;
  }
  *(undefined4 *)(*(int *)PTR_data_ov001_02193c44 + 8) = 0;
LAB_02193b68:
  puVar1 = PTR_data_ov001_02193c44;
  *(undefined4 *)(*(int *)PTR_data_ov001_02193c44 + 0xc) = 0;
  *(undefined4 *)(*(int *)puVar1 + 0x14) = 1;
  uVar3 = func_0x0204799c(PTR_data_ov001_02193c48);
  *(undefined4 *)(*(int *)PTR_data_ov001_02193c44 + 0x38) = uVar3;
  uVar3 = func_0x02047a28(PTR_data_ov001_02193c4c);
  *(undefined4 *)(*(int *)PTR_data_ov001_02193c44 + 0x3c) = uVar3;
  iVar2 = FUN_02192e94();
  if (iVar2 == 1) {
    *(undefined4 *)(*(int *)PTR_data_ov001_02193c44 + 0x18) = 0x32;
  }
  else {
    *(undefined4 *)(*(int *)PTR_data_ov001_02193c44 + 0x18) = 0;
  }
  FUN_02193a20();
  puVar1 = PTR_data_ov001_02193c44;
  iVar2 = 0;
  puVar6 = PTR_data_ov001_02193c50;
  do {
    func_0x02124a98(*puVar6,1,*(undefined4 *)(*(int *)puVar1 + 0x24),
                    *(undefined4 *)(*(int *)puVar1 + 0x30));
    puVar6 = puVar6 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  uVar3 = FUN_0219e920();
  uVar4 = FUN_0219e90c();
  func_0x020ae6d4(uVar3,uVar4);
  func_0x02124ed0(param_1,*(undefined4 *)(*(int *)PTR_data_ov001_02193c44 + 0x30),0,
                  *(int *)PTR_data_ov001_02193c44 + 0x20);
  puVar1 = PTR_data_ov001_02193c44;
  iVar2 = 0;
  piVar5 = (int *)PTR_data_ov001_02193c58;
  puVar6 = PTR_data_ov001_02193c54;
  do {
    iVar7 = 0;
    if (0 < *piVar5) {
      do {
        if (iVar2 == 1) {
          *(undefined2 *)(*(int *)(*(int *)puVar1 + 0x20) + (uint)(byte)puVar6[iVar7] * 0x40 + 4) =
               0xfa;
        }
        else {
          *(undefined2 *)(*(int *)(*(int *)puVar1 + 0x20) + (uint)(byte)puVar6[iVar7] * 0x40 + 4) =
               0xff06;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < *piVar5);
    }
    puVar6 = puVar6 + 4;
    piVar5 = piVar5 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  func_0x021281c8(0xf);
  return;
}

