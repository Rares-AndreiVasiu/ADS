struct person {
    char *name;
    int age;
    struct person *friend;
};

struct person make_person(char *name, int age){
    
    struct person new_person;
    
    new_person.name = name;
    new_person.age = age;
    new_person.friend = NULL;
    
    return new_person;
}
