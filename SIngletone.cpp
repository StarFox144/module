#include <iostream>
#include <string>

class CoffeeShop {
public:
    // Статичний метод для отримання єдиного екземпляра класу
    static CoffeeShop* getInstance() {
        if (!instance) {
            instance = new CoffeeShop();
        }
        return instance;
    }

    // Функції кав'ярні
    void serveCoffee(const std::string& customer) {
        std::cout << "Serving coffee to " << customer << std::endl;
    }

    void cleanUp() {
        std::cout << "Cleaning up the coffee shop" << std::endl;
    }

private:
    // Приватний конструктор, щоб заборонити створення екземплярів ззовні
    CoffeeShop() {}

    // Єдиний екземпляр класу
    static CoffeeShop* instance;
};

// Ініціалізація статичної змінної
CoffeeShop* CoffeeShop::instance = nullptr;

int main() {
    // Отримання єдиного екземпляра кав'ярні
    CoffeeShop* coffeeShop = CoffeeShop::getInstance();

    // Використання кав'ярні
    coffeeShop->serveCoffee("John");
    coffeeShop->serveCoffee("Alice");

    // Очищення кав'ярні
    coffeeShop->cleanUp();

    // Звільнення пам'яті (необов'язково, оскільки CoffeeShop::instance буде звільнено автоматично при закінченні програми)
    delete coffeeShop;

    return 0;
}
