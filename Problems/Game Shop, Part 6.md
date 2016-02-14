## 과제 설명

지난번 과제를 통해 플레이어가 아이템을 구입한 뒤 인벤토리에 보관되어 있던 아이템을 착용할 수 있었다.

아이템을 착용한 플레이어는 몬스터와 전투를 벌였고, 이로 인해 플레이어의 레벨이 상승하게 되었다.

이제 더 좋은 장비를 착용할 때가 되었다! 근데 소지한 골드가 부족하다.

새로운 장비를 착용하면 기존의 장비는 필요가 없으므로 팔아서 골드를 마련하고 싶다.

하지만 아이템을 판매하는 기능이 없다. 플레이어가 아이템을 팔 수 있도록 기능을 구현해 주자!

## 주의할 점

- `Shop` 클래스의 `ShowShopMessage()` 함수를 변경한다.
   - 3을 입력하면 아이템을 팔 수 있도록 한다.
- `Shop` 클래스에 아이템 판매와 관련된 메시지를 보여주는 함수를 만든다.
   - 함수의 이름은 `ShowSellMessage()`다.
   - 함수의 인자로 `Player` 객체의 참조자를 받는다.
   - 플레이어의 인벤토리가 비어있을 경우, 오류 메시지를 출력하고 빠져나간다.
   - 플레이어의 인벤토리가 비어있지 않다면, 인벤토리에 있는 아이템을 출력한다.
   - 인벤토리에 있는 아이템을 출력하고 나면, 판매할 아이템의 번호를 입력한다.
   - 판매할 아이템의 번호를 입력하고 나면, 몇 개를 팔 것인지 묻는 메시지를 출력한다.
      - 0을 입력하면 빠져나간다.
      - 음수를 입력하거나 가지고 있는 아이템의 개수보다 많은 수를 입력하면 오류 메시지를 출력한다.
      - 1 ~ 가지고 있는 아이템의 개수 사이를 입력하면 아이템을 판매하기 위해 `SellItem()` 함수를 호출한다.      
- `Shop` 클래스에 아이템을 판매하는 함수를 만든다.
   - 함수의 이름은 `SellItem()`이다.
   - 함수의 인자로 `Player` 객체의 참조자, 인덱스, 아이템의 개수를 받는다.
   - `판매하는 아이템의 가격 * 판매하는 아이템의 개수` 만큼 골드를 더한다.
   - 인벤토리에서 판매하는 아이템에 대해 판매하는 아이템의 개수만큼 삭제하기 위해 `RemoveItemFromInventory()` 함수를 호출한다.
   - `BuyItem()` 함수와 비슷하게 만든다.
- `Player` 클래스에 인벤토리에서 아이템을 삭제하는 함수를 만든다.
   - 함수의 이름은 `RemoveItemFromInventory()`다.
   - 함수의 인자로 판매할 아이템의 인덱스, 판매할 아이템의 개수를 받는다.
   - 플레이어의 인벤토리에서 아이템을 삭제한다.
   - 판매할 아이템의 개수만큼 줄이고 난 뒤 아이템의 개수가 0개라면, 인벤토리에서 아이템을 지운다.
      - `std::vector`의 `erase()` 함수 이용

## 실행 결과

```
- Shop Select -
   0. Show Player's Inventory
   1. Weapon/Armor Shop
   2. Potion Shop
   3. Exit
   
Select : 0

Inventory is empty!

- Shop Select -
   0. Show Player's Inventory
   1. Weapon/Armor Shop
   2. Potion Shop
   3. Exit

Select : 1

Welcome to Weapon/Armor Shop!
-----------------------------
1. Show Item List
2. Buy Item
3. Sell Item
4. Exit

Select : 1

- Item List -
No. 1
Name        = Sword
Description = Medium DMG
Weight      = 3 lbs
Value       = 10 gold coins
Damage      = 10

No. 2
Name        = Cap
Description = Light Armor
Weight      = 1 lbs
Value       = 5 gold coins
Defense     = 5

No. 3
Name        = Gloves
Description = Light Armor
Weight      = 1 lbs
Value       = 5 gold coins
Defense     = 5

No. 4
Name        = Axe
Description = High DMG
Weight      = 5 lbs
Value       = 15 gold coins
Damage      = 15

No. 5
Name        = Boots
Description = Light Armor
Weight      = 1 lbs
Value       = 5 gold coins
Defense     = 5

Welcome to Weapon/Armor Shop!
-----------------------------
1. Show Item List
2. Buy Item
3. Sell Item
4. Exit

Select : 2

Which item to buy? (1 ~ 5, 0: Exit) 1
How many do you think you'll need? (0: Exit) 2
Thanks for buying the Sword!
Now, your gold is 20 - 20 = 0
2 Sword stored in player's inventory.

Welcome to Weapon/Armor Shop!
-----------------------------
1. Show Item List
2. Buy Item
3. Sell Item
4. Exit

Select : 3
- Item List in Inventory -
No. 1: 2 Sword
Name        = Sword
Description = Medium DMG
Weight      = 3 lbs
Value       = 10 gold coins
Damage      = 10

Which item to sell? (1 ~ 1, 0: Exit) 1
How many do you think you'll sell? (1 ~ 2, 0: Exit) 1
Thanks for selling the Sword!
Now, your gold is 0 + 10 = 10
1 Sword removed in player's inventory.

Welcome to Weapon/Armor Shop!
-----------------------------
1. Show Item List
2. Buy Item
3. Sell Item
4. Exit

Select : 4

- Shop Select -
   0. Show Player's Inventory
   1. Weapon/Armor Shop
   2. Potion Shop
   3. Exit
   
Select : 0

- Item List in Inventory -
No. 1: 1 Sword
Name        = Sword
Description = Medium DMG
Weight      = 3 lbs
Value       = 10 gold coins
Damage      = 10

- Shop Select -
   0. Show Player's Inventory
   1. Weapon/Armor Shop
   2. Potion Shop
   3. Exit

Select : 3
```