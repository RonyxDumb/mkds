/* Decompiled C draft; module arm9; ROM address 020b4e70. No matching claim. */
#include "types.h"
#include "deps/020b4e70_CheckVectorBounds_Clock_Airship.h"

bool CheckVectorBounds_Clock_Airship(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  bVar4 = true;
  iVar1 = GetCurrentInternalCourseId_0();
  if (iVar1 == 0x11) {
    uVar2 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
    if (((((int)uVar2 < iRam020b4f48) || (iRam020b4f4c < (int)uVar2)) ||
        (uVar2 = param_1 + 8 & 3, uVar3 = *(uint *)(param_1 + 8 & 0xfffffffc),
        uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20, (int)uVar2 < iRam020b4f48)) ||
       ((iRam020b4f4c < (int)uVar2 ||
        (uVar2 = param_1 + 4 & 3, uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc),
        bVar4 = iRam020b4f50 <= (int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20), bVar4)))) {
      bVar4 = true;
    }
  }
  else if ((iVar1 == 0x13) &&
          (((uVar2 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                     *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20,
            (int)uVar2 < -0x640000 || (iRam020b4f54 < (int)uVar2)) ||
           ((uVar2 = param_1 + 8 & 3, uVar3 = *(uint *)(param_1 + 8 & 0xfffffffc),
            uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20, (int)uVar2 < iRam020b4f58 ||
            ((iRam020b4f5c < (int)uVar2 ||
             (uVar2 = param_1 + 4 & 3, uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc),
             bVar4 = iRam020b4f60 <= (int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20), bVar4))
            )))))) {
    bVar4 = true;
  }
  return bVar4;
}

