/* Decompiled C draft; module arm9; ROM address 0208aea8. No matching claim. */
#include "types.h"
#include "deps/0208aea8_CopyKartCharPhysicalParam.h"

void CopyKartCharPhysicalParam(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar2 = *(uint *)(uRam0208af38 & 0xfffffffc) >> (uRam0208af38 & 3) * 8 |
          *(uint *)(uRam0208af38 & 0xfffffffc) << (uRam0208af38 & 3) * -8 + 0x20;
  uVar1 = uVar2 + 0xc;
  uVar6 = uVar1 & 3;
  uVar7 = *(uint *)(uVar1 & 0xfffffffc);
  uVar2 = uVar2 + 0x10;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  iVar3 = IsAwardOrStaffRoll_0();
  if (iVar3 == 0) {
    uVar4 = (*(uint *)(uRam0208af3c & 0xfffffffc) >> (uRam0208af3c & 3) * 8 |
            *(uint *)(uRam0208af3c & 0xfffffffc) << (uRam0208af3c & 3) * -8 + 0x20) + 8;
    uVar5 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    if ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) == 2) {
      param_2 = param_3 + 0x25 & 0xffff;
    }
  }
  else {
    param_2 = 0;
    param_3 = param_2;
  }
  uVar5 = *(uint *)(uRam0208af38 & 0xfffffffc) >> (uRam0208af38 & 3) * 8 |
          *(uint *)(uRam0208af38 & 0xfffffffc) << (uRam0208af38 & 3) * -8 + 0x20;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  Mem_CpuCopy8(param_2 * 0x98 + (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20),
               param_1 * 0x98 + (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20));
  uVar6 = (*(uint *)(uRam0208af38 & 0xfffffffc) >> (uRam0208af38 & 3) * 8 |
          *(uint *)(uRam0208af38 & 0xfffffffc) << (uRam0208af38 & 3) * -8 + 0x20) + 4;
  uVar7 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  Mem_CpuCopy8((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + param_3 * 8,
               (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + param_1 * 8,8);
  return;
}

