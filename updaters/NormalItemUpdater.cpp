#include "NormalItemUpdater.h"
#include "QualityHelpers.h"

void NormalItemUpdater::update(Item& item) const {
    decreaseQuality(item, 1);
    item.sellIn -= 1;
    if (item.sellIn < 0) decreaseQuality(item, 1);
}