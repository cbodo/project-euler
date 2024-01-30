#ifndef NAME_H
#define NAME_H

#include <string>

class Name {
private:
    std::string name;
    int score;
    int index;

public:
    Name(const std::string& name, int index);
    
    std::string get_name() const;
    int get_score() const;
    int get_index() const;
    void set_name(const std::string& new_name);
    void set_index(int new_index);
    void update_score();
};

#endif