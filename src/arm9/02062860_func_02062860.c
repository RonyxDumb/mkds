/* Decompiled C draft; module arm9; ROM address 02062860. No matching claim. */
#include "types.h"
#include "deps/02062860_func_02062860.h"

void func_02062860(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  func_02012f24();
  func_02011074();
  func_01ff92b4();
  func_02012b20(1);
  uVar4 = *(uint *)(uRam02062984 & 0xfffffffc) >> (uRam02062984 & 3) * 8 |
          *(uint *)(uRam02062984 & 0xfffffffc) << (uRam02062984 & 3) * -8 + 0x20;
  uVar3 = uVar4 + 0x1c;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  *(uint *)(uVar4 + 0x1c) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20 | 8;
  func_02010fac(0,0,0xfffff000,0);
  func_02010fac(1,uRam02062988,uRam02062988,uRam02062988);
  func_02010fac(2,0,0xfffff000,0);
  func_02010fac(3,0,uRam0206298c,0);
  func_02010f98(0,uRam02062990);
  func_02010f98(1,uRam02062994);
  func_02010f98(2,0x1f);
  func_02010f98(3,uRam02062998);
  func_02010f74(uRam0206299c,uRam0206299c,0);
  func_02010f50(0,0,1);
  func_02010f24(0xf,0,2,0,0x1f,0);
  uVar3 = (*(uint *)(uRam02062984 & 0xfffffffc) >> (uRam02062984 & 3) * 8 |
          *(uint *)(uRam02062984 & 0xfffffffc) << (uRam02062984 & 3) * -8 + 0x20) + 0x24;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar2 = Mem_AllocateHeap(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,0x304);
  *puRam020629a0 = uVar2;
  func_01ff92e0();
  return;
}

