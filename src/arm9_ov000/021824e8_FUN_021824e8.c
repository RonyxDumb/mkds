/* Decompiled C draft; module arm9_ov000; ROM address 021824e8. No matching claim. */
#include "types.h"
#include "deps/021824e8_FUN_021824e8.h"

void FUN_021824e8(void)

{
  bool bVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = func_0x02125f6c();
  if (iVar2 != 0) {
    func_0x0212ecc0(DAT_02182598,0,0x15);
  }
  iVar2 = func_0x02125f88();
  if ((iVar2 != 0) && (iVar2 = func_0x02128294(), iVar2 != 0)) {
    *(undefined4 *)(*DAT_0218259c + 4) = 2;
    FUN_02182de8();
    *(undefined4 *)(*DAT_0218259c + 8) = 1;
    return;
  }
  iVar2 = func_0x02125fa4();
  if ((iVar2 != 0) && (iVar2 = func_0x02128294(), iVar2 != 0)) {
    if ((*(ushort *)(DAT_021825a0 + 0x2e0) & 2) == 0) {
      bVar1 = false;
      bVar3 = false;
      if ((*(short *)(DAT_021825a4 + 0x2e0) == 0) && (*(ushort *)(DAT_021825a8 + 0x2e0) < 5)) {
        bVar3 = true;
      }
      if (((!bVar3) && (*(short *)(DAT_021825ac + 0x2e0) == 0)) &&
         (*(short *)(DAT_021825a4 + 0x2e0) != 0)) {
        bVar1 = true;
      }
      if (!bVar1) {
        return;
      }
      iVar2 = func_0x02128210(*(undefined2 *)(DAT_021825b0 + 0x2e0),
                              *(undefined2 *)(DAT_021825b4 + 0x2e0));
      if (iVar2 == 0) {
        return;
      }
    }
    func_0x02125fc0();
    func_0x02128310(0);
  }
  return;
}

