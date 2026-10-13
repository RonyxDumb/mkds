/* Decompiled C draft; module arm9; ROM address 02010ab4. No matching claim. */
#include "types.h"
#include "deps/02010ab4_StructML_SomeFn_3.h"

void StructML_SomeFn_3(int param_1,int param_2)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  
  uVar1 = param_2 + 8U & 3;
  uVar3 = *(uint *)(param_2 + 8U & 0xfffffffc);
  cVar2 = *(char *)(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  if (cVar2 == 'J') {
    func_02010b50(param_1 + 0x44);
    func_02010bc8((uint *)(uintptr_t)(param_1 + 0x10),param_2);
    return;
  }
  if (cVar2 != 'M') {
    if (cVar2 != 'V') {
      return;
    }
    func_02010b50(param_1 + 0x4c);
    func_02010bc8((uint *)(uintptr_t)(param_1 + 0x18),param_2);
    return;
  }
  func_02010b50(param_1 + 0x3c);
  func_02010bc8((uint *)(uintptr_t)(param_1 + 8),param_2);
  return;
}

