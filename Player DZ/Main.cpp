#include<iostream>
#include<vector>
#include<string>


//Класс предмет имеет приватное поле "название предмета", а так же тип предмета для доступа к ним,
//реализованы Геттеры

class Item {
public:
	Item(std::string name,std::string type):name(name),type(type){}

	std::string GetName()const {
		return name;
	}

	std::string GetType()const {
		return type;
	}
private:
	std::string name;
	std::string type;
};


//Класс рюкзак хранит все добавленные предметы в динамическом массиве
class Backpack {
public:
	void addItem(Item* item) {
		items.push_back(item);
		std::cout << "Предмет " << item->GetName() << " добавлен в рюкзак" << std::endl;
	}

private:
	std::vector<Item*>items;
};

//Класс котрый экипирует приедметы в нужные слоты так же выполняет проверку
//подходит ли предмет для слота
class EquipmentSlot {
public:
	EquipmentSlot(std::string type):type(type),item(nullptr){}

	std::string GetType()const {
		return type;
	}

	bool CanEquipment(const Item& item)const {
		return item.GetType() == type;
	}
	

	void Equipment(Item& item,std::string itemType) {
		if (CanEquipment(item)) {
			this->item = &item;
			std::cout << "Предмет " << item.GetName() << " экипированв в слот " << type
				<< std::endl;
		}
		else {
			std::cout << "Предмет " << item.GetName() << " не может быть экипирован в слот " << type
				<< std::endl;
		}
	}

private:
	std::string type;
	Item* item;
};

//Класс Игрок который содержит свои характеристики а так же может экипировать
//предметы в нужные слоты

class Player {
public:
	Player(std::string name,std::string gender,int age):
		name(name),gender(gender),age(age){}

	void Equipmentitem(Item& item, EquipmentSlot& slot) {
		slot.Equipment(item,item.GetType());
		equippedItems.push_back(&item);
	}

private:
	std::string name;
	std::string gender;
	int age;
	std::vector<Item*> equippedItems;
	Backpack backpack;
};
	


int main() {
	setlocale(LC_ALL, "ru");

	Item sword("Sword", "Weapon");
	Item helmet("Helmet", "Armor");

	EquipmentSlot weaponSlot("Weapon");
	EquipmentSlot armorSlot("Armor");

	Player player("Herman", "Male", 25);

	player.Equipmentitem(sword,weaponSlot);
	player.Equipmentitem(helmet,armorSlot);
	
	player.Equipmentitem(sword, armorSlot);

	Backpack backpack;
	backpack.addItem(&sword);

	return 0;
}