#include <minecraft/src/world/actor/player/Player.hpp>
#include <minecraft/src/world/item/ItemStack.hpp>
#include <minecraft/src/world/item/Item.hpp>

class CPvPAutoTotem {
public:
    static void onClientTick(Player* player) {
        if (!player || !player->isLocalPlayer()) return;

        const ItemStack& offhandStack = player->getOffhandSlot();

        if (offhandStack.isEmpty() || !isTotem(offhandStack)) {
            int totemSlot = findTotemSlot(player);
            if (totemSlot != -1) {
                executeOffhandSwap(player, totemSlot);
            }
        }
    }

private:
    static bool isTotem(const ItemStack& itemStack) {
        if (itemStack.isEmpty()) return false;
        return itemStack.getItem()->getRawNameId() == "totem_of_undying";
    }

    static int findTotemSlot(Player* player) {
        // Prioritas Hotbar
        for (int i = 0; i < 9; ++i) {
            ItemStack stack = player->getSupplies().getItem(i);
            if (isTotem(stack)) return i;
        }
        // Inventaris Utama
        for (int i = 9; i < 36; ++i) {
            ItemStack stack = player->getSupplies().getItem(i);
            if (isTotem(stack)) return i;
        }
        return -1;
    }

    static void executeOffhandSwap(Player* player, int fromSlot) {
        player->getSupplies().swapSlots(fromSlot, 45);
    }
};
