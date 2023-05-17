/*
	此代码未完成,  已经看蒙圈了
*/

#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <memory>
using namespace std;

class GameObject {
public:
	virtual void collide(GameObject& otherObject) = 0;
};

class SpaceShip : public GameObject {
public:
	typedef void (SpaceShip::*HitFunctionPtr) (GameObject&);
	typedef map<string, HitFunctionPtr> HitMap;
	
	
	virtual void collide(GameObject& otherObject);

	virtual void hitSpaceShip(GameObject& spaceShip);
	virtual void hitSpaceStation(GameObject& spaceStation);
	virtual void hitAsteroid(GameObject& asteroid);

	HitMap* initializeCollisionMap();

};

class SpaceStation : public GameObject {};
class Asteroid : public GameObject {};

// throw exption class 
class UnknownCollision { 
public:
	UnknownCollision(GameObject& class1, GameObject& class2) {} 
};

SpaceShip::HitMap* SpaceShip::initializeCollisionMap() {
	HitMap* phm = new HitMap;

	(*phm)["SpaceShip"] = &hitSpaceShip;
	(*phm)["SpaceStation"] = &hitSpaceStation;
	(*phm)["Asteroid"] = &hitAsteroid;

	return phm;
}


void SpaceShip::hitSpaceShip(GameObject& spaceShip) {
	SpaceShip& otherShip = dynamic_cast<SpaceShip&> (spaceShip);
}

void SpaceShip::hitSpaceStation(GameObject& spaceStation) {
	SpaceStation& otherStation = dynamic_cast<SpaceStation&> (spaceStation);
}

void SpaceShip::hitAsteroid(GameObject& asteroid) {
	Asteroid& otherAsteroid = dynamic_cast<Asteroid&> (asteroid);
}



// 第三方类
namespace {
	// 主要的碰撞处理函数
	void shipAsteroid( GameObject& spaceShip, GameObject& asteroid );
	void shipStation( GameObject& spaceShip, GameObject& spaceStation );
	void asteroidStation(GameObject& asteroid, GameObject& spaceStation );


	// 次要的碰撞函数处理, 主要为了实现对称性:
	// 对调参数位置, 然后调用主要的碰撞函数.
	void asteroidShip(GameObject& asteroid, GameObject& spaceShip) {
		shipAsteroid(spaceShip, asteroid);
	}

	void  stationShip(GameObject& spaceStation, GameObject& spaceShip) {
		shipStation(spaceShip, spaceStation);
	}

	void stationAsteroid(GameObject& spaceStation, GameObject& asteroid) {
		asteroidStation(asteroid, spaceStation);
	}


	
	typedef void (*HitFunctionPtr) (GameObject&, GameObject&);
	typedef map< pair< string, string>, HitFunctionPtr > HitMap;

	pair<string, string> makeStringPair(const char* s1, const char* s2);   //这是个fun 别看错了

	HitMap* initializeCollisionMap();    // this is a fun

	HitFunctionPtr lookup(const string& class1, const string& class2);   // this is a fun

}   // spacename  end;  this 匿名空间


void processCollision(GameObject& object1, GameObject& object2) {
	HitFunctionPtr phf = lookup(typeid(object1).name(), typeid(object2).name());  //动态类名
	
	if (phf) {
		phf(object1, object2);
	}
	else {
		throw UnknownCollision(object1, object2);
	}
}


namespace {
	pair<string, string> makeStringPair(const char* s1, const char* s2) {
		return pair<string, string>(s1, s2);
	}
}

namespace {
	HitMap* initializeCollisionMap() {
		HitMap* phm = new HitMap;
		(*phm)[makeStringPair("SpaceShip", "Asteroid")] = &shipAsteroid;
		(*phm)[makeStringPair("SpaceShip", "SpaceStation")] = &shipStation;

		return phm;
	}
}

namespace {
	HitFunctionPtr lookup(const string& class1, const string& class2) {
		static auto_ptr<HitMap> collisionMap(initializeCollisionMap());
	
		HitMap::iterator mapEntry = collisionMap->find(make_pair(class1, class2));

		if (mapEntry == collisionMap->end()) {
			return 0;
		}

		return (*mapEntry).second;
	}
}


class CollisionMap {
public:
	typedef void(*HitFunctionPtr) (GameObject&, GameObject&);

	void addEntry(const string& type1,
		          const string& type2,
		          HitFunctionPtr collisionFunction,
		          bool symmetric = true);
	void removeEntry(const string& type1, const string& type2);

	HitFunctionPtr lookup(const string& type1, const string& type2);

	// 这个函数返回一个引用, 代表仅有有一个map
	static CollisionMap& theCoolisionMap();

private:
	// 这些函数都是private, 用以防止产生多个map 
	CollisionMap();
	CollisionMap(const CollisionMap&);
};


int main(void) {


	system("pause");
	return 0;
}