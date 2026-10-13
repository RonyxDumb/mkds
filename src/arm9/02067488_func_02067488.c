/* Decompiled C draft; module arm9; ROM address 02067488. No matching claim. */
#include "types.h"
#include "deps/02067488_func_02067488.h"

void func_02067488(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar4;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  uint uVar3;
  
  uVar3 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if ((uVar3 & 2) == 0) {
    return;
  }
  if ((uVar3 & 0x200000) != 0) {
    return;
  }
  iVar1 = IsAwardOrStaffRoll();
  if (iVar1 != 1) {
    return;
  }
  uVar3 = *(uint *)(uRam020675a8 & 0xfffffffc) >> (uRam020675a8 & 3) * 8 |
          *(uint *)(uRam020675a8 & 0xfffffffc) << (uRam020675a8 & 3) * -8 + 0x20;
  if ((*(short *)(uVar3 + 0x70) == 0) && (*(short *)(uVar3 + 0x90) == 0)) {
    return;
  }
  uVar3 = param_1 + 0x310U & 3;
  uVar2 = *(uint *)(param_1 + 0x310U & 0xfffffffc);
  func_0208c218(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
  uVar3 = func_02061f90();
  if (*(ushort *)(param_1 + 0x74) != uVar3) {
    return;
  }
  uVar4 = *(uint *)(uRam020675ac & 0xfffffffc) >> (uRam020675ac & 3) * 8 |
          *(uint *)(uRam020675ac & 0xfffffffc) << (uRam020675ac & 3) * -8 + 0x20;
  uVar3 = uVar4 + 8;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (uVar3 >> uVar2 * 8 == 0 && uVar3 << uVar2 * -8 + 0x20 == 0) {
    iVar1 = GetDriverEntry((int)*(char *)(uVar4 + 0x62));
    VecFx32_Subtract(param_1 + 0x80,iVar1 + 0x80,&iStack_18);
    if (iRam020675b0 <
        (iStack_10 >> 0xc) * (iStack_10 >> 0xc) +
        (iStack_18 >> 0xc) * (iStack_18 >> 0xc) + (iStack_14 >> 0xc) * (iStack_14 >> 0xc)) {
      uVar3 = param_1 + 0x48U & 3;
      uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
      *(uint *)(param_1 + 0x48) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20 | 0x8000000;
    }
    else {
      uVar3 = param_1 + 0x48U & 3;
      uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
      *(uint *)(param_1 + 0x48) = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) & 0xf7ffffff;
    }
    return;
  }
  return;
}

