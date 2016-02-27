## 과제 설명

지난번 과제를 통해 플레이어가 아이템을 구입/판매할 수 있게 되었다.

하지만 우리에겐 더 큰 문제가 있었다!

프로그램을 종료하게 되면 샀던 아이템이 전부 날아가버린다는 것이다.

이런 안타까운 일이! 그렇다고 고객 센터를 찾아갈 수도 없고...

게임을 종료할 때 플레이어 정보를 저장하고, 시작할 때 불러올 수 있게 하자!

## 주의할 점

- 플레이어 정보를 저장하는 파일의 이름은 `player_info.txt`다.
   - 파일 내용 구성 : 플레이어 이름 / 플레이어 소지 골드 / 소지 아이템 개수 / 아이템 타입, 이름, 개수
   ```
   Chris
   190
   1
   "Weapon" "Sword" 1
   ```
- `Player` 클래스에 플레이어 정보 파일을 불러오는 함수를 만든다.
   - 함수의 이름은 `LoadPlayerInfoFromFile()`다.
   - 플레이어 정보를 저장하는 파일이 존재하지 않을 경우, 기본 정보를 사용한다.
      - 플레이어 이름 : "Anonymous"
      - 플레이어 소지 골드 : 200 골드
   - 플레이어 정보를 저장하는 파일이 존재할 경우, 정보를 입력받는다.
      - 아이템 타입에 따라 알맞은 아이템을 생성하고 인벤터리에 추가한다.
      - 없는 아이템 타입인 경우 예외(`std::bad_exception()`)를 던진다.
- `Player` 클래스에 플레이어 정보 파일을 저장하는 함수를 만든다.
   - 함수의 이름은 `SavePlayerInfoToFile()`이다.
   - 파일 내용 구성에 맞춰서 플레이어 정보를 저장한다.
- `Item` 클래스에 아이템의 타입을 반환하는 함수를 만든다.
   - 함수의 이름은 `GetType()`다.
   - 순수 가상 함수로 생성한다.
   - `Weapon`, `Armor`, `Potion` 클래스에 `GetType()` 함수를 구현한다.
- 파일 스트림을 열고(`open()`) 닫음(`close()`)에 주의한다.
   - 파일 스트림을 열 때, 다음 모드(Mode)를 참조한다.
      - `std::fstream::in`
      - `std::fstream::out`
      - `std::fstream::trunc`

## 실행 결과

```
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
How many do you think you'll need? (0: Exit) 1
Thanks for buying the Sword!
Now, your gold is 200 - 10 = 190
1 Sword stored in player's inventory.

Welcome to Weapon/Armor Shop!
-----------------------------
1. Show Item List
2. Buy Item
3. Sell Item
4. Exit

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

Select : 3
```

```
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