#ifndef CSCI_FINAL_MERCHANT_H
#define CSCI_FINAL_MERCHANT_H

#endif //CSCI_FINAL_MERCHANT_H

class merchant
{
private:
    int ingredientPrice;
    int cookwarePPrice;
    int cookwareFPrice;
    int cookwareCPrice;
    int weapon0Price;
    int weapon1Price;
    int weapon2Price;
    int weapon3Price;
    int weapon4Price;
    int armorPrice;
    int treasureRPrice;
    int treasureNPrice;
    int treasureBPrice;
    int treasureCPrice;
    int treasureGPrice;
public:
    merchant();
    void setNewPrice(int priceIncrease);
    static int merchantOptions();
    int getIngredientPrice() const;
    int getCookwarePPrice() const;
    int getCookwareFPrice() const;
    int getCookwareCPrice() const;
    int getWeaponCPrice() const;
    int getWeaponSPrice() const;
    int getWeaponRPrice() const;
    int getWeaponBPrice() const;
    int getWeaponLPrice() const;
    int getArmorPrice() const;
    int buyIngredients() const;
    int buyCookware() const;
    int buyWeapons() const;
    int buyArmor() const;
    void sellTreasure();
};
