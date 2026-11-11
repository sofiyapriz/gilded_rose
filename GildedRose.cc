#include "GildedRose.h"
#include "updaters/ItemUpdaterFactory.h"

GildedRose::GildedRose(std::vector<Item>& items) : items(items) {}

void GildedRose::updateQuality() {
    for (auto& item : items) {
        auto updater = ItemUpdaterFactory::createFor(item);
        updater->update(item);
    }
}