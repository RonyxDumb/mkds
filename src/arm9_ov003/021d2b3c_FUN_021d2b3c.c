/* Decompiled C draft; module arm9_ov003; ROM address 021d2b3c. No matching claim. */
#include "types.h"
#include "deps/021d2b3c_FUN_021d2b3c.h"

void FUN_021d2b3c(void)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined2 local_20;
  undefined2 local_1e;
  
  uVar8 = (uint)((*(byte *)(*DAT_021d2c70 + 0x38) & 1) != 0);
  uVar9 = 0;
  iVar4 = func_0x0214e6d4();
  piVar2 = DAT_021d2c70;
  iVar7 = *DAT_021d2c70;
  *(undefined2 *)(iVar7 + 0x2c) = *(undefined2 *)(iVar7 + 0x28);
  *(undefined2 *)(iVar7 + 0x2e) = *(undefined2 *)(iVar7 + 0x2a);
  iVar7 = 0;
  while ((iVar6 = *piVar2 + iVar4 * 8, *(short *)(iVar6 + 4) != 1 || (*(short *)(iVar6 + 6) != 0)))
  {
    iVar7 = iVar7 + 1;
    iVar4 = func_0x02147cd8(iVar4 + 4,5);
    if (3 < iVar7) {
LAB_021d2ba4:
      piVar2 = DAT_021d2c70;
      uVar5 = uVar9 ^ uVar8;
      *(byte *)(*DAT_021d2c70 + 0x38) =
           *(byte *)(*DAT_021d2c70 + 0x38) & 0xfd | (byte)((uVar9 & uVar5) << 1);
      *(byte *)(*piVar2 + 0x38) = *(byte *)(*piVar2 + 0x38) & 0xf7 | (byte)((uVar8 & uVar5) << 3);
      *(byte *)(*piVar2 + 0x38) = *(byte *)(*piVar2 + 0x38) & 0xfe | (byte)uVar9;
      iVar4 = *piVar2;
      *(byte *)(iVar4 + 0x38) =
           *(byte *)(iVar4 + 0x38) & 0xfb |
           (byte)((((uint)*(byte *)(iVar4 + 0x38) << 0x1e) >> 0x1f) << 2);
      pcVar3 = DAT_021d2c74;
      if (uVar9 == 0) {
        *DAT_021d2c74 = '\0';
        return;
      }
      *DAT_021d2c74 = *DAT_021d2c74 + '\x01';
      cVar1 = *pcVar3;
      if (cVar1 == '(') {
        *(byte *)(*piVar2 + 0x38) = *(byte *)(*piVar2 + 0x38) | 4;
        return;
      }
      if (cVar1 == '/') {
        *(byte *)(*piVar2 + 0x38) = *(byte *)(*piVar2 + 0x38) | 4;
        *pcVar3 = '(';
      }
      return;
    }
  }
  uVar9 = 1;
  func_0x0214e334(&local_20);
  FUN_021d2544(local_20,local_1e,(undefined2 *)(uintptr_t)(*DAT_021d2c70 + 0x28));
  goto LAB_021d2ba4;
}

