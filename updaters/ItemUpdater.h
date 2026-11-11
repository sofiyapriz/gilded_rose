#pragma once
#include "GildedRose.h"

// Абстракція: "оновлювач товару".
// Кожен конкретний тип товару реалізує свою логіку.
class ItemUpdater {
public:
    virtual ~ItemUpdater() = default;
    virtual void update(Item& item) const = 0;
};