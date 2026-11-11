
#pragma once
#include "ItemUpdater.h"

class SulfurasUpdater : public ItemUpdater {
public:
    void update(Item& item) const override;
};