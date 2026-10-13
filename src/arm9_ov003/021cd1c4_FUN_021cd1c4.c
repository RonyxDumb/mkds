/* Decompiled C draft; module arm9_ov003; ROM address 021cd1c4. No matching claim. */
#include "types.h"
#include "deps/021cd1c4_FUN_021cd1c4.h"

undefined4 FUN_021cd1c4(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  func_0x0214cfe4(0,*DAT_021cd258 + DAT_021cd25c,DAT_021cd260);
  iVar2 = func_0x02143e10(*DAT_021cd258,DAT_021cd264,3);
  if (iVar2 != 2) {
    return 0;
  }
  do {
    func_0x02143520(*DAT_021cd258 + DAT_021cd268);
    iVar2 = *DAT_021cd258;
  } while (*(short *)(iVar2 + DAT_021cd268) != 2);
  puVar6 = (undefined4 *)(iVar2 + DAT_021cd270);
  iVar5 = 8;
  puVar7 = DAT_021cd26c;
  do {
    uVar3 = *puVar7;
    uVar4 = puVar7[1];
    puVar7 = puVar7 + 2;
    *puVar6 = uVar3;
    puVar6[1] = uVar4;
    puVar6 = puVar6 + 2;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *puVar6 = *puVar7;
  *(int *)(iVar2 + DAT_021cd270) = iVar2 + DAT_021cd274;
  uVar1 = func_0x02143090();
  *(undefined2 *)(*DAT_021cd258 + DAT_021cd278) = uVar1;
  iVar2 = FUN_021cd190();
  if (iVar2 != 0) {
    return 1;
  }
  return 0;
}

