/* Decompiled C draft; module arm9_ov001; ROM address 0218efc4. No matching claim. */
#include "types.h"
#include "deps/0218efc4_FUN_0218efc4.h"

undefined4 FUN_0218efc4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = func_0x0207a974((short)*(char *)(*DAT_0218f140 + 0x62));
  if ((*(uint *)(iVar1 + 0x48) & DAT_0218f144) == 0) {
    FUN_02188998(param_1,(undefined4 *)(uintptr_t)(iVar1 + 0x80));
    FUN_02188d8c(param_1,(undefined4 *)(uintptr_t)(iVar1 + 0x80));
  }
  FUN_0218f724(param_1);
  iVar1 = FUN_02188104(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xb8),0);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + DAT_0218f148) = *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xc0);
  }
  else {
    *(undefined4 *)(param_1 + DAT_0218f148) = 0;
  }
  *(undefined4 *)(param_1 + DAT_0218f14c) = *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x9c);
  if (*(int *)(*DAT_0218f140 + 8) == 4) {
    iVar1 = func_ov001_02181838();
  }
  else {
    iVar1 = 0;
  }
  if (*(int *)(*(int *)(param_1 + 0xa0) + DAT_0218f150) - iVar1 < 1) {
    if (*(int *)(*DAT_0218f140 + 8) == 4) {
      iVar1 = func_ov001_02181838();
    }
    else {
      iVar1 = 0;
    }
    iVar3 = *(int *)(param_1 + 0xa0);
    uVar2 = func_0x02132440((*(int *)(iVar3 + DAT_0218f150) - iVar1) * 0x1000);
    func_0x021329f8(uVar2,DAT_0218f154);
  }
  else {
    if (*(int *)(*DAT_0218f140 + 8) == 4) {
      iVar1 = func_ov001_02181838();
    }
    else {
      iVar1 = 0;
    }
    iVar3 = *(int *)(param_1 + 0xa0);
    uVar2 = func_0x02132440((*(int *)(iVar3 + DAT_0218f150) - iVar1) * 0x1000);
    func_0x02131234(DAT_0218f154,uVar2);
  }
  uVar2 = func_0x021322c8();
  uVar2 = func_0x02133068(uVar2,*(undefined4 *)(iVar3 + DAT_0218f158));
  *(undefined4 *)(param_1 + DAT_0218f15c) = uVar2;
  if (*(int *)(*DAT_0218f140 + 8) == 4) {
    iVar1 = func_ov001_02181838();
  }
  else {
    iVar1 = 0;
  }
  if ((*(int *)(*(int *)(param_1 + 0xa0) + DAT_0218f160) < iVar1) ||
     (iVar1 = FUN_02188000(param_1,0,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0xbc)), iVar1 == 0))
  {
    if (*(int *)(*DAT_0218f140 + 8) == 4) {
      iVar1 = func_ov001_02181838();
    }
    else {
      iVar1 = 0;
    }
    if (*(int *)(*(int *)(param_1 + 0xa0) + DAT_0218f150) < iVar1) {
      FUN_02188e88(param_1);
    }
  }
  else {
    FUN_02188200(param_1,DAT_0218f164);
    *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *DAT_0218f168;
    FUN_0218f16c(param_1);
  }
  return 0;
}

