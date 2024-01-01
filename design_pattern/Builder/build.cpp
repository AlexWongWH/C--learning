#include <iostream>
#include <string>
#include <vector>
#include <memory>

//Creating complex object by making up of simpler objects

//ideal create meal combo for fast food

//builder: meal combo

class Dessert
{
public:
virtual std::string GetDessert() {return name_;}
std::string name_ {"Dessert\n"};
};

class IceCream: public Dessert
{
public:
virtual std::string GetDessert() override {
    name_ = "IceCream";
    return "IceCream";}
};

class Pie: public Dessert
{
public:
virtual std::string GetDessert() override {
    name_ = "Pie";
    return "Pie";}
};

class Appetizer
{
public:
virtual std::string GetAppetizer() {return name_;}
std::string name_ {"Appetizer\n"};
};

class Salad : public Appetizer
{
public:
std::string GetAppetizer() override {
    name_ = "Salad";
    return name_;}
};

class Bread : public Appetizer
{
public:
std::string GetAppetizer() override {
    name_ = "Bread";
    return name_;}
};

class Entree
{
public:
virtual std::string GetEntree() {return name_;}
std::string name_ {"Entree\n"};
};

class Steak : public Entree
{
public:
std::string GetEntree() override {
    name_ = "Steak";
    return name_;}
};

class Fish : public Entree
{
public:
std::string GetEntree() override {
    name_ = "Fish";
    return name_;}
};


class MealCombo
{
public:
 Entree * entree_;
 Appetizer * appetizer_;
 Dessert *dessert_;
 std::string mealname_;

    MealCombo(std::string m) : mealname_ {m} {}
    ~MealCombo(){
        std::cout << "Deleting Combo\n";
        delete entree_;
        delete appetizer_;
        delete dessert_;
    }

    void printMeal()
    {
        std::cout<<"combo: " << mealname_ << "\n Entree " << entree_->GetEntree() << "\n side: "
            << appetizer_->GetAppetizer() << "\n dessert: " << dessert_->GetDessert() <<std::endl;
    }


};

//the interface to override
class MealBuilder
{
protected:
    MealCombo * meal_;
public:
	virtual void cookEntree() {};
	virtual void cookAppetizer() {};
	virtual void cookDessert() {};
	MealCombo* getMeal()
	{
		return meal_;
	}
};

class SteakCombo : public MealBuilder
{
    public:
    SteakCombo()
    {
        meal_ = new MealCombo("Steak Combo");
    }
    void cookEntree()
    {
        meal_->entree_ = new Steak;
    }
    void cookAppetizer()
    {
        meal_->appetizer_ = new Bread;
    }
    void cookDessert()
    {
        meal_->dessert_ = new IceCream;
    }
};

class FishCombo : public MealBuilder
{
    public:
    FishCombo()
    {
        meal_ = new MealCombo("Fish Combo");
    }
    void cookEntree()
    {
        meal_->entree_ = new Fish;
    }
    void cookAppetizer()
    {
        meal_->appetizer_ = new Salad;
    }
    void cookDessert()
    {
        meal_->dessert_ = new Pie;
    }
};


int main() {

    MealBuilder * cook = new MealBuilder; // not sure which meal is created 
    MealCombo* meal;
    cook = new SteakCombo;
    meal = cook->getMeal();

    std::cout << "Meal: " << meal->mealname_ << std::endl;

  return 0;
};