#include "AgedBrieUpdater.h"
#include "QualityHelpers.h"

void AgedBrieUpdater::update(Item& item) const {
    increaseQuality(item, 1);
    item.sellIn -= 1;
    if (item.sellIn < 0) increaseQuality(item, 1);
}