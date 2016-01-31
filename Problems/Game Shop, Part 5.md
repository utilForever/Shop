## 과제 설명

지난 과제를 통해 플레이어가 아이템을 구입할 수 있도록 구현했다.

문제는 구입한 아이템이 어디론가 사라지고 없다는 것이다. (나는 샀지만 산 게 아니다)

플레이어가 구입한 아이템이 저장할 공간이 필요하다. 바로 인벤토리(Inventory)다!

인벤토리를 구현해 플레이어가 구입한 아이템을 저장할 수 있게 해주자.

## 주의할 점

- `Player` 클래스에 인벤토리를 생성한다.
   - 인벤토리 변수 이름은 `m_inventory`다.
   - 인벤토리에 가지고 있는 아이템의 이름과 개수를 저장한다.
   - 인벤토리 변수 타입은 여러 가지가 될 수 있으므로, 원하는 자료 구조를 선택한다.
      - `std::vector<std::pair<std::string, int>>`
      - `std::map<std::string, int>`
      - 기타 등등...
- `Player` 클래스에 인벤토리에 있는 아이템을 볼 수 있는 함수를 만든다.
   - 함수의 이름은 `ShowInventory()`다.
   - 플레이어가 가지고 있는 각 아이템의 이름과 개수를 출력한다.
   - 인벤토리가 비어있을 경우, 비어있다고 출력한다.
- `Player` 클래스에 인벤토리에 아이템을 추가하는 함수를 만든다.
   - 함수의 이름은 `AddItemToInventory()`다.
   - 함수의 인자로 추가할 아이템의 이름과 개수를 받는다.
   - 플레이어의 인벤토리에 아이템을 추가한다.
   - 추가할 아이템이...
      - 인벤토리에 이미 존재하는 경우, 아이템을 새로 추가하지 않고 기존 아이템의 개수를 증가시킨다.
      - 인벤토리에 존재하지 않는 경우, 아이템을 새로 추가한다.   
- `Shop` 클래스의 `ShowBuyMessage()` 함수를 변경한다.
   - 구입할 아이템의 번호를 입력하고 나면, 몇 개를 살 것인지 묻는 메시지를 출력한다.
      - 0을 입력하면 빠져나간다.
      - 음수를 입력하면 오류 메시지를 출력한다.
      - 양수를 입력하면 아이템을 구입하기 위해 `BuyItem()` 함수를 호출한다.      
- `Shop` 클래스의 `BuyItem()` 함수를 변경한다.
   - 함수의 인자에 구입할 아이템의 개수를 받도록 한다.
   - 아이템을 구입할 수 있다면 플레이어의 인벤토리에 구입한 아이템을 추가한다.   
- `main()` 함수의 메뉴를 변경한다.
   - 메인 메뉴에서 0을 입력하면 플레이어의 인벤토리를 볼 수 있도록 한다.

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
3. Exit

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
3. Exit

Select : 2

Which item to buy? (1 ~ 5, 0: Exit) 6
Error: Input invalid number, please input again.
Which item to buy? (1 ~ 5, 0: Exit) 1
How many do you think you'll need? (0: Exit) 2
Thanks for buying the Sword!
Now, your gold is 20 - 10 = 10
2 Sword stored in player's inventory.

Welcome to Weapon/Armor Shop!
-----------------------------
1. Show Item List
2. Buy Item
3. Exit

Select : 3

 - Shop Select -
   0. Show Player's Inventory
   1. Weapon/Armor Shop
   2. Potion Shop
   3. Exit
   
Select : 0

- Item List in Inventory -
No. 1: 2 Sword

 - Shop Select -
   0. Show Player's Inventory
   1. Weapon/Armor Shop
   2. Potion Shop
   3. Exit

Select : 3
```