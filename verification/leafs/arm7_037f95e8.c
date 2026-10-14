/* SDK C reconstruction; complete local bytes verified. Full ROM remains unverified. */
#define OSi_InsertLinkToQueue FUN_037f95e8
#include <nitro/os.h>
#include <nitro/mi.h>
#include <nitro/utest.h>

#include <nitro/code32.h>

#include  <nitro/codereset.h>

#pragma thumb off
void OSi_InsertLinkToQueue (OSThreadQueue * queue, OSThread * thread)
    {
        OSThread * next = queue->head;

        while (next && next->priority <= thread->priority) {
            if (next == thread) {
                return;
            }
            next = next->link.next;
        }

        if (!next) {
            OSThread * prev = queue->tail;

            if (!prev) {
                queue->head = thread;
            } else {
                prev->link.next = thread;
            }

            thread->link.prev = prev;
            thread->link.next = NULL;
            queue->tail = thread;
        } else {
            OSThread * prev = next->link.prev;

            if (!prev) {
                queue->head = thread;
            } else {
                prev->link.next = thread;
            }

            thread->link.prev = prev;
            thread->link.next = next;
            next->link.prev = thread;
        }
    }
