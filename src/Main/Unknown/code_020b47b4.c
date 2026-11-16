#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_02047104.h"

void *m2d_get2dArcFile(const char *name) {
    return arc_get2dArcFile(name);
}

void *m2d_getSceneArcFile(const char *name) {
    return arc_getSceneArcFile(name);
}

void *m2d_getCourseArcFile(const char *path) {
    return arc_getCourseArcFile(path);
}
