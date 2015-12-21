## 과제 설명

총을 쏘려면 총알이 필요하듯이, 전투를 하려면 아이템이 필요하다.

문제는 아이템을 구입하고 싶은데 구입할 곳이 없다.

그래서 아이템을 파는 상점을 만드려고 한다.

상점에는 무기/방어구 상점, 포션 상점이 있으며 각 상점에는 아이템이 등록되어 있다.

첫 화면에서 어떤 상점에 들어갈 것인지 선택할 수 있다.

## 주의할 점

포션을 위한 Potion 클래스를 추가로 만들되, 멤버 변수와 함수는 필요에 따라 구현 (Item 클래스를 상속받음)

Shop 클래스를 만들어서 두 상점에 활용 (각 상점에는 5개의 아이템이 있음)

Shop 클래스에 아이템을 어떻게 보관할 지 고민하기

## 실행 결과

```
- Shop Select -
   1. Weapon/Armor Shop
   2. Potion Shop
   3. Exit

Select : 1

Welcome to Weapon/Armor Shop!
- Item List -
Name        = Sword
Description = Medium DMG
Weight      = 3 lbs
Value       = 10 gold coins
Damage      = 10

Name        = Cap
Description = Light Armor
Weight      = 1 lbs
Value       = 5 gold coins
Defense     = 5

Name        = Gloves
Description = Light Armor
Weight      = 1 lbs
Value       = 5 gold coins
Defense     = 5

Name        = Axe
Description = High DMG
Weight      = 5 lbs
Value       = 15 gold coins
Damage      = 15

Name        = Boots
Description = Light Armor
Weight      = 1 lbs
Value       = 5 gold coins
Defense     = 5

 - Shop Select -
   1. Weapon/Armor Shop
   2. Potion Shop
   3. Exit

Select :
...
```