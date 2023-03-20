struct point{
    int x;
    int y;
};
void move_point(struct point *p, int delta_x, int delta_y){
    p -> x = (*p).x + delta_x;
    
    p-> y = (*p).y + delta_y;
}
