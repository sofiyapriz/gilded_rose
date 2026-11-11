#include <cassert>
#include <iostream>
#include <vector>
#include "GildedRose.h"

// Хелпер: прогнати updateQuality N разів
static void updateNTimes(std::vector<Item>& items, int n) {
    GildedRose gr(items);
    for (int i = 0; i < n; ++i) gr.updateQuality();
}

// ---------- Звичайний товар ----------
static void test_normal_item_degrades() {
    std::vector<Item> items = { Item("+5 Dexterity Vest", 10, 20) };
    updateNTimes(items, 1);
    assert(items[0].sellIn == 9);
    assert(items[0].quality == 19);
}

static void test_normal_item_degrades_twice_after_sellin() {
    std::vector<Item> items = { Item("+5 Dexterity Vest", 0, 20) };
    updateNTimes(items, 1);   // sellIn стане -1, quality -2
    assert(items[0].sellIn == -1);
    assert(items[0].quality == 18);
}

static void test_quality_never_negative() {
    std::vector<Item> items = { Item("+5 Dexterity Vest", 5, 0) };
    updateNTimes(items, 3);
    assert(items[0].quality == 0);
}

// ---------- Aged Brie ----------
static void test_aged_brie_increases() {
    std::vector<Item> items = { Item("Aged Brie", 10, 20) };
    updateNTimes(items, 1);
    assert(items[0].sellIn == 9);
    assert(items[0].quality == 21);
}

static void test_aged_brie_increases_twice_after_sellin() {
    std::vector<Item> items = { Item("Aged Brie", 0, 20) };
    updateNTimes(items, 1);
    assert(items[0].sellIn == -1);
    assert(items[0].quality == 22);
}

static void test_aged_brie_max_50() {
    std::vector<Item> items = { Item("Aged Brie", 5, 50) };
    updateNTimes(items, 5);
    assert(items[0].quality == 50);
}

// ---------- Sulfuras ----------
static void test_sulfuras_never_changes() {
    std::vector<Item> items = { Item("Sulfuras, Hand of Ragnaros", 5, 80) };
    updateNTimes(items, 10);
    assert(items[0].sellIn == 5);
    assert(items[0].quality == 80);
}

// ---------- Backstage passes ----------
static void test_backstage_increases_by_one_when_far() {
    std::vector<Item> items = { Item("Backstage passes to a TAFKAL80ETC concert", 15, 20) };
    updateNTimes(items, 1);
    assert(items[0].sellIn == 14);
    assert(items[0].quality == 21);
}

static void test_backstage_increases_by_two_when_10_days() {
    std::vector<Item> items = { Item("Backstage passes to a TAFKAL80ETC concert", 10, 20) };
    updateNTimes(items, 1);
    assert(items[0].sellIn == 9);
    assert(items[0].quality == 22);
}

static void test_backstage_increases_by_three_when_5_days() {
    std::vector<Item> items = { Item("Backstage passes to a TAFKAL80ETC concert", 5, 20) };
    updateNTimes(items, 1);
    assert(items[0].sellIn == 4);
    assert(items[0].quality == 23);
}

static void test_backstage_drops_to_zero_after_concert() {
    std::vector<Item> items = { Item("Backstage passes to a TAFKAL80ETC concert", 0, 20) };
    updateNTimes(items, 1);
    assert(items[0].sellIn == -1);
    assert(items[0].quality == 0);
}

static void test_backstage_max_50() {
    std::vector<Item> items = { Item("Backstage passes to a TAFKAL80ETC concert", 5, 49) };
    updateNTimes(items, 1);
    assert(items[0].quality == 50);
}

static void test_conjured_degrades_twice_as_fast() {
    std::vector<Item> items = { Item("Conjured Mana Cake", 10, 20) };
    updateNTimes(items, 1);
    assert(items[0].sellIn == 9);
    assert(items[0].quality == 18);
}

static void test_conjured_degrades_four_after_sellin() {
    std::vector<Item> items = { Item("Conjured Mana Cake", 0, 20) };
    updateNTimes(items, 1);
    assert(items[0].sellIn == -1);
    assert(items[0].quality == 16);
}

static void test_conjured_quality_never_negative() {
    std::vector<Item> items = { Item("Conjured Mana Cake", 5, 1) };
    updateNTimes(items, 3);
    assert(items[0].quality == 0);
}
// ---------- Головний запуск ----------
int main() {
    test_normal_item_degrades();
    test_normal_item_degrades_twice_after_sellin();
    test_quality_never_negative();
    test_aged_brie_increases();
    test_aged_brie_increases_twice_after_sellin();
    test_aged_brie_max_50();
    test_sulfuras_never_changes();
    test_backstage_increases_by_one_when_far();
    test_backstage_increases_by_two_when_10_days();
    test_backstage_increases_by_three_when_5_days();
    test_backstage_drops_to_zero_after_concert();
    test_backstage_max_50();
    test_conjured_degrades_twice_as_fast();
    test_conjured_degrades_four_after_sellin();
    test_conjured_quality_never_negative();

    std::cout << "All tests passed!\n";
    return 0;
}