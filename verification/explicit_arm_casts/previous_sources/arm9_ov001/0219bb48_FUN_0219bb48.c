/* Decompiled C draft; module arm9_ov001; ROM address 0219bb48. No matching claim. */
#include "types.h"
#include "deps/0219bb48_FUN_0219bb48.h"

void FUN_0219bb48(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  ushort *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  undefined2 *local_18;
  
  *DAT_0219be2c = *DAT_0219be2c & 0xfffc;
  puVar1 = DAT_0219be30;
  *DAT_0219be30 = *DAT_0219be30 & 0xfffc | 1;
  *puVar1 = *puVar1 & 0x43 | (ushort)DAT_0219be34;
  uVar3 = func_0x02036948();
  iVar4 = func_0x02036bec(uVar3,0x70);
  piVar2 = DAT_0219be38;
  *DAT_0219be38 = iVar4;
  *(undefined4 *)(iVar4 + 0x44) = uVar3;
  *(undefined4 *)(*piVar2 + 0x48) = 0;
  *(undefined4 *)(*piVar2 + 0x60) = 0;
  *(undefined4 *)(*piVar2 + 100) = param_2;
  *(undefined4 *)(*piVar2 + 0x68) = param_3;
  *(undefined4 *)(*piVar2 + 0x6c) = 0;
  FUN_0219c544();
  func_0x02117224(*(undefined4 *)(*DAT_0219be38 + 0x44));
  iVar4 = *DAT_0219be38;
  func_0x02124ed0(*(undefined4 *)(iVar4 + 0x44),*(undefined4 *)(iVar4 + 4),
                  *(undefined4 *)(iVar4 + 8),iVar4 + 0x30);
  iVar4 = *DAT_0219be38;
  func_0x02124ed0(*(undefined4 *)(iVar4 + 0x44),*(undefined4 *)(iVar4 + 0x10),
                  *(undefined4 *)(iVar4 + 0x18),iVar4 + 0x34);
  uVar3 = func_0x02047a28(DAT_0219be3c);
  *(undefined4 *)(*DAT_0219be38 + 0x38) = uVar3;
  uVar3 = func_0x0204799c(DAT_0219be40);
  piVar2 = DAT_0219be38;
  *(undefined4 *)(*DAT_0219be38 + 0x3c) = uVar3;
  iVar4 = DAT_0219be44;
  puVar7 = (undefined4 *)*piVar2;
  iVar5 = func_0x021243ac(puVar7[0x11],0,puVar7[2],0xb4,0xd,0,*puVar7,puVar7[1],puVar7[0xc],
                          DAT_0219be44);
  puVar7 = (undefined4 *)*DAT_0219be38;
  iVar6 = func_0x021243ac(puVar7[0x11],1,puVar7[2],0xb4,0xd,1,*puVar7,puVar7[1],puVar7[0xc],
                          iVar4 - iVar5);
  iVar6 = (iVar4 - iVar5) - iVar6;
  puVar7 = (undefined4 *)*DAT_0219be38;
  iVar4 = func_0x021243ac(puVar7[0x11],2,puVar7[2],0x96,0xd,2,*puVar7,puVar7[1],puVar7[0xc],iVar6);
  iVar6 = iVar6 - iVar4;
  puVar7 = (undefined4 *)*DAT_0219be38;
  iVar4 = func_0x021243ac(puVar7[0x11],3,puVar7[2],0x50,0xd,3,*puVar7,puVar7[1],puVar7[0xc],iVar6);
  iVar6 = iVar6 - iVar4;
  puVar7 = (undefined4 *)*DAT_0219be38;
  iVar4 = func_0x021243ac(puVar7[0x11],4,puVar7[2],0x96,0xd,4,*puVar7,puVar7[1],puVar7[0xc],iVar6);
  puVar7 = (undefined4 *)*DAT_0219be38;
  func_0x021243ac(puVar7[0x11],5,puVar7[2],0x50,0xd,5,*puVar7,puVar7[1],puVar7[0xc],iVar6 - iVar4);
  iVar4 = func_0x02148ca0();
  iVar5 = 0;
  local_18 = DAT_0219be50;
  puVar8 = DAT_0219be48;
  puVar9 = DAT_0219be4c;
  do {
    iVar6 = *DAT_0219be38;
    iVar6 = func_0x021243ac(*(undefined4 *)(iVar6 + 0x44),*local_18,*(undefined4 *)(iVar6 + 0x18),
                            *puVar9,*puVar8,iVar5,*(undefined4 *)(iVar6 + 0xc),
                            *(undefined4 *)(iVar6 + 0x10),*(undefined4 *)(iVar6 + 0x34),iVar4);
    iVar4 = iVar4 - iVar6;
    puVar8 = puVar8 + 1;
    puVar9 = puVar9 + 1;
    local_18 = local_18 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 5);
  iVar5 = *DAT_0219be38;
  func_0x021243ac(*(undefined4 *)(iVar5 + 0x44),5,*(undefined4 *)(iVar5 + 0x18),0x32,0xd,0xb,
                  *(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(iVar5 + 0x10),
                  *(undefined4 *)(iVar5 + 0x34),iVar4);
  iVar4 = *DAT_0219be38;
  uVar3 = func_0x020b3f7c(*(undefined4 *)(iVar4 + 0x3c),8);
  func_0x0212426c(1,*DAT_0219be50,*(undefined4 *)(*DAT_0219be38 + 0x18),uVar3,
                  *(undefined4 *)(iVar4 + 0x10),*(undefined4 *)(iVar4 + 0x34));
  iVar4 = *DAT_0219be38;
  uVar3 = func_0x020b3f7c(*(undefined4 *)(iVar4 + 0x3c),9);
  func_0x0212426c(1,DAT_0219be50[3],*(undefined4 *)(*DAT_0219be38 + 0x18),uVar3,
                  *(undefined4 *)(iVar4 + 0x10),*(undefined4 *)(iVar4 + 0x34));
  iVar4 = *DAT_0219be38;
  uVar3 = func_0x020b3f7c(*(undefined4 *)(iVar4 + 0x3c),*DAT_0219be54);
  func_0x0212426c(1,DAT_0219be50[4],*(undefined4 *)(*DAT_0219be38 + 0x18),uVar3,
                  *(undefined4 *)(iVar4 + 0x10),*(undefined4 *)(iVar4 + 0x34));
  iVar4 = *DAT_0219be38;
  uVar3 = func_0x020b3f7c(*(undefined4 *)(iVar4 + 0x38),4);
  func_0x0212426c(1,5,*(undefined4 *)(*DAT_0219be38 + 0x18),uVar3,*(undefined4 *)(iVar4 + 0x10),
                  *(undefined4 *)(iVar4 + 0x34));
  func_0x0211de40(*(undefined4 *)(*DAT_0219be38 + 0x44));
  func_0x0211df44(*(undefined4 *)(*DAT_0219be38 + 0x44));
  func_0x0212b928(*(undefined4 *)(*DAT_0219be38 + 0x44),*(undefined4 *)(*DAT_0219be38 + 0x1c),4);
  func_0x0212b7fc();
  FUN_0219be5c();
  FUN_0219c480();
  iVar4 = 3;
  puVar7 = DAT_0219be58;
  do {
    iVar5 = func_0x0211e160(*puVar7);
    if (iVar5 != 0) {
      *(int *)(*DAT_0219be38 + 0x60) = iVar4;
      break;
    }
    puVar7 = puVar7 + -1;
    iVar4 = iVar4 + -1;
  } while (-1 < iVar4);
  FUN_0219c0bc();
  func_0x02036820(*(undefined4 *)(*DAT_0219be38 + 0x44));
  return;
}

