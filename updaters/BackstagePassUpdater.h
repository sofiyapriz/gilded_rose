
#pragma once
#include "ItemUpdater.h"

class BackstagePassUpdater : public ItemUpdater {
public:
    void update(Item& item) const override;
};