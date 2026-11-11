#pragma once
#include "ItemUpdater.h"

class AgedBrieUpdater : public ItemUpdater {
public:
    void update(Item& item) const override;
};