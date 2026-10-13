/* Decompiled C draft; module arm9; ROM address 02114ad8. No matching claim. */
#include "types.h"
#include "deps/02114ad8_func_02114ad8.h"

void func_02114ad8(void)

{
  undefined2 uVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  ushort *puVar6;
  ushort *puVar7;
  uint uVar8;
  int local_24;
  
  piVar2 = piRam02114c3c;
  *(int *)(*piRam02114c3c + 0x5c) = *(int *)(*piRam02114c3c + 0x5c) + 1;
  uVar3 = ComputeValueInterpolation_from_thumb(1,0,0xffffff00,*(undefined4 *)(*piVar2 + 0x5c),10);
  uVar8 = (uint)*(ushort *)(*(int *)(*piRam02114c3c + 8) + 6);
  uVar4 = (uint)*(ushort *)(*(int *)(*piRam02114c3c + 0x18) + 6);
  iVar5 = func_021143b4();
  piVar2 = piRam02114c3c;
  if (iVar5 != 0) {
    if (*(int *)(*piRam02114c3c + 0x84) != 0) {
      *(undefined4 *)(*piRam02114c3c + 0x68) = uVar3;
      uVar1 = (undefined2)uVar3;
      *(undefined2 *)(*(int *)(*piVar2 + 0x14) + 0x44) = uVar1;
      *(undefined2 *)(*(int *)(*piVar2 + 0x14) + 0x84) = uVar1;
      *(undefined2 *)(*(int *)(*piVar2 + 0x14) + 0xc4) = uVar1;
      *(undefined2 *)(*(int *)(*piVar2 + 0x14) + uVar8 * 0x40 + 4) = uVar1;
      *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar8 + 1) * 0x40 + 4) = uVar1;
      *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar8 + 0xb) * 0x40 + 4) = uVar1;
      *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar8 + 0xc) * 0x40 + 4) = uVar1;
      local_24 = 0;
      puVar7 = puRam02114c40;
      do {
        iVar5 = 0;
        puVar6 = puVar7;
        do {
          *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar8 + *puVar6) * 0x40 + 4) = uVar1;
          puVar6 = puVar6 + 1;
          iVar5 = iVar5 + 1;
        } while (iVar5 < 3);
        puVar7 = puVar7 + 3;
        local_24 = local_24 + 1;
      } while (local_24 < 3);
      *(undefined2 *)(*(int *)(*piVar2 + 0x24) + 0x44) = uVar1;
      *(undefined2 *)(*(int *)(*piVar2 + 0x24) + uVar4 * 0x40 + 4) = uVar1;
      *(undefined2 *)(*(int *)(*piVar2 + 0x24) + (uVar4 + 1) * 0x40 + 4) = uVar1;
      *(undefined2 *)(*(int *)(*piVar2 + 0x24) + (uVar4 + 0xe) * 0x40 + 4) = uVar1;
      piVar2 = piRam02114c3c;
      iVar5 = 0;
      puVar7 = puRam02114c44;
      do {
        *(undefined2 *)(*(int *)(*piVar2 + 0x24) + (uVar4 + *puVar7) * 0x40 + 4) = uVar1;
        puVar7 = puVar7 + 1;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 0xc);
    }
  }
  iVar5 = TextSystem_IsDialogFinished_from_thumb();
  if (iVar5 != 0) {
    uVar4 = func_02116870();
    uVar8 = func_021143b4();
    if (uVar8 <= uVar4) {
      *(short *)(*piRam02114c3c + 0x76) = *(short *)(*piRam02114c3c + 0x76) + -1;
    }
    piVar2 = piRam02114c3c;
    if (*(short *)(*piRam02114c3c + 0x76) < 0) {
      *(undefined4 *)(*piRam02114c3c + 0xa0) = 3;
      func_02111488(*(undefined4 *)(*piVar2 + 0xa0));
      return;
    }
    func_02115ca0();
  }
  return;
}

