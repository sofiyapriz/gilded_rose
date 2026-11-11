#pragma once
#include "ItemUpdater.h"

class ConjuredItemUpdater : public ItemUpdater {
public:
    void update(Item& item) const override;
};