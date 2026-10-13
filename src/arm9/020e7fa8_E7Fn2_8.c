/* Decompiled C draft; module arm9; ROM address 020e7fa8. No matching claim. */
#include "types.h"
#include "deps/020e7fa8_E7Fn2_8.h"

/* WARNING: Removing unreachable block (ram,0x020e7ffc) */
/* WARNING: Removing unreachable block (ram,0x020e800c) */
/* WARNING: Removing unreachable block (ram,0x020e8024) */
/* WARNING: Removing unreachable block (ram,0x020e803c) */

void E7Fn2_8(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined2 *puVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined4 uVar12;
  
  puVar7 = puRam020e820c;
  puVar6 = puRam020e8208;
  puVar5 = puRam020e8204;
  puVar4 = puRam020e8200;
  puVar3 = puRam020e81fc;
  puVar2 = puRam020e81f8;
  *puRam020e81f4 = 0;
  *puVar5 = 4;
  *puVar6 = 1;
  *puVar7 = 0x1f;
  *puVar2 = 0;
  *puVar3 = 0;
  *puVar4 = 0;
  puVar2 = puRam020e821c;
  *(undefined2 *)(iRam020e8218 + 0x18) = 1;
  *puVar2 = 0;
  iVar8 = func_0203c5e4();
  if (iVar8 == 0) {
    func_02147288(uRam020e8224,uRam020e822c,puRam020e8228);
  }
  else {
    iVar8 = func_020e6b48();
    uVar10 = puRam020e8220[1];
    uVar12 = puRam020e8220[2];
    *(undefined4 *)(iVar8 + 0x24) = *puRam020e8220;
    *(undefined4 *)(iVar8 + 0x28) = uVar10;
    *(undefined4 *)(iVar8 + 0x2c) = uVar12;
    func_02147288(uRam020e8224,iVar8,puRam020e8228);
  }
  puVar2 = puRam020e8230;
  uVar10 = puRam020e8228[1];
  uVar12 = puRam020e8228[2];
  *puRam020e8230 = *puRam020e8228;
  puVar2[1] = uVar10;
  puVar2[2] = uVar12;
  puVar4 = puRam020e8238;
  puVar3 = puRam020e8234;
  uVar10 = puVar2[1];
  uVar12 = puVar2[2];
  *puRam020e8234 = *puVar2;
  puVar3[1] = uVar10;
  puVar3[2] = uVar12;
  uVar10 = puVar3[1];
  uVar12 = puVar3[2];
  *puVar4 = *puVar3;
  puVar4[1] = uVar10;
  puVar4[2] = uVar12;
  puVar3 = puRam020e8240;
  puVar2 = puRam020e823c;
  uVar10 = puVar4[1];
  uVar12 = puVar4[2];
  *puRam020e823c = *puVar4;
  puVar2[1] = uVar10;
  puVar2[2] = uVar12;
  uVar10 = puVar2[1];
  uVar12 = puVar2[2];
  *puVar3 = *puVar2;
  puVar3[1] = uVar10;
  puVar3[2] = uVar12;
  puVar5 = puRam020e824c;
  puVar4 = puRam020e8248;
  puVar2 = puRam020e8244;
  *puRam020e8244 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2 = puRam020e8250;
  *puVar4 = 0;
  *puVar2 = 0;
  puVar2 = puRam020e8254;
  puVar4[1] = 0;
  puVar4[2] = 0;
  puVar7 = puRam020e8258;
  *puVar2 = 0;
  *puVar7 = 0;
  puVar2 = puRam020e8260;
  *puRam020e825c = 0;
  *puVar2 = 0;
  puVar4 = puRam020e826c;
  puVar2 = puRam020e8264;
  *puRam020e8268 = 1;
  *puVar4 = 1;
  uVar10 = puVar3[1];
  uVar12 = puVar3[2];
  *puVar2 = *puVar3;
  puVar2[1] = uVar10;
  puVar2[2] = uVar12;
  *puVar5 = 0;
  uVar10 = func_02108e6c(4);
  func_0212c6f0(uVar10,1);
  uVar9 = func_02108e6c(4);
  if (((*(uint *)(uRam020e8270 & 0xfffffffc) >> (uRam020e8270 & 3) * 8 |
       *(uint *)(uRam020e8270 & 0xfffffffc) << (uRam020e8270 & 3) * -8 + 0x20) & 1) != 0) {
    uVar1 = iRam020e8274 + 0xcU & 3;
    uVar11 = *(uint *)(iRam020e8274 + 0xcU & 0xfffffffc);
    if (uVar11 >> uVar1 * 8 != 0 || uVar11 << uVar1 * -8 + 0x20 != 0) {
      if (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 != 0 ||
          *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar9,0);
      }
      if (*(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 != 0 ||
          *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20 != 0) {
        func_0212c6f0(uVar9,0);
      }
      NNSi_MaybeSndPlayerStartSeq(uVar9,0,uRam020e8278);
      return;
    }
    return;
  }
  return;
}

