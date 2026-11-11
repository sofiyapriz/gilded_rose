#include "BackstagePassUpdater.h"
#include "QualityHelpers.h"

void BackstagePassUpdater::update(Item& item) const {
    increaseQuality(item, 1);
    if (item.sellIn < 11) increaseQuality(item, 1);
    if (item.sellIn < 6)  increaseQuality(item, 1);

    item.sellIn -= 1;

    if (item.sellIn < 0) {
        item.quality = 0;
    }
}