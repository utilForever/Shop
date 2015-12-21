## 과제 설명

기획자가 아이템 정보 100개를 만들었다.

아이템 정보 100개를 C++ 코드에 하나씩 넣기에는 너무 많고, 이후에 추가될 아이템을 고려해야 된다.

따라서 기획자랑 협의를 통해 아이템 정보를 텍스트 파일에 저장한 뒤, 불러오기로 결정했다.

이제 여러분 차례다. 텍스트 파일로부터 아이템 정보를 불러오도록 코드를 변경해 보자.

(편의상 텍스트 파일에 아이템 정보를 10개를 저장 - 장비 아이템 5개, 포션 아이템 5개) 

## 주의할 점

C++ 파일 입출력을 사용할 것 (std::ifstream)

텍스트 파일은 다음과 같이 구성되어 있음

- equip_item.txt

```
"Sword" "Medium DMG" 3.0 10.0 10.0
"Cap" "Light Armor" 1.0 5.0 5.0
"Gloves" "Light Armor" 1.0 5.0 5.0
"Axe" "High DMG" 5.0 15.0 15.0
"Boots" "Light Armor" 1.0 5.0 5.0
```

- potion_item.txt

```
"Small Health Potion" "Recovery 100 HP" 1.0 50.0 "Health" 100.0
"Small Mana Potion" "Recovery 50 MP" 0.5 30.0 "Mana" 50.0
"Medium Health Potion" "Recovery 200 HP" 2.0 120.0 "Health" 200.0
"Medium Mana Potion" "Recovery 100 MP" 1.0 75.0 "Mana" 100.0
"Large Health Potion" "Recovery 300 HP" 3.0 200.0 "Health" 300.0
```

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