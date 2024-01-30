#include "name.h"
#include <string>

Name::Name(const std::string& name, int index) : name(name), index(index) {
    update_score();
}

std::string Name::get_name() const {
    return name;
}

int Name::get_score() const {
    return score;
}

int Name::get_index() const {
    return index;
}

void Name::set_name(const std::string& new_name) {
    name = new_name;
    update_score();
}

// Setter method for score (not recommended for external use)
void Name::set_index(int new_index) {
    index = new_index;
    update_score();
}

void Name::update_score() {
    score = 0;

    for (char ch : name) {
        score += (toupper(ch) - 'A' + 1);
    }
    score *= (index + 1);
}