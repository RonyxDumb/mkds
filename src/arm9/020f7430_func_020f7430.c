/* Decompiled C draft; module arm9; ROM address 020f7430. No matching claim. */
#include "types.h"
#include "deps/020f7430_func_020f7430.h"

/* WARNING: Removing unreachable block (ram,0x020f744c) */
/* WARNING: Removing unreachable block (ram,0x020f7454) */
/* WARNING: Removing unreachable block (ram,0x020f745c) */
/* WARNING: Removing unreachable block (ram,0x020f7464) */
/* WARNING: Removing unreachable block (ram,0x020f7470) */

void func_020f7430(int param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if ((uVar3 & 0x8000000) == 0) {
    if ((uVar3 & 0x180000) == 0) {
      *(undefined4 *)(param_1 + 0x120) = uRam020f7584;
      uVar3 = param_1 + 0x74U & 3;
      uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
      *(uint *)(param_1 + 0x74) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20 | uRam020f7588;
      return;
    }
    return;
  }
  if ((((uVar3 & 0x8000000) == 0) || ((uVar3 & 0x10000000) != 0)) || ((uVar3 & 0x20000000) != 0)) {
    if ((uVar3 & 0x180000) == 0) {
      bVar1 = true;
      *(undefined4 *)(param_1 + 0x120) = uRam020f7584;
      uVar3 = param_1 + 0x74U & 3;
      uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
      *(uint *)(param_1 + 0x74) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20 | uRam020f7588;
    }
    else {
      bVar1 = false;
    }
  }
  else if ((*(ushort *)(param_1 + 0x78) & 0xf00) == 0) {
    bVar1 = true;
    *(ushort *)(param_1 + 0x78) = *(ushort *)(param_1 + 0x78) | *puRam020f7580;
    *(undefined4 *)(param_1 + 0x120) = 0;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    if (param_2 != 0) {
      uVar3 = param_1 + 0x44U & 3;
      uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
      func_020fe7a0(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20,5,8,
                    (int)*(short *)(param_1 + 0x4e));
      return;
    }
    return;
  }
  return;
}

