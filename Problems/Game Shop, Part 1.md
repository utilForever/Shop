## 과제 설명

지금부터 단계별로 진행하며 상점을 구현해 볼 예정이다.

첫 과제로 아이템을 만들어 보기로 한다.

아이템 클래스를 생성하고, 무기와 방어구를 위한 클래스를 생성한다.

상속과 다형성, 가상 함수를 생각하며 작성해 보자.

## 주의할 점

- 아이템을 위한 `Item` 클래스를 생성한다.
   - 다음 멤버 변수를 갖는다.
      - `std::string m_name` : 아이템 이름
      - `std::string m_description` : 아이템 설명
      - `int m_weight` : 아이템 무게
      - `int m_value` : 아이템 가격
   - 다음 멤버 함수를 갖는다.
      - `Item(std::string name, std::string description, int weight, int value)` : 매개 변수로 아이템 이름/설명/무게/가격을 받는 생성자
      - 기타 나머지 특별 함수(복사/이동 생성자, 복사/이동 할당 연산자, 소멸자)는 `= default`로 처리한다.
      - `virtual void Describe()` : 아이템 정보를 출력하는 함수
- 무기 아이템을 위한 `Weapon` 클래스를 생성한다.
   - `Item` 클래스로부터 상속을 받는다.
   - 다음 멤버 변수를 갖는다.
      - `int m_damage` : 무기 데미지
   - 다음 멤버 함수를 갖는다.
      - `Weapon(std::string name, std::string description, int weight, int value, int damage)` : 매개 변수로 아이템 이름/설명/무게/가격/데미지를 받는 생성자
      - 기타 나머지 특별 함수(복사/이동 생성자, 복사/이동 할당 연산자, 소멸자)는 `= default`로 처리한다.
      - `void Describe() override` : 아이템 정보를 출력하는 함수
- 방어구 아이템을 위한 `Armor` 클래스를 생성한다.
   - `Item` 클래스로부터 상속을 받는다.
   - 다음 멤버 변수를 갖는다.
      - `int m_defense` : 방어력
   - 다음 멤버 함수를 갖는다.
      - `Armor(std::string name, std::string description, int weight, int value, int defense)` : 매개 변수로 아이템 이름/설명/무게/가격/방어력을 받는 생성자
      - 기타 나머지 특별 함수(복사/이동 생성자, 복사/이동 할당 연산자, 소멸자)는 `= default`로 처리한다.
      - `void Describe() override` : 아이템 정보를 출력하는 함수
- 테스트를 위한 ItemTest.cpp 파일을 생성한다.
```
int main()
{
	Item* item = new Weapon("Excalibur", "The legendary sword of King Arthur", 12, 1024, 24);
	item->Describe();

	item = new Armor("Steel Armor", "Protective covering made by steel", 15, 805, 18);
	item->Describe();
}
```

## 실행 결과

```
Name        = Excalibur
Description = The legendary sword of King Arthur
Weight      = 12 lbs
Value       = 1024 gold coins
Damage      = 24

Name        = Steel Armor
Description = Protective covering made by steel
Weight      = 15 lbs
Value       = 805 gold coins
Defense     = 18
```