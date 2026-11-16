#include "Main/Unknown/code_0208533c.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0201750c.h"

void model_initResList(void) {
    NNSFndList *list;
    u32 offset;
    u32 value12;
    list = &sModelResList;
    offset = 0u;
    NNS_FndInitList(list, offset);
}
