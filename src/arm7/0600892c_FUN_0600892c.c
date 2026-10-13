/* Decompiled C draft; module arm7; ROM address 0600892c. No matching claim. */
#include "types.h"
#include "deps/0600892c_FUN_0600892c.h"

void FUN_0600892c(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  FUN_0600983c();
  FUN_0600ad78();
  FUN_06009d04();
  FUN_06008cec();
  FUN_06008c0c();
  uVar3 = *(uint *)(DAT_0600897c & 0xfffffffc) >> (DAT_0600897c & 3) * 8 |
          *(uint *)(DAT_0600897c & 0xfffffffc) << (DAT_0600897c & 3) * -8 + 0x20;
  uVar2 = uVar3 + 0x31c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  FUN_0600bd44(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,*(undefined2 *)(uVar3 + 800));
  FUN_0600f118();
  FUN_0600f54c();
  FUN_0600e3c4();
  FUN_0600b218();
  return;
}

