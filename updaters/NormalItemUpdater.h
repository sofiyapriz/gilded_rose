#pragma once
#include "ItemUpdater.h"

class NormalItemUpdater : public ItemUpdater {
public:
    void update(Item& item) const override;
};