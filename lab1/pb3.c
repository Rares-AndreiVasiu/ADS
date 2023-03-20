char* make_copy(char * array){
char *copy = strdup(array);

    if(!copy)
    {
       free(copy);
       return NULL;
    }
  return copy;
}




