
#pragma once
#include <memory>
#include <string>
#include "ItemUpdater.h"

class ItemUpdaterFactory {
public:
    static std::unique_ptr<ItemUpdater> createFor(const Item& item);
};