#include "GoodObject.h"

void GoodObject::onEnter() {
    instances += 1;
};

void GoodObject::onDelete() {
    instances -= 1;
};

void GoodObject::reset() {
    instances = 0;
};

bool GoodObject::toDelete() {
    return !alive;
}

int GoodObject::instances = 0;