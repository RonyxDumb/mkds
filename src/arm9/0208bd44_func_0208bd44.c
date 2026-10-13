/* Decompiled C draft; module arm9; ROM address 0208bd44. No matching claim. */
#include "types.h"
#include "deps/0208bd44_func_0208bd44.h"

void func_0208bd44(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = GetDriverEntry(param_2);
  *(undefined4 *)(param_1 + 0x154) = 0;
  uVar1 = param_1 + 0x154U & 3;
  uVar3 = *(uint *)(param_1 + 0x154U & 0xfffffffc);
  func_0207e400(param_1,iVar2,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  func_0207d814((uint *)(uintptr_t)(param_1 + 0xe8),param_1);
  *(undefined4 *)(param_1 + 0x114) = 0;
  *(undefined2 *)(param_1 + 0x118) = 0;
  if ((uint)*(ushort *)(iVar2 + 0x74) !=
      (int)*(char *)((*(uint *)(uRam0208bdbc & 0xfffffffc) >> (uRam0208bdbc & 3) * 8 |
                     *(uint *)(uRam0208bdbc & 0xfffffffc) << (uRam0208bdbc & 3) * -8 + 0x20) + 0x62)
     ) {
    uVar1 = iVar2 + 0x7cU & 3;
    uVar3 = *(uint *)(iVar2 + 0x7cU & 0xfffffffc);
    *(uint *)(iVar2 + 0x7c) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20 | 0x40;
  }
  return;
}

