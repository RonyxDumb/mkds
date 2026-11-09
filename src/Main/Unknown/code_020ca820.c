#include "Main/Unknown/code_020ca820.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020cab8c.h"

#pragma thumb on
void WriteEmblemChoisesScreenMapWrapper(void) {
    u32 unusedValue;
    WriteEmblemChoisesScreenMap();
}
#pragma thumb off

void *EmblemChoisesGetCurrentHeap(void) {
    void *value0;
    value0 = GetCurrentHeapCall();
    value0 = GetHeap(value0);
    return value0;
}
