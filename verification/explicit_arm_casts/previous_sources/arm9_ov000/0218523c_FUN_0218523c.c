/* Decompiled C draft; module arm9_ov000; ROM address 0218523c. No matching claim. */
#include "types.h"
#include "deps/0218523c_FUN_0218523c.h"

void FUN_0218523c(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  
  iVar2 = func_0x02036bec(param_1,0x40);
  piVar1 = DAT_0218532c;
  *DAT_0218532c = iVar2;
  *(undefined4 *)(iVar2 + 0x18) = param_1;
  *(undefined4 *)*piVar1 = 0;
  *(undefined4 *)(*piVar1 + 4) = 0;
  *(undefined4 *)(*piVar1 + 0x10) = 0xffffffff;
  iVar2 = func_ov000_021806d4();
  if (iVar2 != 1) {
    if (iVar2 == 9) {
      *(undefined4 *)(*DAT_0218532c + 8) = 1;
      goto LAB_02185282;
    }
    if (iVar2 != 0xb) goto LAB_02185282;
  }
  *(undefined4 *)(*DAT_0218532c + 8) = 0;
LAB_02185282:
  piVar1 = DAT_0218532c;
  *(undefined4 *)(*DAT_0218532c + 0xc) = 0;
  *(undefined4 *)(*piVar1 + 0x14) = 1;
  FUN_021851a0();
  piVar1 = DAT_0218532c;
  iVar2 = 0;
  puVar6 = DAT_02185330;
  do {
    func_0x02124a98(*puVar6,1,*(undefined4 *)(*piVar1 + 0x20),*(undefined4 *)(*piVar1 + 0x2c));
    puVar6 = puVar6 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  uVar3 = func_ov000_021804f4();
  uVar4 = func_ov000_021804e0();
  func_0x020ae6d4(uVar3,uVar4);
  func_0x02124ed0(param_1,*(undefined4 *)(*DAT_0218532c + 0x2c),0,*DAT_0218532c + 0x1c);
  uVar3 = func_0x0204799c(DAT_02185334);
  *(undefined4 *)(*DAT_0218532c + 0x38) = uVar3;
  uVar3 = func_0x02047a28(DAT_02185338);
  piVar1 = DAT_0218532c;
  *(undefined4 *)(*DAT_0218532c + 0x3c) = uVar3;
  iVar8 = 0;
  piVar5 = DAT_02185340;
  iVar2 = DAT_0218533c;
  do {
    iVar7 = 0;
    if (0 < *piVar5) {
      do {
        *(undefined2 *)(*(int *)(*piVar1 + 0x1c) + (uint)*(byte *)(iVar2 + iVar7) * 0x40 + 4) = 0xfa
        ;
        iVar7 = iVar7 + 1;
      } while (iVar7 < *piVar5);
    }
    iVar2 = iVar2 + 4;
    piVar5 = piVar5 + 1;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 2);
  func_0x021281c8(0xe);
  return;
}

