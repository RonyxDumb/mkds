/* Decompiled C draft; module arm9; ROM address 0206fe08. No matching claim. */
#include "types.h"
#include "deps/0206fe08_func_0206fe08.h"

/* WARNING: Removing unreachable block (ram,0x0206ff04) */
/* WARNING: Removing unreachable block (ram,0x0206ff00) */
/* WARNING: Removing unreachable block (ram,0x0206ff08) */

void func_0206fe08(int param_1)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 local_20;
  int local_1c;
  undefined4 uStack_18;
  
  uVar7 = param_1 + 0x84U & 3;
  uVar2 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  iVar3 = func_020d3d48(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
  if ((-1 < iVar3) ||
     (uVar7 = param_1 + 0x4cU & 3, uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc),
     ((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 0x4000000) != 0)) {
    *(undefined4 *)(param_1 + 0x500) = 0;
    func_020838dc(param_1);
    return;
  }
  uVar7 = param_1 + 0x3f4U & 3;
  uVar6 = *(uint *)(param_1 + 0x3f4U & 0xfffffffc);
  uVar2 = param_1 + 0xc4U & 3;
  uVar4 = *(uint *)(param_1 + 0xc4U & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) *
          (longlong)(int)(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
  lVar1 = (longlong)(int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14) *
          (longlong)iVar3;
  *(uint *)(param_1 + 0xdc) =
       ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14) + 0x1000;
  uVar7 = param_1 + 0x2ccU & 3;
  uVar4 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
  uVar2 = param_1 + 0xdcU & 3;
  uVar6 = *(uint *)(param_1 + 0xdcU & 0xfffffffc);
  uVar7 = (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 0x78;
  uVar4 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20;
  if ((int)(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) < (int)uVar7) {
    *(uint *)(param_1 + 0xdc) = uVar7;
  }
  func_0207a6c0(param_1);
  *(int *)(param_1 + 0x500) = -iVar3;
  uVar7 = param_1 + 0x84U & 3;
  uVar2 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  iVar5 = func_020d3d48(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20);
  if (((iVar5 < -0x9fff) &&
      (uVar7 = param_1 + 0x90U & 3, uVar2 = *(uint *)(param_1 + 0x90U & 0xfffffffc),
      iVar5 = func_020d3d48(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20), -0xa000 < iVar5)) &&
     (uVar7 = param_1 + 0xa8U & 3, uVar2 = *(uint *)(param_1 + 0xa8U & 0xfffffffc),
     (int)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) < -0x2000)) {
    local_20 = *(undefined4 *)(param_1 + 0x80);
    uStack_18 = *(undefined4 *)(param_1 + 0x88);
    uVar7 = param_1 + 0x84U & 3;
    uVar2 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
    local_1c = (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) - iVar3;
    uVar7 = param_1 + 0x7cU & 3;
    uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    func_0208d978(&local_20,((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 1) != 0);
  }
  uVar7 = param_1 + 0x4cU & 3;
  uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 0x4000000) == 0) {
    func_02083ec4(param_1);
    return;
  }
  return;
}

