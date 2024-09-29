#include "animal.h"
#include "rabbit.h"
#include "fox.h"
#include "game_field.h"
#include "options_parser.h"

#include <iostream>
#include <thread>
#include <chrono>

// in ----    out ------

// 4 4 3      *  *  *  1
// 2 1        *  *  *  1
// 0 1 1 3    * -1  *  *
// 2 2 0 2    *  *  *  * 
// 1 0 1 2    

int main() {
    const long long sleepTimeSec = 1;
    std::string filePath = "source.txt";
    unsigned int turns;
    data::PairUint size;
    std::vector<data::AnimalOptions> animals;

    try {
        data::OptionsParser parser(filePath);
        parser.Parse(animals, size, turns);

        view::GameField gameField(size);

        for (const auto& animal : animals) {
            if (animal.GetType() == data::AnimalType::Rabbit) {
                model::animal::Rabbit rabbit(animal.GetPosition(), animal.GetDirection(), animal.GetStability(), animals.size());
                gameField.AddRabbit(rabbit);
            }
            else if (animal.GetType() == data::AnimalType::Fox) {
                model::animal::Fox fox(animal.GetPosition(), animal.GetDirection(), animal.GetStability(), animals.size());
                gameField.AddFox(fox);
            }
        }

        for (unsigned int i = 0; i < turns; i++) {
            system("CLS");
            
            gameField.Step();
            gameField.Print(std::cout);

            std::this_thread::sleep_for(std::chrono::seconds(sleepTimeSec));
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}