/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define NNS_FndGetNextListObject IntrusiveListWrapper_NextItem
#define NNS_FndGetNthListObject IntrusiveListWrapper_GetAtIndex
#include <nnsys/misc.h>
#include <nnsys/fnd/list.h>
extern void * NNS_FndGetNextListObject (NNSFndList * list, void * object);
#pragma thumb off
void * NNS_FndGetNthListObject (NNSFndList * list, u16 index)
{
    int count = 0;
    NNSFndLink * object = NULL;

    NNS_NULL_ASSERT(list);

    while ((object = NNS_FndGetNextListObject(list, object)) != NULL)
    {
        if (index == count) {
            return object;
        }
        count++;
    }
    return NULL;
}
