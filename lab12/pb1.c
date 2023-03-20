struct person make_person(char *s, int age){
    struct person people;
    
    people.name = strdup(s);
    
    people.age = age;
    
    return people;
}




