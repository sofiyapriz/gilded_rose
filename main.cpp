// main.cpp
#include <iostream>
#include <vector>
#include "GildedRose.h"

int main() {
    std::vector<Item> items = {
        Item("+5 Dexterity Vest", 10, 20),
        Item("Aged Brie", 2, 0),
        Item("Sulfuras, Hand of Ragnaros", 0, 80),
        Item("Backstage passes to a TAFKAL80ETC concert", 15, 20),
    };
    GildedRose gr(items);
    for (int day = 0; day < 3; ++day) {
        std::cout << "Day " << day << ":\n";
        for (auto& it : items) {
            std::cout << "  " << it.name << " sellIn=" << it.sellIn
                << " quality=" << it.quality << "\n";
        }
        gr.updateQuality();
    }
}