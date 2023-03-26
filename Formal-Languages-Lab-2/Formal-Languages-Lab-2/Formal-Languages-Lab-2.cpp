#include <iostream>
#include <string>
#include <numeric>

#pragma region ContextMenu
    #define ignor_rest std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    #define Cin_Err_fix {std::cin.clear();std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');}
#pragma endregion

class ContextMenu {
public:
    auto seleсt_opt() {
        bool flagok = false;
        size_t var = 0;
        while (var == 0 || var > 2) {
            if (flagok) std::cout << "Ошибка ввода, повторите попытку... \n\n";
            std::cin >> var;
            flagok = true;
            if (std::cin.get() != '\n') {
                ignor_rest;
                var = 0;
            }
            if (!std::cin) Cin_Err_fix;
        }
        return var;
    }
    
};

class AK47 {
public:
    bool check(std::string prop) {
        State exp_s = c1;
        for (size_t i = 0; i < prop.size(); i++) {
            char symbol = prop.at(i);
            switch (exp_s) {
                case c1: 
                    if (symbol == 'b') 
                    {
                        exp_s = c2;
                        break;
                    }
                    else return 0;
                case c2: 
                    if (symbol == 'a') 
                    {
                        exp_s = c1;
                        break;
                    }
                    else if (symbol == 'b')
                    {
                        exp_s = c3;
                        break;
                    }
                    else return 0;
                case c3: 
                    if (symbol == 'b' && i + 1 == prop.size()) exp_s = c4;
                    else if (symbol == 'b') 
                    {
                        exp_s = c4;
                        break;
                    }
                    else return 0;
                case c4: 
                    if (i+1 == prop.size()) exp_s = f5;
                    else if (symbol == 'c') exp_s = f5;
                    else return 0;
                case f5: return 1;
            }
        }
        return 0;
    }

private:
    enum State {
        c1, c2, c3, c4, f5
    };
};

int main()
{
    std::string proposal;
    AK47 AK47;
    ContextMenu Menu;
    setlocale(LC_ALL, "rus");
    std::cout << "Добро пожаловать!\nДанная программа поможет определить удовольтворяет ли введенное предложение регулярному.\n";
    while (1) {
        std::cout << "\n\n1.Ввести предложение\n2.Выход\n";
        size_t var = Menu.seleсt_opt();
        if (var == 1) 
        {
            std::cout << "\nНаше регулярное выражение : b(ab)*bbc? \n";
            std::cout << "\nВведите предложение: ";
            std::cin >> proposal;

            if (AK47.check(proposal))
            {
                std::cout << "\nВведенное вами выражение МОЖЕТ быть получено из регулярного!";
            }
            else
            {
                std::cout << "\nВведенное вами выражение НЕ МОЖЕТ быть получено из регулярного!";
            }
        }
        else if (var == 2) 
        {
            std::cout << "\nДо следующей встречи!!!";
            break;
        }
        
    }
    

    return 1;
}

