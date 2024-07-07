#include <string.h>
#include "GR.h"
#include <stdio.h>

Item* init_item(Item* item, const char *name, int sellIn, int quality)
{
    item->sellIn = sellIn;
    item->quality = quality;
    item->name = strdup(name);

    return item;
}

extern char* print_item(char* buffer, Item* item)
{
    sprintf(buffer, "%s, %d, %d", item->name, item->sellIn, item->quality);
}

void update_quality(Item items[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(items[i].name, "Sulfuras") != 0)
        {
            items[i].sellIn--;

            if (strcmp(items[i].name, "Aged Brie") == 0)
            {
                if (items[i].quality < 50)
                {
                    items[i].quality++;
                }
            }
            else if (strcmp(items[i].name, "Backstage passes") == 0)
            {
                if (items[i].quality < 50)
                {
                    items[i].quality++;

                    if (items[i].sellIn <= 10)
                    {
                        if (items[i].quality < 50)
                        {
                            items[i].quality++;
                        }
                    }

                    if (items[i].sellIn <= 5)
                    {
                        if (items[i].quality < 50)
                        {
                            items[i].quality++;
                        }
                    }
                }
            }
            else if (strcmp(items[i].name, "Conjured") == 0)
            {
                if (items[i].quality > 0)
                {
                    items[i].quality -= 2;
                }
            }
            else
            {
                if (items[i].quality > 0)
                {
                    items[i].quality--;
                }

                if (items[i].sellIn <= 0 && items[i].quality > 0)
                {
                    items[i].quality--;
                }
            }

            if (items[i].quality < 0)
            {
                items[i].quality = 0;
            }
        }
    }
}
