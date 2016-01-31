## 과제 설명

현재는 아이템을 볼 수 있는 기능만 구현되어 있다.

하지만 플레이어가 아이 쇼핑(Eye Shopping)만 한다면 상점 주인은 얼마 못 가 망해버릴 것이다.

상점 주인이 먹고 살 수 있도록 플레이어가 아이템을 구입할 수 있는 기능을 추가해 보자.

## 주의할 점

- 플레이어를 위한 `Player` 클래스를 생성한다.
   - 플레이어는 골드를 소유하고 있다. 이 멤버 변수의 이름은 `m_gold`라고 한다.
   - 플레이어는 처음 20 골드를 소지하고 있다.
- 상점에서 판매하는 아이템의 목록을 확인하거나 구입, 판매를 하기 위한 함수를 만든다.
   - 함수의 이름은 `ShowShopMessage()`다.
   - 이 때, 메뉴 목록은 다음과 같이 한다.
      - 1. 아이템 목록 표시
      - 2. 아이템 구입
      - 3. 아이템 판매
      - 4. 나가기
   - 다른 번호를 입력할 경우 오류 메시지를 출력하며, 다시 입력하게 만든다.
- 아이템을 구입하는 함수를 만든다.
   - 함수의 이름은 `BuyItem()`다.
   - 상점에서 판매하는 아이템의 목록을 보여주고, 구입할 아이템의 번호를 입력한다.
   - 구입할 아이템의 번호가...
      - 범위에 없다면 오류 메시지를 출력하며, 다시 입력하게 만든다.
      - 0이라면 빠져나간다.
   - 플레이어가 보유하고 있는 골드가...
      - 아이템 판매 가격과 같거나 많다면, 아이템 구입한 뒤 골드를 차감한다.
      - 아이템 판매 가격보다 적다면, 오류 메시지를 출력한 후 빠져나간다.

## 실행 결과

```
- Shop Select -
   1. Weapon/Armor Shop
   2. Potion Shop
   3. Exit

Select : 1

Welcome to Weapon/Armor Shop!
-----------------------------
1. Show Item List
2. Buy Item
3. Exit

Select : 2

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

Which item to buy? (1 ~ 5, 0: Exit) 6
Error: Input invalid number, please input again.
Which item to buy? (1 ~ 5, 0: Exit) 4
Thanks for buying the Axe!
Now, your gold is 20 - 15 = 5

 - Shop Select -
   1. Weapon/Armor Shop
   2. Potion Shop
   3. Exit

Select : 1

Welcome to Weapon/Armor Shop!
-----------------------------
1. Show Item List
2. Buy Item
3. Exit

Select : 2

Which item to buy? (1 ~ 5, 0: Exit) 4
You can't buy this, because you don't have enough gold!

Welcome to Weapon/Armor Shop!
-----------------------------
1. Show Item List
2. Buy Item
3. Exit

Select : 3

 - Shop Select -
   1. Weapon/Armor Shop
   2. Potion Shop
   3. Exit

Select : 3
```