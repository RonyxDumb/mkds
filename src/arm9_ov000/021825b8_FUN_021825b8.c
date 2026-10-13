/* Decompiled C draft; module arm9_ov000; ROM address 021825b8. No matching claim. */
#include "types.h"
#include "deps/021825b8_FUN_021825b8.h"

void FUN_021825b8(void)

{
  bool bVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = func_0x02125f6c();
  if (iVar2 != 0) {
    func_0x0212ecc0(DAT_02182668,0,0x15);
  }
  iVar2 = func_0x02125f88();
  if ((iVar2 != 0) && (iVar2 = func_0x02128294(), iVar2 != 0)) {
    *(undefined4 *)(*DAT_0218266c + 4) = 2;
    FUN_02182de8();
    *(undefined4 *)(*DAT_0218266c + 8) = 1;
    return;
  }
  iVar2 = func_0x02125fa4();
  if ((iVar2 != 0) && (iVar2 = func_0x02128294(), iVar2 != 0)) {
    if ((*(ushort *)(DAT_02182670 + 0x2e0) & 2) == 0) {
      bVar1 = false;
      bVar3 = false;
      if ((*(short *)(DAT_02182674 + 0x2e0) == 0) && (*(ushort *)(DAT_02182678 + 0x2e0) < 5)) {
        bVar3 = true;
      }
      if (((!bVar3) && (*(short *)(DAT_0218267c + 0x2e0) == 0)) &&
         (*(short *)(DAT_02182674 + 0x2e0) != 0)) {
        bVar1 = true;
      }
      if (!bVar1) {
        return;
      }
      iVar2 = func_0x02128210(*(undefined2 *)(DAT_02182680 + 0x2e0),
                              *(undefined2 *)(DAT_02182684 + 0x2e0));
      if (iVar2 == 0) {
        return;
      }
    }
    func_0x02125fc0();
    func_0x02128310(0);
  }
  return;
}

