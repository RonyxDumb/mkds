/* Decompiled C draft; module arm9; ROM address 0205c6b0. No matching claim. */
#include "types.h"
#include "deps/0205c6b0_E7FnList4_Fn5.h"

void E7FnList4_Fn5(void)

{
  uint uVar1;
  uint uVar2;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined8 uVar9;
  uint uVar3;
  
  uVar8 = 0;
  uVar5 = *(uint *)(uRam0205c798 & 0xfffffffc) >> (uRam0205c798 & 3) * 8 |
          *(uint *)(uRam0205c798 & 0xfffffffc) << (uRam0205c798 & 3) * -8 + 0x20;
  uVar3 = uVar5 + 0x754 & 3;
  uVar2 = *(uint *)(uVar5 + 0x754 & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  iVar7 = uVar3 + 4;
  do {
    iVar6 = uVar8 * 0x38;
    uVar2 = uVar5 + iVar6 + 0x44;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
      Mem_CpuCopy8((ushort *)(uintptr_t)(uVar5 + 0x14 + iVar6),(uint *)(uintptr_t)(iVar7),0x28);
      uVar9 = Os_GetTick();
      *(undefined8 *)(uVar3 + 0x18) = uVar9;
      iVar4 = func_0205c340(uVar8,0,0x28);
      if (iVar4 == 0) {
        Mem_CpuFill8((uint *)(uintptr_t)(iVar7),0,0x28);
      }
      else {
        *(undefined4 *)
         ((*(uint *)(uRam0205c798 & 0xfffffffc) >> (uRam0205c798 & 3) * 8 |
          *(uint *)(uRam0205c798 & 0xfffffffc) << (uRam0205c798 & 3) * -8 + 0x20) + iVar6 + 0x44) =
             0;
      }
      break;
    }
    uVar8 = uVar8 + 1 & 0xff;
  } while (uVar8 < 4);
  uVar3 = *(uint *)(uRam0205c798 & 0xfffffffc) >> (uRam0205c798 & 3) * 8 |
          *(uint *)(uRam0205c798 & 0xfffffffc) << (uRam0205c798 & 3) * -8 + 0x20;
  if (*(byte *)(uVar3 + 0x749) != (*(byte *)(uVar3 + 0x749) & *(byte *)(uVar3 + 0xfa))) {
    func_0205c800(*(undefined2 *)(uVar3 + 0xf8),uRam0205c79c);
    return;
  }
  *(undefined2 *)(uVar3 + 0x10) = 3;
  *(undefined2 *)(uVar3 + 0x12) = 1;
  return;
}

