#pragma once
#include <algorithm>
#include "GildedRose.h"

// Спільні операції над quality: не дозволяємо вийти за [0, 50]
inline void decreaseQuality(Item& item, int amount) {
    item.quality = std::max(0, item.quality - amount);
}

inline void increaseQuality(Item& item, int amount) {
    item.quality = std::min(50, item.quality + amount);
}