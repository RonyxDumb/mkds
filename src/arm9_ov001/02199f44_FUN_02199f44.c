/* Decompiled C draft; module arm9_ov001; ROM address 02199f44. No matching claim. */
#include "types.h"
#include "deps/02199f44_FUN_02199f44.h"

void FUN_02199f44(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  undefined1 *puVar7;
  int iVar8;
  
  iVar2 = func_0x02036bec(param_1,0x34);
  piVar1 = DAT_0219a040;
  *DAT_0219a040 = iVar2;
  *(undefined4 *)(iVar2 + 0x18) = param_1;
  *(undefined4 *)*piVar1 = 0;
  *(undefined4 *)(*piVar1 + 4) = 0;
  uVar3 = FUN_02192e94();
  switch(uVar3) {
  case 0:
  case 5:
    *(undefined4 *)(*DAT_0219a040 + 8) = 0;
    break;
  case 3:
  case 6:
    *(undefined4 *)(*DAT_0219a040 + 8) = 1;
  }
  piVar1 = DAT_0219a040;
  *(undefined4 *)(*DAT_0219a040 + 0xc) = 0;
  *(undefined4 *)(*piVar1 + 0x14) = 1;
  FUN_02199e3c();
  piVar1 = DAT_0219a040;
  iVar2 = 0;
  puVar7 = DAT_0219a044;
  do {
    func_0x02124a98(*puVar7,1,*(undefined4 *)(*piVar1 + 0x20),*(undefined4 *)(*piVar1 + 0x2c));
    puVar7 = puVar7 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  uVar3 = FUN_0219e920();
  uVar4 = FUN_0219e90c();
  func_0x020ae6d4(uVar3,uVar4);
  func_0x02124ed0(param_1,*(undefined4 *)(*DAT_0219a040 + 0x2c),0,(undefined4 *)(uintptr_t)(*DAT_0219a040 + 0x1c));
  piVar1 = DAT_0219a040;
  iVar5 = 0;
  piVar6 = DAT_0219a04c;
  iVar2 = DAT_0219a048;
  do {
    iVar8 = 0;
    if (0 < *piVar6) {
      do {
        if (iVar5 == 1) {
          *(undefined2 *)(*(int *)(*piVar1 + 0x1c) + (uint)*(byte *)(iVar2 + iVar8) * 0x40 + 4) =
               0xfa;
        }
        else {
          *(undefined2 *)(*(int *)(*piVar1 + 0x1c) + (uint)*(byte *)(iVar2 + iVar8) * 0x40 + 4) =
               0xff06;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < *piVar6);
    }
    iVar2 = iVar2 + 4;
    piVar6 = piVar6 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  func_0x021281c8(0xe);
  return;
}

