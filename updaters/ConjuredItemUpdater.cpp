#include "ConjuredItemUpdater.h"
#include "QualityHelpers.h"

void ConjuredItemUpdater::update(Item& item) const {
    decreaseQuality(item, 2);
    item.sellIn -= 1;
    if (item.sellIn < 0) decreaseQuality(item, 2);
}