/* Decompiled C draft; module arm9_ov003; ROM address 021b929c. No matching claim. */
#include "types.h"
#include "deps/021b929c_func_ov003_021b929c.h"

undefined4 func_ov003_021b929c(ushort *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar3 = iRam021b9498;
  iVar2 = iRam021b9494;
  iVar1 = iRam021b9490;
  iVar6 = iRam021b948c;
  iVar7 = (int)param_1 + iRam021b9488;
  if (iVar7 == 0) {
    return 0xffffffff;
  }
  *param_1 = (ushort)*(undefined4 *)(iRam021b949c + 8) & (ushort)*(undefined4 *)(iRam021b949c + 0xc)
  ;
  func_ov003_021b7d84(iVar7,0,uRam021b94a0);
  if ((*param_1 & 1) != 0) {
    func_ov003_021b7d90(iVar7,iVar6 + 0x30,*(undefined4 *)(iVar6 + 4));
    func_ov003_021b7d90(iVar7 + 6,iVar6 + 0x70,*(undefined4 *)(iVar6 + 4));
    func_ov003_021b7d90(iVar7 + 0xc,iVar6 + 0xb0,*(undefined4 *)(iVar6 + 4));
    func_ov003_021b7d90(iVar7 + 0x12,iVar6 + 0xf0,*(undefined4 *)(iVar6 + 4));
    uVar4 = func_ov003_021b7c30((char *)(uintptr_t)(iVar6 + 8));
    iVar5 = func_ov003_021b9278((byte *)(uintptr_t)(iVar6 + 8),uVar4);
    if (iVar5 != 0) goto LAB_021b9472;
    uVar4 = func_ov003_021b7c30((char *)(uintptr_t)(iVar6 + 8));
    func_ov003_021b7d90(iVar7 + 0x18,iVar6 + 8,uVar4);
  }
  if ((*param_1 & 2) != 0) {
    func_ov003_021b7d90(iVar7 + 0x39,iVar1 + 0x30,*(undefined4 *)(iVar1 + 4));
    func_ov003_021b7d90(iVar7 + 0x47,iVar1 + 0x70,*(undefined4 *)(iVar1 + 4));
    func_ov003_021b7d90(iVar7 + 0x55,iVar1 + 0xb0,*(undefined4 *)(iVar1 + 4));
    func_ov003_021b7d90(iVar7 + 99,iVar1 + 0xf0,*(undefined4 *)(iVar1 + 4));
    uVar4 = func_ov003_021b7c30((char *)(uintptr_t)(iVar1 + 8));
    iVar6 = func_ov003_021b9278((byte *)(uintptr_t)(iVar1 + 8),uVar4);
    if (iVar6 != 0) goto LAB_021b9472;
    uVar4 = func_ov003_021b7c30((char *)(uintptr_t)(iVar1 + 8));
    func_ov003_021b7d90(iVar7 + 0x71,iVar1 + 8,uVar4);
  }
  if ((*param_1 & 4) != 0) {
    iVar6 = func_ov003_021b9278((byte *)(uintptr_t)(iVar2 + 0x30),*(int *)(iVar2 + 4) + -1);
    if (iVar6 != 0) goto LAB_021b9472;
    func_ov003_021b7d90(iVar7 + 0x92,iVar2 + 0x30,*(undefined4 *)(iVar2 + 4));
    uVar4 = func_ov003_021b7c30(iVar2 + 8);
    iVar6 = func_ov003_021b9278(iVar2 + 8,uVar4);
    if (iVar6 != 0) goto LAB_021b9472;
    uVar4 = func_ov003_021b7c30(iVar2 + 8);
    func_ov003_021b7d90(iVar7 + 0xd2,iVar2 + 8,uVar4);
  }
  if ((*param_1 & 8) == 0) {
LAB_021b9464:
    *(undefined1 *)((int)param_1 + iRam021b94a8) = 0;
    return 0;
  }
  iVar6 = func_ov003_021b9278(iVar3 + 0x30,*(int *)(iVar3 + 4) + -1);
  if (iVar6 == 0) {
    func_ov003_021b7d90(iVar7 + 0xf3,iVar3 + 0x30,*(undefined4 *)(iVar3 + 4));
    uVar4 = func_ov003_021b7c30(iVar3 + 8);
    iVar6 = func_ov003_021b9278(iVar3 + 8,uVar4);
    if (iVar6 == 0) {
      uVar4 = func_ov003_021b7c30(iVar3 + 8);
      func_ov003_021b7d90(iVar7 + iRam021b94a4,iVar3 + 8,uVar4);
      goto LAB_021b9464;
    }
  }
LAB_021b9472:
  func_ov003_021b7d84(iVar7,0,uRam021b94a0);
  return 0xffffffff;
}

