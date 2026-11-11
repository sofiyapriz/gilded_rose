
#include "ItemUpdaterFactory.h"
#include "NormalItemUpdater.h"
#include "AgedBrieUpdater.h"
#include "SulfurasUpdater.h"
#include "BackstagePassUpdater.h"
#include "ConjuredItemUpdater.h"   // додамо пізніше

std::unique_ptr<ItemUpdater> ItemUpdaterFactory::createFor(const Item& item) {
    if (item.name == "Aged Brie")
        return std::make_unique<AgedBrieUpdater>();
    if (item.name == "Sulfuras, Hand of Ragnaros")
        return std::make_unique<SulfurasUpdater>();
    if (item.name == "Backstage passes to a TAFKAL80ETC concert")
        return std::make_unique<BackstagePassUpdater>();
    if (item.name.rfind("Conjured", 0) == 0)   // починається з "Conjured"
        return std::make_unique<ConjuredItemUpdater>();
    return std::make_unique<NormalItemUpdater>();
}