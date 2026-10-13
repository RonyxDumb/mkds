/* Decompiled C draft; module arm9; ROM address 02144a50. No matching claim. */
#include "types.h"
#include "deps/02144a50_func_02144a50.h"

void func_02144a50(int param_1)

{
  int iVar1;
  short sVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = param_1 + 0x1cU & 3;
  uVar6 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  if (uVar7 == 0) {
    return;
  }
  if (*(short *)(param_1 + 2) != 0) {
    *(undefined2 *)(uVar7 + 0x81c) = 5;
    return;
  }
  sVar2 = *(short *)(param_1 + 4);
  if (sVar2 == 7) {
    func_02144688(uVar7,0);
    return;
  }
  if (sVar2 != 9) {
    if (sVar2 == 0x15) {
      uVar6 = param_1 + 0xcU & 3;
      uVar5 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
      func_02144814(uVar7,*(undefined2 *)(param_1 + 0x12),
                    uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
      func_02144688(uVar7,0);
      return;
    }
    return;
  }
  uVar3 = *(ushort *)(param_1 + 0x12);
  Os_DisableIrq();
  uVar4 = *(ushort *)(uVar7 + 0x808);
  uVar3 = ~(ushort)(1 << (uVar3 & 0xff));
  iVar1 = (uint)uVar4 * 0x200;
  *(ushort *)(uVar7 + iVar1) = *(ushort *)(uVar7 + iVar1) & uVar3;
  if (*(short *)(uVar7 + 0x818) == 1) {
    uVar6 = ((uVar4 + 1 & 3) << 0x10) >> 7;
    *(ushort *)(uVar7 + uVar6) = *(ushort *)(uVar7 + uVar6) & uVar3;
  }
  Os_RestoreIrq();
  func_02144688(uVar7,0);
  if (*(short *)(uVar7 + 0x818) == 1) {
    func_02144688(uVar7,0);
    return;
  }
  return;
}

