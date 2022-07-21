#include <iostream>
#include <vector>

class Talent {
public:
    virtual void show() const = 0;
};

class Swimming: public Talent {
public:
    void show() const override {
        std::cout << "Swimming" << std::endl;
    }
};

class Dancing: public Talent {
public:
    void show() const override {
        std::cout << "Dancing" << std::endl;
    }
};

class Counting: public Talent {
public:
    void show() const override {
        std::cout << "Counting" << std::endl;
    }
};

class Dog {
    std::string name;
    std::vector<Talent*> talents;
public:
    explicit Dog(std::string& _name) {
        name = _name;
    }

    ~Dog() {
        for (auto talent : talents) delete talent;
    }

    void show_talents() const {
        std::cout << "This is " << name << " and it has some talents:" << std::endl;
        for (auto& talent : talents) talent->show();
    }

    void learn(Talent* talent) {
        talents.push_back(talent);
    }
};

int main() {
    std::string name = "Steve";
    Dog* dog = new Dog(name);

    dog->learn(new Swimming);
    dog->learn(new Dancing);
    dog->learn(new Counting);

    dog->show_talents();
    delete dog;
}
