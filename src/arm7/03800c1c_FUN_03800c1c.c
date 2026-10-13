/* Decompiled C draft; module arm7; ROM address 03800c1c. No matching claim. */
#include "types.h"
#include "deps/03800c1c_FUN_03800c1c.h"

void FUN_03800c1c(void)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  
  uVar2 = DAT_03800e0c;
  iVar7 = DAT_03800e0c + 0x48;
  puVar8 = (uint *)(DAT_03800e0c + 0xfc);
LAB_03800c40:
  bVar1 = false;
  uVar3 = FUN_037faf70();
  do {
    uVar5 = uVar2 + 0xfc & 3;
    uVar4 = *(uint *)(uVar2 + 0xfc & 0xfffffffc);
    if (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 4) == 0) {
      uVar5 = uVar2 + 0xfc & 3;
      uVar4 = *(uint *)(uVar2 + 0xfc & 0xfffffffc);
      if (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0x10) != 0) break;
    }
    else {
      uVar5 = uVar2 + 0xfc & 3;
      uVar4 = *(uint *)(uVar2 + 0xfc & 0xfffffffc);
      if (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 8) != 0) goto LAB_03800ca0;
    }
    *(int *)(uVar2 + 0xec) = iVar7;
    FUN_037f9104(0);
  } while( true );
  *puVar8 = *(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
            *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20 | 4;
  *puVar8 = (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
            *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) & 0xffffffef;
  bVar1 = true;
LAB_03800ca0:
  FUN_037faf84(uVar3);
  if (bVar1) {
    *(undefined4 *)
     (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
     *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) = 0;
    uVar5 = uVar2 + 4 & 3;
    uVar4 = *(uint *)(uVar2 + 4 & 0xfffffffc);
    uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
                    /* WARNING: Could not recover jumptable at 0x03800cc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    if (uVar5 < 0xd) {
      (*(code *)(&UNK_03800cc8 + uVar5 * 4))();
      return;
    }
    *(undefined4 *)
     (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
     *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) = 3;
    do {
      iVar6 = FUN_037fb5f4(0xb,1,1);
    } while (iVar6 < 0);
    uVar3 = FUN_037faf70();
    uVar5 = uVar2 + 0xfc & 3;
    uVar4 = *(uint *)(uVar2 + 0xfc & 0xfffffffc);
    *(uint *)(uVar2 + 0xfc) = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0xffffffb3;
    FUN_037f9088((uint *)(uintptr_t)(uVar2 + 0xf4));
    uVar5 = uVar2 + 0xfc & 3;
    uVar4 = *(uint *)(uVar2 + 0xfc & 0xfffffffc);
    if (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0x10) != 0) {
      FUN_037f9054(iVar7);
    }
    FUN_037faf84(uVar3);
  }
  else {
    uVar5 = uVar2 + 0x44 & 3;
    uVar4 = *(uint *)(uVar2 + 0x44 & 0xfffffffc);
    (*(code *)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20))(uVar2);
  }
  goto LAB_03800c40;
}

